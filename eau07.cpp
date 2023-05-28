#include <iostream>
#include "./misc/checkArgs.cpp"

using namespace std;

/*
  Une majuscule sur deux:
  Programme qui met en majuscule une lettre sur deux d’une chaîne de caractères. 
*/


int main (int argc, char* argv[]) {
  vector<string> checks;
  checks.push_back(ONLY_STRINGS);
  checks.push_back(ONLY_ONE_ARGUMENT);
  checks.push_back(AT_LEAST_ONE_ARGUMENT);
  
  try {
    checkArgs(argc, argv, checks);

    string str = string(argv[1]);
    string out;

    for(int i=0; i<str.length(); i++) {

      int charCode = int(str[i]);
      bool isLowerCase  = charCode <= 122 && charCode >= 97;
      bool isUpperCase = charCode <= 90 && charCode >= 65;
    
      if(!isLowerCase && !isUpperCase) {
        out += char(charCode);
        continue;
      }

      int newCharCode = charCode;

      if(isUpperCase) {
        // passer en minuscule
        newCharCode = charCode + 32;
      }

      if(i%2 ==0) {
        newCharCode = newCharCode - 32;
      }

      out += char(newCharCode);
    }

    cout << out << endl;

  } catch(const invalid_argument& e) {
    cerr << "erreur: " << e.what() << endl;
    cerr << -1 << endl;
  }
}
