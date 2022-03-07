/*Requirements: //
Implement a solution for a supermarket checkout that calculates the total price of a number of
items. In a normal supermarket, things are identified using Stock Keeping Units, or SKUs. In our
store, we'll use individual letters of the alphabet (A, B, C, and so on). Our goods are priced
individually. In addition, some items are multi-priced: buy N of them, and they'll cost you Y cents.
For example, item 'A' might cost 50 cents individually, but this week we have a special offer: buy
three 'A's, and they'll cost you $1.30. In fact this week's prices are:

***********************************
* Item   Unit Price Special Price *
-----------------------------------
* A    *    50    *   3 for 130   * (discount 13.3333%) <- I've calculated that to eventually help me in the process
* B    *    30    *   2 for 45    * (discount 25%) <- I've calculated that also to eventually help me in the process
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
info) and the sales record (a kind of electronic receipt - which units, how many of them and
for what price were sold at a given time).
Don’t forget to include a script that creates the database, or alternatively, a database dump. */

#include <cstdio>
#include <sqlite3.h> //SQLite header for database connection
#include <iostream>
#include <cstdlib> //this header allows calling OS commands (e.g. clear, pause and so on)

int main() {


    //Primitive variables declaration
    int number, n; //This variable will be used for the number of purchases of certain product the customer wants to buy
    int total = 0; //self-explanatory, value of 0 needs to be added, otherwise the calculation does not work
    char confirm; //some sort of dialog with the customer (y/n)
    int price[4] = {50, 30, 20, 10}; //array with values of type int for the prices


    //Declaring a label "retry" so the "goto" statement can be used to return the program at its initial point
    //The "goto" statement is not really recommended, however, I do find it working for this case

    retry:

        //Shopping list for the customer to select their choice (I was inspired by the table in the requirements above)
        std::cout << "*===================================================================" << std::endl;
        std::cout << "*                \tList of items to purchase    " << std::endl;
        std::cout << "*===================================================================" << std::endl;
        std::cout << "*      Item     \t||     Unit Price  \t|       *DISCOUNTS*" << std::endl;
        std::cout << "*1. A           \t||        50       \t|| *Special price 3 for 130*" << std::endl;
        std::cout << "*2. B           \t||        30       \t|| *Special price 2 for 45*" << std::endl;
        std::cout << "*3. C           \t||        20       \t|*" << std::endl;
        std::cout << "*4. D           \t||        10       \t|*" << std::endl;

        //IO operations related to the list above
        std::cout << "Please, select your purchase: ";  //Output
        std::cin >> number;                             //Input

        //switch cases for each item in the array
        switch (number) {
            case 1: //Item A
                std::cout << "Please, select how many of the items you want to purchase: ";
                std::cin >> n;
                if(n == 3){
                    total = 130;
                }else{
                    total += price[0] * n; //total = total + price[0] * n
                }
                std::cout << "Is that your final purchase? (y/n)";
                std::cin >> confirm;
                if (confirm == 'y') {
                    std::cout << "Total amount: " << total << std::endl;
                    system("clear");
                    return 0;
                } else if (confirm == 'n' || confirm == 'N') {
                    goto retry;
                } else {
                    std::cout << "------------------------------------" << std::endl;
                    std::cout << "Please, use 'y' or 'n' to confirm!" << std::endl;
                    std::cout << "------------------------------------" << std::endl;
                    goto retry;
                }

            case 2: //Item B
                std::cout << "Please, select how many of the items you want to purchase: ";
                std::cin >> n;
                if(n == 2){
                    total = 45;
                }else{
                total += price[1] * n;
                }
                std::cout << "Is that your final purchase? (y/n)";
                std::cin >> confirm;
                if (confirm == 'y') {
                    std::cout << "Total amount: " << total << std::endl;
                    system("clear");
                    return 0;
                } else if (confirm == 'n' || confirm == 'N') {
                    goto retry;
                } else {
                    std::cout << "------------------------------------" << std::endl;
                    std::cout << "Please, use 'y' or 'n' to confirm!" << std::endl;
                    std::cout << "------------------------------------" << std::endl;
                    goto retry;
                }

            case 3: //Item C
                std::cout << "Please, select how many of the items you want to purchase: ";
                    std::cin >> n;
                    total += price[2] * n;
                    std::cout << "Is that your final purchase? (y/n)";
                    std::cin >> confirm;
                    if (confirm == 'y') {
                        std::cout << "Total amount: " << total << std::endl;
                        system("clear");
                        return 0;
                    } else if (confirm == 'n' || confirm == 'N') {
                        goto retry;
                    } else {
                        std::cout << "------------------------------------" << std::endl;
                        std::cout << "Please, use 'y' or 'n' to confirm!" << std::endl;
                        std::cout << "------------------------------------" << std::endl;
                        goto retry;
                    }
            case 4: //Item D
                std::cout << "Please, select how many of the items you want to purchase: ";
                        std::cin >> n;
                        total += price[3] * n;
                        std::cout << "Is that your final purchase? (y/n)";
                        std::cin >> confirm;
                        if (confirm == 'y') {
                            std::cout << "Total amount: " << total << std::endl;
                            system("clear");
                            return 0;
                        } else if (confirm == 'n' || confirm == 'N') {
                            goto retry;
                        } else {
                            std::cout << "------------------------------------" << std::endl;
                            std::cout << "Please, use 'y' or 'n' to confirm!" << std::endl;
                            std::cout << "------------------------------------" << std::endl;
                            goto retry;
                        }
            default: std::cout << "The use of anything other than 1, 2, 3, and 4 is not a valid selection!";

        }

        goto retry;

}

//SQLite tutorial: https://www.sqlite.org/quickstart.html