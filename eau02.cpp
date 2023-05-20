#include <iostream>
#include <iomanip>

using namespace std;

void print(int num){
  if(num<10) {
    cout << "0";
  }
  cout << num;
}

int main(){
  int max = 9;

  for(int i=0; i<=max; i++) {
    for(int j=0; j<=max; j++) {
      for(int k=0; k<=max; k++) {
        for(int l=0; l<=max; l++) {

          string strFirst = to_string(i) + to_string(j);
          string strSecond = to_string(k) + to_string(l);
          
          int numFirst = stoi(strFirst);
          int numSecond = stoi(strSecond);

          if(numFirst != numSecond) {
            print(i);
            cout << " ";
            print(j);
            cout << ", ";

            print(k);
            cout << " ";
            print(l);
            cout << ", ";
          }
             
        }
      }
    }
  }

  cout << "\n";
  return 0;
}