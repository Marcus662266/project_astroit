#include <iostream>
using namespace std;

// Definisco le costanti
const int ROWS = 6;
const int COLS = 7;
char board[ROWS][COLS]; 


// Definisco le funzioni


// inizializza la board con uno spazio vuoto in ogni cella
void init_board()
{
    for (int i = 0; i < ROWS; i++) // Scorro le righe
    {
        for (int j = 0; j < COLS; j++)
        {
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

void stampaMenu(void)
{
    cout << endl;
    cout << " =========================================================  \n";
    cout << "| 1. Player vs Player                                     | \n";
    cout << "| 2. Player vs Computer                                   | \n";
    cout << " =========================================================  \n";

    cout << "===========================================================" << endl;
}
// visualizza la board di gioco
void display_board()
{
    cout << endl;
    cout << "-----------------------------" << endl;
    for (int i = 0; i < ROWS; i++)
    {
        cout << "| ";
        for (int j = 0; j < COLS; j++)
        {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "-----------------------------" << endl;
    }
    cout << "  ";
    for (int j = 0; j < COLS; j++)
    {
        cout << j << "  ";
    }
    cout << endl;
    cout << endl;
}


// inserisce un tassello nella colonna specificata
// ritorna true se l'inserimento è andato a buon fine, false altrimenti
bool drop_piece(int col, char piece)
{
    if (col < 0 || col >= COLS)
    {
        return false; // la colonna non esiste
    }
    for (int i = ROWS - 1; i >= 0; i--)
    {
        if (board[i][col] == ' ')
        {
            board[i][col] = piece;
            return true;
        }
    }
    return false; // la colonna è piena
}

// gioco completo
void play_game()
{
    init_board();
    display_board();

    char player1 ;
    char player2 ;
    char current_player = player1;

    while (true)
    {
        cout << "Turno del giocatore " << current_player << endl;
        int col;
        cout << "Inserisci la colonna (0-6): ";
        cin >> col;

        if (drop_piece(col, current_player))
        {
            display_board();
            if (current_player == player1)
            {
                current_player = player2;
            }
            else
            {
                current_player = player1;
            }
        }
        else
        {
            cout << "La colonna è piena, riprova." << endl;
        }
    }
}
int xisWinner(char board[ROWS][COLS], char player)
{

    // controllo orizzontale
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS - 3; j++)
        {
            if (board[i][j] == player && board[i][j + 1] == player && board[i][j + 2] == player &&
                board[i][j + 3] == player)
            {
                return 1;
            }
        }
    }

    // controllo verticale
    for (int i = 0; i < ROWS - 3; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] == player && board[i + 1][j] == player && board[i + 2][j] == player &&
                board[i + 3][j] == player)
            {
                return 1;
            }
        }
    }

    // controllo diagonale
    for (int i = 0; i < ROWS - 3; i++)
    {
        for (int j = 0; j < COLS - 3; j++)
        {
            if (board[i][j] == player && board[i + 1][j + 1] == player && board[i + 2][j + 2] == player &&
                board[i + 3][j + 3] == player)
            {
                return 1;
            }
        }
    }

    // controllo diagonale inversa
    for (int i = 3; i < ROWS; i++)
    {
        for (int j = 0; j < COLS - 3; j++)
        {
            if (board[i][j] == player && board[i - 1][j + 1] == player && board[i - 2][j + 2] == player &&
                board[i - 3][j + 3] == player)
            {
                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    int scelta;
    char nome[20];
    char giocatore;
    char tipoGiocatore;
    char pc = 'O';
    //char board[ROWS][COLS];
    int colonna;
    int riga;
    stampaTitolo();
    cout << endl;

    cout << endl;
    cout << "===========================================================" << endl;
    //cout << "  " << Benvenuto e preparati a giocare a forza 4!  << "  "     << endl;
    cout << "===========================================================" << endl;
    cout << endl;
    stampaMenu();
    cout << endl;
    cout << "Digita 1 per giocare Player vs Player." << endl;
    cout << "Digita 2 per giocare Player vs Computer." << endl;
    cin >> scelta;

  
    cout << "Inizia il gioco!" << endl;
    cout << endl;
   // int board[ROWS][COLS];
    bool continua = true;
    while (continua)
    {
        init_board();
        display_board();
        while (true)
        {
            if (tipoGiocatore == 'U')
            {
                cout << "E' il turno di " << nome << endl;
                cout << "Inserisci la colonna in cui vuoi inserire il tuo simbolo" << endl;
                cin >> colonna;
                if (colonna < 0 || colonna > 6)
                {
                    cout << "Colonna non valida" << endl;
                    continue;
                }
                if (drop_piece(colonna, giocatore))
                {
                    display_board();
                    if (xisWinner(board, giocatore))
                    {
                        cout << "Hai vinto!" << endl;
                        break;
                    }
                    tipoGiocatore = 'P';
                }
                else
                {
                    cout << "Colonna piena, riprova" << endl;
                }
            }
            else
            {
                cout << "E' il turno del Computer" << endl;
                colonna = rand() % 7;
                if (drop_piece(colonna, pc))
                {
                    display_board();
                    if (xisWinner(board, pc))
                    {
                        cout << "Hai perso!" << endl;
                        break;
                    }
                    tipoGiocatore = 'U';
                }
            }
        }
        cout << "Vuoi continuare a giocare? (s/n)" << endl;
        char risposta;
        cin >> risposta;
        if (risposta == 'n')
        {
            continua = false;
        }


    }

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
