#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include "Game.hpp"


using namespace std;
using namespace coup;


namespace coup {
     void Game::turn() {
        if(this->_turn >= 0) {
            cout << this->_players.at((unsigned long)this->_turn)->_name << endl;
        }
    }
    
    class Player;
      Game::Game() {   
        this->_turn = -1; 
    }
   

   
    vector<string> Game::players() {
        vector<string> temp ;

        for(unsigned long i = 0; i < this->_players.size(); i++) {
               
            if(this->_players.at(i)->_alive) {

                temp.push_back(this->_players.at(i)->_name);}
        }
        return temp;
    }

    std::string Game::winner() {
        string win;
        if(this->_turn == -1) {
            throw runtime_error("not start the gamr ");           
        }
        string result = "null";
        bool flag = false;
        
        for(unsigned long i = 0; i < this->_players.size(); i++) {
            if(this->_players.at(i)->_alive && !flag) {
                flag = true;
                win = this->_players.at(i)->_name;
            } else if(this->_players.at(i)->_alive && flag) {
                throw runtime_error("not the same game ");
            }
        }
        return win;
    }

    void Game::add_player(Player *other){
        if(this->_turn > 0) {
            throw runtime_error("you cant add player");
        }
        this->_players.push_back(other);
        if(this->_players.size() == 2) {
            this->_turn = 0;
        }
    }

  
    void Game::change_turn(){
        if(this->_turn ==  this->_players.size()-1) {
            this->_turn = 0;
        } else {
            this->_turn +=1;
        }
        if(!(this->_players.at((unsigned long)this->_turn)->_alive)) {
            change_turn();
        }
    }



}
