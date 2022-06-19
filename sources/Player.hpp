#pragma once
#include <string>
using namespace std;

#include <array>
#include "Game.hpp"

namespace coup
{
   class Game;
   class Player {
       public:
    string _role ;
    string _name;
    int _steal;   
    string _LastAction;
    Player *_lastPlayer;
     int _coins; 
     bool _alive;
   
      Game *_game;
   Player(Game &g, string name);
      void income();
      void foreign_aid();
      virtual void coup(Player &player);
     
      string role()const ;
      int coins() const;
     
   };
}