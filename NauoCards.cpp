#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int n;

int main () {
  cin >> n;
  string pt;
  cin.ignore();
  getline(cin, pt);
  int count = 0;
  bool started = false;

  for(int i=0 ; i<n; ++i) {
   
      if(pt[i] == '+') { 
         started = true;
         count += 1;
      } else if(pt[i] == '-' && started) {
           started = true;
          count -= 1;
      }

  }
 cout << count;

return 0;

}

