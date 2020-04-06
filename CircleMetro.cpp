#include <algorithm>
#include <iostream>
using namespace std;

int main () {
int n, a, x,b,y = 0;
cin >> n >> a >> x >> b >>y;
int dan, vlad = 0;
int ans = -1;
dan = a -1; vlad = b -1;
 while(true) {
   if(dan == vlad) {
	 cout<<"YES\n";
	 return 0;
   }
   if(dan == x || vlad == y) {
         break;
   }
   dan =  (dan +  1) % n ;

   vlad = (vlad - 1 + n) % n;
   
  }
  cout << "NO";

}