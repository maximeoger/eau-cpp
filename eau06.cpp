#include <iostream>
#include <stdexcept>
#include "./misc/checkArgs.cpp"

using namespace std;

/*
  String dans string:
  Programme qui détermine si une chaîne de caractère se trouve dans une autre.
*/

int isSubstr(string s1, string s2) {
  int M = s1.length();
  int N = s2.length();

  // parcourir une portion de string ( déterminée par la différence entre taille chaine 1 et taille chaine 2 ) correspondant au mot recherché
  for (int i = 0; i <= N - M; i++) {
      int j;
      for (j = 0; j < M; j++)
          if (s2[i + j] != s1[j])
              break;

      if (j == M)
          return i;
  }

  return -1;
}

int main (int argc, char* argv[]) {
  vector<string> checks;
  checks.push_back(ONLY_STRINGS);
  checks.push_back(ONLY_TWO_ARGUMENTS);

  try {

    checkArgs(argc, argv, checks);

    if(isSubstr(string(argv[2]), string(argv[1])) != -1) {
      cout << "true" << "\n";
    } else {
      cout << "false" << "\n";
    }

    return 0;

  } catch(const invalid_argument& e) {
    cerr << "erreur: " << e.what() << "\n";
    cerr << -1 << "\n";
  }
}