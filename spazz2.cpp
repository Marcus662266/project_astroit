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
int xisWinner (char matrice[ROWS][COLS], char player) {

    // controllo orizzontale
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (matrice[i][j] == player && matrice[i][j + 1] == player && matrice[i][j + 2] == player &&
                matrice[i][j + 3] == player) {
                return 1;
            }
        }
    }

    // controllo verticale
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrice[i][j] == player && matrice[i + 1][j] == player && matrice[i + 2][j] == player &&
                matrice[i + 3][j] == player) {
                return 1;
            }
        }
    }

    // controllo diagonale
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (matrice[i][j] == player && matrice[i + 1][j + 1] == player && matrice[i + 2][j + 2] == player &&
                matrice[i + 3][j + 3] == player) {
                return 1;
            }
        }
    }

    // controllo diagonale inversa
    for (int i = 3; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (matrice[i][j] == player && matrice[i - 1][j + 1] == player && matrice[i - 2][j + 2] == player &&
                matrice[i - 3][j + 3] == player) {
                return 1;
            }
        }
    }

    return 0;
}

 int main() {

    stampaTitolo();
    cout<<endl;
    
    cout << "Benvenuto e preparati a giocare al Forza 4 " << endl;
    cout << endl;
    play_game();

    return 0;

       /* int choice;
        cout << "1. Gioca" << endl;
        cout << "2. Esci" << endl;
        cout << "Scelta: ";
        cin >> choice;
        if (choice == 2) {
            return 0;
        }
        // continua a giocare
        if (choice == 1) {
            play_game();
        }
        play_game();
        return 0;*/
}
