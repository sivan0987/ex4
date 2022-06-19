#include "Captain.hpp"
using namespace coup;

namespace coup {
    Captain::Captain(Game &game,string name) : Player(game,move(name)) {
        this->_role = "Captain";
    }
    
   

    void Captain::block(Player &player){
        if(this->_game->_players.at((unsigned long)_game->_turn)->_name != this->_name) {
            throw runtime_error("no turn");
        }
          if(!player._alive) {
            throw runtime_error("you deaed");
        }
        if(this->_game->_turn == -1) {
            throw runtime_error("cant start ");
        }
        
        if(!this->_alive) {
            throw runtime_error("deadd");
        }
        if(player._game != this->_game) {
            throw runtime_error("wrong");
        }
      
        
        if (player._LastAction != "steal") {
            throw runtime_error("wrong action");
        } 
         this->_coins-=2;
        this->_LastAction = "block";
        player._lastPlayer->_coins += 2;
       
        this->_lastPlayer = &player;
        
    }

     void Captain::steal(Player &player){
          if(!player._alive) {
            throw runtime_error("the player is already dead");
        }
          if(!this->_alive) {
            throw runtime_error("deaed");
        }
         if(player._game != this->_game) {
            throw runtime_error("wrong no game ");
        }
       
           if(this->_game->_players.at((unsigned long)_game->_turn)->_name != this->_name) {
            throw runtime_error("wrong");
        }
        if(this->_game->_turn == -1) {
            throw runtime_error("cant start ");
        }
      
       
       
        if(player.coins() >=2) {
              this->_coins += 2;
            this->_steal=2;
            player._coins -= 2;
          
        } 
        else if(player.coins() == 1) {
              this->_coins += 1;
            this->_steal = 1;   
            player._coins -= 1;
               
        } else {
            this->_steal = 0;        
        }
        this->_LastAction = "steal";
        this->_lastPlayer = &player;
        this->_game-> change_turn();
    }
    
}