// Includo le librerie che mi serviranno
#include <iostream>
#include <string>
#include <random>

using namespace std;

// Inizializzo le "variabili" COSTANTI
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

// Funzione ce stampa il titolo del programma
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
void stampaTabella(char matrice[RIGHE][COLONNE])
{
    cout << endl;
    cout << endl;
    cout << "-------------------------------------------------";
    for (int i = 0; i < RIGHE; i++)
    {
        cout << endl;
        for (int j = 0; j < COLONNE; j++) // Scorro l'indice delle colonne
        {
            cout << matrice[i][j] << "|  " << VUOTO << "  |";
        }
        // cout << "  " << i << " ";
        cout << endl;
    }
    cout << "-------------------------------------------------\n";
    cout << "   ";
    for (int i = 1; i < COLONNE + 1; i++) // Scorro l'indice delle colonne
    {
        cout << i << "      "; // Stampo l'indice delle colonne
    }
    cout << endl;
    cout << endl;
};

// Funzione che inizializza la matrice
void inizializzaTabella(char matrice[RIGHE][COLONNE])
{
    for (int i = 0; i < RIGHE; i++) // Scorro l'indice delle righe
    {
        for (int j = 0; j < COLONNE; j++) // Scorro l'indice delle colonne
        {
            matrice[i][j] = VUOTO;
        }
    }
};

// Controlla se il giocatore ha vinto
int xIsWinner(char matrice[RIGHE][COLONNE], char giocatore)
{
    int contatore = 0;
    for (int i = 0; i < RIGHE; i++)
    {
        for (int j = 0; j < COLONNE; j++)
        {
            if (matrice[i][j] == giocatore) // Controllo se nella cella ci sono 4 gettoni uguali
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

// Gestisco il turno dell'UTENTE
int giocatore(char matrice[RIGHE][COLONNE], char giocatore, char tipoGiocatore, string nome)
{
    int riga = 0;
    int colonna = 0;
    int contatore = 0;
    if (tipoGiocatore == 'U') // Se il giocatore è un UTENTE
    {
        cout << "Inserisci il numero della colonna dove vuoi inserire il gettone: ";
        cin >> colonna;
        colonna--;
        if (colonna < 0 || colonna < COLONNE - 1) // Controllo la validità della colonna inserita
        {
            cout << "Colonna non valida, riprova. \n";
            return 0;
        }
        for (int i = RIGHE; i >= 0; i--) // Scorro le RIGHE al contrario
        {
            if (matrice[i][colonna] == VUOTO)
            {
                matrice[i][colonna] = giocatore; // Inserisce il gettone nel primo spazio libero della colonna scelta
                riga = i;
                break;
            }
        }
        if (riga == 0)
        {
            cout << "La colonna è piena, scegli un'altra colonna \n";
            return 0;
        }
    }
    else
    {
        for (int i = RIGHE; i >= 0; i--) // Scorro le RIGHE
        {
            for (int j = 0; j < COLONNE; j++)
            {
                if (matrice[i][j] == VUOTO)
                {
                    matrice[i][j] = giocatore; // Inserisce il gettone nel primo spazio libero della colonna scelta
                    riga = i;
                    colonna = j;
                    contatore++;
                    break;
                }
            }
            if (contatore == 1) // Una volta inserito il gettone esco dal ciclo
            {
                break;
            }
        }
        if (riga == 0)
        {
            cout << "La colonna è piena, scegli un'altra colonna \n";
            return 0;
        }
        cout << nome << " ha inserito il gettone nella colonna " << colonna + 1 << endl;
    }
    return 1;
}

// Gestisce inserimento dei gettoni
int inserisciGettoni(char matrice[RIGHE][COLONNE], char giocatore, char tipoGiocatore, string nome)
{
    int riga = 0;
    int colonna = 0;
    int contatore = 0;

    if (tipoGiocatore == 'U') // Se il giocatore è umano
    {
        cout << "Inserisci la colonna dove vuoi inserire il gettone: ";
        cin >> colonna;
        colonna--;
        if (colonna < 0 || colonna > COLONNE - 1) // Controllo che la colonna inserita sia valida
        {
            cout << "Colonna non valida, riprova" << endl;
            return 0;
        }
        for (int i = RIGHE - 1; i >= 0; i--) // Scorro l'indice delle righe
        {
            if (matrice[i][colonna] == VUOTO)
            {
                matrice[i][colonna] = giocatore; // Inserisco il gettone nella cella vuota
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
            for (int j = 0; j < COLONNE; j++) // Scorro l'indice delle colonne
            {
                if (matrice[i][j] == VUOTO)
                {
                    matrice[i][j] = giocatore; // Inserisco il gettone nella cella vuota
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
        cout << nome << " ha inserito il gettone nella colonna " << colonna + 1 << endl;
    }
    return 1;
}

// Gestisco il turno del COMPUTER
int mossaPC(char matrice[RIGHE][COLONNE], char giocatore, char tipoGiocatore, string nome)
{
    int riga = 0;
    int colonna = 0;
    int contatore = 0;
    if (tipoGiocatore == 'U') // Se il giocatore è un UTENTE
    {
        cout << "Inserisci il numero della colonna dove vuoi inserire il gettone: ";
        cin >> colonna;
        colonna--;
        if (colonna < 0 || colonna < COLONNE - 1) // Controllo la validità della colonna inserita
        {
            cout << "Colonna non valida, riprova. \n";
            return 0;
        }
        for (int i = RIGHE; i >= 0; i--) // Scorro le RIGHE al contrario
        {
            if (matrice[i][colonna] == VUOTO)
            {
                matrice[i][colonna] = giocatore; // Inserisce il gettone nel primo spazio libero della colonna scelta
                riga = i;
                break;
            }
        }
        if (riga == 0)
        {
            cout << "La colonna è piena, scegli un'altra colonna \n";
            return 0;
        }
    }
    else
    {
        for (int i = RIGHE; i >= 0; i--) // Scorro le Righe
        {
            for (int j = 0; j < COLONNE; j++)
            {
                if (matrice[i][j] == VUOTO)
                {
                    matrice[i][j] = giocatore; // Inserisce il gettone nel primo spazio libero della colonna scelta
                    riga = i;
                    colonna = j;
                    contatore++;
                    break;
                }
            }
            if (contatore == 1) // Una volta inserito il gettone esco dal ciclo
            {
                break;
            }
        }
        if (riga == 0)
        {
            cout << "La colonna è piena, scegli un'altra colonna \n";
            return 0;
        }
        cout << nome << " ha inserito il gettone nella colonna " << colonna + 1 << endl;
    }
    return 1;
}

// Gestisco il gioco
/*void gioca( char matrice[RIGHE][COLONNE],char tipoGioco, string nome1, string nome2)
{
    char giocatore = 'X';
    char tipoGiocatore1 = 'U';
    char tipoGiocatore2 = 'U';
    int colonna = 0;
    int riga = 0;
    int contatore = 0;
    int vittoria = 0;
    int turno = 0;
    int mossa = 0;
    if (tipoGioco == 'C') // Se il giocatore vuole giocare contro il computer
    {
        tipoGiocatore2 = 'C';
    }
    while (vittoria == 0) // Finchè non c'è una vittoria
    {
        if (turno == 0) // Se è il turno del giocatore 1
        {
            mossa = inserisciGettoni (matrice, giocatore, tipoGiocatore1, nome1);
            if (mossa == 0) // Se la mossa non è valida
            {
                turno = 0;
            }
            else
            {
                turno = 1;
            }
        }
        else // Se è il turno del giocatore 2
        {
            mossa = inserisciGettoni (matrice, giocatore, tipoGiocatore2, nome2);
            if (mossa == 0) // Se la mossa non è valida
            {
                turno = 1;
            }
            else
            {
                turno = 0;
            }
        }
        if (turno == 0) // Se è il turno del giocatore 1
        {
            giocatore = 'X';
        }
        else // Se è il turno del giocatore 2
        {
            giocatore = 'O';
        }
        // Qui abbiamo un problema e dobbiamo risolverlo creando una funzione che controlla se la colonna è piena
        vittoria = controlloVittoria (matrice, giocatore, riga, colonna, contatore); // Controllo se c'è una vittoria
    }
    if (vittoria == 1) // Se c'è una vittoria
    {
        if (turno == 0) // Se è il turno del giocatore 1
        {
            cout << nome1 << " ha vinto!" << endl;
        }
        else // Se è il turno del giocatore 2
        {
            cout << nome2 << " ha vinto!" << endl;
        }
    }
    else // Se c'è un pareggio
    {
        cout << "Pareggio!" << endl;
    }
}*/

// Stampo una riga piena
void stampaRigaPiena(char matrice[RIGHE][COLONNE], int riga, int colonna, int contatore)
{
    for (int i = 0; i < COLONNE; i++) // Scorro l'indice delle COLONNE
    {
        cout << matrice[riga][i] << " ";
    }
    cout << endl;
}

int main()
{
    char matrice[RIGHE][COLONNE];
    char tipoGioco = ' ';
    string nome1 = " ";
    string nome2 = " ";
    int scelta = 0;
    int contatore = 0;
    int riga = 0;
    int colonna = 0;
    int vittoria = 0;

    stampaTitolo();
    cout << endl;
    cout << "Benvenuto e preparati a giocare a FORZA 4! \n";
    cout << endl;
    cout << "Se vuoi giocare contro il COMPUTER premi 1.\n";
    cout << "Se vuoi giocare contro un UTENTE premi 2.\n";
    cin >> scelta;
    if (scelta == 1)
    {
        tipoGioco = 'C';
        cout << "Inserisci il tuo nome: ";
        cin >> nome1;
        nome2 = "Computer";
    }
    else
    {
        tipoGioco = 'U';
    }
    cout << "Inserisci il nome del primo giocatore: ";
    cin >> nome1;
    if (tipoGioco == 'C') // Se il giocatore vuole giocare contro il COMPUTER
    {
        nome2 = "COMPUTER";
    }
    else // Se il giocatore vuole giocare contro un UTENTE
    {
        cout << "Inserisci il nome del secondo giocatore: ";
        cin >> nome2;
    }
    // da finire dopo
}