#include <iostream>
#include <vector>

using namespace std;

/*
  Paramètres à l'envers:
  Programme qui affiche les paramètres reçus à l'envers.
*/

void printErr(string message) {
  cerr << message << "\n";
}

void checkArgs(int argc) {
  bool noArguments = argc == 1;

  if(noArguments) {
    throw invalid_argument("Error.");
  }
}


int main(int argc, char* argv[]){
  try {
    checkArgs(argc);
  } catch (exception) {
    printErr("Erreur .");
    return 1;
  }

  int count =  argc-1;
  
  for(int i=count; i>=1; i--) {
    cout << string(argv[i]) << "\n";
  }

  return 0;
}