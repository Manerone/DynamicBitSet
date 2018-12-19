//
// Created by Matheus Nerone on 2018-12-07.
//
#include <iostream>
#include "dynamic_bitset.h"
#include <vector>
#include <chrono>
#include <boost/dynamic_bitset.hpp>

using namespace std;

#define N_BITS 4294967296

boost::dynamic_bitset<> test_boost(){
    chrono::high_resolution_clock::time_point start, end;

    start = chrono::high_resolution_clock::now();
    boost::dynamic_bitset<> bitset(N_BITS);
    boost::dynamic_bitset<> bitset2(N_BITS);
    end = chrono::high_resolution_clock::now();

    auto d0 = chrono::duration_cast<chrono::microseconds>( end - start ).count();
    cout << "Boost - initialize: " << d0/1000000.0 << "\n";

    start = chrono::high_resolution_clock::now();
    for(uint64_t i = 0; i < N_BITS; i += 3)
    {
        bitset[i] = 1;
    }
    end = chrono::high_resolution_clock::now();

    auto d1 = chrono::duration_cast<chrono::microseconds>( end - start ).count();

    cout << "Boost - first bitset: " << d1/1000000.0 << "\n";

    start = chrono::high_resolution_clock::now();

    for(uint64_t i = 0; i < N_BITS; i += 2)
    {
        bitset2[i] = 1;
    }

    end = chrono::high_resolution_clock::now();

    auto d2 = chrono::duration_cast<chrono::microseconds>( end - start ).count();

    cout << "Boost - second bitset: " << d2/1000000.0 << "\n";

    start = chrono::high_resolution_clock::now();

    bitset &= bitset2;

    end = chrono::high_resolution_clock::now();

    auto d3 = chrono::duration_cast<chrono::microseconds>( end - start ).count();

    cout << "Boost - intersection: " << d3/1000000.0 << "\n";

    return bitset;
}

DynamicBitSet test_dynamic_bitset(){
    chrono::high_resolution_clock::time_point start, end;

    start = chrono::high_resolution_clock::now();
    DynamicBitSet bitset = DynamicBitSet(N_BITS);
    DynamicBitSet bitset2 = DynamicBitSet(N_BITS);
    end = chrono::high_resolution_clock::now();

    auto d0 = chrono::duration_cast<chrono::microseconds>( end - start ).count();
    cout << "Dynamic bitset - initialize: " << d0/1000000.0 << "\n";

    start = chrono::high_resolution_clock::now();
    for(uint64_t i = 0; i < N_BITS; i += 3)
    {
        bitset.setBitToOne(i);
    }
    end = chrono::high_resolution_clock::now();

    auto d1 = chrono::duration_cast<chrono::microseconds>( end - start ).count();

    cout << "Dynamic bitset - first bitset: " << d1/1000000.0 << "\n";

    start = chrono::high_resolution_clock::now();

    for(uint64_t i = 0; i < N_BITS; i += 2)
    {
        bitset2.setBitToOne(i);
    }

    end = chrono::high_resolution_clock::now();

    auto d2 = chrono::duration_cast<chrono::microseconds>( end - start ).count();

    cout << "Dynamic bitset - second bitset: " << d2/1000000.0 << "\n";

    start = chrono::high_resolution_clock::now();

    bitset.intersection_on_self(bitset2);

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
    for(uint64_t i = 0; i < N_BITS; i += 3)
    {
        bitset.at(i) = 1;
    }
    end = chrono::high_resolution_clock::now();

    auto d1 = chrono::duration_cast<chrono::microseconds>( end - start ).count();

    cout << "Vector Bool - first bitset: " << d1/1000000.0 << "\n";

    start = chrono::high_resolution_clock::now();

    for(uint64_t i = 0; i < N_BITS; i += 2)
    {
        bitset2.at(i) = 1;
    }

    end = chrono::high_resolution_clock::now();

    auto d2 = chrono::duration_cast<chrono::microseconds>( end - start ).count();

    cout << "Vector Bool - second bitset: " << d2/1000000.0 << "\n";

    start = chrono::high_resolution_clock::now();

    for(uint64_t i = 0; i < N_BITS; i++)
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

    chrono::high_resolution_clock::time_point t5 = chrono::high_resolution_clock::now();
    boost::dynamic_bitset<> c = test_boost();
    chrono::high_resolution_clock::time_point t6 = chrono::high_resolution_clock::now();

    auto d1 = chrono::duration_cast<chrono::microseconds>( t2 - t1 ).count();

    auto d2 = chrono::duration_cast<chrono::microseconds>( t4 - t3 ).count();

    auto d3 = chrono::duration_cast<chrono::microseconds>( t6 - t5 ).count();

    cout << "Dynamic bitset: " << d1/1000000.0 << "\n";

    cout << "Vector bool: " << d2/1000000.0 << "\n";

    cout << "Boost bitset: " << d3/1000000.0 << "\n";

    for(uint64_t i = 0; i < N_BITS; i++)
    {
        if(a.readBit(i) != b.at(i) || (a.readBit(i) != c[i])){
            printf("Wrong value, %llu\n", i);
            return -1;
        }
    }

    return 0;
}

