// 5_Takehome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BingoCard.h"
using namespace std;

void checkAndPrint(BingoCard* input) {
    if (input->checkBingo()) {
        cout << "Bingo!" << endl;
    }
    else {
        cout << "No Bingo!" << endl;
    }
    cout << input->toString() << endl;
    input->clearBoard();
    /*TODO: call checkBingo() on the input
     *      and print either "Bingo!" or "No Bingo!"
     *      then print the board using cout and toString
     *      and finally call clearBoard()
     */
}

int main()
{
    BingoCard *bc = new BingoCard(5);
    
    bc->call(03);
    bc->call(12);
    bc->call(25);
    bc->call(37);
    bc->call(61);
    bc->call(64);
    checkAndPrint(bc);

    bc->call(14);
    bc->call(22);
    bc->call(31);
    bc->call(55);
    bc->call(73);
    checkAndPrint(bc);

    bc->call(28);
    bc->call(30);
    bc->call(22);
    bc->call(26);
    bc->call(23);
    checkAndPrint(bc);

    bc->call(10);
    bc->call(30);
    bc->call(31);
    bc->call(54);
    bc->call(73);
    checkAndPrint(bc);

    bc->call(12);
    bc->call(26);
    bc->call(31);
    bc->call(68);
    bc->call(48);
    checkAndPrint(bc);

    delete bc;
}
