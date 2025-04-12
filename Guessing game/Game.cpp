#include <iostream>
#include <random>
#include <ctime>

void Game(int number, int tries);
int SelectDifficulty(bool validchoice);
void KeepTrack(int score);

int main(){
    bool replay = true;
    int difficulty;
    int tries;
    bool validchoice;

    while(replay){
        validchoice = false;
        srand(time(0));
        int number = 1 + rand() % 100;
        std::cout << "Game rules \n" << "You have to guess the number between 1 and 100. Good Luck! \n";
        tries = SelectDifficulty(validchoice);
        Game(number, tries);
        std::cout << "Do you want to play again? [y/n]: ";
        char userchoice;
        while(true){
            std::cin >> userchoice;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid choice. Please enter y or n: ";
            }
            else if (userchoice != 'y' || userchoice != 'n'){
                std::cout << "Invalid choice. Please enter y or n: ";
            }
            else{
                break;
            }
        }
        switch (userchoice)
        {
            case 'y': replay = true;
                break;
            case 'n': replay = false;
                break;
            default: replay = false;
                break;
        } 
    }

    return 0;
}

void Game(int number, int tries){
    int playernum;
    for (int i = 0; i < tries; i++){
        while(true){
            std::cout << "Attempt "<< i + 1 << ". Enter number: ";
            std::cin >> playernum;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input, please enter an integer\n";
            }
            else if(playernum < 1 || playernum > 100){
                std::cout << "Please enter a number between 1 and 100\n";
            }
            else{
                break;
            }
        }
        if (playernum == number){
            std::cout << "You won! You guessed the number in " << i + 1 <<" attempts \n";
            KeepTrack(i);
                break;
            }
        else if (playernum > number){
            if(i == tries - 1){
                std::cout << "You lost. The number was: " << number << "\n";
            }
            else{
                std::cout << "The number is lower than " << playernum << "\n";
            }
        }
        else{
            if(i == tries - 1){
                std::cout << "You lost. The number was: " << number << "\n";
            }
            else{
                std::cout << "The number is higher than " << playernum << "\n";
            }
        }
    }
}

int SelectDifficulty(bool validchoice){
    int difficulty;
    int tries;
    while (validchoice == false){
        std::cout << "Please select difficulty \n";
        std::cout << "1.Easy (10 chances) \n2.Medium (5 chances) \n3.Hard (3 chances) \nEnter your choice: ";
        while(true){
            std::cin >> difficulty;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter 1,2 or 3: ";      
            }
            else if(difficulty < 1 || difficulty > 3){
                std::cout << "Incalid input. Please enter 1,2 or 3: ";
            }
            else {
                break;
            }
        }
        switch (difficulty){
            case 1: tries = 10;
                std::cout << "You have selected easy level\n";
                validchoice = true;
                break;
            case 2: tries = 5;
                std::cout << "You have selected medium level\n";
                validchoice = true;     
                break;
            case 3: tries = 3;
                std::cout << "You have selected hard level\n";
                validchoice = true; 
                break;
            default: 
                std::cout << "Invalid choice. Please enter 1,2 or 3: "; 
                break;
        }
    }
    return tries;
}

void KeepTrack(int score){
    int best = 100;
    if (score < best){
        best = score;
    }
    std::cout << "Your best score is: " << best + 1 << "\n";
}