#include <bits/stdc++.h>
using namespace std;
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> a;
        map<int, int> freq;
        int ct = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }

        sort(a.begin(), a.end());
        int i = 0;
        int j = a.size() - 1;
        while (i < j) {
            if (a[i] + a[j] < k)
                i++;
            else
                break;
        }
        int rem = (j - i + 1) / 2;

        cout << ct + rem << endl;
    }
}