#ifndef DYNAMIC_BITSET_H
#define DYNAMIC_BITSET_H

#include "inttypes.h"
#include <math.h>

class DynamicBitSet {
private:

    typedef uint64_t min_element_size;

    const min_element_size one = 1;
    const min_element_size min_element_size_bits = sizeof(min_element_size) * 8;
    const min_element_size log_of_min_element = log2(min_element_size_bits);

    min_element_size *bitset;
    uint64_t bitset_size;
    uint64_t n_of_bits;

public:
    DynamicBitSet(uint64_t number_of_bits);

    void setBitToOne(uint64_t bit);
    void setBitToZero(uint64_t bit);

    bool readBit(uint64_t bit);

    DynamicBitSet intersection(DynamicBitSet bitset);
    void intersection_on_self(DynamicBitSet bitset);

    void print();
};

#endif