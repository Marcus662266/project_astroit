#include <iostream>
#include <string>
#include <array>
#include <random>
#include <vector>
 
using namespace std;

void stampaTabella(char tabella);


 
int main () {
 
 
 
    int r,a,b,c,d,w;
    char tabella[6][7] ;
    int cont1=0,cont2=0,turno=0;
    int inizio();
    int difesa();
    int pc ();
    char colonna;
    int alte;
 
 
 
//Orizzontale
 
    for ( r = 0; r < 6 ; r++) {
        for (a=0,b=1,c=2,d=3 ; d<7 ; a++,b++,c++,d++) {
 
            if (tabella[r][a]=='X' && tabella[r][b]=='X' && tabella[r][c]=='X' && tabella[r][d]==0)
            {
                for(w=0; w<=r; w++)
                {
                    if(tabella[w][d]=0)
                    {
                        if(w==r)
                        {
                            tabella[w][d]=='O';cont2++; turno=0; inizio (); break;
                        }else{
                            break;
                        }
                    }
                }
            }
 
 
            if (tabella[r][a]=='X' && tabella[r][b]=='X' && tabella[r][c]==0 && tabella[r][d]=='X')
            {
                for(w=0; w<=r; w++)
                {
                    if(tabella[w][c]=0)
                    {
                        if(w==r)
                        {
                            tabella[w][c]=='O';cont2++; turno=0; inizio (); break;
                        }else{
                            break;
                        }
                    }
                }
            }
 
            if (tabella[r][a]=='X' && tabella[r][b]==0 && tabella[r][c]=='X' && tabella[r][d]=='X')
            {
                for(w=0; w<=r; w++)
                {
                    if(tabella[w][b]=0)
                    {
                        if(w==r)
                        {
                            tabella[w][b]=='O';cont2++; turno=0; inizio (); break;
                        }else{
                            break;
                        }
                    }
                }
            }
 
            if (tabella[r][a]==0 && tabella[r][b]=='X' && tabella[r][c]=='X' && tabella[r][d]=='X')
            {
                for(w=0; w<=r; w++)
                {
                    if(tabella[w][a]=0)
                    {
                        if(w==r)
                        {
                            tabella[w][a]=='O';cont2++; turno=0; inizio (); break;
                        }else{
                            break;
                        }
                    }
                }
            }
 
        }
    }
 
//Verticale
    for (r = 0 ; r < 7 ; r++) {
        for (a=0,b=1,c=2,d=3 ; d<6 ; a++,b++,c++,d++) {
            if (tabella[a][r]=='X' && tabella[b][r]=='X' && tabella[c][r]=='X' && tabella[d][r]==0)
            {
                tabella[d][r]='O'; cont2++; turno=0; inizio (); break;
            }
 
            if (tabella[a][r]=='X' && tabella[b][r]=='X' && tabella[c][r]==0 && tabella[d][r]=='X')
            {
                tabella[c][r]='O'; cont2++; turno=0; inizio (); break;
            }
            if (tabella[a][r]=='X' && tabella[b][r]==0 && tabella[c][r]=='X'&& tabella[d][r]=='X')
            {
                tabella[b][r]='O'; cont2++; turno=0; inizio (); break;
            }
 
            if (tabella[a][r]==0 && tabella[b][r]=='X' && tabella[c][r]=='X'&& tabella[d][r]=='X')
            {
                tabella[a][r]='O'; cont2++; turno=0; inizio (); break;
            }
        }
    }
 
 
//Diagonale [VersoDestra]
    for (r = 0 ; r < 3 ; r++) {
        for (a=0,b=1,c=2,d=3 ; d<7 ; a++,b++,c++,d++) {
            if (tabella[r][a]=='X' && tabella[r+1][b]=='X' && tabella[r+2][c]=='X' && tabella[r+3][d]==0)
            {
                for(w=0; w<=r+3; w++)
                {
                    if(tabella[w][d]=0)
                    {
                        if(w==r+3)
                        {
                            tabella[w][d]=='O';cont2++; turno=0; inizio (); break;
                        }else{
                            break;
                        }
                    }
                }
            }
 
 
 
            if (tabella[r][a]=='X' && tabella[r+1][b]=='X' && tabella[r+2][c]==0 && tabella[r+3][d]=='X')
            {
                for(w=0; w<=r+2; w++)
                {
                    if(tabella[w][c]=0)
                    {
                        if(w==r+2)
                        {
                            tabella[w][c]=='O';cont2++; turno=0; inizio (); break;
                        }else{
                            break;
                        }
                    }
                }
            }
 
            if (tabella[r][a]=='X' && tabella[r+1][b]==0 && tabella[r+2][c]=='X' && tabella[r+3][d]=='X')
            {
                for(w=0; w<=r+1; w++)
                {
                    if(tabella[w][b]=0)
                    {
                        if(w==r+1)
                        {
                            tabella[w][b]=='O';cont2++; turno=0; inizio (); break;
                        }else{
                            break;
                        }
                    }
                }
            }
 
            if (tabella[r][a]==0 && tabella[r+1][b]=='X' && tabella[r+2][c]=='X' && tabella[r+3][d]=='X')
            {
                for(w=0; w<=r; w++)
                {
                    if(tabella[w][a]=0)
                    {
                        if(w==r)
                        {
                            tabella[w][a]=='O';cont2++; turno=0; inizio (); break;
                        }else{
                            break;
                        }
                    }
                }
            }
        }
    }
 
//Diagonale [VersoSinistra]
    for (r = 0 ; r < 3 ; r++) {
        for (a=3,b=4,c=5,d=6 ; a>=0 ; a--,b--,c--,d--) {
            if (tabella[r][d]=='X' && tabella[r+1][c]=='X' && tabella[r+2][b]=='X' && tabella[r+3][a]==0)
            {
                for(w=0; w<=r+3; w++)
                {
                    if(tabella[w][a]=0)
                    {
                        if(w==r+3)
                        {
                            tabella[w][a]=='O';cont2++; turno=0; inizio (); break;
                        }else{
                            break;
                        }
                    }
                }
            }
 
 
            if (tabella[r][d]=='X' && tabella[r+1][c]=='X' && tabella[r+2][b]==0 && tabella[r+3][a]=='X')
            {
                for(w=0; w<=r+2; w++)
                {
                    if(tabella[w][b]=0)
                    {
                        if(w==r+2)
                        {
                            tabella[w][b]=='O';cont2++; turno=0; inizio (); break;
                        }else{
                            break;
                        }
                    }
                }
            }
 
            if (tabella[r][d]=='X' && tabella[r+1][c]==0 && tabella[r+2][b]=='X' && tabella[r+3][a]=='X')
            {
                for(w=0; w<=r+1; w++)
                {
                    if(tabella[w][c]=0)
                    {
                        if(w==r+1)
                        {
                            tabella[w][c]=='O';cont2++; turno=0; inizio (); break;
                        }else{
                            break;
                        }
                    }
                }
            }
 
            if (tabella[r][d]==0 && tabella[r+1][c]=='X' && tabella[r+2][b]=='X' && tabella[r+3][a]=='X')
            {
                for(w=0; w<=r; w++)
                {
                    if(tabella[w][d]=0)
                    {
                        if(w==r)
                        {
                            tabella[w][d]=='O';cont2++; turno=0; inizio (); break;
                        }else{
                            break;
                        }
                    }
                }
            }
        }
    }
 
   /// ATTACCO///
 
 
//Orizzontale
 
    for ( r = 0; r < 6 ; r++) {
        for (a=0,b=1,c=2,d=3 ; d<7 ; a++,b++,c++,d++) {
 
            if (tabella[r][a]=='O' && tabella[r][b]=='O' && tabella[r][c]=='O' && tabella[r][d]==0)
            {
                for(w=0; w<=r; w++)
                {
                    if(tabella[w][d]=0)
                    {
                        if(w==r)
                        {
                            tabella[w][d]=='O';cont2++; turno=0; inizio (); break;
                        }else{
                            break;
                        }
                    }
                }
            }
 
 
            if (tabella[r][a]=='O' && tabella[r][b]=='O' && tabella[r][c]==0 && tabella[r][d]=='O')
            {
                for(w=0; w<=r; w++)
                {
                    if(tabella[w][c]=0)
                    {
                        if(w==r)
                        {
                            tabella[w][c]=='O';cont2++; turno=0; inizio (); break;
                        }else{
                            break;
                        }
                    }
                }
            }
 
            if (tabella[r][a]=='O' && tabella[r][b]==0 && tabella[r][c]=='O' && tabella[r][d]=='O')
            {
                for(w=0; w<=r; w++)
                {
                    if(tabella[w][b]=0)
                    {
                        if(w==r)
                        {
                            tabella[w][b]=='O';cont2++; turno=0; inizio (); break;
                        }else{
                            break;
                        }
                    }
                }
            }
 
            if (tabella[r][a]==0 && tabella[r][b]=='O' && tabella[r][c]=='O' && tabella[r][d]=='O')
            {
                for(w=0; w<=r; w++)
                {
                    if(tabella[w][a]=0)
                    {
                        if(w==r)
                        {
                            tabella[w][a]=='O';cont2++; turno=0; inizio (); break;
                        }else{
                            break;
                        }
                    }
                }
            }
 
        }
    }
 
//Verticale
    for (r = 0 ; r < 7 ; r++) {
        for (a=0,b=1,c=2,d=3 ; d<6 ; a++,b++,c++,d++) {
            if (tabella[a][r]=='O' && tabella[b][r]=='O' && tabella[c][r]=='O' && tabella[d][r]==0)
            {
                tabella[d][r]='O'; cont2++; turno=0; inizio (); break;
            }
 
            if (tabella[a][r]=='O' && tabella[b][r]=='O' && tabella[c][r]==0 && tabella[d][r]=='O')
            {
                tabella[c][r]='O'; cont2++; turno=0; inizio (); break;
            }
            if (tabella[a][r]=='O' && tabella[b][r]==0 && tabella[c][r]=='O'&& tabella[d][r]=='O')
            {
                tabella[b][r]='O'; cont2++; turno=0; inizio (); break;
            }
 
            if (tabella[a][r]==0 && tabella[b][r]=='O' && tabella[c][r]=='O'&& tabella[d][r]=='O')
            {
                tabella[a][r]='O'; cont2++; turno=0; inizio (); break;
            }
        }
    }
 
 
//Diagonale [VersoDestra]
    for (r = 0 ; r < 3 ; r++) {
        for (a=0,b=1,c=2,d=3 ; d<7 ; a++,b++,c++,d++) {
            if (tabella[r][a]=='O' && tabella[r+1][b]=='O' && tabella[r+2][c]=='O' && tabella[r+3][d]==0)
            {
                for(w=0; w<=r+3; w++)
                {
                    if(tabella[w][d]=0)
                    {
                        if(w==r+3)
                        {
                            tabella[w][d]=='O';cont2++; turno=0; inizio (); break;
                        }else{
                            break;
                        }
                    }
                }
            }
 
 
 
            if (tabella[r][a]=='O' && tabella[r+1][b]=='O' && tabella[r+2][c]==0 && tabella[r+3][d]=='O')
            {
                for(w=0; w<=r+2; w++)
                {
                    if(tabella[w][c]=0)
                    {
                        if(w==r+2)
                        {
                            tabella[w][c]=='O';cont2++; turno=0; inizio (); break;
                        }else{
                            break;
                        }
                    }
                }
            }
 
            if (tabella[r][a]=='O' && tabella[r+1][b]==0 && tabella[r+2][c]=='O' && tabella[r+3][d]=='O')
            {
                for(w=0; w<=r+1; w++)
                {
                    if(tabella[w][b]=0)
                    {
                        if(w==r+1)
                        {
                            tabella[w][b]=='O';cont2++; turno=0; inizio (); break;
                        }else{
                            break;
                        }
                    }
                }
            }
 
            if (tabella[r][a]==0 && tabella[r+1][b]=='O' && tabella[r+2][c]=='O' && tabella[r+3][d]=='O')
            {
                for(w=0; w<=r; w++)
                {
                    if(tabella[w][a]=0)
                    {
                        if(w==r)
                        {
                            tabella[w][a]=='O';cont2++; turno=0; inizio (); break;
                        }else{
                            break;
                        }
                    }
                }
            }
        }
    }
 
//Diagonale [VersoSinistra]
    for (r = 0 ; r < 3 ; r++) {
        for (a=3,b=4,c=5,d=6 ; a>=0 ; a--,b--,c--,d--) {
            if (tabella[r][d]=='O' && tabella[r+1][c]=='O' && tabella[r+2][b]=='O' && tabella[r+3][a]==0)
            {
                for(w=0; w<=r+3; w++)
                {
                    if(tabella[w][a]=0)
                    {
                        if(w==r+3)
                        {
                            tabella[w][a]=='O';cont2++; turno=0; inizio (); break;
                        }else{
                            break;
                        }
                    }
                }
            }
 
 
            if (tabella[r][d]=='O' && tabella[r+1][c]=='O' && tabella[r+2][b]==0 && tabella[r+3][a]=='O')
            {
                for(w=0; w<=r+2; w++)
                {
                    if(tabella[w][b]=0)
                    {
                        if(w==r+2)
                        {
                            tabella[w][b]=='O';cont2++; turno=0; inizio (); break;
                        }else{
                            break;
                        }
                    }
                }
            }
 
            if (tabella[r][d]=='O' && tabella[r+1][c]==0 && tabella[r+2][b]=='O' && tabella[r+3][a]=='O')
            {
                for(w=0; w<=r+1; w++)
                {
                    if(tabella[w][c]=0)
                    {
                        if(w==r+1)
                        {
                            tabella[w][c]=='O';cont2++; turno=0; inizio (); break;
                        }else{
                            break;
                        }
                    }
                }
            }
 
            if (tabella[r][d]==0 && tabella[r+1][c]=='O' && tabella[r+2][b]=='O' && tabella[r+3][a]=='O')
            {
                for(w=0; w<=r; w++)
                {
                    if(tabella[w][d]=0)
                    {
                        if(w==r)
                        {
                            tabella[w][d]=='O';cont2++; turno=0; inizio (); break;
                        }else{
                            break;
                        }
                    }
                }
            }
        }
    }
 
 
 
///CASO///
 
 
    colonna = rand() % 7;
    while (colonna < 0 || colonna > 7);
    for (alte=0;alte<6;alte++) {
        if (tabella[alte][colonna]==0) { tabella[alte][colonna] = 'O'; cont2++; turno=0; inizio (); break;}
    }
    cout << "\n\nQuesta colonna e' piena!\n\n";
    pc ();
 
}
