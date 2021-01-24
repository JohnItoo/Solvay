#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> teams(n + 5, 0);
    vector<vector<int> > adj(n + 5, vector<int>());

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool impossible = false;
    for (int i = 1; i <= n; i++) {
        if (teams[i]) continue;
        if (impossible) break;
        stack<pair<int, int> > toProcess;
        pair<int, int> curr = make_pair(i, 1);
        toProcess.push(curr);

        while (!toProcess.empty() && !impossible) {
            pair<int, int> item = toProcess.top();
            toProcess.pop();
            int person = item.first;
            int team = item.second;
            if (teams[person] != 0 && teams[person] != team) {
                impossible = true;
                break;
            }

            for (int ct : adj[person]) {
                if (teams[ct] == 0) {
                    int friendTeam = team == 1 ? 2 : 1;
                    toProcess.push(make_pair(ct, friendTeam));
                } else if (teams[ct] == team) {
                    impossible = true;
                    break;
                }
            }
            teams[person] = team;
        }
    }
    if (impossible)
        cout << "IMPOSSIBLE\n";
    else {
        for (int i = 1; i <= n; i++) cout << teams[i] << " ";
        cout << endl;
    }

    return 0;
}
