
// you can use includes, for example:
#include <bits/stdc++.h>

#include <algorithm>
#include <cstdint>
    using namespace std;
using ll = long long int;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    stack<ll> st;
    int md = 1000000007;
    int sz = A.size();
    if (sz == 2) return 0;
    stack<ll> tot;

    for (int i = sz - 2; i > 0; i--) {
        ll val = (A[sz - 1] - A[i]) * 1LL;
        val %= md;
        st.push(val);
        if (tot.size() == 0) {
            tot.push(st.top());
        } else {
            ll here = (st.top() + tot.top());
            here %= md;
            tot.push(here);
        }
    }

    ll ans = (tot.top());
    int idx = 1;
    ll leftTotal = 0;
    while (idx < sz - 1) {
        int diff = A[idx] - A[idx - 1];
        leftTotal += (idx * diff * 1LL);
        leftTotal %= md;
        if (tot.size() > 0) tot.pop();
        ll tops = tot.size() > 0 ? tot.top() : 0;
        ll res = (leftTotal + tops);
        ans = min(ans, res);
        idx++;
    }
    return ans;
}