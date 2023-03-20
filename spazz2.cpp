#include <iostream>
using namespace std;

const int ROWS = 6;
const int COLS = 7;
char board[ROWS][COLS]; // matrice per il gioco

// inizializza la matrice con uno spazio vuoto in ogni cella
void init_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
}

// visualizza la matrice di gioco
void display_board() {
    cout << "-----------------------------" << endl;
    for (int i = 0; i < ROWS; i++) {
        cout << "| ";
        for (int j = 0; j < COLS; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "-----------------------------" << endl;
    }
}

// inserisce un tassello nella colonna specificata
// ritorna true se l'inserimento è andato a buon fine, false altrimenti
bool drop_piece(int col, char piece) {
    if (col < 0 || col >= COLS) {
        return false; // la colonna non esiste
    }
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][col] == ' ') {
            board[i][col] = piece;
            return true;
        }
    }
    return false; // la colonna è piena
}

// gioco completo
void play_game() {
    init_board();
    display_board();

    char player1 = 'X';
    char player2 = 'O';
    char current_player = player1;

    while (true) {
        cout << "Turno del giocatore " << current_player << endl;
        int col;
        cout << "Inserisci la colonna (0-6): ";
        cin >> col;

        if (drop_piece(col, current_player)) {
            display_board();
            if (current_player == player1) {
                current_player = player2;
            } else {
                current_player = player1;
            }
        } else {
            cout << "La colonna è piena, riprova." << endl;
        }
    }
}

int main() {
    play_game();
    return 0;
}
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
int xisWinner (char matrice[ROWS][col], char player)
{
    int contatore = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrice [i][j] == player) // Controllo se nella cella ci sono 4 pedine uguali
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