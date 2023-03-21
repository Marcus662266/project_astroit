
/*

PROJECT FORZA 4: Il progetto consiste nella creazione del gioco "Forza 4", nel quale sarà possibile giocare in locale o in rete.
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

/* The code above does the following:
1. Declares all the functions (prototypes)
2. Declares all the global variables
3. Declares all the constants
4. Declares all the structures */

// Libraries

#include <iostream>
#include <string>
#include <cstdlib>

// Constants

const int ROWS = 6;
const int COLUMNS = 7;
const int WIN = 4;

// Structures

struct Player
{
    std::string name;
    char symbol;
};

// Global variables (they are declared here because they are used in more than one function)

char board[ROWS][COLUMNS];
Player player1, player2;
int turn = 0;

// Function prototypes

void initBoard( char board[ROWS][COLUMNS] ){
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            board[i][j] = ' ';
        }
    }

};

void printBoard( char board[ROWS][COLUMNS] ){
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
};

void play( char board[ROWS][COLUMNS] ){
    int choice;
    std::cout << "Welcome to Forza 4!" << std::endl;
    std::cout << "Choose the game mode:" << std::endl;
    std::cout << "1. User vs User" << std::endl;
    std::cout << "2. User vs Computer" << std::endl;
    std::cout << "3. Computer vs Computer" << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;

    switch (choice)
    {
        case 1:
            playUserVsUser();
            break;
        case 2:
            playUserVsComputer();
            break;
        case 3:
            //playComputerVsComputer();
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
            break;
    }
};

void playUserVsUser(
    char board[ROWS][COLUMNS],
    Player player1,
    Player player2,
    int turn){
    int choice;
    std::cout << "Welcome to Forza 4!" << std::endl;
    std::cout << "Choose the game mode:" << std::endl;
    std::cout << "1. User vs User" << std::endl;
    std::cout << "2. User vs Computer" << std::endl;
    std::cout << "3. Computer vs Computer" << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;

    switch (choice)
    {
        case 1:
            playUserVsUser();
            break;
        case 2:
            playUserVsComputer();
            break;
        case 3:
            //playComputerVsComputer();
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
            break;
    }
};

void playUserVsComputer( char board[ROWS][COLUMNS], Player player1, Player player2, int turn ){
    int choice;
    std::cout << "Welcome to Forza 4!" << std::endl;
    std::cout << "Choose the game mode:" << std::endl;
    std::cout << "1. User vs User" << std::endl;
    std::cout << "2. User vs Computer" << std::endl;
    std::cout << "3. Computer vs Computer" << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;

    switch (choice)
    {
        case 1:
            playUserVsUser();
            break;
        case 2:
            playUserVsComputer();
            break;
        case 3:
            //playComputerVsComputer();
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
            break;
    }
    if (choice == 1){
        playUserVsUser();
    }
    else if (choice == 2){
        playUserVsComputer();
    }
    else if (choice == 3){
        //playComputerVsComputer();
    }
    else{
        std::cout << "Invalid choice!" << std::endl;
    }
    
};

//void playComputerVsComputer();

void playTurn( char board[ROWS][COLUMNS], Player player1, Player player2, int turn ){
    int choice;
    std::cout << "Welcome to Forza 4!" << std::endl;
    std::cout << "Choose the game mode:" << std::endl;
    std::cout << "1. User vs User" << std::endl;
    std::cout << "2. User vs Computer" << std::endl;
    std::cout << "3. Computer vs Computer" << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;

    switch (choice)
    {
        case 1:
            playTurnUserVsUser( board[ROWS][COLUMNS], player1, player2, turn );{
                if (turn % 2 == 0){
                    std::cout << player1.name << "'s turn" << std::endl;
                }
                else{
                    std::cout << player2.name << "'s turn" << std::endl;
                }
            }
            break;
        case 2:
            playTurnUserVsComputer( board[ROWS][COLUMNS], player1, player2, turn );{
                if (turn % 2 == 0){
                    std::cout << player1.name << "'s turn" << std::endl;
                }
                else{
                    std::cout << player2.name << "'s turn" << std::endl;
                }
            }
    
            break;
        case 3:
            playTurnComputerVsComputer( board[ROWS][COLUMNS], player1, player2, turn );{
                if (turn % 2 == 0){
                    std::cout << player1.name << "'s turn" << std::endl;
                }
                else{
                    std::cout << player2.name << "'s turn" << std::endl;
                }
            }
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
            break;
    }
};
void playTurnUserVsUser( char board[ROWS][COLUMNS], Player player1, Player player2, int turn ){
    int choice;
    std::cout << "Welcome to Forza 4!" << std::endl;
    std::cout << "Choose the game mode:" << std::endl;
    std::cout << "1. User vs User" << std::endl;
    std::cout << "2. User vs Computer" << std::endl;
    std::cout << "3. Computer vs Computer" << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;

    switch (choice)
    {
        case 1:
            playTurnUserVsUser( board[ROWS][COLUMNS], player1, player2, turn );{
                if (turn % 2 == 0){
                    std::cout << player1.name << "'s turn" << std::endl;
                }
                else{
                    std::cout << player2.name << "'s turn" << std::endl;
                }
            }
            break;
        case 2:
            playTurnUserVsComputer( board[ROWS][COLUMNS], player1, player2, turn );{
                if (turn % 2 == 0){
                    std::cout << player1.name << "'s turn" << std::endl;
                }
                else{
                    std::cout << player2.name << "'s turn" << std::endl;
                }
            }
    
            break;
        case 3:
            playTurnComputerVsComputer( board[ROWS][COLUMNS], player1, player2, turn );{
                if (turn % 2 == 0){
                    std::cout << player1.name << "'s turn" << std::endl;
                }
                else{
                    std::cout << player2.name << "'s turn" << std::endl;
                }
            }
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
            break;
    }
};
void playTurnUserVsComputer( char board[ROWS][COLUMNS], Player player1, Player player2, int turn ){
    int choice;
    std::cout << "Welcome to Forza 4!" << std::endl;
    std::cout << "Choose the game mode:" << std::endl;
    std::cout << "1. User vs User" << std::endl;
    std::cout << "2. User vs Computer" << std::endl;
    std::cout << "3. Computer vs Computer" << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;

    switch (choice)
    {
        case 1:
            playTurnUserVsUser( board[ROWS][COLUMNS], player1, player2, turn );{
                if (turn % 2 == 0){
                    std::cout << player1.name << "'s turn" << std::endl;
                }
                else{
                    std::cout << player2.name << "'s turn" << std::endl;
                }
            }
            break;
        case 2:
            playTurnUserVsComputer( board[ROWS][COLUMNS], player1, player2, turn );{
                if (turn % 2 == 0){
                    std::cout << player1.name << "'s turn" << std::endl;
                }
                else{
                    std::cout << player2.name << "'s turn" << std::endl;
                }
            }
    
            break;
        case 3:
            playTurnComputerVsComputer( board[ROWS][COLUMNS], player1, player2, turn );{
                if (turn % 2 == 0){
                    std::cout << player1.name << "'s turn" << std::endl;
                }
                else{
                    std::cout << player2.name << "'s turn" << std::endl;
                }
            }
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
            break;
    }
};

//void playTurnComputerVsComputer();
void checkWin( char board[ROWS][COLUMNS], Player player1, Player player2, int turn){
    int  ROWS, COLUMNS;
    int choice;
    std::cout << "Welcome to Forza 4!" << std::endl;
    std::cout << "Choose the game mode:" << std::endl;
    std::cout << "1. User vs User" << std::endl;
    std::cout << "2. User vs Computer" << std::endl;
    std::cout << "3. Computer vs Computer" << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;

    do {
        switch (choice)
        {
            case 1:
                checkWinUserVsUser( board[ROWS][COLUMNS], player1, player2, turn );{
                    if (turn % 2 == 0){
                        std::cout << player1.name << "'s turn" << std::endl;
                    }
                    else{
                        std::cout << player2.name << "'s turn" << std::endl;
                    }
                }
                break;
            case 2:
                checkWinUserVsComputer( board[ROWS][COLUMNS], player1, player2, turn );{
                    if (turn % 2 == 0){
                        std::cout << player1.name << "'s turn" << std::endl;
                    }
                    else{
                        std::cout << player2.name << "'s turn" << std::endl;
                    }
                }
        
                break;
            case 3:
                checkWinComputerVsComputer( board[ROWS][COLUMNS], player1, player2, turn );{
                    if (turn % 2 == 0){
                        std::cout << player1.name << "'s turn" << std::endl;
                    }
                    else{
                        std::cout << player2.name << "'s turn" << std::endl;
                    }
                }
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
        }
    } while (choice != 1 || choice != 2 || choice != 3);
     
};
void checkWinUserVsUser( char board[ROWS][COLUMNS], Player player1, Player player2, int turn){
    int  ROWS, COLUMNS;
    int choice;
    std::cout << "Welcome to Forza 4!" << std::endl;
    std::cout << "Choose the game mode:" << std::endl;
    std::cout << "1. User vs User" << std::endl;
    std::cout << "2. User vs Computer" << std::endl;
    std::cout << "3. Computer vs Computer" << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;

    do {
        
        while (choice == 1){
            checkWinUserVsUser( board[ROWS][COLUMNS], player1, player2, turn );{
                if (turn % 2 == 0){
                    std::cout << player1.name << "'s turn" << std::endl;
                }
                else{
                    std::cout << player2.name << "'s turn" << std::endl;
                }
            }
        }
    } while (choice != 1 || choice != 2 || choice != 3);
     if (choice == 2){
        checkWinUserVsComputer( board[ROWS][COLUMNS], player1, player2, turn );{
            if (turn % 2 == 0){
                std::cout << player1.name << "'s turn" << std::endl;
            }
            else{
                std::cout << player2.name << "'s turn" << std::endl;
            }
        }
    }
    else if (choice == 3){
        checkWinComputerVsComputer( board[ROWS][COLUMNS], player1, player2, turn );{
            if (turn % 2 == 0){
                std::cout << player1.name << "'s turn" << std::endl;
            }
            else{
                std::cout << player2.name << "'s turn" << std::endl;
            }
        }
    }
   return WIN;
     
};
void checkWinUserVsComputer( char board[ROWS][COLUMNS], Player player1, Player player2, int turn){
    int  ROWS, COLUMNS;
    int choice;
    std::cout << "Welcome to Forza 4!" << std::endl;
    std::cout << "Choose the game mode:" << std::endl;
    std::cout << "1. User vs User" << std::endl;
    std::cout << "2. User vs Computer" << std::endl;
    std::cout << "3. Computer vs Computer" << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;

    do {
        
        while (choice == 1){
            checkWinUserVsUser( board[ROWS][COLUMNS], player1, player2, turn );{
                if (turn % 2 == 0){
                    std::cout << player1.name << "'s turn" << std::endl;
                }
                else{
                    std::cout << player2.name << "'s turn" << std::endl;
                }
            }
        }
    } while (choice != 1 || choice != 2 || choice != 3);
     if (choice == 2){
        checkWinUserVsComputer( board[ROWS][COLUMNS], player1, player2, turn );{
            if (turn % 2 == 0){
                std::cout << player1.name << "'s turn" << std::endl;
            }
            else{
                std::cout << player2.name << "'s turn" << std::endl;
            }
        }
    }
    else if (choice == 3){
        checkWinComputerVsComputer( board[ROWS][COLUMNS], player1, player2, turn );{
            if (turn % 2 == 0){
                std::cout << player1.name << "'s turn" << std::endl;
            }
            else{
                std::cout << player2.name << "'s turn" << std::endl;
            }
        }
    }
   return WIN;
     
};
//void checkWinComputerVsComputer();
void checkDraw( char board[ROWS][COLUMNS], Player player1, Player player2, int turn){
    int  ROWS, COLUMNS;
    int choice;
    std::cout << "Welcome to Forza 4!" << std::endl;
    std::cout << "Choose the game mode:" << std::endl;
    std::cout << "1. User vs User" << std::endl;
    std::cout << "2. User vs Computer" << std::endl;
    std::cout << "3. Computer vs Computer" << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;

    do {
        
        while (choice == 1){
            checkWinUserVsUser( board[ROWS][COLUMNS], player1, player2, turn );{
                if (turn % 2 == 0){
                    std::cout << player1.name << "'s turn" << std::endl;
                }
                else{
                    std::cout << player2.name << "'s turn" << std::endl;
                }
            }
        }
    } while (choice != 1 || choice != 2 || choice != 3);
     if (choice == 2){
        checkWinUserVsComputer( board[ROWS][COLUMNS], player1, player2, turn );{
            if (turn % 2 == 0){
                std::cout << player1.name << "'s turn" << std::endl;
            }
            else{
                std::cout << player2.name << "'s turn" << std::endl;
            }
        }
    }
    else if (choice == 3){
        checkWinComputerVsComputer( board[ROWS][COLUMNS], player1, player2, turn );{
            if (turn % 2 == 0){
                std::cout << player1.name << "'s turn" << std::endl;
            }
            else{
                std::cout << player2.name << "'s turn" << std::endl;
            }
        }
    }
   return DRAW;
     
};
void checkDrawUserVsUser( char board[ROWS][COLUMNS], Player player1, Player player2, int turn){
    int  ROWS, COLUMNS;
    int choice;
    std::cout << "Welcome to Forza 4!" << std::endl;
    std::cout << "Choose the game mode:" << std::endl;
    std::cout << "1. User vs User" << std::endl;
    std::cout << "2. User vs Computer" << std::endl;
    std::cout << "3. Computer vs Computer" << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;

    do {
        
        while (choice == 1){
            checkWinUserVsUser( board[ROWS][COLUMNS], player1, player2, turn );{
                if (turn % 2 == 0){
                    std::cout << player1.name << "'s turn" << std::endl;
                }
                else{
                    std::cout << player2.name << "'s turn" << std::endl;
                }
            }
        }
    } while (choice != 1 || choice != 2 || choice != 3);
     if (choice == 2){
        checkWinUserVsComputer( board[ROWS][COLUMNS], player1, player2, turn );{
            if (turn % 2 == 0){
                std::cout << player1.name << "'s turn" << std::endl;
            }
            else{
                std::cout << player2.name << "'s turn" << std::endl;
            }
        }
    }
    else if (choice == 3){
        checkWinComputerVsComputer( board[ROWS][COLUMNS], player1, player2, turn );{
            if (turn % 2 == 0){
                std::cout << player1.name << "'s turn" << std::endl;
            }
            else{
                std::cout << player2.name << "'s turn" << std::endl;
            }
        }
    }
   return DRAW;
     
};
void checkDrawUserVsComputer( char board[ROWS][COLUMNS], Player player1, Player player2, int turn){
    int  ROWS, COLUMNS;
    int choice;
    std::cout << "Welcome to Forza 4!" << std::endl;
    std::cout << "Choose the game mode:" << std::endl;
    std::cout << "1. User vs User" << std::endl;
    std::cout << "2. User vs Computer" << std::endl;
    std::cout << "3. Computer vs Computer" << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;

    do {
        
        while (choice == 1){
            checkWinUserVsUser( board[ROWS][COLUMNS], player1, player2, turn );{
                if (turn % 2 == 0){
                    std::cout << player1.name << "'s turn" << std::endl;
                }
                else{
                    std::cout << player2.name << "'s turn" << std::endl;
                }
            }
        }
    } while (choice != 1 || choice != 2 || choice != 3);
     if (choice == 2){
        checkWinUserVsComputer( board[ROWS][COLUMNS], player1, player2, turn );{
            if (turn % 2 == 0){
                std::cout << player1.name << "'s turn" << std::endl;
            }
            else{
                std::cout << player2.name << "'s turn" << std::endl;
            }
        }
    }
    else if (choice == 3){
        checkWinComputerVsComputer( board[ROWS][COLUMNS], player1, player2, turn );{
            if (turn % 2 == 0){
                std::cout << player1.name << "'s turn" << std::endl;
            }
            else{
                std::cout << player2.name << "'s turn" << std::endl;
            }
        }
    }
   return DRAW;
     
};
//void checkDrawComputerVsComputer();
void resetBoard( char board[ROWS][COLUMNS] ){
    int ROWS, COLUMNS;
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLUMNS; j++){
            board[i][j] = ' ';
        }
    }
};
void resetBoardUserVsUser( char board[ROWS][COLUMNS] ){
    int ROWS, COLUMNS;
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLUMNS; j++){
            board[i][j] = ' ';
        }
    }
};
void resetBoardUserVsComputer( char board[ROWS][COLUMNS] ){
    int ROWS, COLUMNS;
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLUMNS; j++){
            board[i][j] = ' ';
        }
    }
};
//void resetBoardComputerVsComputer();
void resetGame( char board[ROWS][COLUMNS], Player player1, Player player2, int turn ){
    int ROWS, COLUMNS;
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLUMNS; j++){
            board[i][j] = ' ';
        }
    }
    turn = 0;
    player1.name = "Player 1";
    player1.symbol = 'X';
    player2.name = "Player 2";
    player2.symbol = 'O';
};
void resetGameUserVsUser( char board[ROWS][COLUMNS], Player player1, Player player2, int turn ){
    int ROWS, COLUMNS;
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLUMNS; j++){
            board[i][j] = ' ';
        }
    }
    turn = 0;
    player1.name = "Player 1";
    player1.symbol = 'X';
    player2.name = "Player 2";
    player2.symbol = 'O';
};
void resetGameUserVsComputer( char board[ROWS][COLUMNS], Player player1, Player player2, int turn ){
    int ROWS, COLUMNS;
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLUMNS; j++){
            board[i][j] = ' ';
        }
    }
    turn = 0;
    player1.name = "Player 1";
    player1.symbol = 'X';
    player2.name = "Player 2";
    player2.symbol = 'O';
};
//void resetGameComputerVsComputer();

// Main function

int main()
{
    int choice;

    std::cout << "Welcome to Forza 4!" << std::endl;
    std::cout << "Choose the game mode:" << std::endl;
    std::cout << "1. User vs User" << std::endl;
    std::cout << "2. User vs Computer" << std::endl;
    std::cout << "3. Computer vs Computer" << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;

    do {
        
        while (choice == 1){
            checkWinUserVsUser( board[ROWS][COLUMNS], player1, player2, turn );{
                if (turn % 2 == 0){
                    std::cout << player1.name << "'s turn" << std::endl;
                }
                else{
                    std::cout << player2.name << "'s turn" << std::endl;
                }
            }
        }
    } while (choice != 1 || choice != 2 || choice != 3);
     if (choice == 2){
        checkWinUserVsComputer( board[ROWS][COLUMNS], player1, player2, turn );{
            if (turn % 2 == 0){
                std::cout << player1.name << "'s turn" << std::endl;
            }
            else{
                std::cout << player2.name << "'s turn" << std::endl;
            }
        }
    }
    else if (choice == 3){
        checkWinComputerVsComputer( board[ROWS][COLUMNS], player1, player2, turn );{
            if (turn % 2 == 0){
                std::cout << player1.name << "'s turn" << std::endl;
            }
            else{
                std::cout << player2.name << "'s turn" << std::endl;
            }
        }
    }
    return WIN;
}
