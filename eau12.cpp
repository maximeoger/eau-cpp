#include <iostream>
#include <string>
#include <vector>
#include "./misc/checkArgs.cpp"

using namespace std;

/*
  Différence minimum absolue:
  Programme qui affiche la différence minimum absolue entre deux éléments d’un tableau constitué uniquement de nombres.
*/


// la différence absolue revient a faire la différence du terme le plus grand avec le plus petit
int absDiff(int n1, int n2) {
  if(n1 >= n2) {
    return n1 - n2;
  } else {
    return n2 - n1;
  }
}

int main(int argc, char* argv[]){
  vector<string> checks;
  checks.push_back(AT_LEAST_TWO_ARGUMENTS);
  checks.push_back(ONLY_INTEGERS);
  
  try {
    checkArgs(argc, argv, checks);

    int smallestDiff = -1;
    
    for (int i=1; i<argc; i++) {
      int a = stoi(argv[i]);

      for (int j=argc-1; j>i; j--) {
        int b = stoi(argv[j]);
        int diff = absDiff(a, b);
        // si la diff est plus petite ou que c'est la première différence calculée
        if(smallestDiff == -1 || diff < smallestDiff) {
          smallestDiff = diff;
        }
      }
      
    }

    cout << smallestDiff << endl;

  } catch(const invalid_argument& e) {
    cerr << "erreur: " << e.what() << endl;
    cerr << -1 << endl;
  }
}