/**
* @name Deniz Mutlu
*
* Problem
*
2048 is a famous single-player game in which the objective is to slide tiles on a grid to combine them and create a
tile with the number 2048.

2048 is played on a simple 4 x 4 grid with tiles that slide smoothly when a player moves them. For each movement,
the player can choose to move all tiles in 4 directions, left, right, up, and down, as far as possible at the same
time. If two tiles of the same number collide while moving, they will merge into a tile with the total value of the
two tiles that collided. In one movement, one newly created tile can not be merged again and always is merged with
the tile next to it along the moving direction first. E.g. if the three "2" are in a row "2 2 2" and the player choose
to move left, it will become "4 2 0", the most left 2 "2" are merged.
The above figure shows how 4 x 4 grid varies when player moves all tiles 'right'.

Alice and Bob accidentally find this game and love the feel when two tiles are merged. After a few round, they start
to be bored about the size of the board and decide to extend the size of board to N x N, which they called the game
"Super 2048".

The big board then makes them dazzled (no zuo no die -_-| ). They ask you to write a program to help them figure out
what the board will be looked like after all tiles move to one specific direction on a given board.

Input
The first line of the input gives the number of test cases, T. T test cases follow. The first line of each test case
gives the side length of the board, N, and the direction the tiles will move to, DIR. N and DIR are separated by a
single space. DIR will be one of four strings: "left", "right", "up", or "down".

The next N lines each contain N space-separated integers describing the original state of the board. Each line
represents a row of the board (from top to bottom); each integer represents the value of a tile (or 0 if there is no
number at that position).

Output
For each test case, output one line containing "Case #x:", where x is the test case number (starting from 1).
Then output N more lines, each containing N space-separated integers which describe the board after the move in the
same format as the input.

Limits
Time limit: 30 seconds per test set.
Memory limit: 1GB.
Each number in the grid is either 0 or a power of two between 2 and 1024, inclusive.

Small dataset (Test set 1 - Visible)
1 ≤ T ≤ 20
1 ≤ N ≤ 4
Large dataset (Test set 2 - Hidden)
1 ≤ T ≤ 100
1 ≤ N ≤ 20

*/

#include <iostream>

using namespace std;

int main() {
    int input;
    std::string direction;
    std::string directions[] = {"right,left,north,south"};
    std::cout << "enter an positive integer A for board area AxA , A must be greater than 1." << std::endl;
    std::cin >> input;
    if (input < 1) {
        std::cout << "A cant be less than 1, exiting system." << std::endl;
        return 31;
    }
    std::cout << "enter a direction (right, left, north, south)" << std::endl;
    std::cin >> direction;
    int counter = 0;
    for (int i = 0; i < 4; i++) {
        if (direction == directions[i]) {

        } else {
            counter++;
        }
    }
    if (counter == 4) {
        std::cout << "there is no direction named " << direction << " ,exiting system." << std::endl;
        return 31;
    }
    int arr[3][3] = {{2, 2, 2},  // 0 2 4
                     {2, 0, 2},  // 0 0 4
                     {0, 4, 4}}; // 0 0 8

//    for (int i = 0; i < size(arr); i++) {
//        for (int j = 0; j < size(arr); j++) {
//
//            if (counter == 2) {
//                std::cout << arr[i][j] << std::endl;
//                counter = 0;
//
//            } else {
//                std::cout << arr[i][j];
//                counter++;
//            }
//        }
//    }

    // 2 0 4
    // 2 2 0
    // 0 4 0

    if (direction == "right") {
        for (int i = 0; i < std::size(arr); i++) {
            for (int j = 0; j < std::size(arr[i]); j++) {
                if (arr[i][std::size(arr[i]) - j - 1] == 0) {
                    continue;
                } else if (j != std::size(arr[i])-1 && arr[i][std::size(arr[i]) - j - 1] == arr[i][std::size(arr[i]) - j]) {
                    arr[i][std::size(arr[i]) - j] *= 2;
                    arr[i][std::size(arr[i]) - j - 1] = 0;
                    //j = 2
                }
                if (j != std::size(arr[i])-1 && arr[i][std::size(arr[i]) - j] == 0) {
                    int ct = j;
                    while (arr[i][std::size(arr[i]) - ct] != 0) {
                        if (arr[i][std::size(arr[i]) - ct] == arr[i][std::size(arr[i]) - ct + 1]) {
                            arr[i][std::size(arr[i]) - ct + 1] = arr[i][std::size(arr[i]) - ct];
                            arr[i][std::size(arr[i]) - ct] = 0;
                            ct++;
                        } else {
                            arr[i][std::size(arr[i]) - ct + 1] = arr[i][std::size(arr[i]) - ct];
                            arr[i][std::size(arr[i]) - ct] = 0;
                        }
                    }

                }
            }

        }
    }
    for (auto &i: arr) {
        int ctt = 0;
        for (int j = 0; j < std::size(i); j++) {
            if (ctt == 2) {
                std::cout << i[j] << std::endl;
            } else {
                std::cout << i[j];
                ctt++;
            }


        }
    }
    return 0;
}

