#include <iostream> // Preprocessor directive
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room...\nEnter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    // expression statememnts
    // print welcome messages to terminal
    PrintIntroduction(Difficulty);

    // declaration statements
    // declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum =  CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // expression statements
    // print sum and product to the terminal
    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ There codes add-up to: " << CodeSum;
    std::cout << "\n+ There codes multiply to give: " << CodeProduct << std::endl;

    // store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // check if player guess is correct
    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** Well done agent! You have extracted a file! Keep going! ***";
        return true;
    }
    else
    {
        std::cout << "\n*** You entered wrong code! Careful agent! Try again! ***";
        return false;
    }
}

 // main function
int main()
{
    srand(time(NULL));
    
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) // loop game until all levels completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // clearns any errors
        std::cin.ignore(); // discards the buffer

        if (bLevelComplete) 
        {
            // increase the level difficulty
            ++LevelDifficulty;
        }
    }

    std::cout << "\n*** Great work agent! You got all the files! Now get out of there! ***";
    return 0; // return statement
}