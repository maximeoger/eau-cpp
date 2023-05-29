#include <iostream>
#include "./misc/checkArgs.cpp"

using namespace std;

/*
  Une majuscule sur deux:
  Programme qui met en majuscule une lettre sur deux d’une chaîne de caractères. 
*/


int main(int argc, char* argv[]){
  vector<string> checks;
  checks.push_back(ONLY_STRINGS);
  checks.push_back(ONLY_ONE_ARGUMENT);
  checks.push_back(AT_LEAST_ONE_ARGUMENT);
  
  try {
    checkArgs(argc, argv, checks);

    string str = string(argv[1]);
    string out;

    // le char courant est une lettre ET le char précédent est un espace
    // le char courant est une lettre ET est le premier de la chaine

    for(int i=0; i<str.length(); i++) {
      int c = int(str[i]);
      bool letter = c >= 97 && c <= 122;
      bool lineBreak = c == 10 && str[i-1] == 13;

      if(i==0 && letter || i>0 && letter && (int(str[i-1]) == 32 || lineBreak)) {
        out += char(c - 32);
        continue;
      }
      out += str[i];
    }

    cout << out << endl;

  } catch(const invalid_argument& e) {
    cerr << "erreur: " << e.what() << endl;
    cerr << -1 << endl;
  }
}