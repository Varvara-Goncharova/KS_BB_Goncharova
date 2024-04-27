#pragma once
#include<vector>
#include<cstdint>
#include<iostream>

using namespace std;

struct Item{
    uint64_t price;
    uint64_t weight;
};

struct BackPack{
    vector<Item> items;
    uint64_t max_weight;
};

struct Answer{
    vector<bool> items;
    uint64_t price;
    uint64_t max_weight;
    uint64_t weight;
};

istream& operator>>(std::istream& stream, BackPack& backpack);
ostream& operator<<(std::ostream& stream, const Answer& answer);