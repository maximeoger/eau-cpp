#include <iostream>
#include <string>
#include <vector>
#include "./misc/checkArgs.cpp"

using namespace std;

/*
  Tri a bulles:
  Programme qui qui trie une liste de nombres.
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

    
    for(int i=arr.size()-1; i>1; i--) {
      bool sorted = true;
      for(int j=0; j<i-1; j--) {
        int next = arr[j+1];
        int current = arr[j];

        if(next < current) {
          arr[j+1] = current;
          arr[j] = next;
          sorted = false;
        }
      }
      if(sorted == true) break;
    }
    

    for(int i=0; i<arr.size(); i++) {
      cout << arr[i] << " ";
    }

    // [1]    2584 segmentation fault  ./out 6 5 4 3 2 1

  } catch(const invalid_argument& e) {
    cerr << "erreur: " << e.what() << endl;
    cerr << -1 << endl;
  }
}