#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        int cnt  = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] & 1) cnt++;
        }
        if( cnt < k || cnt % 2 !=  k % 2) {
            cout << "NO\n";
            continue;
        }
        int mv = 0;

        cout << "YES\n";

        for(int i = 0; i < n; i++) {
            if (k == 1) break;
            if(mv < k && (a[i] & 1)) {
                mv++;
                cout << i + 1 << " ";
            }
        }
        cout << "\n";
    }


    return 0;
}