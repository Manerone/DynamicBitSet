#ifndef DYNAMIC_BITSET_H
#define DYNAMIC_BITSET_H

#include "inttypes.h"
#include <math.h>

class DynamicBitSet {
private:
    uint64_t *bitset;
    uint32_t bitset_size;

    uint32_t bitPositionInBitset(uint32_t n);

public:
    DynamicBitSet(uint32_t n);

    void setBitToOne(uint32_t n);
    void setBitToZero(uint32_t n);

    bool readBit(uint32_t n);
};

#endif