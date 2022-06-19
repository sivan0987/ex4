#include "Contessa.hpp"
using namespace coup;

namespace coup {
  
    
    void Contessa::block(Player &other) {
         if(!this->_alive) {
            throw runtime_error("you are dead!!");
        }
        if(!other._alive) {
            throw runtime_error("the player is already dead");
        }
        if(this->_game->_turn == -1) {
            throw runtime_error("cant start");
        }
         if (other._LastAction != "coup") {
            throw runtime_error("cant block not kill action");
        } 
       
        if(other._game != this->_game) {
            throw runtime_error("no game ");
        }
        
        
       
        other._lastPlayer->_alive = true;
        this->_LastAction = "block";
        this->_lastPlayer = &other; 
             
    }

    
    
}