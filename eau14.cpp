#include <iostream>
#include <string>
#include <vector>
#include "./misc/checkArgs.cpp"

using namespace std;

/*
  Tri par sélection:
  Programme qui implémente l'algorithme du tri par séléction
*/


int main(int argc, char* argv[]){
  vector<string> checks;
  checks.push_back(AT_LEAST_TWO_ARGUMENTS);
  checks.push_back(ONLY_INTEGERS);
  
  try {
    checkArgs(argc, argv, checks);

    vector<int> arr;

    for(int i=1; i<argc; i++) {
      arr.push_back(atoi(argv[i]));
    }
    
    for(int i=0; i<arr.size()-1; i++) {
      int min = i;
      for (int j=i+1; j<arr.size(); j++) {
        if(arr[j] < arr[min]) {
          min = j;
        }
      }
      if(min != i) {
        int temp;
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
      }
    }

    for(int i=0; i<arr.size(); i++) {
      cout << arr[i] << " ";
    }

  } catch(const invalid_argument& e) {
    cerr << "erreur: " << e.what() << endl;
    cerr << -1 << endl;
  }
}