#include <bits/stdc++.h>

using namespace std;

int main() {

    int tc; cin >> tc;
    while (tc--) {
        int n;  cin >> n;
        vector<int> a(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            a[i] = x + a[i - 1];
        }

        int left = 1;

        while (left <= n && (a[left] % 2) == 0) {
            left++;
        }
        if (left == n + 1) {
            cout << "NO\n";
            continue;
        }
        int mid = left + 1;
        int right = n;

        // while(left < mid && mid < right && !((a[left] - a[0]) & 1 ) && (a[mid] - a[left] & 1) && (a[right] - a[mid] & 1) ) {

        // }
        cout << a[mid] << " mid\n";
        cout << a[left] << " left\n";
        cout << a[mid] - a[left] << " mid left\n";
        cout << a[n] - a[mid] << " n mid\n";
        while ( mid < n && (((a[mid] - a[left]) % 2 == 0) || ((a[n] - a[mid]) % 2  == 0) )) {
            mid++;
        }
        if (mid == n) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        cout << left << " " << mid << " " << right  << "\n";

    }
    return 0;
}