// Duke
#include <string>
#include "Player.hpp"
using namespace std;
#pragma once

namespace coup
{
    class Player;
    class Game;
    class Duke : public Player
    {
   

    public:
        Duke(Game &game,string name): Player(game,move(name)) {
             this->_role = "Duke";
        }
        void tax();
        void block(Player &other);
    };
}