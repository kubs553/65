#include <iostream>
#include <fstream>

using namespace std;

const int rozmiar = 1000;
float t[rozmiar][2];

int nwd(int a, int b) {
  if (b == 0)
    return a;
  return nwd(b, a % b);
}

int main() {
  int suma = 0;
  int ob_nwd = 0;
  ifstream in ("dane_ulamki.txt");
  for (int i = 0; i < rozmiar; i++) {
    in >> t[i][0] >> t[i][1];
  }
  for (int i = 0; i < rozmiar; i++) {
    float licznik = t[i][0];
    float mianownik = t[i][1];
    while (nwd(licznik, mianownik) > 1) {
      ob_nwd = nwd(licznik, mianownik);
      licznik = licznik / ob_nwd;
      mianownik = mianownik / ob_nwd;
    }
    suma += licznik;
  }
  cout << suma << endl;
}