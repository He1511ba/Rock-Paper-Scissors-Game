#include <iostream>
#include <cstdlib>
using namespace std;

enum emChoice
{
    Stone = 1,
    Papar = 2,
    Scissors = 3
};

enum emWinner
{
    Player = 1,
    Computer = 2,
    Draw = 3
};

int ReadNumOfRound()
{
    int numRound;
    do
    {
        cout << "Chose Number of Round Between 1 to 10: \n";
        cin >> numRound;
    } while (numRound < 1 || numRound > 10);

    return numRound;
}

int RandomNum(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

emChoice readPlayerChoice() // enum function
{
    int playerChoice;
    do
    {
        cout << "\n Your Choice :[1]--> Stone , [2]--> Paper , [3] --> Scissors ? \n";
        cin >> playerChoice;
    } while (playerChoice < 1 || playerChoice > 3);

    return (emChoice)playerChoice; // enum variable
}

emChoice readComputerChoice()
{
    return (emChoice)RandomNum(1, 3);
}

struct stRoundInfo
{
    short numOfRound;
    emChoice playerChoice;
    emChoice comChoice;
    emWinner whoWinner;
    string WinnerName;
};

emWinner whoWonInTheRound(stRoundInfo StRoundInfo)
{
    if (StRoundInfo.comChoice == StRoundInfo.playerChoice)
        return emWinner::Draw;
        
    switch (StRoundInfo.playerChoice)
    {
    case emChoice::Stone:
        if (StRoundInfo.comChoice == emChoice::Papar)
            return emWinner::Computer;
        break;
    case emChoice::Papar:
        if (StRoundInfo.comChoice == emChoice::Scissors)
            return emWinner::Computer;
        break;
    case emChoice::Scissors:
        if (StRoundInfo.comChoice == emChoice::Stone)
            return emWinner::Computer;
        break;
    }
    return emWinner::Player;
}

int main()
{
    ReadNumOfRound();
    readPlayerChoice();
}
