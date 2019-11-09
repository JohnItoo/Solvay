#include <algorithm>
#include <iostream>
#include <pair>
#include <vector>
Using namespace std;
vector<pair<int, int>> v;

int main() {
 int n,m;
 bool rgt[n];

 cin >> n >> m;
 int max = m;
while (max--) {
 int a, b;
cin >> a >> b;
 v.push_back(make_pair(a, b));
}

// For each pair lets go through all the pairs and check which one occurs at least once

for(int i = 0; i < m; ++i) {
     pair<int,int> p1 = v[i];
	for(int j =0; j <m; ++j) {
	pair<int,int> p2 = v[j];
         if(p1.first !=  p2.first || p.first != p2.second || p1.second != p2.first || p1.second != p2.second) {
         break;
	}
   }
}

}