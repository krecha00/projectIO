#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <conio.h>
#include <string>

using namespace std;

struct projekty
{
  string autor;
  string tytul;
  string odpowiedzialnosc;
  string dedline;
};

short i;             // zmienna przechowujaca ilosc projektow
projekty projekt[200];   //200 elementowa tablica struktur

void Dodaj();        //deklaruje funkcje
void Zobacz();
void Zapisz();
void Wczytaj();
void Usun();
void Edytuj();

int main()
{
  cout<< "*******************\n"
         "**** Projekty *****\n"
         "*******************\n";
  cout << "\n\n\n";
  char wybor;

  do
  {
    cout <<"Aktualnie posiadasz "<<i<<" projektow"<<endl;
    cout <<"1. Dodaj Projekt "<<endl;
    cout <<"2. Zobacz wszystkie projekty "<<endl;
    cout <<"3. Zapisz wprowadzone projekty "<<endl;
    cout <<"4. Wczytaj projekty z bazy "<<endl;
    cout <<"5. Usun Projekt "<<endl;
  	cout <<"6. Edytuj Projekt "<<endl;

    cout <<"ESC - Koniec programu "<<endl<<endl;

    wybor = getch();

    switch (wybor)
    {
      case 49: Dodaj();
      break;
      case 50: Zobacz();
      break;
      case 51: Zapisz();
      break;
      case 52: Wczytaj();
      break;
      case 53: Usun();
      break;
      case 54: Edytuj();
      break;
    }

    system("cls");
  } while (wybor != 27);



 // system("pause");
  return 0;
}   // koniec main
void Dodaj()
{
  cout <<"Podaj autora projektu: \n";       ////przypisanie wartości x w obiekcie projekt
  cin >>projekt[i].autor;

  cout <<"Podaj tytul projektu: \n";
  cin >>projekt[i].tytul;

  cout <<"Podaj osoby odpowiedzialne za projekt: \n";
  cin >>projekt[i].odpowiedzialnosc;

  cout <<"Podaj dedline: \n";
  cin >>projekt[i].dedline;

  cin.ignore();

  i++;

  cout <<". Wcisnij ENTER! :)";
  getchar();
}
void Zobacz()
{
  if ( i != 0)                             //musi byc conajmniej 1 element do wypisania
  {
    for (short j = 0; j < i; j++)   //j jest indeksem umozliwiajacym wypisywanie kolejnych elementow.wypisuje od 0 do i
    {                               //j<i wyswietlanie prawidlowej wartosci   i = j-1
      cout <<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
      cout <<"x     projekt nr "<<j+1<<": "<<endl;
      cout <<"x     Autor: "<<projekt[j].autor<<endl;
      cout <<"x     Tutul: "<<projekt[j].tytul<<endl;
      cout <<"x     odpowiedzialnosc: "<<projekt[j].odpowiedzialnosc<<endl;
      cout <<"x     dedline: "<<projekt[j].dedline<<endl;
      cout <<"x";
      cout <<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;


    }
  }
  else
  cout <<"Nie ma zadnej projekty w bazie!!";

  cout <<"Nacisnij ENTER";

  getchar();
}

void Zapisz()
{
  ofstream plik("projekty.txt", ios::out | ios::trunc);

  plik <<i<<"\n";

  for (short j = 0; j < i; j++)
  {
    plik <<projekt[j].autor<<endl;
    plik <<projekt[j].tytul<<endl;
    plik <<projekt[j].odpowiedzialnosc<<endl;
    plik <<projekt[j].dedline<<endl;
  }

  cout <<"Dane zostaly zapisane! :). Wcisnij ENTER";

  getchar();
}



void Wczytaj()
{
  ifstream plik("projekty.txt", ios::in);

  plik >> i;


  short j = 0;

  do
  {
    plik >>projekt[j].autor;
    plik >>projekt[j].tytul;
    plik >>projekt[j].odpowiedzialnosc;
    plik >>projekt[j].dedline;
    j++;
  } while( !plik.eof() );

  cout <<"Wczytano dane. Nacisnij ENTER!";

  getchar();
}

void Usun()
{
  short kogo;

  if (i != 0)
  {
    cout <<"Podaj numer projekty ktora chcesz usunac: ";
    cin >>kogo;
    cin.ignore();

    if (kogo > i)
    cout <<"Operacja nie powiodla sie. Brak projekty o takim numerze";
    else
    {
      for (short k = kogo; k < i; k++)
      {
        projekt[k-1].autor = projekt[k].autor;   //polega na zastapieniu elementu , elementem nastepnym,  na nastepnie i--
        projekt[k-1].tytul = projekt[k].tytul;
        projekt[k-1].odpowiedzialnosc = projekt[k].odpowiedzialnosc;
        projekt[k-1].dedline = projekt[k].dedline;
      }
      i--;

      cout <<"Operacja zakonczyla sie sukcesem! projekt o numerze "<<kogo<<" zostala usunieta!";
      Zapisz();
    }

  }
  else
  {
    cout <<"Nie ma projektow w bazie!! Wcisnij ENTER!";
    getchar();
  }
}

void Edytuj()
{
  //short kogo;
        int kogo;

  if (i != 0)
  {
    cout <<"Podaj numer projekty ktora chcesz zmienic: ";
    cin >>kogo;
    cin.ignore();

    if (kogo > i)
    cout <<"Operacja nie powiodla sie. Brak projekty o takim numerze";
    else
    {
//jest -1 bo zakladam ze numeracja projektow jest taka jak w wypisaniu. Natiomiast
                // tablica zaczyna sie od zera.
cout <<"Podaj autora projekty: \n";
cin>>projekt[kogo-1].autor;                                //jest -1 bo zakladam ze numeracja projektow jest taka jak w wypisaniu. Natiomiast
                                                        // tablica zaczyna sie od zera.
             cout <<"Podaj tytul projekty: \n";;
     cin>>projekt[kogo-1].tytul;
   cout <<"Podaj osoby odpowiedzialne za projekt: \n";
     cin>>projekt[kogo-1].odpowiedzialnosc;
   cout <<"Podaj dedline: \n";
     cin>>projekt[kogo-1].dedline;


      cout <<"Operacja zakonczyla sie sukcesem! projekt o numerze "<<kogo<<" zostala zmieniona!";
      Zapisz();
    }

  }
  else
  {
    cout <<"Nie ma projektow w bazie!! Wcisnij ENTER!";
    getchar();
  }
}
