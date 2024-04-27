#include"Solver.h"
#include<cstddef>
#include<utility>

void Solution(
    const BackPack& back_pack, 
    std::vector<bool>& taken, 
    std::vector<bool>& max_taken, 
    size_t& max_price, 
    size_t& max_weight, 
    size_t i, 
    size_t current_weight,
    size_t current_price
    ){
    if(i == back_pack.items.size()){
        return;
    }
    if(current_weight + back_pack.items[i].weight > back_pack.max_weight){
        return;
    }
    current_weight += back_pack.items[i].weight;
    current_price += back_pack.items[i].price;
    taken[i] = true;
    if(current_price > max_price){
        max_price = current_price;
        max_weight = current_weight;
        max_taken = taken;
    }
    Solution(back_pack, taken, max_taken, max_price, max_weight, i + 1, current_weight, current_price);
    current_weight -= back_pack.items[i].weight;
    current_price -= back_pack.items[i].price;
    taken[i] = false;
    Solution(back_pack, taken, max_taken, max_price, max_weight, i + 1, current_weight, current_price);
}

Answer Solution(const BackPack& back_pack){
    std::vector<bool> taken(back_pack.items.size(), false);
    std::vector<bool> max_taken(back_pack.items.size(), false);
    size_t max_price = 0;
    size_t max_weight = 0;
    Solution(back_pack, taken, max_taken, max_price, max_weight, 0, 0, 0);
    Answer answer;
    answer.price = max_price;
    answer.items = std::move(max_taken);
    answer.max_weight = back_pack.max_weight;
    answer.weight = max_weight;
    return answer;
}