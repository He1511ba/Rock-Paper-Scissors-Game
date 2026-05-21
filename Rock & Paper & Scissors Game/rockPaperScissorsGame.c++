#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

short n, resPlayer = 0, resComputer = 0, draw = 0, ComChoice, PlayerChoice;
string answar;

void NumOfRaund()
{
    cout << "Chose Number of Round Between 1 to 10: \n";
    cin >> n;
    cout << "\n --------- \n";
}

void ReadComputerChoise(int from, int to)
{
    ComChoice = rand() % (to - from + 1) + from;
}

void ReadPlayerChoise()
{
    cout << "\n Your Choice :[0]--> Stone , [1]--> Paper , [2] --> Scissors ? \n";
    cin >> PlayerChoice;
    if (PlayerChoice > 2)
    {
        cout << "\n Choice Number between 0 to 2. \n ";
        ReadPlayerChoise();
    }
}

string choiceNameForPlayer()
{
    if (PlayerChoice == 0)
        return "Stone";

    if (PlayerChoice == 1)
        return "Paper";

    if (PlayerChoice == 2)
        return "Scissors";

    return "not";
}

string choiceNameForComputer()
{
    if (ComChoice == 0)
        return "Stone";

    if (ComChoice == 1)
        return "Paper";

    if (ComChoice == 2)
        return "Scissors";

    return "not";
}

string choiceWinner()
{
    if (ComChoice == PlayerChoice)
        return "draw";

    if (ComChoice == 2 && PlayerChoice == 0)
        return "player";

    else if (ComChoice == 0 && PlayerChoice == 1)
        return "player";

    else if (ComChoice == 1 && PlayerChoice == 2)
        return "player";
    else
        return "computer";
}

string resForEachRound(string winner)
{
    if (winner == "computer")
        return "Computer";
    else if (winner == "player")
        return "Player";
    else if (winner == "draw")
        return "Draw";
}

string increaseScore(string winner)
{
    if (winner == "computer")
        resComputer++;
    else if (winner == "player")
        resPlayer++;
    else if (winner == "draw")
        draw++;
}

string decidesWinner()
{
    if (resComputer > resPlayer)
        return "Computer\n";
    else if (resPlayer > resComputer)
        return "Player\n";
    else
        return "Draw\n";
}

void PrintRoundResults(int m)
{
    cout << "\n----------------Round [" << m << " ]-----------------------\n";
    cout << "Player Choise : " << choiceNameForPlayer() << endl;
    cout << "Computer Choise : " << choiceNameForComputer() << endl;
    cout << "The Winer in this Round is : " <<resForEachRound(choiceWinner())<< endl;
    cout << "\n------------------------------------------------------------\n";
}

void round()
{
    for (int i = 1; i <= n; i++)
    {
        cout << "Round [ " << i << " ] beginer : \n";
        ReadComputerChoise(0, 2);
        ReadPlayerChoise();
        increaseScore(choiceWinner());
        PrintRoundResults(i);
    }
}

void GameOvr()
{
    cout << "\n-----------------------------------------------\n";
    cout << "|                     Game Over                  |\n";
    cout << "\n-----------------------------------------------\n";
    cout << "-------------------- Game Result ----------------\n";
    cout << "Game Round : " << n << endl;
    cout << "Player won times : " << resPlayer << endl;
    cout << "Computer won times : " << resComputer << endl;
    cout << "Draw times : " << draw << endl;
    cout << "Final Winner : " << decidesWinner() << endl;
}

void ResetScreen()
{
    n = 0,
    resPlayer = 0,
    resComputer = 0,
    draw = 0,
    ComChoice = 0,
    PlayerChoice = 0;
    system("cls");
}

void startGame()
{
    do
    {
        ResetScreen();
        NumOfRaund();
        round();
        GameOvr();
        cout << "You want play again ? (yes or no)\n";
        cin >> answar;
        cout << "\n----------------------------\n";

    } while (answar == "yes" || answar == "Yes");
}
int main()
{
    startGame();
}