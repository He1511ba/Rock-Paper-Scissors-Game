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
        cout << " Chose Number of Round Between 1 to 10: ";
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
        cout << "\n Your Choice [1]: Stone , [2]: Paper , [3]:Scissors : ";
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
    return arr[choice - 1];
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

void PrintRoundResults(stRoundInfo RoundInfo)
{

    cout << "\n__________________________________ Round [" << RoundInfo.numOfRound << "] ___________________________________\n"
         << endl;
    cout << "\tPlayer Choise : " << choiceName(RoundInfo.playerChoice) << endl;
    cout << "\tComputer Choise : " << choiceName(RoundInfo.comChoice) << endl;
    cout << "\tThe Winer in this Round is : " << RoundInfo.WinnerName << endl;
    cout << "\n________________________________________________________________________________\n";

    changecolor(RoundInfo.whoWinner);
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

string NameFinalWinner(emWinner winner)
{
    string arr[3] = {
        "Player",
        "Computer",
        "Draw"};
    return arr[winner - 1];
}

stGameResult printGameResult(int HowManyRounds, short PlayerWonTimes, short ComputerWonTimes, short DrawTimes)
{
    stGameResult GameResult;

    GameResult.gameRounds = HowManyRounds;
    GameResult.playerTimeWinner = PlayerWonTimes;
    GameResult.computerTimeWinner = ComputerWonTimes;
    GameResult.drawTimes = DrawTimes;
    GameResult.whoFinalWinner = whoFinalWinner(PlayerWonTimes, ComputerWonTimes, DrawTimes);
    GameResult.nameFinalWinner = NameFinalWinner(GameResult.whoFinalWinner);

    return GameResult;
}

stGameResult playGame(int HowManyRounds)
{
    short PlayerWonTimes = 0, ComputerWonTimes = 0, DrawTimes = 0;
    stRoundInfo RoundInfo;

    for (int i = 1; i <= HowManyRounds; i++)
    {
        cout << "\n Round [" << i << "] begin:  \n";
        RoundInfo.numOfRound = i;
        RoundInfo.playerChoice = readPlayerChoice();
        RoundInfo.comChoice = readComputerChoice();
        RoundInfo.whoWinner = whoWonInTheRound(RoundInfo);
        RoundInfo.WinnerName = winnerNameFromRound(RoundInfo.whoWinner);

        PrintRoundResults(RoundInfo);

        if (RoundInfo.whoWinner == emWinner::Computer)
            ComputerWonTimes++;
        else if (RoundInfo.whoWinner == emWinner::Player)
            PlayerWonTimes++;
        else
            DrawTimes++;
    }

    return printGameResult(HowManyRounds, PlayerWonTimes, ComputerWonTimes, DrawTimes);
}

void ShowFinalResult(stGameResult GameResult)
{
    cout << "_______________________________ [ Game Result ] ________________________________\n\n";
    cout << "\tGame Round         : " << GameResult.gameRounds << endl;
    cout << "\tPlayer won times   : " << GameResult.playerTimeWinner << endl;
    cout << "\tComputer won times : " << GameResult.computerTimeWinner << endl;
    cout << "\tDraw times         : " << GameResult.drawTimes << endl;
    cout << "\tFinal winner       : " << GameResult.nameFinalWinner << endl;
    cout << "\n________________________________________________________________________________\n\n";

    changecolor(GameResult.whoFinalWinner);
}

void resetScreen()
{
    system("cls");
    system("color 0f");
}

void startGame()
{
    char PlayAgain;
    do
    {
        resetScreen();
        stGameResult GameResult = playGame(ReadNumOfRound());
        ShowFinalResult(GameResult);

        cout << "\tDo you want to play again? Y/N? ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
    startGame();
}
