// #pragma once
// #include <iostream>
// #include <vector>
// #include <stdexcept>
// #include <string>
// #include "Player.hpp"

// namespace coup {
//     class Player;
//     class Game {
//         // private:
//         //     int _turn;
//         //     vector <Player *> _players;
//         //     //int _winner;        
    
//         public:
//             int _turn;
//             vector <Player *> _players;
            
//              Game() {   
//         this->_turn = -1; 
//     }
//             void turn();
//             vector<string> players();
//             string winner();
//             void add_player(Player *player);
          
//             void chang_turn();
//             vector<Player *> get_players();
//             ~Game();
//     };
// } 
#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include "Player.hpp"

namespace coup {
    class Player;
    class Game {
             
    
        public:
            int _turn;

            vector <Player *> _players;

            Game();
            void turn();
           
            
            void add_player(Player *other);
            int get_turn() const;
            void change_turn();
             vector<string> players();
            string winner();
    };
} 