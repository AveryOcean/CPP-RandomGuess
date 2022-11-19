#include <iostream>

void StartLevel(int level);
void GameOver();
void SelectLevel();

int main() {
    std::cout << "-- RANDOM NUMBER GUESSING --" << std::endl;
    SelectLevel();
    return 0;
}

void StartLevel(int level) {
    // Create variables
    int max = 10 * level;
    int guess = 0;
    int tries = 0;

    // Initialize random seed
    srand(time(NULL));

    // Generate answer using random number generator
    int answer = rand() % max + 1;

    std::cout << "Guess a number between 1 and " << max << std::endl;
    std::cout << "You have 5 tries" << std::endl;
    std::cout << "Enter your guess: ";

    while(tries < 5)
    {
        // Try to get a valid guess
        try {
            std::cin >> guess;
            tries++;
        } catch (std::exception e) {
            std::cout << "Invalid input" << std::endl;
            std::cout << "Enter your guess: ";
            continue;
        }

        // Check if guess is correct
        if(guess == answer)
        {
            std::cout << "You win!" << std::endl;
            break;
        }
        else if(guess > answer)
        {
            std::cout << "Too high!" << std::endl;
        }
        else if(guess < answer)
        {
            std::cout << "Too low!" << std::endl;
        }
    }

    // Check if player ran out of tries
    if(tries == 5)
    {
        // Game over
        GameOver();
        return;
    }

    // Proceed to the next level
    std::cout << "You guessed it in " << tries << " tries" << std::endl;
    std::cout << "Proceed to the next level" << std::endl;

    // Pause the program until a key is pressed
    char c = 0;
    std::cin >> c;

    StartLevel(level + 1);
    std::cout << std::endl;
}

void SelectLevel() {
    int level = 1;

    std::cout << "Select Level to start on" << std::endl;
    std::cout << "A level determines how high the maximum number to guess is" << std::endl;
    std::cout << "Level must have a minimum value of 1" << std::endl;

    // Try to get a valid level
    do {
        std::cin >> level;
    } while (level < 1);

    // Start game on selected level
    std::cout << "You selected level " << level << std::endl;
    StartLevel(level);
}

void GameOver() {
    std::cout << "Game Over" << std::endl;
    std::cout << "Do you want to play again? (y/n)" << std::endl;

    char answer;
    std::cin >> answer;

    // Make answer lowercase
    answer = tolower(answer);

    // Check if player wants to play again
    if (answer == 'y') {
        StartLevel(1);
    } else {
        std::cout << "Thanks for playing!" << std::endl;
    }
}