#include <iostream>
#include <stdexcept>

using namespace std;

/*
  Suite de Fibonacci:
  Programme qui affiche la position sur la suite de Fibonacci de l'argument passé en paramètre.
*/

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

    int input = atoi(argv[1]);

    if(input == 0) {
      cout << 1 << "\n";
      return 0;
    }

    int _temp, 
        i = 2, 
        current = 1, 
        last = 0;
    
    while(input > current) {
      // stocker la valeur courante temporairement
      _temp = current;
      // la valeur courante est la somme des valeurs courante et ancienne
      current = last + current;
      // qui sera utilisée comme valeur précédente au prochain tour
      last = _temp;
      i++;
    }
    
    if(input !=0 && input!=current) {
      throw invalid_argument("Le paramètre d\'entrée n'appartiens pas à la suite de Fibonacci.");
    }

    cout << i << "\n"; 

    return 0;
 
  } catch(const invalid_argument& e) {
    cerr << "erreur: " << e.what() << "\n";
    cerr << -1 << "\n";

    return -1;
  }
}