#include "dynamic_bitset.h"
#include "inttypes.h"
#include "stdio.h"
#include "string.h"
#include <math.h>

#define min_element_size uint64_t

DynamicBitSet::DynamicBitSet(uint32_t n_of_bits) {
    bitset_size = determineBitsetSize(n_of_bits);
    bitset = new min_element_size[bitset_size];
    memset(bitset, 0, bitset_size * min_element_size_bits()/8);
}

void DynamicBitSet::setBitToOne(uint32_t bit) {
    bitset[elementPositionInBitset(bit)] |= (1 << (bit % min_element_size_bits()));
}

void DynamicBitSet::setBitToZero(uint32_t bit) {
    bitset[elementPositionInBitset(bit)] |= ~(1 << (bit % min_element_size_bits()));
}

bool DynamicBitSet::readBit(uint32_t bit) {
    min_element_size value = bitset[elementPositionInBitset(bit)];
    return (min_element_size) 1 & (value >> (bit % min_element_size_bits()));
}

void DynamicBitSet::print(){
    
    for(size_t i = 0; i < bitset_size * min_element_size_bits(); i++)
    {
        if(i % min_element_size_bits() == 0)
            printf("|");
        printf("%d", readBit(i));
    }
    printf("\n");
    
}

uint32_t DynamicBitSet::elementPositionInBitset(uint32_t bit_position) {
    return ceil((double)bit_position / min_element_size_bits());
}

uint32_t DynamicBitSet::determineBitsetSize(uint32_t n_of_bits){
    return ceil((double)n_of_bits / min_element_size_bits());
}

uint64_t DynamicBitSet::min_element_size_bits(){
    return sizeof(min_element_size)*8;
}