#include <iostream>
#include <algorithm>
using namespace std;
int n,m;

int main() {
cin >> n >> m;
int arr[n];

for(int i=0; i<n; i++) {
cin >> arr[i];
}

bool sot = true;
for(int i=0; i<n-1; i++) {
 if(arr[i] > arr[i+1]){ sot = false; break;}
}

if(!sot) {
 
   // how long will it take to be like the neighbouring integer.. 
bool arrng =  true;
int ans = -1;

for(int i =0; i < n-1; ++i) {
       arrng = true;
   for(int j = i; j<n -1; ++j) {
   	if(arr[j] >arr[j+1]) {
          cout << "enter false " << i << " " <<j;
          arrng = false;
          if(arr[j] == m-1) arr[j] = 0;
	  else arr[j+1] += 1;
   	} else if(arr[i] > (arr[j] || arr[j+1])) {
          if(arr[i] == m -1) { arr[i] = 0;}
	  else {arr[i] += 1;}
	  arrng = false;
          ans++;
	}

   }
   if(arrng) {ans = i;  break;}
}

cout << ans;

} else {
  cout << 0;
}

return 0;

}