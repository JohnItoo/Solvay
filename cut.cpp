#include <iostream>
#include <algorithm>
using namespace std;
int coord[100];

int DP(int left, int right) {

int cost = 100000;

 for(int i =left+1; i<right; ++i) {
  cost = min(cost, DP(left, i) + DP(i, right) + coord[right] - coord[left]); 
 cout << cost<<"\n";

 }
 return cost;

}

int main() {
 int n, l;

cin >> l >> n;
int i = 0;
while (i<n) {
 scanf("%d", &coord[i++]);
}

cout << "here";
DP(0,n);

 return 0;
}