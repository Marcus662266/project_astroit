#include <iostream>
using namespace std;

const char VUOTO = '-';
const int RIGHE = 6;
const int COLONNE = 7;

void stampaLogo(void)
{
    cout << endl;
    cout << " ========================================================  \n";
    cout << "| READY TO PLAY...                                       | \n";
    cout << "|      _______  _______  ____________     ____      ___  | \n";
    cout << "|     /  ____/ / ___  / / __  /__   /    /    |    /   | | \n";
    cout << "|    /  /___  / /  / / / /_/ /  /  /    /     |   / /| | | \n";
    cout << "|   /  ____/ / /  / / /  _  /  /  /    /  /|  |  / /_| | | \n";
    cout << "|  /  /     / /__/ / /  / | | /  /___ /  / |  | /____  | | \n";
    cout << "| /__/     /______/ /__/  |_|/______//__/  |__|      |_| | \n";
    cout << " ========================================================  \n";
    cout << "                        Create by... Serge, Marco, Jacopo    ";
}

int main()
{
    stampaLogo();
    char griglia[RIGHE][COLONNE]; // Inizializzo la griglia

    // Stampo la griglia di gioco
    cout << endl;
    cout << endl;
    cout << "-------------------------------------------------";
    for (int i = 0; i < RIGHE; i++) 
    {
        cout << endl;
        for (int j = 0; j < COLONNE; j++)
        {
            cout << griglia [i][j] << "|  " << VUOTO << "  |";
        }
        //cout << "  " << i << " ";

        cout << endl;
    }
    cout << "-------------------------------------------------\n";
    cout << "   ";
    for (int i = 1; i < COLONNE + 1; i++) // Scorro l'indice delle colonne
    {
        cout << i << "      "; // Stampo l'indice delle colonne
    }
}