//
// Created by Matheus Nerone on 2018-12-07.
//
#include <iostream>
#include "dynamic_bitset.h"
#include <vector>
#include <chrono>

using namespace std;

#define N_BITS 4294967296

DynamicBitSet test_dynamic_bitset(){
    chrono::high_resolution_clock::time_point start, end;

    start = chrono::high_resolution_clock::now();
    DynamicBitSet bitset = DynamicBitSet(N_BITS);
    DynamicBitSet bitset2 = DynamicBitSet(N_BITS);
    end = chrono::high_resolution_clock::now();

    auto d0 = chrono::duration_cast<chrono::microseconds>( end - start ).count();
    cout << "Dynamic bitset - initialize: " << d0/1000000.0 << "\n";

    start = chrono::high_resolution_clock::now();
    for(size_t i = 0; i < N_BITS; i += 3)
    {
        DynamicBitSet::setBitToOne(bitset, i);
    }
    end = chrono::high_resolution_clock::now();

    auto d1 = chrono::duration_cast<chrono::microseconds>( end - start ).count();

    cout << "Dynamic bitset - first bitset: " << d1/1000000.0 << "\n";

    start = chrono::high_resolution_clock::now();

    for(size_t i = 0; i < N_BITS; i += 2)
    {
        DynamicBitSet::setBitToOne(bitset2, i);
    }

    end = chrono::high_resolution_clock::now();

    auto d2 = chrono::duration_cast<chrono::microseconds>( end - start ).count();

    cout << "Dynamic bitset - second bitset: " << d2/1000000.0 << "\n";

    start = chrono::high_resolution_clock::now();

    DynamicBitSet::intersection_on_self(bitset, bitset2);

    end = chrono::high_resolution_clock::now();

    auto d3 = chrono::duration_cast<chrono::microseconds>( end - start ).count();

    cout << "Dynamic bitset - intersection: " << d3/1000000.0 << "\n";

    return bitset;
}

vector<bool> test_vector_bool(){

    chrono::high_resolution_clock::time_point start, end;

    start = chrono::high_resolution_clock::now();
    vector<bool> bitset(N_BITS);
    vector<bool> bitset2(N_BITS);
    end = chrono::high_resolution_clock::now();

    auto d0 = chrono::duration_cast<chrono::microseconds>( end - start ).count();
    cout << "Vector Bool - initialize: " << d0/1000000.0 << "\n";

    start = chrono::high_resolution_clock::now();
    for(size_t i = 0; i < N_BITS; i += 3)
    {
        bitset.at(i) = 1;
    }
    end = chrono::high_resolution_clock::now();

    auto d1 = chrono::duration_cast<chrono::microseconds>( end - start ).count();

    cout << "Vector Bool - first bitset: " << d1/1000000.0 << "\n";

    start = chrono::high_resolution_clock::now();

    for(size_t i = 0; i < N_BITS; i += 2)
    {
        bitset2.at(i) = 1;
    }

    end = chrono::high_resolution_clock::now();

    auto d2 = chrono::duration_cast<chrono::microseconds>( end - start ).count();

    cout << "Vector Bool - second bitset: " << d2/1000000.0 << "\n";

    start = chrono::high_resolution_clock::now();

    for(size_t i = 0; i < N_BITS; i++)
    {
        bitset.at(i) = bitset.at(i) && bitset2.at(i);
    }

    end = chrono::high_resolution_clock::now();

    auto d3 = chrono::duration_cast<chrono::microseconds>( end - start ).count();

    cout << "Vector Bool - intersection: " << d3/1000000.0 << "\n";

    return bitset;
}

int main(){


    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
    DynamicBitSet a = test_dynamic_bitset();
    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();

    chrono::high_resolution_clock::time_point t3 = chrono::high_resolution_clock::now();
    vector<bool> b = test_vector_bool();
    chrono::high_resolution_clock::time_point t4 = chrono::high_resolution_clock::now();

    auto d1 = chrono::duration_cast<chrono::microseconds>( t2 - t1 ).count();

    auto d2 = chrono::duration_cast<chrono::microseconds>( t4 - t3 ).count();

    cout << "Dynamic bitset: " << d1/1000000.0 << "\n";

    cout << "Vector bool: " << d2/1000000.0 << "\n";

    for(size_t i = 0; i < N_BITS; i++)
    {
        if(DynamicBitSet::readBit(a, i) != b.at(i)){
            printf("Wrong value\n");
            return -1;
        }
    }

    return 0;
}

