#include <iostream>
#include <string>
#include <vector>
#include "./misc/checkArgs.cpp"

using namespace std;

/*
  Tri par ordre ascii:
  Programme qui trie les éléments données en argument par ordre ascii
*/


int main(int argc, char* argv[]){
  vector<string> checks;
  checks.push_back(AT_LEAST_ONE_ARGUMENT);
  
  try {
    checkArgs(argc, argv, checks);

    vector<char*> arr;

    for(int i=1; i<argc; i++) {
      arr.push_back(argv[i]);
    }

    for (int i=arr.size()-1; i>=1; i--) {
      for (int j=0; j<=i-1; j++) {
        char* next = arr[j+1];
        char* current = arr[j];

        int nextAsciiValue = next[0];
        int currentAsciiValue = current[0];
        
        if(nextAsciiValue < currentAsciiValue) {
          arr[j+1] = current;
          arr[j] = next;
        }
      }
    }

    for (int i=0; i<arr.size(); i++) {
      cout << arr[i] << " ";
    }

  } catch(const invalid_argument& e) {
    cerr << "erreur: " << e.what() << endl;
    cerr << -1 << endl;
  }
}