#ifndef DYNAMIC_BITSET_H
#define DYNAMIC_BITSET_H

#include "inttypes.h"
#include <math.h>

class DynamicBitSet {
private:
    uint64_t *bitset;
    uint32_t bitset_size;

    uint32_t elementPositionInBitset(uint32_t bit_position);
    uint32_t determineBitsetSize(uint32_t n_of_bits);
    uint64_t min_element_size_bits();

public:
    DynamicBitSet(uint32_t n_of_bits);

    void setBitToOne(uint32_t bit);
    void setBitToZero(uint32_t bit);

    bool readBit(uint32_t bit);

    DynamicBitSet intersection(DynamicBitSet bitset);

    void print();
};

#endif