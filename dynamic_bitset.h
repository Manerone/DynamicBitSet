#ifndef DYNAMIC_BITSET_H
#define DYNAMIC_BITSET_H

#include "inttypes.h"
#include <math.h>

class DynamicBitSet {
private:

    typedef uint64_t min_element_size;

    min_element_size *bitset;
    uint64_t bitset_size;
    uint64_t n_of_bits;

    uint64_t min_element_size_bits();

public:
    DynamicBitSet(uint64_t n_of_bits);

    static void setBitToOne(DynamicBitSet bitset, uint64_t bit);
    static void setBitToZero(DynamicBitSet bitset, uint64_t bit);

    static bool readBit(DynamicBitSet bitset, uint64_t bit);

    static DynamicBitSet intersection(DynamicBitSet bitset, DynamicBitSet b2);
    static void intersection_on_self(DynamicBitSet bitset, DynamicBitSet b2);

    static void print(DynamicBitSet bitset);
};

#endif