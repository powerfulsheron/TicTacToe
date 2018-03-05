#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <setjmp.h> 

using namespace std;
//string tabcoupsrestants[8] abandonné car je n'ai pas réussi à assigner les deux indices dans une case tableau, mais mon aléatoire fonctionne bien.
void Initialiser(char tableau[3][3]); // Prototype de l'initialisation du jeu
int RandMinMax(int Min, int Max); // Prototype du random
void Afficher(char tableau[3][3]);// Prototype d'affichage du jeu
void Remplir(char tableau[3][3]);// Prototype de remplissage du tableau
void SaisieJoueur(char tableau[3][3],char pionJoueur); // Prototype de saisie
void JeuOrdinateur(char tableau[3][3],char pionOrdinateur); // Prototype du jeu ordinateur.
void ModeOffensif(char tableau[3][3],char pionOrdinateur,char pionJoueur); // Prototype du mode offensif.
void ModeDefensif(char tableau[3][3],char pionOrdinateur,char pionJoueur);// Prototype du mode defensif.
void PremierJoueur(char &pionOrdinateur,char &pionJoueur); // Prototype de la définition du premier joueur
void JouerOffensif(char tableau[3][3], char pionOrdinateur, char pionJoueur);// Prototype du mode offensif
void JouerDefensif(char tableau[3][3], char pionOrdinateur, char pionJoueur);//Prototype du mode defensif
void Jouer(char tableau[3][3], char pionOrdinateur, char pionJoueur); // void CoupsRestants(char tableau[2][2]); // std string ne reconnait pas la méthode to_string, pour pouvoir assigner les indices du morpion dans une case tableau ... j'ai laissé un random mais qui fonctionne bien.
bool IsGagne(char tableau[3][3],char pionJoueur,char pionOrdinateur); // Prototype du test si le jeu est gagné ou non 

int main(){
setlocale(LC_ALL, "");
int choix;
cout<<"Bienvenue dans le morpion\n\n\n1. Jouer contre l'ordinateur en mode aléatoire\n2. Jouer contre l'ordinateur en mode défensif \n3. Jouer contre l'ordinateur en mode Offensif\n4. Quitter\n\nVotre choix ? ";
cin>>choix;
char tableau[3][3], pionOrdinateur='a',pionJoueur='b';
switch(choix){
              
              case 1: // Mode aléatoire
                   system("CLS");
                   Initialiser(tableau);
                   PremierJoueur(pionOrdinateur,pionJoueur);
                   do{
                   Jouer(tableau,pionOrdinateur,pionJoueur);
                   }while((IsGagne(tableau,pionJoueur,pionOrdinateur)==false));
              case 2: // Mode Défensif
                   system("CLS");
                   Initialiser(tableau);
                   PremierJoueur(pionOrdinateur,pionJoueur);
                   do{
                   JouerDefensif(tableau,pionOrdinateur,pionJoueur);
                   }while((IsGagne(tableau,pionJoueur,pionOrdinateur)==false));
              case 3: // Mode Offensif
                   system("CLS");
                   Initialiser(tableau);
                   PremierJoueur(pionOrdinateur,pionJoueur);
                   do{
                   JouerOffensif(tableau,pionOrdinateur,pionJoueur);
                   }while((IsGagne(tableau,pionJoueur,pionOrdinateur)==false));
              case 4:
                   cout<<"\n\nA plus dans le bus !\n\n";
                   system("PAUSE");
                   return EXIT_SUCCESS;  
              }


} // Fin du Main();

int RandMinMax(int Min, int Max) // fonction random
{
srand(time(NULL));
return (Min + rand() % (Max - Min));
}

void Afficher(char tableau[3][3]){ // affiche le morpion
    cout<<" " ;
    cout<< "    a    b    c    \n";
    cout<< "    ____ ____ ____ \n " ;
    cout<< "  |    |    |    | \n " ;
    cout<< "1 |  "<< tableau[0][0] <<" |  "<< tableau[1][0] <<" |  "<< tableau[2][0] <<" | \n ";
    cout<< "  |____|____|____| \n " ;
    cout<< "  |    |    |    | \n " ;
    cout<< "2 |  "<< tableau[0][1] <<" |  "<< tableau[1][1] <<" |  "<< tableau[2][1] <<" | \n ";
    cout<< "  |____|____|____| \n " ;
    cout<< "  |    |    |    | \n " ;
    cout<< "3 |  "<< tableau[0][2] <<" |  "<< tableau[1][2] <<" |  "<< tableau[2][2] <<" | \n ";
    cout<< "  |____|____|____| \n \n" ;
}
     
void Remplir(char tableau[3][3]){ // initialise le morpion
for (int ligne=0; ligne<3;ligne++) {
    for(int colone=0;colone<3;colone++){
            tableau[ligne][colone]=' ';
            }
            }
}

void Initialiser(char tableau[3][3]){ // initialise le jeu 
     cout<<"Initilisation du jeu : \n\n";
          Remplir(tableau);
          Afficher(tableau);
          }
          
void PremierJoueur(char &pionOrdinateur,char &pionJoueur){ //  On défini juste le premier joueur et les pions respectifs.
     if (RandMinMax(1,3)==1){
                            pionOrdinateur='X';
                            pionJoueur='O';
                            cout<<"L'ordinateur sera le premier joueur avec les 'X'\n\n";
                            system("PAUSE");
                            }
     else{
         pionOrdinateur='O';
         pionJoueur='X';
         cout<<"Vous serez le premier joueur avec les 'X'\n\n";
         }      
}

void JeuOrdinateur(char tableau[3][3],char pionOrdinateur){ // Mode aléatoire de l'ordi
cout<<"l'odinateur joue\n";
int colone,ligne;
bool flag = false;
while(flag==false){ //Tant que la case random n'est pas ' ' , l'ordinateur ne place pas son pion.
colone=rand()%3;    //RandMinMax(0,3); Marche mieux sans la fonction car le srand(time(NULL)) ralentis les descisions de l'ordinateur.
ligne=rand()%3;     //RandMinMax(0,3);  Marche mieux sans la fonction
if(tableau[colone][ligne]==' '){ 
              tableau[colone][ligne]=pionOrdinateur; 
              flag=true;
              system("CLS");
               }  
}       
Afficher(tableau);
}
    
void SaisieJoueur(char tableau[3][3], char pionJoueur){ // saisie du joueur
     string saisie;
     saisie:
     cout<<"\nOu voulez vous jouer ? (Lettre,chiffre)";
     cin.clear();
     cin>>saisie;
     cin.clear();  
     char saisie1=saisie[0];
     char saisie2=saisie[1]; // on décompose la saisie en deux charactère et on analyse
     int ligne,colone;
     if(saisie1=='a'){colone=0;}
     else if(saisie1=='b'){colone=1;}
     else if(saisie1=='c'){colone=2;}
     if(saisie2=='1'){ligne=0;}
     else if(saisie2=='2'){ligne=1;}
     else if(saisie2=='3'){ligne=2;}
     if(tableau[colone][ligne]!=' '){ // Controle de la saisie
                                         cout<<"\nLa case que vous avez choisie est déja remplie, veuillez resaisir.\n";
                                         goto saisie;
                                         }
     system("CLS");
     tableau[colone][ligne]=pionJoueur;
     Afficher(tableau);
     }

void JouerDefensif(char tableau[3][3], char pionOrdinateur, char pionJoueur){ // Déroulement d'une partie en mode Defensif.
     if(pionOrdinateur=='X'){ // Si l'ordinateur est le premier joueur
          ModeDefensif(tableau,pionOrdinateur,pionJoueur);
          if(IsGagne(tableau,pionJoueur,pionOrdinateur)==true){
                                                     cout<<"\nL'ordinateur vous a rétam ! dur !\n\n";
                                                     system("PAUSE");
                                                     system("CLS");
                                                     main(); 
                                                               }
         SaisieJoueur(tableau,pionJoueur);
          if(IsGagne(tableau,pionJoueur,pionOrdinateur)==true){
                                                     cout<<"\nVous avez Gagné, GG !\n\n";
                                                     system("PAUSE");
                                                     system("CLS");
                                                     main(); 
                                                               }                                                              

                                                               }             
else{
      SaisieJoueur(tableau,pionJoueur); 
      if(IsGagne(tableau,pionJoueur,pionOrdinateur)==true){
                                                     cout<<"\nVous avez Gagné, GG !\n\n";
                                                     system("PAUSE");
                                                     system("CLS");
                                                     main(); 
                                                               }
     ModeDefensif(tableau,pionOrdinateur,pionJoueur);
     if(IsGagne(tableau,pionJoueur,pionOrdinateur)==true){
                                                     cout<<"\nL'ordinateur vous a rétam ! dur !\n\n";
                                                     system("PAUSE");
                                                     system("CLS");
                                                     main(); 
                                                               }

      }
      }
      
void JouerOffensif(char tableau[3][3], char pionOrdinateur, char pionJoueur){ // Déroulement d'une partie en mode Offensif
     if(pionOrdinateur=='X'){ // Si l'ordinateur est le premier joueur
          ModeOffensif(tableau,pionOrdinateur,pionJoueur);
          if(IsGagne(tableau,pionJoueur,pionOrdinateur)==true){
                                                     cout<<"\nL'ordinateur vous a rétam ! dur !\n\n";
                                                     system("PAUSE");
                                                     system("CLS");
                                                     main(); 
                                                               }
         SaisieJoueur(tableau,pionJoueur);
          if(IsGagne(tableau,pionJoueur,pionOrdinateur)==true){
                                                     cout<<"\nVous avez Gagné, GG !\n\n";
                                                     system("PAUSE");
                                                     system("CLS");
                                                     main(); 
                                                               }                                                              

                                                               }             
else{
      SaisieJoueur(tableau,pionJoueur); 
      if(IsGagne(tableau,pionJoueur,pionOrdinateur)==true){
                                                     cout<<"\nVous avez Gagné, GG !\n\n";
                                                     system("PAUSE");
                                                     system("CLS");
                                                     main(); 
                                                               }
     ModeOffensif(tableau,pionOrdinateur,pionJoueur);
     if(IsGagne(tableau,pionJoueur,pionOrdinateur)==true){
                                                     cout<<"\nL'ordinateur vous a rétam ! dur !\n\n";
                                                     system("PAUSE");
                                                     system("CLS");
                                                     main(); 
                                                               }

      } 
     }
void Jouer(char tableau[3][3], char pionOrdinateur,char pionJoueur){ // déroulement d'une partie en Mode aléatoire.
 if(pionOrdinateur=='X'){ // Si l'ordinateur est le premier joueur
          JeuOrdinateur(tableau,pionOrdinateur);
          if(IsGagne(tableau,pionJoueur,pionOrdinateur)==true){
                                                     cout<<"\nL'ordinateur vous a rétam ! dur !\n\n";
                                                     system("PAUSE");
                                                     system("CLS");
                                                     main(); 
                                                               }
         SaisieJoueur(tableau,pionJoueur);
          if(IsGagne(tableau,pionJoueur,pionOrdinateur)==true){
                                                     cout<<"\nVous avez Gagné, GG !\n\n";
                                                     system("PAUSE");
                                                     system("CLS");
                                                     main(); 
                                                               }                                                              

                                                               }             
else{
      SaisieJoueur(tableau,pionJoueur); 
      if(IsGagne(tableau,pionJoueur,pionOrdinateur)==true){
                                                     cout<<"\nVous avez Gagné, GG !\n\n";
                                                     system("PAUSE");
                                                     system("CLS");
                                                     main(); 
                                                               }
               JeuOrdinateur(tableau,pionOrdinateur);
     if(IsGagne(tableau,pionJoueur,pionOrdinateur)==true){
                                                     cout<<"\nL'ordinateur vous a rétam ! dur !\n\n";
                                                     system("PAUSE");
                                                     system("CLS");
                                                     main(); 
                                                               }

      } 
           } 

bool IsGagne(char tableau[3][3],char pionJoueur,char pionOrdinateur){ // Procédure qui test si joueur ou ordi à gagné apres un coup.
     bool flag = false;
     if(tableau[0][0]==pionJoueur&&tableau[0][1]==pionJoueur&&tableau[0][2]==pionJoueur){flag = true;}
     else if(tableau[1][0]==pionJoueur&&tableau[1][1]==pionJoueur&&tableau[1][2]==pionJoueur){flag = true;}
     else if(tableau[2][0]==pionJoueur&&tableau[2][1]==pionJoueur&&tableau[2][2]==pionJoueur){flag = true;}
     else if(tableau[0][1]==pionJoueur&&tableau[0][2]==pionJoueur&&tableau[0][2]==pionJoueur){flag = true;}
     else if(tableau[0][0]==pionJoueur&&tableau[1][0]==pionJoueur&&tableau[2][0]==pionJoueur){flag = true;}
     else if(tableau[0][1]==pionJoueur&&tableau[1][1]==pionJoueur&&tableau[2][1]==pionJoueur){flag = true;}
     else if(tableau[0][2]==pionJoueur&&tableau[1][2]==pionJoueur&&tableau[2][2]==pionJoueur){flag = true;}
     else if(tableau[0][0]==pionJoueur&&tableau[1][1]==pionJoueur&&tableau[2][2]==pionJoueur){flag = true;}
     else if(tableau[2][0]==pionJoueur&&tableau[1][1]==pionJoueur&&tableau[0][2]==pionJoueur){flag = true;}
     
     else if(tableau[0][0]==pionOrdinateur&&tableau[0][1]==pionOrdinateur&&tableau[0][2]==pionOrdinateur){flag = true;}
     else if(tableau[1][0]==pionOrdinateur&&tableau[1][1]==pionOrdinateur&&tableau[1][2]==pionOrdinateur){flag = true;}
     else if(tableau[2][0]==pionOrdinateur&&tableau[2][1]==pionOrdinateur&&tableau[2][2]==pionOrdinateur){flag = true;}
     else if(tableau[0][1]==pionOrdinateur&&tableau[0][2]==pionOrdinateur&&tableau[0][3]==pionOrdinateur){flag = true;}
     else if(tableau[0][0]==pionOrdinateur&&tableau[1][0]==pionOrdinateur&&tableau[2][0]==pionOrdinateur){flag = true;}
     else if(tableau[0][1]==pionOrdinateur&&tableau[1][1]==pionOrdinateur&&tableau[2][1]==pionOrdinateur){flag = true;}
     else if(tableau[0][2]==pionOrdinateur&&tableau[1][2]==pionOrdinateur&&tableau[2][2]==pionOrdinateur){flag = true;}
     else if(tableau[0][0]==pionOrdinateur&&tableau[1][1]==pionOrdinateur&&tableau[2][2]==pionOrdinateur){flag = true;}
     else if(tableau[2][0]==pionOrdinateur&&tableau[1][1]==pionOrdinateur&&tableau[0][2]==pionOrdinateur){flag = true;}

int compteur=0; // Compte le nombre de cases pleines. Si toutes les cases sont pleines et que personne n'a gagné il y a match nul.
    for(int ligne=0; ligne<3;ligne++) {
    for(int colone=0;colone<3;colone++){
            if(tableau[ligne][colone]!=' '){
                                         compteur++;
                                         }
            }
            }
if(compteur==9){
                cout<<"\nMatch Nul !\n\n";
                system("PAUSE");
                system("CLS");
                main();
                }
     return flag;
}

void ModeDefensif(char tableau[3][3],char pionOrdinateur,char pionJoueur){ 
     if(tableau[1][1]==' '){tableau[1][1]=pionOrdinateur;}
      
           else if((tableau[1][1]==pionJoueur)&&(tableau[0][2]==pionJoueur)&&tableau[2][0]==' '){tableau[2][0]=pionOrdinateur;}
           else if((tableau[1][1]==pionJoueur)&&(tableau[2][0]==pionJoueur)&&tableau[0][2]==' '){tableau[0][2]=pionOrdinateur;}
           else if((tableau[1][1]==pionJoueur)&&(tableau[1][0]==pionJoueur)&&tableau[1][2]==' '){tableau[1][2]=pionOrdinateur;}
           else if((tableau[1][1]==pionJoueur)&&(tableau[1][2]==pionJoueur)&&tableau[1][0]==' '){tableau[1][0]=pionOrdinateur;}
           else if((tableau[1][1]==pionJoueur)&&(tableau[2][2]==pionJoueur)&&tableau[0][0]==' '){tableau[0][0]=pionOrdinateur;}
           else if((tableau[1][1]==pionJoueur)&&(tableau[0][0]==pionJoueur)&&tableau[2][2]==' '){tableau[2][2]=pionOrdinateur;}
           else if((tableau[1][1]==pionJoueur)&&(tableau[0][1]==pionJoueur)&&tableau[2][1]==' '){tableau[2][1]=pionOrdinateur;}
           else if((tableau[1][1]==pionJoueur)&&(tableau[2][1]==pionJoueur)&&tableau[0][1]==' '){tableau[0][1]=pionOrdinateur;}
           else if((tableau[0][1]==pionJoueur)&&(tableau[0][0]==pionJoueur)&&tableau[0][2]==' '){tableau[0][2]=pionOrdinateur;}
           else if((tableau[0][1]==pionJoueur)&&(tableau[0][2]==pionJoueur)&&tableau[0][0]==' '){tableau[0][0]=pionOrdinateur;}
           else if((tableau[2][1]==pionJoueur)&&(tableau[2][0]==pionJoueur)&&tableau[2][2]==' '){tableau[2][2]=pionOrdinateur;}
           else if((tableau[2][1]==pionJoueur)&&(tableau[2][2]==pionJoueur)&&tableau[2][0]==' '){tableau[2][0]=pionOrdinateur;}
           else if((tableau[0][0]==pionJoueur)&&(tableau[1][0]==pionJoueur)&&tableau[2][0]==' '){tableau[2][0]=pionOrdinateur;}
           else if((tableau[1][0]==pionJoueur)&&(tableau[2][0]==pionJoueur)&&tableau[0][0]==' '){tableau[0][0]=pionOrdinateur;}
           else if((tableau[1][2]==pionJoueur)&&(tableau[2][2]==pionJoueur)&&tableau[0][2]==' '){tableau[0][2]=pionOrdinateur;}
           else if((tableau[1][2]==pionJoueur)&&(tableau[0][2]==pionJoueur)&&tableau[2][2]==' '){tableau[2][2]=pionOrdinateur;}
           else if((tableau[0][0]==pionJoueur)&&(tableau[2][0]==pionJoueur)&&tableau[1][0]==' '){tableau[1][0]=pionOrdinateur;}
           else if((tableau[0][1]==pionJoueur)&&(tableau[2][1]==pionJoueur)&&tableau[1][1]==' '){tableau[1][1]=pionOrdinateur;}
           else if((tableau[0][2]==pionJoueur)&&(tableau[2][2]==pionJoueur)&&tableau[1][2]==' '){tableau[1][2]=pionOrdinateur;}
           else if((tableau[0][0]==pionJoueur)&&(tableau[0][2]==pionJoueur)&&tableau[0][1]==' '){tableau[0][1]=pionOrdinateur;}
           else if((tableau[1][0]==pionJoueur)&&(tableau[1][2]==pionJoueur)&&tableau[1][1]==' '){tableau[1][1]=pionOrdinateur;}
           else if((tableau[2][0]==pionJoueur)&&(tableau[2][2]==pionJoueur)&&tableau[2][1]==' '){tableau[2][1]=pionOrdinateur;}
           else if((tableau[0][0]==pionJoueur)&&(tableau[2][2]==pionJoueur)&&tableau[1][1]==' '){tableau[1][1]=pionOrdinateur;}
           else if((tableau[2][0]==pionJoueur)&&(tableau[0][2]==pionJoueur)&&tableau[1][1]==' '){tableau[1][1]=pionOrdinateur;}
           else{JeuOrdinateur(tableau,pionOrdinateur);}
           system("CLS");
           Afficher(tableau);
     }

void ModeOffensif(char tableau[3][3],char pionOrdinateur,char pionJoueur){
           if(tableau[1][1]==' '){tableau[1][1]=pionOrdinateur;}
           
           else if((tableau[1][1]==pionOrdinateur)&&(tableau[0][2]==pionOrdinateur)&&tableau[2][0]==' '){tableau[2][0]=pionOrdinateur;}
           else if((tableau[1][1]==pionOrdinateur)&&(tableau[2][0]==pionOrdinateur)&&tableau[0][2]==' '){tableau[0][2]=pionOrdinateur;}
           else if((tableau[1][1]==pionOrdinateur)&&(tableau[1][0]==pionOrdinateur)&&tableau[1][2]==' '){tableau[1][2]=pionOrdinateur;}
           else if((tableau[1][1]==pionOrdinateur)&&(tableau[1][2]==pionOrdinateur)&&tableau[1][0]==' '){tableau[1][0]=pionOrdinateur;}
           else if((tableau[1][1]==pionOrdinateur)&&(tableau[2][2]==pionOrdinateur)&&tableau[0][0]==' '){tableau[0][0]=pionOrdinateur;}
           else if((tableau[1][1]==pionOrdinateur)&&(tableau[0][0]==pionOrdinateur)&&tableau[2][2]==' '){tableau[2][2]=pionOrdinateur;}
           else if((tableau[1][1]==pionOrdinateur)&&(tableau[0][1]==pionOrdinateur)&&tableau[2][1]==' '){tableau[2][1]=pionOrdinateur;}
           else if((tableau[1][1]==pionOrdinateur)&&(tableau[2][1]==pionOrdinateur)&&tableau[0][1]==' '){tableau[0][1]=pionOrdinateur;}
           else if((tableau[0][1]==pionOrdinateur)&&(tableau[0][0]==pionOrdinateur)&&tableau[0][2]==' '){tableau[0][2]=pionOrdinateur;}
           else if((tableau[0][1]==pionOrdinateur)&&(tableau[0][2]==pionOrdinateur)&&tableau[0][0]==' '){tableau[0][0]=pionOrdinateur;}
           else if((tableau[2][1]==pionOrdinateur)&&(tableau[2][0]==pionOrdinateur)&&tableau[2][2]==' '){tableau[2][2]=pionOrdinateur;}
           else if((tableau[2][1]==pionOrdinateur)&&(tableau[2][2]==pionOrdinateur)&&tableau[2][0]==' '){tableau[2][0]=pionOrdinateur;}
           else if((tableau[0][0]==pionOrdinateur)&&(tableau[1][0]==pionOrdinateur)&&tableau[2][0]==' '){tableau[2][0]=pionOrdinateur;}
           else if((tableau[1][0]==pionOrdinateur)&&(tableau[2][0]==pionOrdinateur)&&tableau[0][0]==' '){tableau[0][0]=pionOrdinateur;}
           else if((tableau[1][2]==pionOrdinateur)&&(tableau[2][2]==pionOrdinateur)&&tableau[0][2]==' '){tableau[0][2]=pionOrdinateur;}
           else if((tableau[1][2]==pionOrdinateur)&&(tableau[0][2]==pionOrdinateur)&&tableau[2][2]==' '){tableau[2][2]=pionOrdinateur;}
           else if((tableau[0][0]==pionOrdinateur)&&(tableau[2][0]==pionOrdinateur)&&tableau[1][0]==' '){tableau[1][0]=pionOrdinateur;}
           else if((tableau[0][1]==pionOrdinateur)&&(tableau[2][1]==pionOrdinateur)&&tableau[1][1]==' '){tableau[1][1]=pionOrdinateur;}
           else if((tableau[0][2]==pionOrdinateur)&&(tableau[2][2]==pionOrdinateur)&&tableau[1][2]==' '){tableau[1][2]=pionOrdinateur;}
           else if((tableau[0][0]==pionOrdinateur)&&(tableau[0][2]==pionOrdinateur)&&tableau[0][1]==' '){tableau[0][1]=pionOrdinateur;}
           else if((tableau[1][0]==pionOrdinateur)&&(tableau[1][2]==pionOrdinateur)&&tableau[1][1]==' '){tableau[1][1]=pionOrdinateur;}
           else if((tableau[2][0]==pionOrdinateur)&&(tableau[2][2]==pionOrdinateur)&&tableau[2][1]==' '){tableau[2][1]=pionOrdinateur;}
           else if((tableau[0][0]==pionOrdinateur)&&(tableau[2][2]==pionOrdinateur)&&tableau[1][1]==' '){tableau[1][1]=pionOrdinateur;}
           else if((tableau[2][0]==pionOrdinateur)&&(tableau[0][2]==pionOrdinateur)&&tableau[1][1]==' '){tableau[1][1]=pionOrdinateur;}
           
           
           else if((tableau[1][1]==pionJoueur)&&(tableau[0][2]==pionJoueur)&&tableau[2][0]==' '){tableau[2][0]=pionOrdinateur;}
           else if((tableau[1][1]==pionJoueur)&&(tableau[2][0]==pionJoueur)&&tableau[0][2]==' '){tableau[0][2]=pionOrdinateur;}
           else if((tableau[1][1]==pionJoueur)&&(tableau[1][0]==pionJoueur)&&tableau[1][2]==' '){tableau[1][2]=pionOrdinateur;}
           else if((tableau[1][1]==pionJoueur)&&(tableau[1][2]==pionJoueur)&&tableau[1][0]==' '){tableau[1][0]=pionOrdinateur;}
           else if((tableau[1][1]==pionJoueur)&&(tableau[2][2]==pionJoueur)&&tableau[0][0]==' '){tableau[0][0]=pionOrdinateur;}
           else if((tableau[1][1]==pionJoueur)&&(tableau[0][0]==pionJoueur)&&tableau[2][2]==' '){tableau[2][2]=pionOrdinateur;}
           else if((tableau[1][1]==pionJoueur)&&(tableau[0][1]==pionJoueur)&&tableau[2][1]==' '){tableau[2][1]=pionOrdinateur;}
           else if((tableau[1][1]==pionJoueur)&&(tableau[2][1]==pionJoueur)&&tableau[0][1]==' '){tableau[0][1]=pionOrdinateur;}
           else if((tableau[0][1]==pionJoueur)&&(tableau[0][0]==pionJoueur)&&tableau[0][2]==' '){tableau[0][2]=pionOrdinateur;}
           else if((tableau[0][1]==pionJoueur)&&(tableau[0][2]==pionJoueur)&&tableau[0][0]==' '){tableau[0][0]=pionOrdinateur;}
           else if((tableau[2][1]==pionJoueur)&&(tableau[2][0]==pionJoueur)&&tableau[2][2]==' '){tableau[2][2]=pionOrdinateur;}
           else if((tableau[2][1]==pionJoueur)&&(tableau[2][2]==pionJoueur)&&tableau[2][0]==' '){tableau[2][0]=pionOrdinateur;}
           else if((tableau[0][0]==pionJoueur)&&(tableau[1][0]==pionJoueur)&&tableau[2][0]==' '){tableau[2][0]=pionOrdinateur;}
           else if((tableau[1][0]==pionJoueur)&&(tableau[2][0]==pionJoueur)&&tableau[0][0]==' '){tableau[0][0]=pionOrdinateur;}
           else if((tableau[1][2]==pionJoueur)&&(tableau[2][2]==pionJoueur)&&tableau[0][2]==' '){tableau[0][2]=pionOrdinateur;}
           else if((tableau[1][2]==pionJoueur)&&(tableau[0][2]==pionJoueur)&&tableau[2][2]==' '){tableau[2][2]=pionOrdinateur;}
           else if((tableau[0][0]==pionJoueur)&&(tableau[2][0]==pionJoueur)&&tableau[1][0]==' '){tableau[1][0]=pionOrdinateur;}
           else if((tableau[0][1]==pionJoueur)&&(tableau[2][1]==pionJoueur)&&tableau[1][1]==' '){tableau[1][1]=pionOrdinateur;}
           else if((tableau[0][2]==pionJoueur)&&(tableau[2][2]==pionJoueur)&&tableau[1][2]==' '){tableau[1][2]=pionOrdinateur;}
           else if((tableau[0][0]==pionJoueur)&&(tableau[0][2]==pionJoueur)&&tableau[0][1]==' '){tableau[0][1]=pionOrdinateur;}
           else if((tableau[1][0]==pionJoueur)&&(tableau[1][2]==pionJoueur)&&tableau[1][1]==' '){tableau[1][1]=pionOrdinateur;}
           else if((tableau[2][0]==pionJoueur)&&(tableau[2][2]==pionJoueur)&&tableau[2][1]==' '){tableau[2][1]=pionOrdinateur;}
           else if((tableau[0][0]==pionJoueur)&&(tableau[2][2]==pionJoueur)&&tableau[1][1]==' '){tableau[1][1]=pionOrdinateur;}
           else if((tableau[2][0]==pionJoueur)&&(tableau[0][2]==pionJoueur)&&tableau[1][1]==' '){tableau[1][1]=pionOrdinateur;}
           else{JeuOrdinateur(tableau,pionOrdinateur);}
           system("CLS");
           Afficher(tableau);
           }

//void CoupsRestants(char tableau[2][2],string tabcoupsrestants[8]) // J'ai essayé ... 
//{
//int i=0;
//for(int colone=0;colone<3;colone++){
//for(int ligne=0;ligne<3;ligne++){
//if(tableau[colone][ligne]==' '){
//tabcoupsrestants[i]=colone,ligne;
//cout<<tabcoupsrestants[i];
//i++;
//}
//}
//}
//}
