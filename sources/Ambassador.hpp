//Ambassador
#pragma once
#include <string>
#include "Player.hpp"
using namespace std;
namespace coup{
    class Ambassador : public Player
    {
    
    
        public:
        Player *playerOf;
     Ambassador(Game &game,string name) : Player(game,move(name)) {
        this->playerOf = NULL;
        this->_role ="Ambassador";
    }
            void transfer(Player &player1, Player &player2);
            void PreventSteel(Player  &player);
            void block(Player &player);
    };
    
    
    


}