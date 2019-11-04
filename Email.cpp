#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
int n;
string f,s;

int main() {

cin >> n;
while(n--) {
cout << n<< "\n";
set<char> cs;
cin >> f;
cin >> s;

bool is = true;
char prev = 'a'; 
 char curr = 'c';
int lb, ls;
if(f.length() > s.length()) { lb = f.length(); ls = s.length();} 
if(f.length() < s.length()) { ls = f.length(); lb = s.length();}
else {ls = f.length(); lb = s.length();}

for(int i = 0 ; i < lb; i++) {
 if(i < s.length()) {curr = s[i];}
 else {is = false; break;}
 if(curr == prev) {continue;}
 if(i >= f.length()) {is = false; break;}
 if(curr!= prev &&  curr != f[i]) {
 is = false; 
break;
}
 prev = curr;

}
 if(is) cout << "YES\n";
 else cout << "NO\n";

}
return 0;
}