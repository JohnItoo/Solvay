#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int odds = 0, evens = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] & 1)
                odds++;
            else
                evens++;
        }
        if (odds == 0) {
            cout << -1 << endl;
        } else {
            cout << evens << endl;
        }
    }
    return 0;
}