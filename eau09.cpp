#include <iostream>
#include "./misc/checkArgs.cpp"

using namespace std;

/*
  Chiffres only:
  
  Programme qui détermine si une chaîne de caractères ne contient que des chiffres. 
*/


int main(int argc, char* argv[]){
  vector<string> checks;
  checks.push_back(ONLY_ONE_ARGUMENT);
  checks.push_back(AT_LEAST_ONE_ARGUMENT);
  
  try {
    checkArgs(argc, argv, checks);

    string str = string(argv[1]);
    string out = "true";

    for(int i=0; i<str.length(); i++) {
      char code = int(str[i]);

      if(code < 48 || code > 57) {
        out = "false";
      }
    }

    cout << out << endl;

  } catch(const invalid_argument& e) {
    cerr << "erreur: " << e.what() << endl;
    cerr << -1 << endl;
  }
}