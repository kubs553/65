#include <iostream>
#include <fstream>

using namespace std;

const int rozmiar = 1000;
float t[rozmiar][2];

int main() {
  float licznik = 999; 
  float mianownik = 999;
  float min_ulamek = 999;
  float ulamek = 0;
  ifstream in ("dane_ulamki.txt");
  for (int i = 0; i < rozmiar; i++) {
    in >> t[i][0] >> t[i][1];
  }
  for (int i = 0; i < rozmiar; i++) {
    ulamek = t[i][0] / t[i][1];
    if (ulamek <= min_ulamek) {
      if (ulamek == min_ulamek && t[i][1] > mianownik)
        continue;
      min_ulamek = ulamek;
      licznik = t[i][0];
      mianownik = t[i][1];
    }
  }
  cout << "Licznik: " << licznik << " Mianownik: " << mianownik << "\n";
}