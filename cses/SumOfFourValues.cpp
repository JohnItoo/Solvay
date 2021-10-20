#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n;
  cin >> n;
  ll x;
  cin >> x;

  map<ll, int> fq;

  vector<pair<ll, int> > a(n);
  for (int i = 0; i < n; i++) {
    ll curr;
    cin >> curr;
    a[i] = make_pair(curr, i + 1);
    fq[curr]++;
  }
  sort(a.begin(), a.end());
  int i = 0;
  int b = -1, y = -1, z = -1;
  int look = -1;
  set<int> picked;
  while (i + 1 < n && b == -1) {
    ll fd = a[i].first;
    ll need = x - fd;
    int p = i + 1;
    int r = n - 1;
    while (p < r) {
      ll got = a[p].first + a[r].first;
      if (got < need) {
        int rem = need - got;

        map<ll, int> mp;
        mp[fd]++;
        mp[a[p].first]++;
        mp[a[r].first]++;
        mp[rem]++;

        bool vld = true;

        for (auto hr : mp) {
          if (fq.find(hr.first) != fq.end() && hr.second <= fq[hr.first])
            continue;
          vld = false;
          break;
        }
        if (vld) {
          b = a[i].second;
          y = a[p].second;
          z = a[r].second;
          picked.insert(b);
          picked.insert(y);
          picked.insert(z);
          look = rem;
          break;
        } else {
          p++;
        }
      } else if (got >= need)
        r--;
    }
    i++;
  }
  int q = -1;
  for (int i = 0; i < n; i++) {
    if (a[i].first == look && picked.find(a[i].second) == picked.end()) {
      q = a[i].second;
      break;
    }
  }
  if (b != -1) {
    cout << b << " " << y << " " << z << " " << q << endl;
  } else {
    cout << "IMPOSSIBLE\n";
  }

  return 0;
}