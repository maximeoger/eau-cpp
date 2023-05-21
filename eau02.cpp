#include <iostream>

/*
  Combinaison de 2 chiffres:
  Programme qui affiche toutes les différentes combinaisons possibles de trois chiffres dans l’ordre croissant, dans l’ordre croissant.

  ex: 00 01, 00 02, 00 03, 00 04, ... , 00 99, 01 02, ... , 97 99, 98 99
*/

using namespace std;

int main(){
  int max = 9;

  for(int i=0; i<=max; i++) {
    for(int j=0; j<=max; j++) {
      for(int k=0; k<=max; k++) {
        for(int l=0; l<=max; l++) {

          string strFirst = to_string(i) + to_string(j);
          string strSecond = to_string(k) + to_string(l);
          
          int numFirst = stoi(strFirst);
          int numSecond = stoi(strSecond);

          if(
            (numFirst != numSecond) &&
            (i <= j) && (k <= l)
          ) {
            cout << i;
            cout << j;
            cout << " ";
            cout << k;
            cout << l;
            cout << ", ";
          }
             
        }
      }
    }
  }

  cout << "\n";
  return 0;
}