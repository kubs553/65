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
  int licznik = 0;
  ifstream plik("dane_ulamki.txt");
  for (int i = 0; i < rozmiar; i++) {
    plik >> t[i][0] >> t[i][1];
  }
  for (int i = 0; i < rozmiar; i++) {
    if (nwd(t[i][0], t[i][1]) > 1)
      continue;
    licznik++;
  }
  cout << licznik << "\n";
}