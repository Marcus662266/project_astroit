//
// Created by guea on 17.03.23.
//

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

void stampaTitolo(void){
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

};

void stampaTabella( char matrice[RIGHE][COLONNE]){ // Funzione che stampa la tabella
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
        //cout << "  " << i << " ";

        cout << endl;
    }
    cout << "-------------------------------------------------\n";
    cout << "   ";
    for (int i = 1; i < COLONNE + 1; i++) // Scorro l'indice delle colonne
    {
        cout << i << "      "; // Stampo l'indice delle colonne
    }
};

void inizializzaTabella(char matrice[RIGHE][COLONNE]){ // Funzione che inizializza la matrice
    for (int i = 0; i < RIGHE; i++)  // Scorro l'indice delle righe
    {
        for (int j = 0; j < COLONNE; j++)// Scorro l'indice delle colonne
        {
            matrice [i][j] = VUOTO;
        }
    }
};

int xisWinner (char matrice[RIGHE][COLONNE], char giocatore){ // Funzione che controlla se il giocatore ha vinto
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
};

int giocatore (char matrice[RIGHE][COLONNE], char giocatore ,char tipoGiocatore , string nome){ // Funzione che gestisce il turno del giocatore

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
    else //
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

int inserisciGettoni (char matrice[RIGHE][COLONNE], char giocatore ,char tipoGiocatore , string nome){ // Funzione che inserisce i gettoni nella tabella
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

};

int mossaPC (char matrice[RIGHE][COLONNE], char giocatore ,char tipoGiocatore , string nome){ // Funzione che gestisce il turno del PC
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

};


// Funzione che controlla se c'è una vittoria
int controlloVittoria (char *arr){
     int combinazioni[8][4] =
             {{0,1,2,3},
              {1,2,3,4},
              {2,3,4,5},
              {3,4,5,6},
              {7,8,9,10},
              {8,9,10,11},
              {9,10,11,12},
              {10,11,12,13}
             }; // Array che contiene le combinazioni vincenti
    for (int i = 0; i < 8; i++) // Scorro l'indice delle combinazioni
    {
        if (arr[combinazioni[i][0]] == arr[combinazioni[i][1]] && arr[combinazioni[i][1]] == arr[combinazioni[i][2]] && arr[combinazioni[i][2]] == arr[combinazioni[i][3]] && arr[combinazioni[i][0]] != VUOTO) // Se le 4 celle sono uguali e diverse da vuoto
        {
            return 1; // Ritorno 1
        }
    }
    return 0; // Ritorno 0
}

    // Funzione che controlla se c'è una vittoria
   /* int contatore = 0;
    int vittoria = 0;
// controllo orizzontale
    for (int i = 0; i < RIGHE; i++) // Scorro l'indice delle righe
    {
        for (int j = 0; j < COLONNE; j++) // Scorro l'indice delle colonne
        {
            if (matrice [i][j] == giocatore) // Se la cella corrisponde al giocatore
            {
                contatore++; // Incremento il contatore
                if (contatore == 4) // Se il contatore è uguale a 4
                {
                    vittoria = 1; // La vittoria è uguale a 1
                    break;
                }
            }
            else
            {
                contatore = 0; // Se la cella non corrisponde al giocatore il contatore è uguale a 0
            }
        }
        contatore = 0; // Azzero il contatore
    }
    contatore = 0; // Azzero il contatore
    // controllo verticale
    for (int i = 0; i < COLONNE; i++) // Scorro l'indice delle colonne
    {
        for (int j = 0; j < RIGHE; j++) // Scorro l'indice delle righe
        {
            if (matrice [j][i] == giocatore) // Se la cella corrisponde al giocatore
            {
                contatore++; // Incremento il contatore
                if (contatore == 4) // Se il contatore è uguale a 4
                {
                    vittoria = 1; // La vittoria è uguale a 1
                    break;
                }
            }
            else
            {
                contatore = 0; // Se la cella non corrisponde al giocatore il contatore è uguale a 0
            }
        }
        contatore = 0; // Azzero il contatore
    }
    contatore = 0; // Azzero il contatore

    // controllo diagonale
    for (int i = 0; i < RIGHE; i++) // Scorro l'indice delle righe
    {
        for (int j = 0; j < COLONNE; j++) // Scorro l'indice delle colonne
        {
            if (matrice [i][j] == giocatore) // Se la cella corrisponde al giocatore
            {
                contatore++; // Incremento il contatore
                if (contatore == 4) // Se il contatore è uguale a 4
                {
                    vittoria = 1; // La vittoria è uguale a 1
                    break;
                }
            }
            else
            {
                contatore = 0; // Se la cella non corrisponde al giocatore il contatore è uguale a 0
            }
        }
        contatore = 0; // Azzero il contatore
    }
    contatore = 0; // Azzero il contatore
    return vittoria;*/



 void stampaRigaPiena (char matrice[RIGHE][COLONNE], int riga, int colonna, int contatore){ // Funzione che stampa una riga piena
    for (int i = 0; i < COLONNE; i++) // Scorro l'indice delle colonne
    {
        cout << matrice [riga][i] << " ";
    }
    cout << endl;
};


int main(){
    char matrice[RIGHE][COLONNE];
    char tipoGioco = ' ';
    string nome1 = " ";
    string nome2 = " ";
    int scelta = 0;
    int contatore = 0;
    int riga = 0;
    int colonna = 0;
    int vittoria = 0;

    cout << "Benvenuto nel gioco del Forza 4!" << endl;
    cout << "Vuoi giocare contro il computer o contro un altro giocatore?" << endl;
    cout << "Premi 1 per giocare contro il computer, premi 2 per giocare contro un altro giocatore: ";
    cin >> scelta;
    if (scelta == 1) // Se il giocatore vuole giocare contro il computer
    {
        tipoGioco = 'C';
    }
    else // Se il giocatore vuole giocare contro un altro giocatore
    {
        tipoGioco = 'U';
    }
    cout << "Inserisci il nome del primo giocatore: ";
    cin >> nome1;
    if (tipoGioco == 'C') // Se il giocatore vuole giocare contro il computer
    {
        nome2 = "Computer";
    }
    else // Se il giocatore vuole giocare contro un altro giocatore
    {
        cout << "Inserisci il nome del secondo giocatore: ";
        cin >> nome2;
    }
    // da finire dopo
}






