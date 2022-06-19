#include "Assassin.hpp"
using namespace coup;

namespace coup {
    class Player;
    class Duke;
    
   
    
    void  Assassin::coup(Player &player) {
          if(!this->_alive) {
            throw runtime_error("deaad");
        }
       if(!player._alive) {
            throw runtime_error("you daye");
        }
        int const seven = 7;

        if (this->coins() >= seven) {
            Player::coup(player);
            return;
        }
         if(this->_game->_players.at((unsigned long)_game->_turn)->_name != this->_name) {
            throw runtime_error("no turn");
        }
        if(this->_game->_turn == -1) {
            throw runtime_error("cant start");
        }
       
      
        if(this->coins() < 3) {
            throw runtime_error("you dont have enough money");
        }
        if(!player._alive) {
            throw runtime_error("the player is already dead");
        }
          this->_LastAction = "coup";
        this->_lastPlayer = &player; 
        player._alive = false;
        this->_coins -= 3;
      
        this->_game->change_turn();
    }

}

        