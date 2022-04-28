#include "Game.hpp"

void rnd(CardSet& v){
    srand(time(NULL));
    for (auto i = 0, j = 0; i <= 4; i++){
            j = std::rand() % 12 + 1;
            v.push_back(std::make_pair(static_cast<Figures>(j), static_cast<Colour>(i)));
    }
    random_shuffle(v.begin(), v.end());
}

void PrintVector(CardSet &x){
    for (size_t i = 0; i < x.size(); ++i){
        std::cout << "Figure: " << x[i].first << "\tColour: " << x[i].second << std::endl;
    }
}

int main(){
    std::cout << "Hello from Main" << std::endl;
    CardSet setCard;
    rnd(setCard);
    PrintVector(setCard);

    //const char heart[] = "\xe2\x99\xa5";
    std::cout << "\xe2\x99\xa4" << std::endl;

    return 0;
}