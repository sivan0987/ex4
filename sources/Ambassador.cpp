#include "Ambassador.hpp"
using namespace coup;

namespace coup {
    
  void Ambassador::PreventSteel(Player &player) {
          if(!this->_alive) {
            throw runtime_error("deead");
        }
          
        if(!player._alive) {
            throw runtime_error("deead");
        }
         if(player._game != this->_game) {
            throw runtime_error("it is no same game");
        }
        if(player._LastAction != "steal") {
            throw runtime_error("this is not steal ");
        }
      if(this->_game->_turn == -1) {
            throw runtime_error("errorr");
        }
       

        int amount = _steal;        
        player._lastPlayer->_coins += amount;
        player._coins -= amount;
        this->_LastAction = "PreventSteel";
        this->_lastPlayer = &player;
        this->_game->change_turn();
    }

    
    void Ambassador::transfer(Player &player1, Player &player2) {
           if(!player1._alive )  {
            throw runtime_error("dead");
        }
      if(!player2._alive )  {
            throw runtime_error("dead");
        }
        const int ten = 10;
        if(this->coins() >= ten) {
            throw runtime_error("you have more than 10 coins");
        }
         if(this->_game->_turn == -1) {
            throw runtime_error("the game can start with at least 2 players");
        }
        if(this->_game->_players.at((unsigned long)_game->_turn)->_name != this->_name) {
            throw runtime_error("not your turn");
        }
        if(!this->_alive) {
            throw runtime_error("deead");
        }
        

        if(player1._game != this->_game && player2._game != this->_game) {
            throw runtime_error("you are not in the same game ");
        }
     
      
        if(player1.coins() > 0) {
            player1._coins--;
            player2._coins++;
            this->_LastAction = "transfer";
            this->_lastPlayer = &player1;
            this->playerOf = &player2;
        } 
        else {
            throw runtime_error("not enogh money");
        }
        this->_game->change_turn();     
    }
    
    void Ambassador::block(Player &player) {
        if(this->_game->_turn == -1) {
            throw runtime_error("cant start the game ");
        }
        
        if(!this->_alive) {
            throw runtime_error("deaad");
        }
        if(player._game != this->_game) {
            throw runtime_error("no in the same game");
        }
        if(!player._alive) {
            throw runtime_error("the player is already dead");
        }
       
        if (player._LastAction != "steal") {
            throw runtime_error("this is wring action");
        }
        player._lastPlayer->_coins += 2;
        player._coins-=2;
        this->_LastAction = "block";
        this->_lastPlayer = &player; 
               
    }

    
    

}