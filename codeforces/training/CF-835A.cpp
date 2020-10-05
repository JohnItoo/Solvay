#include <bits/stdc++.h>
using namespace std;

int main() {
	int s, v1, v2, t1, t2;
	cin >> s >> v1 >> v2 >> t1 >> t2;

   int lef = 2 * t1 + s * v1;
   int rig = 2 * t2 + s * v2;

   if(lef == rig) {
   	cout << "Friendship\n";
   } else if (lef < rig) {
   	cout << "First\n";
   } else {
   	cout << "Second\n";
   }

	return 0;
}