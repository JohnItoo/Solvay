#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N;
vector<char> vc;

bool isCorrect() {
 int sz = vc.size();

if(vc[sz -1] != '.' || vc[0] != 'B' ) {
 return false;
} 
bool should = true;
for(int i = 0; i< sz-1; ++i) {
 if(vc[i] == '.' && vc[i+1] == '.') {
  should = false;
  break;
}
}
 return should;

}

int main() {
 cin >> N;

int TC = 1;

while(TC <= N) {
string put;
getline(cin, put);
cin.ignore();
int l = put.length();
for(int i = 1; i<l; ++i) {
  vc.push_back(put[i]);
}
bool ans = false;
do {
 if ( isCorrect()) {
   ans = true;
   break;
}
} while (next_permutation(vc.begin(), vc.end()));

if(ans) cout <<"Case #"<<TC<<":"<<" "<< "Y"<< endl;
else cout <<"Case #"<<TC<<":"<<" "<< "N"<< endl;
TC++;
}

}