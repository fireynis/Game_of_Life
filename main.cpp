#include <iostream>
#include "game_of_life.h"

using namespace std;

int main() {

    game_of_life game(20);

    cout << "Conways Game of Life" << endl;
    cout << endl;
    game.life();

    return 0;
}