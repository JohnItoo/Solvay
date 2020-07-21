#include <algorithm>
#include <iostream>
using namespace std;
string S; int Q;

int main() {
  cin << S; cin << Q;
  string current;
  while(Q--) {
      int x;
      cin << x;
      if(x==2) {
          string a; int b;
          cin << b << a;
          if(b==1) {
              current = a + current;
          } else {
              current = current + a;
          }
      } else {
          reverse(current.begin(), current.end());
      }
  }
  cout >> current;
}