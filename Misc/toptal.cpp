
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n;
int main() {
    cin >> n;
    vector<int> graph[1005];
    int arr[1005];
    bool solVisited[1005];
    int depth[1005];
    int prod[1005];
    queue<int> q;
    int capital = 1;
    
    for(int i = 0;i<n; ++i) scanf("%d",&arr[i]);
    
    for(int i = 0;i<n; ++i) {
        if(arr[i] != i){
            graph[i].push_back(arr[i]);
            graph[arr[i]].push_back(i);
        } else {
            capital = i;
        }
    }
    // set capital when arr[i] == i
    solVisited[capital] = true;
    depth[capital] = 0;
    q.push(capital);
    while(!q.empty()) {
        int currentCity = q.front(); q.pop();
                for(auto adjCity : graph[currentCity]) {
            if(solVisited[adjCity]) continue; // if we have visited this city ,skip!
            solVisited[adjCity] = true;       // mark present  adjacent city to current city as visited
            //increasing the number at (parent vertex + 1) by 1
            depth[adjCity] = depth[currentCity] + 1; // getting new depth based on depth of current city
            prod[depth[adjCity]]++; // increasing number of cities at new depth.
            // push city to q
            q.push(adjCity);
        }
    }
    
    for(int i = 1;i<n; ++i) {
        printf("%d, ", prod[i]);
    }
    return 0;
}

