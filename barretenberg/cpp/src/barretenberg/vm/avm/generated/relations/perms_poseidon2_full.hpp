// AUTOGENERATED FILE
#pragma once

#include "../columns.hpp"
#include "barretenberg/relations/generic_permutation/generic_permutation_relation.hpp"

#include <cstddef>
#include <tuple>

namespace bb::avm {

/////////////////// perm_pos2_fixed_pos2_perm ///////////////////

class perm_pos2_fixed_pos2_perm_permutation_settings {
  public:
    // This constant defines how many columns are bundled together to form each set.
    constexpr static size_t COLUMNS_PER_SET = 9;

    // Columns using the Column enum.
    static constexpr Column SRC_SELECTOR = Column::poseidon2_full_sel_poseidon;
    static constexpr Column DST_SELECTOR = Column::poseidon2_sel_poseidon_perm_immediate;
    static constexpr Column INVERSES = Column::perm_pos2_fixed_pos2_perm_inv;

    template <typename AllEntities> static inline auto inverse_polynomial_is_computed_at_row(const AllEntities& in)
    {
        return (in.poseidon2_full_sel_poseidon == 1 || in.poseidon2_sel_poseidon_perm_immediate == 1);
    }

    template <typename AllEntities> static inline auto get_const_entities(const AllEntities& in)
    {
        return std::forward_as_tuple(in.perm_pos2_fixed_pos2_perm_inv,
                                     in.poseidon2_full_sel_poseidon,
                                     in.poseidon2_full_sel_poseidon,
                                     in.poseidon2_sel_poseidon_perm_immediate,
                                     in.poseidon2_full_clk,
                                     in.poseidon2_full_a_0,
                                     in.poseidon2_full_a_1,
                                     in.poseidon2_full_a_2,
                                     in.poseidon2_full_a_3,
                                     in.poseidon2_full_b_0,
                                     in.poseidon2_full_b_1,
                                     in.poseidon2_full_b_2,
                                     in.poseidon2_full_b_3,
                                     in.poseidon2_clk,
                                     in.poseidon2_a_0,
                                     in.poseidon2_a_1,
                                     in.poseidon2_a_2,
                                     in.poseidon2_a_3,
                                     in.poseidon2_b_0,
                                     in.poseidon2_b_1,
                                     in.poseidon2_b_2,
                                     in.poseidon2_b_3);
    }

    template <typename AllEntities> static inline auto get_nonconst_entities(AllEntities& in)
    {
        return std::forward_as_tuple(in.perm_pos2_fixed_pos2_perm_inv,
                                     in.poseidon2_full_sel_poseidon,
                                     in.poseidon2_full_sel_poseidon,
                                     in.poseidon2_sel_poseidon_perm_immediate,
                                     in.poseidon2_full_clk,
                                     in.poseidon2_full_a_0,
                                     in.poseidon2_full_a_1,
                                     in.poseidon2_full_a_2,
                                     in.poseidon2_full_a_3,
                                     in.poseidon2_full_b_0,
                                     in.poseidon2_full_b_1,
                                     in.poseidon2_full_b_2,
                                     in.poseidon2_full_b_3,
                                     in.poseidon2_clk,
                                     in.poseidon2_a_0,
                                     in.poseidon2_a_1,
                                     in.poseidon2_a_2,
                                     in.poseidon2_a_3,
                                     in.poseidon2_b_0,
                                     in.poseidon2_b_1,
                                     in.poseidon2_b_2,
                                     in.poseidon2_b_3);
    }
};

template <typename FF_>
class perm_pos2_fixed_pos2_perm_relation
    : public GenericPermutationRelation<perm_pos2_fixed_pos2_perm_permutation_settings, FF_> {
  public:
    static constexpr const char* NAME = "PERM_POS2_FIXED_POS2_PERM";
};
template <typename FF_>
using perm_pos2_fixed_pos2_perm = GenericPermutation<perm_pos2_fixed_pos2_perm_permutation_settings, FF_>;

} // namespace bb::avm