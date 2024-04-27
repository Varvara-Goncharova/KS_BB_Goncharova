#include "Parser.h"
#include<algorithm>
#include<cstddef>

istream& operator>>(std::istream& stream, BackPack& backpack){
    size_t amount;
    stream >> amount;
    stream >> backpack.max_weight;
    backpack.items.resize(amount);
    for(size_t i = 0; i < amount; ++i){
        stream >> backpack.items[i].price >> backpack.items[i].weight;
    }
    return stream;
}

ostream& operator<<(std::ostream& stream, const Answer& answer){
    stream << answer.price << " " << answer.max_weight - answer.weight << std::endl;
    for(size_t i = 0; i < answer.items.size(); ++i){
        if(answer.items[i]){
            stream << 1 << " ";
        }
        else{
            stream << 0 << " ";
        }
    }
    return stream;
}