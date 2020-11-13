#include <bits/stdc++.h>
#define  ll long long
using namespace std;


int main() {
  ll s, c; cin >> s >> c;
  ll ans = 0;
  if(s * 2 >= c) {
  	ans = c/2;
  } else {
  	ll a = c - (2*s);
  	ll rem = a/4;
  	ans = s + rem;
  }
  cout << ans << endl;
  
  
  return 0;
}