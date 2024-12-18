#!/usr/bin/env bash
set -eu

cd "$(dirname "$0")"

CMD=${1:-}

if [ -n "$CMD" ]; then
  if [ "$CMD" = "clean" ]; then
    git clean -fdx
    exit 0
  else
    echo "Unknown command: $CMD"
    exit 1
  fi
fi

# Attempt to just pull artefacts from CI and exit on success.
[ -n "${USE_CACHE:-}" ] && ./bootstrap_cache.sh && exit

g="\033[32m"  # Green
b="\033[34m"  # Blue
r="\033[0m"   # Reset

AVAILABLE_MEMORY=0

case "$(uname)" in
  Linux*)
    # Check available memory on Linux
    AVAILABLE_MEMORY=$(awk '/MemTotal/ { printf $2 }' /proc/meminfo)
    ;;
  *)
    echo "Parallel builds not supported on this operating system"
    ;;
esac
# If builds fail with an amount of free memory greater than this value then it should be increased.
MIN_PARALLEL_BUILD_MEMORY=134217728

yarn

if [[ AVAILABLE_MEMORY -lt MIN_PARALLEL_BUILD_MEMORY ]]; then
  echo "System does not have enough memory for parallel builds, falling back to sequential"
  ./noir-contracts/bootstrap.sh
  ./noir-protocol-circuits/bootstrap.sh
  ./mock-protocol-circuits/bootstrap.sh
else
  ((./noir-contracts/bootstrap.sh) > >(awk -v g="$g" -v r="$r" '{print g "contracts: " r $0}')) &
  ((./noir-protocol-circuits/bootstrap.sh) > >(awk -v b="$b" -v r="$r" '{print  b "protocol-circuits: " r $0}')) &
  ((./mock-protocol-circuits/bootstrap.sh) > >(awk -v b="$b" -v r="$r" '{print  b "mock-protocol-circuits: " r $0}')) &

  for job in $(jobs -p); do
    wait $job || exit 1
  done
fi