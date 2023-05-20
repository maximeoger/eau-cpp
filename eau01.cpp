#include <iostream>

using namespace std;

/*
  Combinaison de 3 chiffres:
  Programme qui affiche toutes les différentes combinaisons possibles de trois chiffres dans l’ordre croissant, dans l’ordre croissant.

  ex: 012, 013, 014, 015, 016, 017, 018, 019, 023, 024, ... , 789
*/

int main(int argc, char* argv[]){
  for(int i=0; i<=9; i++) {
    for(int j=0; j<=9; j++) {
      for(int k=0; k<=9; k++) {
        if(
          (i!=j && k!=j && k!=i) && 
          (i<j && i<k && j<k)
        ) {
          cout << i << j << k << ",";
        }
      }
    }
  }
  cout << "\n";
  return 0;
}