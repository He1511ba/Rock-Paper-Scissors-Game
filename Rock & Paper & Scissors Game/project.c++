#include <iostream>
#include <cstdlib>
using namespace std;

int n, resPlayer = 0, resComputer = 0, draw = 0, ComChoice, PlayerChoice;
string answar;

enum element
{
    Stone,
    Paper,
    Scissors
};

void NumOfRaund()
{
    cout << "Chose Number of Round Between 1 to 10: \n";
    cin >> n;
    if (n <= 0 || n > 10)
    {
        cout << "\n Wrong answer , you have to choice number between 1 to 10. \n ";
        NumOfRaund();
    }
}

void ReadComputerChoise(int from, int to)
{
    ComChoice = rand() % (to - from + 1) + from;
}

void ReadPlayerChoise()
{

    cout << "\n Your Choice :[0]--> Stone , [1]--> Paper , [2] --> Scissors ? \n";
    cin >> PlayerChoice;
    if (PlayerChoice > 2 || PlayerChoice < 0)
    {
        cout << "\n Wrong answer , you have to choice number between 0 to 2. \n ";
        ReadPlayerChoise();
    }
}

string choiceName(element Choice)
{
    switch (Choice)
    {
    case Stone:
        return "Stone";
        break;
    case Paper:
        return "Paper";
        break;
    case Scissors:
        return "Scissors";
        break;
    }
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

void changecolor(string winner)
{
    if (winner == "computer" || winner == "Computer")
        system("color 4f"); // red
    else if (winner == "player" || winner == "Player")
        system("color 2f"); // green
    else if (winner == "draw" || winner == "Draw")
        system("color 1f"); // blue
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
        return "Computer";
    else if (resPlayer > resComputer)
        return "Player";
    else
        return "Draw";
}

void PrintRoundResults(int m)
{

    cout << "\n---------------------Round [" << m << " ]-----------------------------\n";
    cout << "Player Choise : " << choiceName((element)PlayerChoice) << endl;
    cout << "Computer Choise : " << choiceName((element)ComChoice) << endl;
    cout << "The Winer in this Round is : " << resForEachRound(choiceWinner()) << endl;
    cout << "\n------------------------------------------------------------\n";
}

void round()
{
    for (int i = 1; i <= n; i++)
    {
        cout << "Round [ " << i << " ] beginer : \n";
        ReadComputerChoise(0, 2);
        ReadPlayerChoise();
        changecolor(choiceWinner());
        increaseScore(choiceWinner());
        PrintRoundResults(i);
    }
}

void GameOvr()
{
    cout << "\n------------------------------------------------------------\n";
    cout << "\n                         Game Over                          \n";
    cout << "\n------------------------------------------------------------\n";
    cout << "\n------------------------ Game Result -----------------------\n";
    cout << "Game Round : " << n << endl;
    cout << "Player won times : " << resPlayer << endl;
    cout << "Computer won times : " << resComputer << endl;
    cout << "Draw times : " << draw << endl;
    changecolor(decidesWinner());
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
    system("color 0F");
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