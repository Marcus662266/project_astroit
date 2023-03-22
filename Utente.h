#ifndef UTENTE_H
#define UTENTE_H

using namespace std;

class Utente
{
private:
    string nome;
    int punteggio;
    int partite;

public:
    // costruttore
    Utente(string n, int p)
    {
        nome = n;
        punteggio = p;
        partite = 0;
    }

    string getNome()
    {
        return nome;
    }
    int getPunteggio()
    {
        return punteggio;
    }

    void incrementaPunteggio(int punti)
    {
        punteggio += punti;
    }

    void finePartita()
    {
        partite++;
    }

    int getPartite()
    {
        return partite;
    }
};
#endif
