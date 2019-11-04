#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
int M,N, mem[10005],coins[4];

int coin(int M) {
 if(M <  0) {
  return 10000;
}
 if(M  == 0) {
   return 0;
}

if(mem[M] != -1) {
  return mem[M];
}
   int ans = 10000;
  for(int j = 0; j<N; ++j) {
    ans = min (ans, 1+ coin(M - coins[j]));
}
 cout << ans << "\n";
 return mem[M] = ans;;

}

int main() {
cin >> M >> N;
for (int i = 0; i < N; ++i) {
 cin >> coins[i];
}

memset(mem, -1, sizeof mem);
int ans = coin(M);
cout << ans;

return 0;
}