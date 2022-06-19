#pragma once
//Assassin
#include <string>
#include "Player.hpp"
using namespace std;

namespace coup{
    class Assassin : public Player
    {
    protected:
        public:
       Assassin (Game &game,string name) : Player(game,move(name)) {
           this->_role ="Assassin";
       } 
        void coup(Player &player);
    };
    
    
    


}