/*PROJECT FORZA 4: Il progetto consiste nella creazione del gioco "Forza 4", nel quale sarà possibile giocare in locale o in rete.
Si suppone di avere 2 giocatori identificati dal loro nome o da un "personaggio". L'obiettivo di ogni giocatore è quello di mettere
in fila quattro proprie pedine che vengono fatte cadere lungo le colonne, in modo tale che una pedina inserita in una certa
colonna va sempre a occupare la posizione libera situata più in basso nella colonna stessa.
Il gioco termina automaticamente (il programma effetua il controllo) quando uno dei giocatori ha messo in fila quattro delle sue pedine.
Il programma al momento dell'esecuzione consente di scegliere la modalità di gioco, composta da 3 modalità: Utente vs Utente (1), Utente vs Computer (2),
Computer vs Computer (3), la scelta viene effettuata inserendo un numero compreso tra 1-3. Prima di iniziare la part ita viene chiesto il nome dei due giocatori,
in questo modo si viene identificati nella gestione del turno. Le pedine vengono fatte cadere verticalmente in un griglia, in cui vanno ad occupare
la posizione libera della colonna scelta. Vince chi riesce a mettere in fila quattro pedine di seguito, ovviamente il programma comprende anche un eventuale
pareggio, dopo aver individuato il vincitore lo visualizzerà a schermo e verrà chiesto se si vuole iniziare una nuova partita o terminare (s/n).
 */

#include <iostream>
#include <string>
#include <random>
#include <vector>

using namespace std;

//  Definizione delle costanti

const char VUOTO = '-';
const int RIGHE = 6;
const int COLONNE = 7;
const char NUMERO_GIOCATORI = 2;
const int GIOCATORE_1 = 0;
const int GIOCATORE_2 = 1;
const int COMPUTER = 2;
const int GIOCATORE_1_VINCE = 1;
const int GIOCATORE_2_VINCE = 2;
const int PAREGGIO = 3;
const int GIOCO_IN_CORSO = 4;

//  Definizione delle funzioni

// Stampa il titolo del programma
void stampaTitolo(void)
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

// Funzione che stampa la tabella
void stampaTabella( char matrice[RIGHE][COLONNE])
{ 
    cout << endl;
    cout << endl;
    cout << "-------------------------------------------------";
    for (int i = 0; i < RIGHE; i++)
    {
        cout << endl;
        for (int j = 0; j < COLONNE; j++) // Scorro l'indice delle colonne
        {
            cout << matrice [i][j] << "|  " << VUOTO << "  |";
        }
        cout << endl;
    }
    cout << "-------------------------------------------------\n";
    cout << "   ";
    for (int i = 1; i < COLONNE + 1; i++) // Scorro l'indice delle colonne
    {
        cout << i << "      "; // Stampo l'indice delle colonne
    }
}

// Funzione che stampa il menu
void stampaMenu(void)
{ 
    cout << endl;
    cout << " =========================================================  \n";
    cout << "| 1. Player vs Player                                     | \n";
    cout << "| 2. Player vs Computer                                   | \n";
    cout << "| 3. Computer vs Computer                                 | \n";
    cout << " =========================================================  \n";
}

// Funzione che inizializza la matrice
void inizializzaTabella(char matrice[RIGHE][COLONNE])
{ 
    for (int i = 0; i < RIGHE; i++)  // Scorro l'indice delle righe
    {
        for (int j = 0; j < COLONNE; j++)// Scorro l'indice delle colonne
        {
            matrice [i][j] = VUOTO;
        }
    }
}

// Funzione che stampa la matrice
void stampMatrice(char matrice[RIGHE][COLONNE])
{ 
    for (int i = 0; i < RIGHE; i++)  // Scorro l'indice delle righe
    {
        for (int j = 0; j < COLONNE; j++)// Scorro l'indice delle colonne
        {
            cout << matrice [i][j] << " ";
        }
        cout << endl;
    }
}

// Funzione che inizializza la matrice
int inizializzaMatrice(char matrice[RIGHE][COLONNE])
{ 
    for (int i = 0; i < RIGHE; i++)  // Scorro l'indice delle righe
    {
        for (int j = 0; j < COLONNE; j++)// Scorro l'indice delle colonne
        {
            matrice [i][j] = VUOTO;
        }
    }
    return 0;
}

// Funzione che inizializza i giocatori
int inizializzaGiocatori(char giocatore[NUMERO_GIOCATORI])
{ 
    giocatore [GIOCATORE_1] = 'X';
    giocatore [GIOCATORE_2] = 'O';
    return 0;
}

// Funzione che inizializza le gettoni
int inizializzaGettone(char gettone[NUMERO_GIOCATORI])
{ 
    gettone [GIOCATORE_1] = 'X';
    gettone [GIOCATORE_2] = 'O';
    return 0;
}

// Funzione che controlla se il giocatore ha vinto
int xisWinner (char matrice[RIGHE][COLONNE], char giocatore)
{ 
    int contatore = 0;
    for (int i = 0; i < RIGHE; i++)
    {
        for (int j = 0; j < COLONNE; j++)
        {
            if (matrice [i][j] == giocatore) // Controllo se nella cella ci sono 4 pedine uguali
            {
                contatore++;
                if (contatore == 4)
                {
                    return 1;
                }
            }
            else
            {
                contatore = 0;
            }
        }
        contatore = 0;
    }
    return 0;
}

// Funzione che gestisce il turno del giocatore
int giocatore (char matrice[RIGHE][COLONNE], char giocatore ,char tipoGiocatore , string nome)
{ 
    int riga = 0;
    int colonna = 0;
    int contatore = 0;
    if (tipoGiocatore == 'U') // Se il giocatore è un utente
    {
        cout << "Inserisci la colonna dove vuoi inserire la pedina: ";
        cin >> colonna;
        colonna--;
        if (colonna < 0 || colonna > COLONNE - 1) // Controllo che la colonna inserita sia valida
        {
            cout << "Colonna non valida, riprova" << endl;
            return 0;
        }
        for (int i = RIGHE - 1; i >= 0; i--) // Scorro le righe
        {
            if (matrice [i][colonna] == VUOTO)
            {
                matrice [i][colonna] = giocatore;// Inserisco la pedina nella prima posizione libera della colonna scelta
                riga = i;
                break;
            }
        }
        if (riga == 0)
        {
            cout << "Colonna piena, riprova" << endl;
            return 0;
        }
    }
    else 
    {
        for (int i = RIGHE - 1; i >= 0; i--)// Scorro le righe
        {
            for (int j = 0; j < COLONNE; j++)
            {
                if (matrice [i][j] == VUOTO)
                {
                    matrice [i][j] = giocatore; // Inserisco la pedina nella prima posizione libera della colonna scelta
                    riga = i;
                    colonna = j;
                    contatore++;
                    break;
                }
            }
            if (contatore == 1) // Se ho inserito la pedina esco dal ciclo
            {
                break; // Esco dal ciclo
            }
        }
        if (riga == 0)
        {
            cout << "Colonna piena, riprova" << endl;
            return 0;
        }
        cout << nome << " ha inserito la pedina nella colonna " << colonna + 1 << endl; // Stampo la colonna dove ha inserito la pedina
    }
    return 1;
}

// Funzione che inserisce i gettoni nella tabella
int inserisciGettoni (char matrice[RIGHE][COLONNE], char giocatore ,char tipoGiocatore , string nome)
{ 
    int riga = 0;
    int colonna = 0;
    int contatore = 0;
    if (tipoGiocatore == 'U') // Se il giocatore è umano
    {
        cout << "Inserisci la colonna dove vuoi inserire la pedina: ";
        cin >> colonna;
        colonna--;
        if (colonna < 0 || colonna > COLONNE - 1) // Controllo che la colonna inserita sia valida
        {
            cout << "Colonna non valida, riprova" << endl;
            return 0;
        }
        for (int i = RIGHE - 1; i >= 0; i--) // Scorro l'indice delle righe
        {
            if (matrice [i][colonna] == VUOTO)
            {
                matrice [i][colonna] = giocatore; // Inserisco il gettone nella cella vuota
                riga = i;
                break;
            }
        }
        if (riga == 0)
        {
            cout << "Colonna piena, riprova" << endl;
            return 0;
        }
    }
    else
    {
        for (int i = RIGHE - 1; i >= 0; i--) // Scorro l'indice delle righe
        {
            for (int j = 0; j < COLONNE; j++)// Scorro l'indice delle colonne
            {
                if (matrice [i][j] == VUOTO)
                {
                    matrice [i][j] = giocatore; // Inserisco il gettone nella cella vuota
                    riga = i;
                    colonna = j;
                    contatore++;
                    break;
                }
            }
            if (contatore == 1) // Se ho trovato una cella vuota esco dal ciclo
            {
                break;
            }
        }
        if (riga == 0)
        {
            cout << "Colonna piena, riprova" << endl;
            return 0;
        }
        cout << nome << " ha inserito la pedina nella colonna " << colonna + 1 << endl;
    }
    return 1;
}

// Funzione che gestisce il turno del PC
int mossaPC (char *arr)
{
    int colonna = 0;
    int riga = 0;
    int contatore = 0;
    for (int i = RIGHE - 1; i >= 0; i--) // Scorro l'indice delle righe
    {
        for (int j = 0; j < COLONNE; j++) // Scorro l'indice delle colonne
        {
            if (arr [i * COLONNE + j] == VUOTO) // Controllo se la cella è vuota
            {
                arr [i * COLONNE + j] = 'O'; // Inserisco il gettone nella cella vuota
                riga = i;
                colonna = j;
                contatore++;
                break;
            }
        }
        if (contatore == 1) // Se ho trovato una cella vuota esco dal ciclo
        {
            break;
        }
    }
    if (riga == 0)
    {
        cout << "Colonna piena, riprova" << endl;
        return 0;
    }
    cout << "Il PC ha inserito la pedina nella colonna " << colonna + 1 << endl;
    return 1;
}

// Funzione che stampa una riga piena
/*void stampaRigaPiena (char matrice[RIGHE][COLONNE], int riga, int colonna, int contatore)
{ 
    for (int i = 0; i < COLONNE; i++) // Scorro l'indice delle colonne
    {
        cout << matrice [riga][i] << " ";
    }
    cout << endl;
}*/

int main() 
{
    stampaTitolo();
    
    char matrice[RIGHE][COLONNE];
    char arr[RIGHE * COLONNE];
    char giocatore = 'X';
    char tipoGiocatore = 'U';
    string nome = "Giocatore";
    int scelta = 0;
    int contatore = 0;
    int riga = 0;
    int colonna = 0;
    int vittoria = 0;
    int vittoriaPC = 0;
    int vittoriaGiocatore = 0;
    int vittoriaPareggio = 0;

    cout << endl;
    cout << "Benvenuto e preparati a giocare a forza 4! " << endl;
    cout << endl;
    stampaMenu();
    cout << endl;
    cout << "Se vuoi giocare contro un altro giocatore digita 1." << endl;
    cout << "Se vuoi giocare contro il COMPUTER digita 2." << endl;
    cout << "Se vuoi far giocare il COMPUTER contro se stesso digita 3." << endl;
    cin >> scelta;
    
    if (scelta == 1)
    {
        cout << "Hai scelto di giocare contro il pc" << endl;
        cout << "Inserisci il tuo nome" << endl;
        cin >> nome;
        cout << "Inserisci il tuo simbolo" << endl;
        cin >> giocatore;
        tipoGiocatore = 'U';
        cout << "Inserisci il simbolo del pc" << endl;
    } 
    else if (scelta == 2)
    {
        cout << "Hai scelto di giocare contro un altro giocatore" << endl;
        cout << "Inserisci il nome del primo giocatore" << endl;
        cin >> nome;
        cout << "Inserisci il simbolo del primo giocatore" << endl;
        cin >> giocatore;
        tipoGiocatore = 'U';
        cout << "Inserisci il nome del secondo giocatore" << endl;
        cin >> nome;
        cout << "Inserisci il simbolo del secondo giocatore" << endl;
        cin >> giocatore;
        tipoGiocatore = 'U';
    } 
    else
    {
        cout << "Scelta non valida" << endl;
        return 0;
    }
    cout << endl;
    cout << "Iniziamo a giocare!" << endl;
    cout << endl;
    cout << "La griglia è composta così:" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "-------------------------------------------";

    for (int i = 0; i < RIGHE; i++)
    {
        cout << endl;
        cout << "|";
        for (int j = 0; j < COLONNE; j++) // Scorro l'indice delle colonne
        {
            matrice[i][j] = VUOTO;
            cout << "  ";
            cout << matrice[i][j] << "  |";
        }
        // cout << "  " << i << " ";
        cout << endl;
    }
    cout << "-------------------------------------------\n";
    cout << "   ";
    for (int i = 1; i < COLONNE + 1; i++) // Scorro l'indice delle colonne
    {
        cout << i << "     "; // Stampo l'indice delle colonne
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Inserisci il numero della colonna dove vuoi inserire il tuo gettone" << endl;
    //int inizializzaGettone(char gettone[NUMERO_GIOCATORI]);
    //int inserisciGettoni (char matrice[RIGHE][COLONNE], char giocatore ,char tipoGiocatore , string nome);
    cout << endl;
    cout << "Inserisci il numero della colonna dove vuoi inserire il tuo gettone" << endl;
    cout << endl;

    cout << "Buona fortuna!" << endl;
    cout << endl;
    cout << "Inizia " << nome << endl;
    cout << endl;
    cout << "Inserisci il numero della colonna dove vuoi inserire il tuo gettone" << endl;
    cout << endl;
    cout << "Buona fortuna!" << endl;
    cout << endl;
}
