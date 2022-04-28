#include "Game.hpp"

void rnd(CardSet& v){
    srand(time(NULL));
    for (auto i = 0, j = 0; i <= 4; i++){
            j = std::rand() % 13 + 1;
            v.push_back(std::make_pair(static_cast<Figures>(j), static_cast<Colour>(i)));
    }
random_shuffle(v.begin(), v.end()); 
}

void PrintVector(CardSet &x){
    for (size_t i = 0; i < x.size(); ++i){
        std::cout << "Figura: " << x[i].first << "\tKolor: " << x[i].second << std::endl;
    }
}

int main(){
    std::cout << "Hello from Main" << std::endl;
    CardSet setCard;
    rnd(setCard);
    PrintVector(setCard);

    return 0;
}