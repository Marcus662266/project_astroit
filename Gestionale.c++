#include <iostream>
#include <fstream>
#include "Utente.h"

using namespace std;

int main()
{

    cout << "Inserisci il tuo nome: " << endl;
    string nome;
    cin >> nome;
    int punteggio;

    // apro il file
    ifstream fileUtenti;
    fileUtenti.open("utenti.txt");

    // cerco il nome
    string riga;
    bool nuovo = true;
    while (getline(fileUtenti, riga))
    {
        if (riga == nome)
        {
            // trovato
            nuovo = false;
            getline(fileUtenti, riga);
            punteggio = stoi(riga);
            break;
        }
    }
    fileUtenti.close();

    // se non lo trovo lo creo
    if (nuovo)
    {
        punteggio = 0;
    }

    Utente giocatore = Utente(nome, punteggio);

    // faccio la partita
    //...


    // // fine partita
    giocatore.finePartita();
    // // incremento punteggio
    giocatore.incrementaPunteggio(10);

    // // vedere nome
    cout << giocatore.getNome() << endl;
    // // vedere il punteggio
    cout << giocatore.getPunteggio() << endl;
    
    // // vedere partite giocate
    cout << giocatore.getPartite() << endl;

    // salvo il punteggio

    if (nuovo)
    {
        // nuovo giocatore, aggiungo alla fine
        // leggo vecchio file
        ifstream fileUtenti2;
        ofstream fileTemporaneoS;
        fileTemporaneoS.open("utentiTemp.txt");
        fileUtenti2.open("utenti.txt");
        while (getline(fileUtenti2, riga))
        {
            fileTemporaneoS << riga << endl;
        }
        fileTemporaneoS << giocatore.getNome() << endl;
        fileTemporaneoS << giocatore.getPunteggio() << endl;

        fileUtenti2.close();
        fileTemporaneoS.close();

        ifstream fileTemporaneoL;
        ofstream fileUtentiFinal;

        fileTemporaneoL.open("utentiTemp.txt");
        fileUtentiFinal.open("utenti.txt");

        while (getline(fileTemporaneoL, riga))
        {
            fileUtentiFinal << riga << endl;
        }

        fileTemporaneoL.close();
        fileUtentiFinal.close();
    }
    else
    {

        // giocatore con esperienza, modifico il punteggio
        // leggo vecchio file
        ifstream fileUtenti2;
        ofstream fileTemporaneoS;
        fileTemporaneoS.open("utentiTemp.txt");
        fileUtenti2.open("utenti.txt");
        while (getline(fileUtenti2, riga))
        {
            if (riga == giocatore.getNome())
            {
                fileTemporaneoS << riga << endl;
                fileTemporaneoS << giocatore.getPunteggio() << endl;
                getline(fileUtenti2, riga);
            }
            else
            {
                fileTemporaneoS << riga << endl;
            }
        }

        fileUtenti2.close();
        fileTemporaneoS.close();

        ifstream fileTemporaneoL;
        ofstream fileUtentiFinal;

        fileTemporaneoL.open("utentiTemp.txt");
        fileUtentiFinal.open("utenti.txt");

        while (getline(fileTemporaneoL, riga))
        {
            fileUtentiFinal << riga << endl;
        }

        fileTemporaneoL.close();
        fileUtentiFinal.close();
    }
}
