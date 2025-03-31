#include <iostream>
#include <random>
using namespace std;

// Get user's name
string UserInput(string &name)
{
    cout << "Enter your name: ";
    cin >> name;
    return name;
}

// Display welcome message
void Welcome(string name)
{
    cout << "\n\n";
    cout << "================ Welcome " << name << " ================" << endl;
    cout << "To Guess the Random Number Game!" << endl;
    cout << "I'm thinking of an integer between 1-100. Depending on your difficulty level, you will have a set number of tries. GOOD LUCK!" << endl;
}

// Select difficulty level
int Difficulty(int &difficulty)
{
    cout << "\n\n";
    cout << "================ Difficulty select ================\n";
    cout << "Please select the difficulty level:\n1. Easy (10 chances)\n2. Medium (5 chances)\n3. Hard (3 chances)\n"
         << endl;
    cin >> difficulty;

    switch (difficulty)
    {
    case 1:
        cout << "You chose Easy. You have 10 tries!" << endl;
        return 10;
    case 2:
        cout << "You chose Medium. You have 5 tries. Good luck!" << endl;
        return 5;
    case 3:
        cout << "You chose Hard. You have 3 tries!" << endl;
        return 3;
    default:
        cout << "You chose an invalid option. Defaulting to Easy.\nYou have 10 tries!" << endl;
        return 10;
    }
}

// Generate random integer between 1 and 100
int GeneInteger()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 100);
    return dist(gen);
}

// Game logic - user guesses the number
void gamePlay(int value, int difficulty)
{
    int guess;

    for (int i = 0; i < difficulty; i++)
    {
        cout << "\nEnter your guess: ";
        cin >> guess;
        cout << "Attempt number " << i + 1 << "\n" << endl;

        if (guess == value)
        {
            cout << "CONGRATS!! You have guessed the right value!" << endl;
            return;
        }
        else if (guess > value)
        {
            cout << "Your guessed value is too big. Please try again." << endl;
        }
        else
        {
            cout << "Your guessed value is too small. Please try again." << endl;
        }
    }

    // If user runs out of tries
    cout << "\n You have run out of tries :( Restart the game to try again." << endl;
    cout << "The value was " << value;
}

// Main function
int main()
{
    string name;
    int difficulty, value;

    // Get user name
    UserInput(name);

    // Welcome message
    Welcome(name);

    // Select difficulty
    difficulty = Difficulty(difficulty);

    // Generate random number
    value = GeneInteger();

    // Start the game
    gamePlay(value, difficulty);

    return 0;
}
