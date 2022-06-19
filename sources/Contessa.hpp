
//Contessa
#include <string>
#include "Player.hpp"
using namespace std;
#pragma once
namespace coup{
    class Contessa : public Player
    {
     protected:
   
      
   
        public:
             Contessa(Game &game,string name) : Player(game,move(name)) {
                  this->_role = "Contessa";
             }
            void block(Player &other);
    };
    
    
    


}