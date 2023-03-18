//
// Created by guea on 18.03.23.
//


#include <iostream>
//#include <vector>
#include <string>
#include <random>

using namespace std;

const int ROWS = 6;
const int COLUMNS = 7;
const char VUOTO = '-';

// Funzione per creare il tabellone vuoto

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
    cout << "                        Create by... Serge, Marco, Jacopo  \n";
}

void stampaTabella(char matrice[ROWS][COLUMNS])
{
    // Stampo la griglia di gioco
    cout << endl;
    cout << endl;
    cout << "--------------------------------------------------" << endl;

    for (int i = 0; i < ROWS; i++)
    {

        for (int j = 0; j < COLUMNS; j++)
        {
            if (j == 0)
            {
                cout << i + 1;
            } // ho aggiunto i numeri sulle righe

            cout << "|  " << VUOTO << "  |";
            // ho tolto griglia per stampare la tabella  base
        }
        // cout << "  " << i << " ";

        cout << endl;
    }
    cout << "--------------------------------------------------\n";
    cout << "   ";
    for (int i = 1; i < COLUMNS + 1; i++) // Scorro l'indice delle colonne
    {
        cout << i << "      " ; // Stampo l'indice delle colonne
    }
    cout << endl;
}

int inizializzaTabella(char matrice[ROWS][COLUMNS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            matrice[i][j] = VUOTO;
        }
    }
    return 0;
}
/*vector<vector<int>> crea_tabellone() {
    vector<vector<int>> tabellone;
    for (int i = 0; i < ROWS; i++) {
        vector<int> row(COLUMNS, 0);
        tabellone.push_back(row);
    }
    return tabellone;
}*/

// Funzione per stampare il tabellone
/*void stampa_tabellone(vector<vector<int>> tabellone) {
    for (int i = ROWS - 1; i >= 0; i--) {
        for (int j = 0; j < COLUMNS; j++) {
            cout << tabellone[i][j] << " ";
        }
        cout << endl;
    }
}*/

// Funzione per inserire una fiches in una determinata colonna
int inserisciFiches(char matrice[ROWS][COLUMNS], int colonna, char giocatore) {
    if (colonna < 0 || colonna >= COLUMNS) {
        return -1;
    }
    for (int i = ROWS - 1; i >= 0; i--) {
        if (matrice[i][colonna] == VUOTO) {
            matrice[i][colonna] = giocatore;
            return 0;
        }
    }
    return -1;
}

// Funzione per controllare se una colonna è piena
bool colonnaPiena(char matrice[ROWS][COLUMNS], int colonna) {
    if (colonna < 0 || colonna >= COLUMNS) {
        return false;
    }
    return matrice[0][colonna] != VUOTO;
}

// Funzione per controllare se un giocatore ha vinto
bool xIsWinner(char matrice[ROWS][COLUMNS], int giocatore) {

    // Controllo delle righe
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS - 3; j++) {
            if (matrice[i][j] == giocatore && matrice[i][j+1] == giocatore && matrice[i][j+2] == giocatore && matrice[i][j+3] == giocatore) {
                return true;
            }
        }
    }
    // Controllo delle colonne
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (matrice[i][j] == giocatore && matrice[i+1][j] == giocatore && matrice[i+2][j] == giocatore && matrice[i+3][j] == giocatore) {
                return true;
            }
        }
    }
    // Controllo delle diagonali ascendenti
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLUMNS - 3; j++) {
            if (matrice[i][j] == giocatore && matrice[i+1][j+1] == giocatore && matrice[i+2][j+2] == giocatore && matrice[i+3][j+3] == giocatore) {
                return true;
            }
        }
    }
    // Controllo delle diagonali discendenti
    for (int i = 3; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS - 3; j++) {
            if (matrice[i][j] == giocatore && matrice[i-1][j+1] == giocatore && matrice[i-2][j+2] == giocatore && matrice[i-3][j+3] == giocatore) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    char matrice[ROWS][COLUMNS];
    stampaLogo();

    // vector<vector<int>> tabellone = crea_tabellone();
    int turno = 1;
    int colonna;
    while (true) {
        stampaTabella(matrice);
        cout << "Turno del giocatore " << turno << endl;
        cout << "Inserisci la colonna: ";
        cin >> colonna;

        return 0;
    }
}
