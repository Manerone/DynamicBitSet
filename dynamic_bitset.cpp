#include "dynamic_bitset.h"
#include "inttypes.h"
#include <math.h>

DynamicBitSet::DynamicBitSet(uint32_t n) {
    bitset_size = bitPositionInBitset(n);
    bitset = new uint64_t[bitset_size];
}

void DynamicBitSet::setBitToOne(uint32_t n) {
    bitset[bitPositionInBitset(n)] |= (1 << n);
}

void DynamicBitSet::setBitToZero(uint32_t n) {
    bitset[bitPositionInBitset(n)] |= ~(1 << n);
}

bool DynamicBitSet::readBit(uint32_t n) {
    uint64_t value = bitset[bitPositionInBitset(n)];
    return (uint64_t) 1 & (value >> n);
}

uint32_t DynamicBitSet::bitPositionInBitset(uint32_t n) {
    return ceil((double)n / sizeof(uint32_t));
}