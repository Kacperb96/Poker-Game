#include "Game.hpp"

short countCards1(std::vector<int>& cardSet){
    short counter {0};
    for(std::size_t i = 0; i < cardSet.size(); i++){
        for(std::size_t j = i + 1; j < cardSet.size(); j++){
            if(cardSet[j] == cardSet[i]) counter ++;
        }
    }

    return counter;
}

int main(){
    std::cout << "Hello from Main" << std::endl;
    std::vector<int> vec {1,2,2,2,2};
    std::cout << "Licznik: " << countCards1(vec) << std::endl;

    return 0;
}