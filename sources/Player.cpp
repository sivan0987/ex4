#include "Player.hpp"
#include "Game.hpp"
using namespace coup;
using namespace std;

namespace coup {
    
    void Player::income() {
         int const ten= 10;
         if(this->coins() >= ten) {
            throw runtime_error("till 10 coins");
        }
        if(!this->_alive) {
            throw runtime_error(" dead");
        }
        if(this->_game->_turn == -1) {
            throw runtime_error("EROOR!");
        }
         if(this->_game->_players.at((unsigned long)_game->_turn)->_name != this->_name) {
            throw runtime_error("opps not your turn");
        }
        
        
         this->_LastAction = "income";
        this->_coins++;
        
        this->_game->change_turn();
    }

     Player:: Player(Game &g, string name): _LastAction("NULL"), _lastPlayer(NULL),_coins(0){
         _role = "player";
         _alive = true;
        int const maxPlayers = 6;
        vector<string> players = g.players();
      
        if(players.size() == maxPlayers) {
            throw runtime_error("YOU HAVE 6 PLAYERS");
        }
        this->_name = move(name);
        
        g.add_player(this);
        this->_game = &g;
        this->_steal = 0; }
   
    
    
    
    void Player::foreign_aid() {
        int const ten= 10;
            if(this->coins() >= ten) {
            throw runtime_error("you have to do coup");
        }
        if(this->_game->_players.at((unsigned long)_game->_turn)->_name != this->_name) {
            throw runtime_error("opps not your turn");
        }
        if(this->_game->_turn == -1) {
            throw runtime_error("EROOR!");
        }
        
        if(!this->_alive) {
            throw runtime_error("you are dead!!");
        }
     
       this->_LastAction = "foreign_aid";
        this->_coins+=2;
        
        this->_game->change_turn();
    }
    
    void Player::coup(Player &player) {
        int const seven = 7;
             if(this->coins() < seven) {
            throw runtime_error("you dont have enough money");
        }
         if(this->_game->_players.at((unsigned long)_game->_turn)->_name != this->_name) {
            throw runtime_error("opps not your turn");
        }
        if(this->_game->_turn == -1) {
            throw runtime_error("EROOR!");
        }

       
        if(!this->_alive) {
            throw runtime_error("you are dead!!");
        }
        if(player._game != this->_game) {
            throw runtime_error("not the same game ");
        }
   
        if(!player._alive) {
            throw runtime_error("dead");
        }
        this->_lastPlayer = &player;   
        player._alive = false;
        this->_coins-=seven;
        this->_LastAction = "coup_cant_be_block";
        
        this->_game->change_turn();      
    }

   
    
    string Player::role() const{
        return _role ;
    }
    
    int Player::coins() const {
        return this->_coins;
    }
    
 
}