#include <iostream>
#include "./misc/checkArgs.cpp"

using namespace std;

/*
  Index wanted:
  
  Programme qui affiche le premier index d’un élément recherché dans un tableau. Le tableau est constitué de tous les arguments sauf le dernier. afficher -1 si l'element n'existe pas.
*/

int compareStrings(char s1[], char s2[]) {
  int result;
  /*
    ici on traite s1 et s2 qui sont des pointeurs vers la chaine de caractère argv[i][0], 
    si le caractère nul '\0' est rencontré, on stop la récursion.
  */ 
  bool thisIsTheEnd = s1[0] == '\0' || s2[0] == '\0'; 
  // Avoir deux mots identiques signifie qu'on a rencontré le caractère nul et que tous les caractères sont égaux.
  if (thisIsTheEnd && s1[0] == s2[0]) {
    return 0;
  } else {
    if(s1[0] == s2[0]) {
      char *ref1 = &(s1[1]);
      char *ref2 = &(s2[1]); // récupérer l'addresse memoire des caractères suivant (on se retrouve donc avec le reste de la chaine)
      result = compareStrings(ref1, ref2); // et les passer à la fonction recursive
    } else {
      result = -1;
    }
  }
  return result;
}

int main(int argc, char* argv[]){
  vector<string> checks;
  checks.push_back(AT_LEAST_TWO_ARGUMENTS);
  checks.push_back(ONLY_STRINGS);
  
  try {
    checkArgs(argc, argv, checks);
    
    char* search = argv[argc-1];

    int ret = compareStrings(argv[1], argv[2]);

    int returnValue = -1;

    for(int i=1; i<=argc-2; i++) {
      char* word = argv[i];
      
      if(compareStrings(word, search) == 0) {
        returnValue = 0;
      }
    }

    cout << returnValue << endl;

  } catch(const invalid_argument& e) {
    cerr << "erreur: " << e.what() << endl;
    cerr << -1 << endl;
  }
}