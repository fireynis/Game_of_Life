//
// Created by jeremy on 10/26/2015.
//

#ifndef GAME_OF_LIFE_GAME_OF_LIFE_H
#define GAME_OF_LIFE_GAME_OF_LIFE_H

#include <iostream>
#include "random.h"

class game_of_life {

private:
    int generations;

public:
    game_of_life(int setGen):
            generations(setGen)
    {}

    int getCount(int dataArray[20][20], int i, int j);
    void copy(int inArray[20][20], int outArray[20][20]);

    void print(int pInt[20][20]);

    void life() {
        int lifeArray[20][20];
        int x, y, z, generation = 0;

        std::cout << "Please enter three numbers as seeds:" << std::endl;
        std::cin >> x >> y >> z;

        while (std::cin.fail()) {
            std::cout << "Please enter three numbers as seeds:" << std::endl;

            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> x >> y >> z;
        }

        random generator(x, y, z);

        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; ++j) {
                if (generator.getDouble() < 0.6) {
                    lifeArray[i][j] = 1;
                } else {
                    lifeArray[i][j] = 0;
                }
            }
        }

        std::cout << "Generation 0" << std::endl;
        print(lifeArray);
        std::cout << std::endl;

        while (generation != generations) {
            std::cout << "Generation " << generation+1 << std::endl;
            generation++;
            int newArray[20][20];
            copy(lifeArray, newArray);
            for (int i = 0; i < 20; ++i) {
                for (int j = 0; j < 20; ++j) {
                    int neighbour = getCount(lifeArray, i, j);
                    if (neighbour < 2 || neighbour > 3) {
                        newArray[i][j] = 0;
                    } else if (neighbour == 2) {
                        newArray[i][j] = lifeArray[i][j];
                    } else if (neighbour == 3) {
                        newArray[i][j] = 1;
                    }
                }
            }

            copy(newArray, lifeArray);
            print(lifeArray);
            std::cout << std::endl;
        }

        std::cout << "That was all 20 generations, time flies!" << "\n" << std::endl;
    }
};

#endif //GAME_OF_LIFE_GAME_OF_LIFE_H

int game_of_life::getCount(int dataArray[20][20], int i, int j) {
    int count =
            dataArray[(i-1 < 0)? 19:i-1][(j-1 < 0)? 19:j-1]+
            dataArray[(i-1 < 0)? 19:i-1][j]+
            dataArray[(i-1 < 0)? 19:i-1][(j+1 > 19)? 0:j+1]+
            dataArray[i][(j-1 < 0)? 19:j-1]+
            dataArray[i][(j+1 > 19)? 0:j+1]+
            dataArray[(i+1 < 19)? 0:i+1][(j-1 < 0)? 19:j-1]+
            dataArray[(i+1 < 19)? 0:i+1][j]+
            dataArray[(i+1 < 19)? 0:i+1][(j+1 > 19)? 0:j+1];
    return count;
}

void game_of_life::copy(int inArray[20][20], int outArray[20][20])
{
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
            outArray[i][i] = inArray[i][j];
    }
}

void game_of_life::print(int (*pInt)[20]) {

    for (int k = 0; k < 20; ++k) {
        for (int l = 0; l < 20; ++l) {
            if (pInt[k][l]) {
                std::cout << "X";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

}
