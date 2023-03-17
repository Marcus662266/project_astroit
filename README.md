# project_astroit
===Progetto For(za4)===


# Introduzione

Questo progetto viene realizzato per il corso di ingegneria del software della società ASTROIT.
Il progetto consiste nella creazione del gioco "Forza 4", nel quale sarà possibile giocare in locale o in rete.
Il programma viene creato in C++ utilizzando:

# Librerie adoperate durante il corso:
                                        - <iostream>
                                        - <string>
                                        - <array>
                                        - <random>
                                        - <vector>

 ========================================================  
| READY TO PLAY....                                      | 
|      _______  _______  ____________     ____      ___  | 
|     /  ____/ / ___  / / __  /__   /    /    |    /   | | 
|    /  /___  / /  / / / /_/ /  /  /    /     |   / /| | | 
|   /  ____/ / /  / / /  _  /  /  /    /  /|  |  / /_| | | 
|  /  /     / /__/ / /  / | | /  /___ /  / |  | /____  | | 
| /__/     /______/ /__/  |_|/______//__/  |__|      |_| | 
 ========================================================  
                        Create by... Serge, Marco, Jacopo  

L'obiettivo di ogni giocatore (G1,G2) è quello di mettere in fila quattro pedine proprie (X,O). La scacchiera rettangolare è posta in orizzontale. 
Il gioco termina automaticamente (il programma effetua il controllo) quando uno dei giocatori ha messo in fila quattro delle sue pedine in verticale o in diagonale o in orizzontale.

# vittoria in diagonale (X)
-------------------------------------------------
|  -  ||  -  ||  -  ||  -  ||  -  ||  -  ||  -  |    

|  -  ||  -  ||  -  ||  -  ||  -  ||  -  ||  -  |

|  -  ||  -  ||  -  ||  X  ||  -  ||  -  ||  -  |

|  -  ||  X  ||  X  ||  O  ||  -  ||  -  ||  -  |

|  O  ||  X  ||  O  ||  O  ||  -  ||  -  ||  -  |

|  X  ||  O  ||  O  ||  X  ||  -  ||  -  ||  -  |
-------------------------------------------------
   1      2      3      4      5      6      7   

# vittoria in orizzontale (x)
-------------------------------------------------
|  -  ||  -  ||  -  ||  -  ||  -  ||  -  ||  -  |    

|  -  ||  -  ||  -  ||  -  ||  -  ||  -  ||  -  |

|  -  ||  -  ||  -  ||  -  ||  -  ||  -  ||  -  |

|  X  ||  X  ||  X  ||  X  ||  -  ||  -  ||  -  |

|  X  ||  O  ||  O  ||  O  ||  -  ||  -  ||  -  |

|  X  ||  O  ||  O  ||  X  ||  -  ||  -  ||  -  |
-------------------------------------------------
   1      2      3      4      5      6      7   

# vittoria in verticale (X)
-------------------------------------------------
|  -  ||  -  ||  -  ||  -  ||  -  ||  -  ||  -  |    

|  -  ||  -  ||  -  ||  -  ||  -  ||  -  ||  -  |

|  X  ||  -  ||  -  ||  -  ||  -  ||  -  ||  -  |

|  X  ||  X  ||  X  ||  O  ||  -  ||  -  ||  -  |

|  X  ||  O  ||  O  ||  O  ||  -  ||  -  ||  -  |

|  X  ||  O  ||  O  ||  X  ||  -  ||  -  ||  -  |
-------------------------------------------------
   1      2      3      4      5      6      7   

                     Grazie per aver scaricato questo progetto. 
                                Buon divertimento a presto.
