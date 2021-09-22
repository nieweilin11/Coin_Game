﻿#include "std_lib_facilities.h"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;


vector<int> coin_flip(vector<int> x, int y[3], int b) {
    for (int i = 0; i < b; i++) {//put the array to "coin"
        if (x[y[i] - 1] == 1) //
            x[y[i] - 1] = 0;
        else if (x[y[i] - 1] == 0) {
            if (x[y[b - 1] - 1] == 0 && b > 1) {//when the largest number is "0", it cannot be turned
                for (int i = 0; i < b; i++) {
                    y[i] = 4;
                    cout << "y" << i << "=" << y[i];
                }
                error("The right most coin is facing head can't choose this one please choose again");
            }
            x[y[i] - 1] = 1;
        }
    }
    for (int i = 0; i < b; i++)
        y[i] = 4;

    return x;
}

bool isNum(string str);
int parseInt(string str);

int main() {
    cout << "                                                    COIN FLIP" << endl;
    cout << "                                PlayerA and PlayerB flip the coin game, a total of [10] coins" << endl;
    cout << "                                PlayerA flips first, PlayerB flips back, in turn, each time you can flip [1-3] coins" << endl;
    cout << "                                Who filp the [10th] coin who is the winner" << endl;

    vector<string> player(2);
    vector<int>coin_num;
    vector<int>coin_2;
    int sum_total = 10;
    string str_num;
    player[0] = "Player_A";
    player[1] = "Player_B";
    int select = 0, n = 0, round_counter = 0, round = 1;
    vector<int>coin;
    int len[3] = { 4,4,4 };

    for (int i = 0; i < 10; i++) {
        coin.push_back(1);
    }

    while (sum_total)
    {

        if (round_counter % 2 == 0 && round_counter != 0) {//round calculator
            round++;
            cout << endl;
            cout << endl;
        }

        cout << "                                         " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "Ronud_" << round << endl;
        cout << "                                     " << "     There are" << "[" << sum_total << "]" << "coins are facing up." << endl;
        cout << "                                     " << " " << " " << " " << " " << " " << " " << " " << "-----------------------------" << endl;
        cout << "                                     " << " " << " " << " " << " " << " " << " " << " ";
        for (int i = 0; i < 10; i++) {
            if (coin[i] == 1)
                cout << "H" << "  ";
            if (coin[i] == 0)
                cout << "T" << "  ";
        }
        cout << endl;
        cout << "                                     " << " " << " " << " " << " " << " " << " " << " " << "1  2  3  4  5  6  7  8  9  10" << endl;
        cout << endl;
        cout << "                                           " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "[" << player[n] << "]" << endl;
        cout << "                                    " << "       Please choose how many to turn (1-3)：";

        try {

            if (select > sum_total) {
                cout << "                                                Still left" << "[" << sum_total << "]" << "coin，" << endl;
                error("                                                Cannot select more coins than the remaining coins, please select again");
                select = 0;
                cout << endl;
                continue;
            }
            cout << "                                           Choose which coin to flip:";
            int int_num;
            if (select == 1) {
                while (cin >> str_num)
                {
                    if (!isNum(str_num)) {
                        error("Please enter a number ");
                        break;
                    }
                    int_num = parseInt(str_num);
                    if (int_num > 10 || int_num < 1) {
                        error("Please enter a number from 1-10 ");
                        break;
                    }
                    coin_num.push_back(int_num);
                    break;
                }
            }

            if (select == 2) {
                int e = 0;
                int e_1 = 0;
                for (int i = 0; i < 2; i++) {
                    while (cin >> str_num)
                    {
                        int_num = parseInt(str_num);
                        if (int_num == ' ')
                            break;
                        if (!isNum(str_num)) {
                            e_1 = 1;
                            break;
                        }
                        int_num = parseInt(str_num);
                        if (int_num > 10 || int_num < 1) {
                            e = 1;
                            break;
                        }
                        coin_num.push_back(int_num);
                        break;
                    }
                    sort(coin_num.begin(), coin_num.end());
                }
                if (e == 1)
                    error("Please enter a number from 1 - 10 ");
                if (e_1 == 1)
                    error("Please enter  number  ");
            }
            if (select == 3) {
                int e = 0;
                int e_1 = 0;
                for (int i = 0; i < 3; i++) {
                    while (cin >> str_num)
                    {

                        int_num = parseInt(str_num);
                        if (int_num == ' ')
                            break;
                        if (!isNum(str_num)) {
                            e_1 = 1;
                            break;
                        }
                        int_num = parseInt(str_num);
                        if (int_num > 10 || int_num < 1) {
                            e = 1;
                            break;
                        }
                        coin_num.push_back(int_num);
                        break;
                    }

                    sort(coin_num.begin(), coin_num.end());
                }
                if (e == 1)
                    error("Please enter a number from 1 - 10 ");
                if (e_1 == 1)
                    error("Please enter  number  ");
            }

            int coin_size = coin_num.size();
            for (int i = 0; i < coin_size; i++) {
                len[i] = coin_num[i];
            }
            coin = coin_flip(coin, len, coin_size);


            coin_num.clear();
            int coin_cout_p = 0;
            for (int i = 0; i < 10; i++) {
                if (coin[i] == 1)
                    coin_cout_p++;
            }

            sum_total = coin_cout_p;//add them
            if (sum_total == 0)
                break;
            n++;
            if (n > 1)n = 0;
            round_counter++;

        }

        catch (exception& e) {
            cout << endl;
            cout << endl;
            coin_num.clear();
            for (int i = 0; i < coin_num.size(); i++)
                len[i] = 4;
            cout << "                                          " << e.what() << endl;
            cout << endl;
            cout << endl;
            continue;
        }


    }

    cout << "                                            " << player[n] << " Win!!! " << endl;
    system("pause");
}
