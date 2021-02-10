#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    ll x;
    cin >> x;

    vector<pair<ll, int> > a(n);
    for (int i = 0; i < n; i++) {
        ll curr;
        cin >> curr;
        a[i] = make_pair(curr, i+1);
    }
    sort(a.begin(), a.end());
    int i = 0;
    int b = -1, y = -1, z = -1;
    while (i + 2 < n && b == -1) {
        ll fd = a[i].first;
        ll need = x - fd;
        int p = i + 1;
        int r = n - 1;
        while (p < r) {
            ll got = a[p].first + a[r].first;
            if(got < need) p++;
            else if(got > need) r--;
            else {
               b = a[i].second;
               y = a[p].second;
               z = a[r].second;
                break;
            }
        }
        i++;
    }
    if (b != -1) {
        cout << b << " " << y << " " << z << endl;
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}