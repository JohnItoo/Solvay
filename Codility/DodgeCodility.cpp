// you can use includes, for example:
#include <bits/stdc++.h>

#include <algorithm>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool solution(vector<int> &P, vector<int> &T, vector<int> &A, vector<int> &B) {
  // write your code in C++14 (g++ 6.2.0)
  int n = P.size();
  int m = A.size();
  vector<vector<int> > graph(n);
  for (int i = 0; i < m; i++) {
    graph[A[i]].push_back(B[i]);
    graph[B[i]].push_back(A[i]);
  }
  vector<int> done(n, 0);
  for (int i = 0; i < n; i++) {
    if (done[i]) continue;
    stack<int> dfs;
    dfs.push(i);
    int desone = 0, one = 0;
    int destwo = 0, two = 0;
    while (!dfs.empty()) {
      int top = dfs.top();
      dfs.pop();
      if (done[top]) continue;
      done[top] = 1;

      if (P[top] == 1)
        one++;
      else
        two++;
      if (T[top] == 1)
        desone++;
      else
        destwo++;
      for (auto edge : graph[top]) {
        dfs.push(edge);
      }
    }

    if (desone != one || destwo != two) {
      return false;
    }
  }
  return true;
}
