#include <iostream>
#include <windows.h>
#include <ctime>
#include <cmath>
using namespace std;

int main()
{
  srand(time(0));
  int Y=20;                                  // wysokosc okna
  int X=70;                                  // szerokosc okna
  int Z=0;                                 // liczba poczatkowych pol z jedzeniem
  string langton[X][Y];                        // utworzenie przestrzeni dla mrowki langtona
  bool langton2[X][Y];                        // langton2 sluzy do obliczen, langton do wizualizacji
  int kierunek=rand()%4;                        // kierunek poczatkowy: 0 - gora, 1 - prawo, 2 - dol, 3 - lewo
  int mrowka[2]={rand()%X,rand()%Y};               // wspolrzedne poczatkowe mrowki
  for (int i=0;i<Y; i++)                        // wyczyszczenie przestrzeni
  {
    for (int j=0;j<X; j++)
    {
      langton[j][i]=" ";
      langton2[j][i]=false;
    }
  }
  for (int i=0; i<Z; i++)                        // umieszczenie w Z losowych miejscach jedzenia
  {
    langton[rand()%X][rand()%Y]="+";
    langton2[rand()%X][rand()%Y]=true;
  }
  langton[mrowka[0]][mrowka[1]]="#";               // umieszczenie w przestrzeni mrowki
  
  
  do
  {
    for (int i=0; i<Y; i++)                     // wyswietlenie na ekranie
    {
      for (int j=0; j<X; j++)
      {
        cout << langton[j][i];
      }
      cout << endl;
    }
    
    
    if (langton2[mrowka[0]][mrowka[1]]==true)      // jesli jest wypelniona
    {
      kierunek=(kierunek+1)%4;               // dodanie 1 oznacza skret w prawo (wszystko w pierscieniu Z4)
      langton[mrowka[0]][mrowka[1]]=" ";         // po wizycie mrowki zmieniamy wartosci odwiedzonej pozycji
      langton2[mrowka[0]][mrowka[1]]=false;
    }
    else
    {
      kierunek=abs((kierunek+3)%4);            // jesli nie jest wypelniona, to skret w lewo
      langton[mrowka[0]][mrowka[1]]="+";
      langton2[mrowka[0]][mrowka[1]]=true;
    }
    if (kierunek==0)   mrowka[0]--;            // jesli ma isc do gory
    if (kierunek==2)   mrowka[0]++;            // jesli ma isc w dol
    if (kierunek==1)                                // jesli ma isc w prawo
    {
      if (mrowka[0]==X-1)  mrowka[0]=int(X/2);    // jesli jest przy granicy i chce isc w prawo to przenies na srodek
      else mrowka[1]++;   
    }
    if (kierunek==3)                               // jesli ma isc w lewo
    {
      if (mrowka[0]==0)    mrowka[0]=int(X/2);    // jesli jest przy granicy i chce isc w lewo to przenies na srodek
      else mrowka[1]--;            
    }
    langton[mrowka[0]][mrowka[1]]="#";            // nowe polozenie mrowki
    Sleep(5);
    system("cls");
  }
  while (true);
}