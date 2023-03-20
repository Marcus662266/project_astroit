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

//  Definizione delle funzioni

int vittoriaVerticale(char pString[6][7], char giocatore);

int vittoriaOrizzontale(char pString[6][7], char giocatore);

int vittoriaDiagonale(char pString[6][7], char giocatore);

int colonnaPiena(char pString[6][7], int colonna);

void stampaMatrice(char pString[6][7]);

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

// Funzione che stampa matrice
void stampaMatrice(char pString[6][7]) {
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
            cout << "  ";
            cout << pString[i][j] << "  |";
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


}


// Funzione che stampa il menu
void stampaMenu(void)
{
    cout << endl;
    cout << " =========================================================  \n";
    cout << "| 1. Player vs Player                                     | \n";
    cout << "| 2. Player vs Computer                                   | \n";
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
int xisWinner (char matrice[RIGHE][COLONNE], char player) {

    // controllo orizzontale
    for (int i = 0; i < RIGHE; i++) {
        for (int j = 0; j < COLONNE - 3; j++) {
            if (matrice[i][j] == player && matrice[i][j + 1] == player && matrice[i][j + 2] == player &&
                matrice[i][j + 3] == player) {
                return 1;
            }
        }
    }

    // controllo verticale
    for (int i = 0; i < RIGHE - 3; i++) {
        for (int j = 0; j < COLONNE; j++) {
            if (matrice[i][j] == player && matrice[i + 1][j] == player && matrice[i + 2][j] == player &&
                matrice[i + 3][j] == player) {
                return 1;
            }
        }
    }

    // controllo diagonale
    for (int i = 0; i < RIGHE - 3; i++) {
        for (int j = 0; j <COLONNE- 3; j++) {
            if (matrice[i][j] == player && matrice[i + 1][j + 1] == player && matrice[i + 2][j + 2] == player &&
                matrice[i + 3][j + 3] == player) {
                return 1;
            }
        }
    }

    // controllo diagonale inversa
    for (int i = 3; i < RIGHE; i++) {
        for (int j = 0; j < COLONNE - 3; j++) {
            if (matrice[i][j] == player && matrice[i - 1][j + 1] == player && matrice[i - 2][j + 2] == player &&
                matrice[i - 3][j + 3] == player) {
                return 1;
            }
        }
    }

    return 0;
}

// Funzione che gestisce il  giocatore
int giocatore( char matrice[RIGHE][COLONNE], char player)
{
    int colonna = 0;
    int riga = 0;
    int contatore = 0;
    for (int i = RIGHE - 1; i >= 0; i--) // Scorro l'indice delle righe
    {
        for (int j = 0; j < COLONNE; j++) // Scorro l'indice delle colonne
        {
            if (matrice [i][j] == VUOTO) // Controllo se la cella è vuota
            {
                matrice [i][j] = player; // Inserisco il gettone nella cella vuota
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
    if (riga == 0 && colonna == 0) // Se la cella è vuota e non ho trovato una cella vuota
    {
        cout << "La colonna è piena, riprova" << endl;
        return 0;
    }
    else
    {
        return 1;
    }
}

// Funzione che controlla se la matrice è piena
int matricePiena(char matrice[RIGHE][COLONNE])
{
    int contatore = 0;
    for (int i = 0; i < RIGHE; i++) // Scorro l'indice delle righe
    {
        for (int j = 0; j < COLONNE; j++) // Scorro l'indice delle colonne
        {
            if (matrice [i][j] != VUOTO) // Controllo se la cella è vuota
            {
                contatore++;
            }
        }
    }
    if (contatore == RIGHE * COLONNE) // Se la matrice è piena
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// funzione che inserisce il gettone nella matrice
int inserisciGettone(char matrice[6][7], char player, char i1)
{
    int colonna = 0;
    int riga = 0;
    int contatore = 0;
    for (int i = RIGHE - 1; i >= 0; i--) // Scorro l'indice delle righe
    {
        for (int j = 0; j < COLONNE; j++) // Scorro l'indice delle colonne
        {
            if (matrice [i][j] == VUOTO) // Controllo se la cella è vuota
            {
                matrice [i][j] = player; // Inserisco il gettone nella cella vuota
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
    if (riga == 0 && colonna == 0) // Se la cella è vuota e non ho trovato una cella vuota
    {
        cout << "La colonna è piena, riprova" << endl;
        return 0;
    }
    else
    {
        return 1;
    }
}

/*int inserisciGettone (char *arr , int colonna, char gettone ) // Funzione con array unidimensionale
{
    char *p = arr + (RIGHE - 1) * COLONNE + colonna;
    for (int i = 0; i < RIGHE; i++)
    {
        if (*p == VUOTO)
        {
            *p = gettone;
            return 1;
        }
        p -= COLONNE;
    }
    return 0;
}*/

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

// Funzione che controlla se c'è pareggio
int pareggio (char matrice[RIGHE][COLONNE])
{
    int contatore = 0;
    for (int i = 0; i < RIGHE; i++) // Scorro l'indice delle righe
    {
        for (int j = 0; j < COLONNE; j++) // Scorro l'indice delle colonne
        {
            if (matrice [i][j] != VUOTO) // Controllo se la cella è vuota
            {
                contatore++;
            }
        }
    }
    if (contatore == RIGHE * COLONNE) // Se la matrice è piena
    {
        return 1;
    }
    else
    {
        return 0;
    }
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

// Funzione che controllo se c'è vittoria orizzontale
int vittoriaOrizzontale(char pString[6][7], char giocatore) {
    int contatore = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (pString[i][j] == giocatore) {
                contatore++;
                if (contatore == 4) {
                    return 1;
                }
            } else {
                contatore = 0;
            }
        }
        contatore = 0;
    }
    return 0;
}

// Funzione che controlla se c'è vittoria diagonale
int vittoriaDiagonale(char pString[6][7], char giocatore) {
    int contatore = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (pString[i][j] == giocatore) {
                contatore++;
                if (contatore == 4) {
                    return 1;
                }
            } else {
                contatore = 0;
            }
        }
        contatore = 0;
    }
    return 0;
}

// Funzione che controlla se c'è vittoria verticale
int vittoriaVerticale(char pString[6][7], char giocatore) {
    int contatore = 0;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 6; j++) {
            if (pString[j][i] == giocatore) {
                contatore++;
                if (contatore == 4) {
                    return 1;
                }
            } else {
                contatore = 0;
            }
        }
        contatore = 0;
    }
    return 0;
}

// Funzione che controlla se la colonna è piena
int colonnaPiena(char pString[6][7], int colonna) {
    if (pString[0][colonna] != VUOTO) {
        return 1;
    }
    return 0;
}


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

    // Inizializzo la matrice
    for (int i = 0; i < RIGHE; i++) // Scorro l'indice delle righe
    {
        for (int j = 0; j < COLONNE; j++) // Scorro l'indice delle colonne
        {
            matrice [i][j] = VUOTO;
        }
    }

    // Inizializzo l'array
    for (int i = 0; i < RIGHE * COLONNE; i++)
    {
        arr [i] = VUOTO;
    }

    // Menu
    cout << endl;
    cout << "Benvenuto e preparati a giocare a forza 4! " << endl;
    cout << endl;
    stampaMenu();
    cout << endl;
    cout << "Digita 1 per giocare contro un altro giocatore." << endl;
    cout << "Digita 2 per giocare contro il COMPUTER." << endl;
    cin >> scelta;

    if (scelta == 1)
    {
        cout << "Hai scelto di giocare player vs player" << endl;
        cout << "Inserisci il tuo nome" << endl;
        cin >> nome;
        cout << "Inserisci il tuo simbolo" << endl;
        cin >> giocatore;
        tipoGiocatore = 'U';
        cout << "Inserisci il simbolo del pc" << endl;
    }
    else if (scelta == 2)
    {
        cout << "Hai scelto di giocare player vs pc" << endl;
        cout << "Inserisci il tuo nome" << endl;
        cin >> nome;
        cout << "Inserisci il tuo simbolo" << endl;
        cin >> giocatore;
        tipoGiocatore = 'U';
        cout << "Inserisci il simbolo del pc" << endl;
    }
    else
    {
        cout << "Scelta non valida" << endl;
        return 0;
    }
    cin >> giocatore;
    cout << endl;
    cout << "Inizia il gioco!" << endl;
    cout << endl;

    // Gioco
    while (vittoria == 0)
    {
        // Stampo la matrice
        stampaMatrice (matrice);
        cout << endl;

        // Chiedo all'utente di inserire la colonna
        cout << nome << " inserisci la colonna in cui vuoi inserire il gettone" << endl;
        cin >> colonna;
        cout << endl;

        // Controllo se la colonna è piena
        if (colonnaPiena (matrice, colonna) == 1)
        {
            cout << "Colonna piena, riprova" << endl;
            continue;
        }

        // Inserisco il gettone nella matrice
        inserisciGettone(matrice, colonna, giocatore);

        // Controllo se c'è vittoria
        if (vittoriaOrizzontale (matrice, giocatore) == 1 || vittoriaVerticale (matrice, giocatore) == 1 || vittoriaDiagonale (matrice, giocatore) == 1)
        {
            vittoria = 1;
            vittoriaGiocatore = 1;
            break;
        }

        // Controllo se c'è pareggio
        if (pareggio (matrice) == 1)
        {
            vittoria = 1;
            vittoriaPareggio = 1;
            break;
        }

        // Se il giocatore è un utente
        if (tipoGiocatore == 'U')
        {
            // Chiedo all'utente di inserire la colonna
            cout << "Inserisci la colonna in cui vuoi inserire il gettone" << endl;
            cin >> colonna;
            cout << endl;

            // Controllo se la colonna è piena
            if (colonnaPiena (matrice, colonna) == 1)
            {
                cout << "Colonna piena, riprova" << endl;
                continue;
            }

            // Inserisco il gettone nella matrice
            inserisciGettone(matrice, colonna, giocatore);

            // Controllo se c'è vittoria
            if (vittoriaOrizzontale (matrice, giocatore) == 1 || vittoriaVerticale (matrice, giocatore) == 1 || vittoriaDiagonale (matrice, giocatore) == 1)
            {
                vittoria = 1;
                vittoriaGiocatore = 1;
                break;
            }

            // Controllo se c'è pareggio
            if (pareggio (matrice) == 1)
            {
                vittoria = 1;
                vittoriaPareggio = 1;
                break;
            }
        }

        // Se il giocatore è il computer
        else if (tipoGiocatore == 'C')
        {
            // Inserisco il gettone nella matrice
            inserisciGettone(matrice, colonna, giocatore);

            // Controllo se c'è vittoria
            if (vittoriaOrizzontale (matrice, giocatore) == 1 || vittoriaVerticale (matrice, giocatore) == 1 || vittoriaDiagonale (matrice, giocatore) == 1)
            {
                vittoria = 1;
                vittoriaPC = 1;
                break;
            }

            // Controllo se c'è pareggio
            if (pareggio (matrice) == 1)
            {
                vittoria = 1;
                vittoriaPareggio = 1;
                break;
            }
        }
    }
}
