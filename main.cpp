/*Requirements:
Implement a solution for a supermarket checkout that calculates the total price of a number of
items. In a normal supermarket, things are identified using Stock Keeping Units, or SKUs. In our
store, we'll use individual letters of the alphabet (A, B, C, and so on). Our goods are priced
individually. In addition, some items are multi-priced: buy N of them, and they'll cost you Y cents.
For example, item 'A' might cost 50 cents individually, but this week we have a special offer: buy
three 'A's, and they'll cost you $1.30. In fact this week's prices are:

***********************************
* Item   Unit Price Special Price *
-----------------------------------
* A    *    50    *   3 for 130   *
* B    *    30    *   2 for 45    *
* C    *    20    *               *
* D    *    10    *               *
***********************************

Our checkout accepts items in any order, so that if we scan a B, an A, and another B, we'll
recognize the two B's and price them at 45 (for a total price so far of 95). Because the pricing
changes frequently, any update should be accounted for in subsequent orders.
The following lists of products should produce these prices:

50, price("A")
80, price("AB")
110, price("CDBA")
100, price("AA")
130, price("AAA")
180, price("AAAA")
230, price("AAAAA")
260, price("AAAAAA")
160, price("AAAB")
175, price("AAABB")
185, price("AAABBD")
185, price("DABABA")
------------------------------------------------------------------------------------------------------------------------
Technical Guidelines:
The program needs to be written in your preferred programming language.
You can use any framework that you feel comfortable with, or start from scratch and write a no framework solution yourself.
Create a simple webpage, that submits a form, the input is being validated, calculation is performed, and a receipt is printed on the screen.

DB schema shall be implemented to store unit price information (including special promotion
info) and the sales record (a kind of an electronic receipt - which units, how many of them and
for what price were sold at a given time).
Don’t forget to include a script that creates the database, or alternatively, a database dump. */

#include <iostream>
#include <cstdlib>

int main() {

    //Variables declaration
    int number, n;
    int total = 0;
    char ask; //some sort of dialog with the customer
    int price[4] = {50, 30, 20, 10}; //array of type int for the prices

    //Declaring a lable so the "goto" statment can be used to return the program at its initial point
    retry:

    //Shopping list for the customer to select hid choice (I was inspired by the table in the requirements above)
    std::cout << "======================================" << std::endl;
    std::cout << "              LIST                    " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "Name of product\t||       Price       " << std::endl;
    std::cout << "1. A           \t||        50         " << std::endl;
    std::cout << "2. B           \t||        30         " << std::endl;
    std::cout << "3. C           \t||        20         " << std::endl;
    std::cout << "4. D           \t||        10         " << std::endl;

    //IO operations related to the list above
    std::cout << "Please, select your purchase: ";  //output
    std::cin >> number;                             //Input

    //switch cases for the products
    switch (number) {
        case 1:
            std::cout << "Please, select how many of the products you want to purchase: ";
            std::cin >> n;
            total +=price[0] * n;
            std::cout << "Would that be all you wish to purchase? (y/n)";
            std::cin >> ask;
            if(ask=='y'){
                system("clear");
                goto retry;
            }else{
                std::cout << "Total amount: " << total << std::endl;
            }

        case 2:
            std::cout << "Please, select how many of the products you want to purchase: ";
            std::cin >> n;
            total +=price[1] * n;
            std::cout << "Would that be all you wish to purchase? (y/n)";
            std::cin >> ask;
            if(ask=='y'){
                system("clear");
                goto retry;
            }else{
                std::cout << "Total amount: " << total << std::endl;
            }

        case 3:
            std::cout << "Please, select how many of the products you want to purchase: ";
            std::cin >> n;
            total +=price[2] * n;
            std::cout << "Would that be all you wish to purchase? (y/n)";
            std::cin >> ask;
            if(ask=='y'){
                system("clear");
                goto retry;
            }else{
                std::cout << "Total amount: " << total << std::endl;
            }

        case 4:
            std::cout << "Please, select how many of the products you want to purchase: ";
            std::cin >> n;
            total +=price[3] * n;
            std::cout << "Would that be all you wish to purchase? (y/n)";
            std::cin >> ask;
            if(ask=='y'){
                system("clear");
                goto retry;
            }else {

                std::cout << "Total amount: " << total << std::endl;
            }

    }

    return 0;
}
