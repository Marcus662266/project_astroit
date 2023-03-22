#include <iostream>
#include <random>
using namespace std;

// Definisco le costanti
const int ROWS = 6;
const int COLS = 7;

char board[ROWS][COLS];

// Definisco le funzioni

// Inizializza la board con uno spazio "vuoto" in ogni cella
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

// Stampa il menù
void stampaMenu(void)
{
    cout << endl;
    cout << " =========================================================  \n";
    cout << "|                  PLAYER   VS   COMPUTER                 | \n";
    cout << " =========================================================  \n";
    cout << endl;
}

// Visualizza la board di gioco
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
        cout << j << "   ";
    }
    cout << endl;
    cout << endl;
}

// Inserisce un tassello nella colonna specificata
bool drop_piece(int col, char piece)
{
    if (col < 0 || col >= COLS)
    {
        return false; // La colonna non esiste
    }
    for (int i = ROWS - 1; i >= 0; i--)
    {
        if (board[i][col] == ' ')
        {
            board[i][col] = piece;
            return true;
        }
    }
    return false; // La colonna è piena
}
// Controlla se c'è una vittoria
int xisWinner(char board[ROWS][COLS], char player)
{
    // Controllo orizzontale
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

    // Controllo verticale
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

    // Controllo diagonale
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

    // Controllo diagonale inversa
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
    int colonna;

    cout <<"\033[35m"; // colore viola
    stampaTitolo();

    cout << endl;
    cout << endl;
    cout <<"\033[37m"; //colore bianco
    cout << " ========================================================= " << endl;
    cout << "|        BENVENUTO E PREPARATI A GIOCARE A FORZA 4!       |" << endl;
    cout << " ========================================================= " << endl;
    cout << endl;

    stampaMenu();

    cout << endl;
    cout << " ========================================================= " << endl;
    cout << "|                                                         |" << endl;
    cout << "|              DIGITA 1 PER INIZIARE IL GIOCO             |" << endl;
    cout << "|                                                         |" << endl;
    cout << " ========================================================= " << endl;
    cout << endl;
    cin >> scelta;
    if(scelta == 1)
    {
        cout << endl;
        cout << " ========================================================= " << endl;
        cout << "|                INSERISCI IL TUO NOME                    |" << endl;
        cout << " ========================================================= " << endl;
        cin >> nome;
        cout << endl;
        cout << endl;
        cout << " ========================================================= " << endl;
        cout << "|          INSERISCI IL SIMBOLO CHE VUOI USARE            |" << endl;
        cout << " ========================================================= " << endl;
        cin >> giocatore;
        cout << endl;
        tipoGiocatore = 'U';
    }
    else
    {
        cout << endl;
        cout <<"\033[31m"; //colore rosso
        cout << " ========================================================= " << endl;
        cout << "|                   SCELTA NON VALIDA!                    |" << endl;
        cout << " ========================================================= " << endl;
        cout << endl;
        return 0;
    }

    cout << endl;
    cout <<"\033[35m"; //colore viola
    cout << " ========================================================= " << endl;
    cout << "|                      INIZIA IL GIOCO!                   |" << endl;
    cout << " ========================================================= " << endl;
    cout << endl;
    cout << endl;
    
    bool continua = true;
    while (continua)
    {               
        
      cout <<"\033[32m"; //colore verde

        init_board();
        display_board();
        while (true)
        {
            if (tipoGiocatore == 'U')
            {
                cout << endl;
                cout << " ========================================================= " << endl;
                cout << "|                      E'IL TUO TURNO!                    |" << endl;
                cout << " ========================================================= " << endl;
                cout << endl;
                cout << endl;
                cout << " ========================================================================= " << endl;
                cout << "|      INSERISCI IL NUMERO DELLA COLONNA DOVE VUOI METTERE IL GETTONE     |" << endl;
                cout << " ========================================================================= " << endl;
                cin >> colonna;
                cout << endl;

                if (colonna < 0 || colonna > 6)
                {
                    cout << endl;
                    cout <<"\033[31m"; //colore rosso
                    cout << " ========================================================= " << endl;
                    cout << "|                    COLONNA NON VALIDA!                  |" << endl;
                    cout << " ========================================================= " << endl;
                    cout <<"\033[32m"; //colore verde

                    cout << endl;
                    continue;
                }
                if (drop_piece(colonna, giocatore))
                {
                    display_board();
                    if (xisWinner(board, giocatore))
                    {
                        cout << endl;
                        cout <<"\033[33m"; //colore giallo
                        cout << " ========================================================= " << endl;
                        cout << "|                       HAI VINTO!                        |" << endl;
                        cout << "|                                                         |" << endl;
                        cout << "|           GRAZIE PER AVER GIOCATO A FORZA 4!            |" << endl;
                        cout << " ========================================================= " << endl;
                        cout << endl;
                        cout << endl;
                        cout <<" \033[36m"; //colore azzurro
                        cout << " ======================================================== " << endl;
                        cout << "|                SE NON VUOI GIOCARE PIU'                |" << endl;
                        cout << "|            PREMI IL TASTO F13 SULLA TASTIERA           |" << endl;
                        cout << "|                     ENTRO 2 SECONDI                    |" << endl;
                        cout << "|                                                        |" << endl;
                        cout << "|             altrimenti giocherai per sempre!           |" << endl;
                        cout << " ======================================================== " << endl;
                        cout <<"\033[32m"; //colore verde

                        break;
                    }
                    tipoGiocatore = 'P';
                }
                else
                {
                    cout << endl;
                    cout <<"\033[31m"; //colore rosso
                    cout << " ========================================================= " << endl;
                    cout << "|                  COLONNA PIENA! RIPROVA                 |" << endl;
                    cout << " ========================================================= " << endl;
                    cout << endl;
                    cout <<"\033[32m"; //colore verde
                }
            }
            else
            {
                cout << endl;
                cout <<"\033[32m"; //colore verde
                cout << " ========================================================= " << endl;
                cout << "|                 E' IL TURNO DEL COMPUTER                |" << endl;
                cout << " ========================================================= " << endl;
                cout << endl;
                colonna = rand() % 7;
                if (drop_piece(colonna, pc))
                {
                    display_board();
                    if (xisWinner(board, pc))
                    {
                        cout << endl;
                        cout <<"\033[31m"; //colore rosso
                        cout << " ======================================================== " << endl;
                        cout << "|                       HAI PERSO!                       |" << endl;
                        cout << " ======================================================== " << endl;
                        cout << endl;
                        cout << endl;
                        cout <<" \033[36m"; //colore azzurro
                        cout << " ======================================================== " << endl;
                        cout << "|                SE NON VUOI GIOCARE PIU'                |" << endl;
                        cout << "|            PREMI IL TASTO F13 SULLA TASTIERA           |" << endl;
                        cout << "|                     ENTRO 2 SECONDI                    |" << endl;
                        cout << "|                                                        |" << endl;
                        cout << "|             altrimenti giocherai per sempre!           |" << endl;
                        cout << " ======================================================== " << endl;
                        cout <<"\033[32m"; //colore verde

                        break;
                    }
                    tipoGiocatore = 'U';
                }
            }
        }
    }
    cout << endl;
    return 0;
}
