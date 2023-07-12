#include <iostream>
#include <string>
#include <vector>
#include "./misc/checkArgs.cpp"

using namespace std;

/*
  Fin
*/

int main(int argc, char* argv[]){
  vector<string> checks;
  checks.push_back(AT_LEAST_ONE_ARGUMENT);
  
  try {
    checkArgs(argc, argv, checks);

    cout << "J'ai fini les épreuves de l'eau, c'était " << argv[1] << endl;

  } catch(const invalid_argument& e) {
    cerr << "erreur: " << e.what() << endl;
    cerr << -1 << endl;
  }
}