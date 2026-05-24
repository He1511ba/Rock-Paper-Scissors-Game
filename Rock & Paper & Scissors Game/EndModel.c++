#include <iostream>
#include <cstdlib>
using namespace std;

enum emChioce
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

emChioce readPlayerChoice() //enum function 
{
    int playerChoice;
    do
    {
        cout << "\n Your Choice :[1]--> Stone , [2]--> Paper , [3] --> Scissors ? \n";
        cin >> playerChoice;
    } while (playerChoice < 1 || playerChoice > 3);

    return (emChioce)playerChoice; // enum variable
}

emChioce readComputerChoice()
{
    return (emChioce)RandomNum(1,3) ;
}

int main()
{
    ReadNumOfRound();
    readPlayerChoice();
}
