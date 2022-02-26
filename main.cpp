//Guess the number

//REQUIREMENTS:
/*In the beginning of the execution, ask the customer to enter min and max number and tries count,
after the user enters min, max, tries count,
the program should generate random number between min and max and to give the user X number of tries to guess the number

If the user does not guess the number, output "Game over", if he guesses the number "Congratulations" and exit code 0!*/

/*------------------------------------------------------------------------------------------------------------------
/*Algorithm:
 * 1. Define the variables
 * 2. Output to the customer to enter the variable values
 * 3. Input with the variables
 * 4. for loop (since we know how many tries/iterations will be done as the user will define that)
 * 5. The user should guess the generated random number
 * 6. Output message depending on if he won or not - "Game over" or "Congratulations"
------------------------------------------------------------------------------------------------------------------*/

#include <iostream>
#include <cstdlib> //this header contains the srand() and rand() methods/functions for random number generation

int main() {

    //The minimum and maximum numbers which define the range and the tries counter variables
    int minNumber;
    int maxNumber;
    int triesCounter;
    int randomlyGeneratedNumber;

    //IO operations
    std::cout << "Please, enter minimum number: ";
    std::cin >> minNumber;

    std::cout << "Please, enter maximum number: ";
    std::cin >> maxNumber;

    std::cout << "Please, enter the number of tries you will guess the number with: ";
    std:: cin >> triesCounter;

    //This code will not be used, it was from pre-alpha testing of my own, where I was about to use srand()
    /* initialize random seed: */
    //srand (time(NULL));


    /* generate secret number between "minNumber" and "maxNumber": */
    randomlyGeneratedNumber = rand() % (maxNumber - minNumber + 1) + minNumber;

    int guessedNumber;
    do
    {
        std::cout << "Please, enter your guessed number: ";
        std::cin >> guessedNumber;
    }
    //while loop
    while(randomlyGeneratedNumber != guessedNumber && (--triesCounter > 0));

    /*Using ternary operator instead of if/else conditionals (v1)
    (randomlyGeneratedNumber == guessedNumber )
    ? std::cout << "Congratulations!"
    : std::cout << "Game over!";*/


   /*Using ternary operator instead of if/else conditionals (v2). I found that v1 type is more popular.
    * This below is written by me, but v1 was "stolen", it is not my own*/
   (randomlyGeneratedNumber==guessedNumber)? std::cout << "Congratulations!" : std::cout << "Game over!";


    return 0;
}
