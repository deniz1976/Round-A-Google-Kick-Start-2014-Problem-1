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



int main() {
    int arr[4][4] = {{4, 4, 8, 2 },
                     {2, 0, 4, 2 },
                     {2, 2, 4, 8 },
                     {2, 2, 4, 4 }
                     };

    std::string direction;
    std::cout << "For this test case, we have an array " << std::size(arr) << "x" << std::size(arr[0]) << std::endl;
    std::cout << "enter a direction (right, left, north, south)" << std::endl;
    std::cin >> direction;
//    for (int i = 0; i < size(arr); i++) {
//        for (int j = 0; j < size(arr[0]); j++) {
//            if (arr[i][j] != 0) {
//                if (arr[i][j] % 2 != 0) {
//                    arr[i][j] = 0;
//                } else {
//                    while (true) {
//                        if (arr[i][j] == 2) {
//                            break;
//                        } else if (arr[i][j] % 2 == 0) {
//                            arr[i][j] = arr[i][j] / 2;
//                        } else {
//                            arr[i][j] = 0;
//                            break;
//                        }
//                    }
//                }
//            }
//        }
//    }
    if (direction == "right" || direction == "r") {
        int list;
        int r;

        for (int i = 0; i < std::size(arr); i++) {
            list = i, r = std::size(arr) - 1;
            for (int j = std::size(arr) - 2; j >= 0; j--) {
                if (arr[i][j] != 0) {
                    if (arr[i][j + 1] == 0 || arr[i][j + 1] == arr[i][j]) {
                        if (arr[list][r] == arr[i][j]) {
                            arr[list][r] *= 2;
                            arr[i][j] = 0;
                        } else {
                            if (arr[list][r] == 0) {
                                arr[list][r] = arr[i][j];
                                arr[i][j] = 0;
                            } else {
                                arr[list][--r] = arr[i][j];
                                arr[i][j] = 0;
                            }
                        }
                    } else r--;
                }
            }
        }
        for (auto &k: arr) {
            int ctt = 0;
            for (int l = 0; l < std::size(k); l++) {
                if (ctt == std::size(k) - 1) {
                    std::cout << k[l] << std::endl;
                } else {
                    std::cout << k[l];
                    ctt++;

                }
            }
        }
    } else if (direction == "left" || direction == "l") {
        int list;
        int r;

        for (int i = 0; i < std::size(arr); i++) {
            list = i, r = 0;
            for (int j = 1; j < std::size(arr); j++) {
                if (arr[i][j] != 0) {
                    if (arr[i][j - 1] == 0 || arr[i][j - 1] == arr[i][j]) {
                        if (arr[list][r] == arr[i][j]) {
                            arr[list][r] *= 2;
                            arr[i][j] = 0;
                        } else {
                            if (arr[list][r] == 0) {
                                arr[list][r] = arr[i][j];
                                arr[i][j] = 0;
                            } else {
                                arr[list][++r] = arr[i][j];
                                arr[i][j] = 0;
                            }
                        }
                    } else r++;
                }
            }
        }
        for (auto &k: arr) {
            int ctt = 0;
            for (int l = 0; l < std::size(k); l++) {
                if (ctt == std::size(k) - 1) {
                    std::cout << k[l] << std::endl;
                } else {
                    std::cout << k[l];
                    ctt++;
                }
            }
        }
    } else if (direction == "south" || direction == "down" || direction == "s" || direction == "d") {
        int list;
        int r;

        for (int i = 0; i < std::size(arr); i++) {
            list = i, r = std::size(arr) - 1;
            for (int j = std::size(arr) - 2; j >= 0; j--) {
                if (arr[j][i] != 0) {
                    if (arr[j + 1][i] == 0 || arr[j + 1][i] == arr[j][i]) {
                        if (arr[r][list] == arr[j][i]) {
                            arr[r][list] *= 2;
                            arr[j][i] = 0;
                        } else {
                            if (arr[r][list] == 0) {
                                arr[r][list] = arr[j][i];
                                arr[j][i] = 0;
                            } else {
                                arr[--r][list] = arr[j][i];
                                arr[j][i] = 0;
                            }
                        }
                    } else r--;
                }
            }
        }
        for (auto &k: arr) {
            int ctt = 0;
            for (int l = 0; l < std::size(k); l++) {
                if (ctt == std::size(k) - 1) {
                    std::cout << k[l] << std::endl;
                } else {
                    std::cout << k[l];
                    ctt++;
                }
            }
        }
    } else if (direction == "north" || direction == "up" || direction == "n" || direction == "u") {
        int list;
        int r;

        for (int i = 0; i < std::size(arr); i++) {
            list = i, r = 0;
            for (int j = 1; j < std::size(arr); j++) {
                if (arr[j][i] != 0) {
                    if (arr[j - 1][i] == 0 || arr[j - 1][i] == arr[j][i]) {
                        if (arr[r][list] == arr[j][i]) {
                            arr[r][list] *= 2;
                            arr[j][i] = 0;
                        } else {
                            if (arr[r][list] == 0) {
                                arr[r][list] = arr[j][i];
                                arr[j][i] = 0;
                            } else {
                                arr[++r][list] = arr[j][i];
                                arr[j][i] = 0;
                            }
                        }
                    } else r++;
                }
            }
        }
        for (auto &k: arr) {
            int ctt = 0;
            for (int l = 0; l < std::size(k); l++) {
                if (ctt == std::size(k) - 1) {
                    std::cout << k[l] << std::endl;
                } else {
                    std::cout << k[l];
                    ctt++;
                }
            }
        }
    } else {
        std::cout << "there is no direction named " << direction << " ,exiting system." << std::endl;
        return 31;
    }

    return 0;
}






