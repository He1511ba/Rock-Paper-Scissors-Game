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

emWinner whoFinalWinner(short playerWonTimes, short comWonTimes, short drawWonTimes)
{
    if (playerWonTimes == comWonTimes)
        return emWinner::Draw;
    else if (playerWonTimes > comWonTimes)
        return emWinner::Player;
    else
        return emWinner ::Computer;
}

string winnerNameFromRound(emWinner winner)
{
    string arr[3] = {
        "Player",
        "Computer",
        "Draw"};
    return arr[winner - 1];
}

string choiceName(emChoice choice)
{
    string arr[3] = {
        "Stone",
        "Papar",
        "Scissors"};
    return arr[choice - 3];
}

void changecolor(emWinner winner)
{
    switch (winner)
    {
    case emWinner::Player:
        system("color 2f");
        break;
    case emWinner::Computer:
        system("color 4f");
        break;
    case emWinner::Draw:
        system("color 1f");
        break;
    }
}

void PrintRoundResults(stRoundInfo StRoundInfo)
{

    cout << "\n---------------------Round [" << StRoundInfo.numOfRound << " ]-----------------------------\n"
         << endl;
    cout << "Player Choise : " << choiceName(StRoundInfo.playerChoice) << endl;
    cout << "Computer Choise : " << choiceName(StRoundInfo.comChoice) << endl;
    cout << "The Winer in this Round is : " << StRoundInfo.WinnerName << endl
         << endl;
    cout << "\n------------------------------------------------------------\n";

    changecolor(StRoundInfo.whoWinner);
}

struct stGameResult
{
    short gameRounds;
    short playerTimeWinner;
    short computerTimeWinner;
    short drawTimes;
    emWinner whoFinalWinner;
    string nameFinalWinner;
};

string  NameFinalWinner(emWinner winner)
{
    string arr[3] = {
        "Player",
        "Computer",
        "Draw"};
    return arr[winner - 1];
}

stGameResult printGameResualt(int HowManyRounds, short Player1WonTimes, short ComputerWonTimes, short DrawTimes)
{
    stGameResult  GameResult;

    GameResult.gameRounds= HowManyRounds;
    GameResult.playerTimeWinner=Player1WonTimes;
    GameResult.computerTimeWinner=ComputerWonTimes;
    GameResult.drawTimes = DrawTimes;
    GameResult.whoFinalWinner = whoFinalWinner(Player1WonTimes,ComputerWonTimes,DrawTimes);
    GameResult.nameFinalWinner= NameFinalWinner(GameResult.whoFinalWinner);

    return GameResult;
}


void restart()
{
    system("cls");
    system("color 0f");
}

int main()
{
    ReadNumOfRound();
    readPlayerChoice();
    restart();
}
