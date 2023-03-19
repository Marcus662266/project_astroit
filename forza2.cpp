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

void stampaTabella(char griglia[RIGHE][COLONNE])
{
    // Stampo la griglia di gioco
    cout << endl;
    cout << endl;
    cout << "--------------------------------------------------" << endl;
    for (int i = 0; i < RIGHE; i++)
    {

        for (int j = 0; j < COLONNE; j++)
        {
            if (j == 0)
            {
                cout << i + 1;
            } // ho aggiunto i numeri sulle righe

            cout << "|  " << griglia[i][j] << "  |";
            // ho tolto griglia per stampare la tabella  base
        }
        // cout << "  " << i << " ";

        cout << endl;
    }
    cout << "--------------------------------------------------\n";
    cout << "   ";
    for (int i = 1; i < COLONNE + 1; i++) // Scorro l'indice delle colonne
    {
        cout << i << "      "; // Stampo l'indice delle colonne
    }
}

void caricaMatrice(char griglia[RIGHE][COLONNE])
{
    for (int i = 0; i < RIGHE; i++)
    {
        for (int j = 0; j < COLONNE; j++)
        {
            griglia[i][j] = VUOTO;
        }
    }
}

// ho inserito un metodo rtiutilizzabile per inserire i giocatori
string stampaGiocatore(string tipoGiocatore)
{
    string giocatore;

    cout << endl;
    cout << endl;
    cout << endl;
    cout << "inserisci " << tipoGiocatore << ": ";
    cin >> giocatore;
    cout << giocatore << endl;
    return giocatore;
}
void inserisciTassello(char griglia[RIGHE][COLONNE], int checkRiga, string tipoGiocatore, string giocatoreMomentaneo)
{
    bool checkInserimento = false;

    for (int i = RIGHE; i > 0; i--)
    {
        int j = 0;
        do
        {

            if (j == checkRiga - 1 && griglia[i - 1][j] == '-') // andare a leggere lo spazio vuoto partendo dalla fine della griglia
            {
                if (giocatoreMomentaneo == tipoGiocatore)
                {
                    cout << giocatoreMomentaneo << " ha inserito: X " << endl; // inserisco x se il giocatoreMomentaneo è uguale a giocatore1
                    griglia[i - 1][j] = ' X ';
                }
                else
                {
                    cout << giocatoreMomentaneo << " ha inserito: O " << endl; // inserisco o se automaticamente il giocatore diventa il secondo
                    griglia[i - 1][j] = ' O ';
                }
                checkInserimento = true;
            }
            j++;
        } while (j < COLONNE && checkInserimento != true); // ho inserito un check inserimento per uscire dal ciclo do while se l'utente inserisce il tassello

        if (checkInserimento == true)
        {
            stampaTabella(griglia);
            break;
        }
    }
}

// Controlla se il giocatore ha vinto
string xIsWinner(char griglia[RIGHE][COLONNE])
{
    string giocatoreVincente = "nessuno";
    int contX = 0;
    int contO = 0;
    // controllo vittoria in caso di 4 tasselli in orizzonatale
    for (int j = 0; j < COLONNE; j++)
    {
        for (int i = 0; i < RIGHE; i++)
        {

            // Controllo se nella cella ci sono 4 gettoni uguali
            if (griglia[i][j] == 'X')
            {
                contO = 0;
                contX++;
            }
            else
            {
                contX = 0;
                contO++;
            }

            // Controllo se per questa riga mi ritrovo 4 X vicine
        }
        if (contX == 4)
        {
            cout << "G1 win";
            giocatoreVincente = "giocatore1";

            // Controllo se per questa riga mi ritrovo 4 O vicine
        }
        else if (contO == 4)
        {
            cout << "G2 win";
            giocatoreVincente = "giocatore2";
        }
    }

    // controllo vittoria in caso di 4 tasselli in verticale
    if (giocatoreVincente != "nessuno")
    {
        for (int i = 0; i < RIGHE; i++)
        {
            for (int j = 0; j < COLONNE; j++)
            {

                // Controllo se nella cella ci sono 4 gettoni uguali
                if (griglia[i][j] == 'X')
                {
                    contO = 0;
                    contX++;
                }
                else
                {
                    contX = 0;
                    contO++;
                }

                // Controllo se per questa riga mi ritrovo 4 X vicine
            }
            if (contX == 4)
            {
                cout << "G1 win";
                giocatoreVincente = "giocatore1";

                // Controllo se per questa riga mi ritrovo 4 O vicine
            }
            else if (contO == 4)
            {
                cout << "G2 win";
                giocatoreVincente = "giocatore2";
            }
        }
    }

    // controllo vittoria in caso di 4 tasselli in diagonale
    if (giocatoreVincente != "nessuno")
    {
        for (int j = 0; j < COLONNE - 4; j++)
        {
            for (int i = 0; i < RIGHE - 4; i++)
            {

                // Controllo se nella cella ci sono 4 gettoni uguali
                if (griglia[i][j] == 'X' && griglia[i + 1][j + 1] == 'X' && griglia[i + 2][j + 2] == 'X' && griglia[i + 3][j + 3] == 'X')
                {
                    giocatoreVincente = "giocatore1";
                }
                if (griglia[i][j] == 'O' && griglia[i + 1][j + 1] == 'O' && griglia[i + 2][j + 2] == 'O' && griglia[i + 3][j + 3] == 'O')
                {
                    giocatoreVincente = "giocatore2";
                }

                // Controllo se per questa riga mi ritrovo 4 X vicine
            }
        }
/*

    // Check for diagonal wins starting from top-right corner
    for (int i = 0; i <= ROWS - 4; i++) {
        for (int j = 3; j < COLS; j++) {
            if (board[i][j] == player && board[i+1][j-1] == player &&
                board[i+2][j-2] == player && board[i+3][j-3] == player) {
                return true;
            }
        }
    }




*/



        // faccio un controllo per le diagonali nel verso opposto
        for (int j = COLONNE-4; j > 0; j--)
        {
            for (int i = RIGHE-4; i > 0; i--)
            {

                // Controllo se nella cella ci sono 4 gettoni uguali
                if (griglia[i - 1][j - 1] == 'X' && griglia[i - 2][j - 2] == 'X' && griglia[i - 3][j - 3] == 'X' && griglia[i - 4][j - 4] == 'X')
                {
                    giocatoreVincente = "giocatore1";
                }
                if (griglia[i - 1][j - 1] == 'O' && griglia[i - 2][j - 2] == 'O' && griglia[i - 3][j - 3] == 'O' && griglia[i - 4][j - 4] == 'O')
                {
                    giocatoreVincente = "giocatore2";
                }

                // Controllo se per questa riga mi ritrovo 4 X vicine
            }
        }
    }
    return giocatoreVincente;
}

int main()
{
    stampaLogo();
    char griglia[RIGHE][COLONNE]; // Inizializzo la griglia
    caricaMatrice(griglia);
    stampaTabella(griglia);
    string giocatore1 = stampaGiocatore("giocatore1");
    string giocatore2 = stampaGiocatore("giocatore2");
    cout << giocatore1 << endl;
    inserisciTassello(griglia, 5);
}

