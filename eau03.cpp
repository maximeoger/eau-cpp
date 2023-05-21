#include <iostream>
#include <vector>

using namespace std;

void printErr(string message) {
  cerr << message << "\n";
}

void checkArgs(int argc) {
  bool noArguments = argc == 1;

  if(noArguments) {
    throw invalid_argument("Error.");
  }
}

int main(int argc, char* argv[]){

  try {
    checkArgs(argc);
  } catch (exception) {
    printErr("Erreur .");
    return 1;
  }

  vector<string> args; 
  int count =  argc-1;
  
  for(int i=1; i<=count; i++) {
    args.push_back(string(argv[i]));
  }
  
  for(int i=args.size()-1; i>=0; i--) {   
    string arg = string(args[i]);
    int len = arg.size(), j = 0;
    char arr[len];

    while (arr[j] != "\0") {
      
    }
  }

  cout << "\n";
  
  return 0;
}