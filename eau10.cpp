#include <iostream>
#include "./misc/checkArgs.cpp"

using namespace std;

/*
  Entre min et max:
  
  Programme qui affiche toutes les valeurs comprises entre deux nombres dans l’ordre croissant. Min inclus, max exclus. 
*/


int main(int argc, char* argv[]){
  vector<string> checks;
  checks.push_back(ONLY_TWO_ARGUMENTS);
  checks.push_back(ONLY_INTEGERS);
  
  try {
    checkArgs(argc, argv, checks);

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    for(int i=num1; i<=num2; i++) {
      cout << i << " ";  
    }

    cout << endl;

  } catch(const invalid_argument& e) {
    cerr << "erreur: " << e.what() << endl;
    cerr << -1 << endl;
  }
}