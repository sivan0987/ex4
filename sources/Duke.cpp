#include "Duke.hpp"
using namespace coup;

namespace coup {
    class Player;
    class Duke;
   

    void Duke::block(Player &other) {
       
        if (other._LastAction != "foreign_aid") {
            throw runtime_error("wrong action");
        } 
        if(!this->_alive) {
            throw runtime_error("deaed");
        }
        if(other._game != this->_game) {
            throw runtime_error("no game ");
        }
         if(this->_game->_turn == -1) {
            throw runtime_error("cant start");
        }
        if(!other._alive) {
            throw runtime_error("deaed");
        } this-> _LastAction= "block";
        
       
        other._alive = true;
       
        this->_lastPlayer = &other; 
        
    }
    
    void Duke::tax() {
        const int ten = 10;
       if(this->coins() >= ten) {
            throw runtime_error("alot of coins");
        }
        if(this->_game->_turn == -1) {
            throw runtime_error("erorr");
        }
        if(this->_game->_players.at((unsigned long)_game->_turn)->_name != this->_name) {
            throw runtime_error("eroor");
        }
        if(!this->_alive) {
            throw runtime_error("deaed");
        }this->_LastAction = "tax";
        
        this->_coins += 3;
        
        this->_game->change_turn();
    }
    
   
}