#include <iostream>
#include <stdexcept>

using namespace std;

/*
  Prochain nombre premier:
  Programme qui affiche le premier nombre premier supérieur au nombre donné en argument.
*/

bool isPrimeNumber(int num) {
  int dividers = 0;
  for(int i=0; i<=num; i++) {
    if(num%i == 0) {
      dividers += 1;
    }
  }
  return dividers == 2; 
}

bool isNumber(string str) {
  for(int i=0; i<str.length(); i++) {
    if(isdigit(str[i]) == false) {
      return false;
    }
  }
  return true;
}

void checkArgs(int argc, char* argv[]) {

  if(argc == 1) {
    throw invalid_argument("Veuillez entrer un nombre.");
  }

  bool moreThanOneArgument = argc > 2;
  bool argumentIsNegativeOrNotInteger = isNumber(string(argv[1])) == false;
  bool argumentIsNotPrimeNumber = !isPrimeNumber(atoi(argv[1]));

  if(argumentIsNegativeOrNotInteger) {
    throw invalid_argument("Veuillez entrer un nombre entier.");
  }

  if(moreThanOneArgument) {
    throw invalid_argument("Veuillez entre un seul nombre.");
  }
}

int main (int argc, char* argv[]) {
  try {
    checkArgs(argc, argv);
    int arg = atoi(argv[1]);

    int found = -1;

    while(found == -1) {
      int guess = arg + 1;
      if(isPrimeNumber(guess)) {
        found = guess;
      }
      arg++;
    }

    cout << found << "\n";

    return 0;
 
  } catch(const invalid_argument& e) {
    cerr << "erreur: " << e.what() << "\n";
    cerr << -1 << "\n";

    return -1;
  }
}