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

            cout << "|  " << VUOTO << "  |";
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
void inserisciTassello(char griglia[RIGHE][COLONNE], int checkRiga)
{
    bool checkInserimento = false;
    for (int i = RIGHE; i > 0; i--)
    {
        int j = 0;
        do
        {

            if (j == checkRiga - 1 && griglia[i - 1][j] != '-')
            {
                // DA INS
                checkInserimento = true;
            }
            j++;
        } while (j < COLONNE && checkInserimento != true); // ho inserito un check inserimento per uscire dal ciclo do while se l'utente inserisce il tassello

        if (checkInserimento == true)
        {
            break;
        }
    }
}

int main()
{
    stampaLogo();
    char griglia[RIGHE][COLONNE]; // Inizializzo la griglia

    stampaTabella(griglia);
    string giocatore1 = stampaGiocatore("giocatore1");
    string giocatore2 = stampaGiocatore("giocatore2");
    cout << giocatore1 << endl;
    inserisciTassello(griglia, 5);
}