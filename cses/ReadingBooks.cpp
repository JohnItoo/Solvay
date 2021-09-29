#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.rbegin(), a.rend());
    if (n == 1) {
        cout << a[0] * 2 << endl;
        return 0;
    }

    ll left = 0;
    ll right = 0;
    int i = 0;
    int tm = 0;
    while (i < n) {
        ll currL = a[i];
        int j = i + 1;
        ll currR = 0;
        tm++;
        while (j < n && currR < currL) {
            currR += a[j++];
        }
        left += currL;
        right += currR;
        i = j;
    }
    ll ans = accumulate(a.begin(), a.end(), 0LL);
    if (tm == 1) {
        cout << min(max(left, right) * 2, ans) << endl;
    } else {
        cout << left + right << endl;
    }

    return 0;
}