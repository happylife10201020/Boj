// https://www.acmicpc.net/problem/1260
#include<bits/stdc++.h>
using namespace std ;

void dfs(const vector<vector<int>> &g, vector<int> &isVisited, const int &V) {
    // cout << V << " " ;
    for (int i : g[V]) {
        // cout << "looping .. now i is " << i << endl ;
        if (isVisited[i] == 0) {
            isVisited[i] = 1 ;
            // cout << "now is " << V ;
            // cout << " and goto " << i << endl ;
            cout << " " << i ;
            dfs(g, isVisited, i) ;
        }
    }
    // cout << "back " << endl ;
}



int main() {
    int N, M, V ;
    cin >> N >> M >> V ;

    vector<vector<int>> g(N+1) ;
    while(M--) {
        int a, b ;
        cin >> a >> b ;
        g[a].emplace_back(b) ;
        g[b].emplace_back(a) ;
    }

    for (auto &vec: g) {
        sort(vec.begin(), vec.end()) ;
    }
    vector<int> isVisit(N+1) ;

    // // DFS
    // isVisit[V] = 1 ;
    // cout << V ;
    // dfs(g, isVisit, V) ;

    function<void(int)> DFS = [&](int v) {
        isVisit[v] = 1 ;
        cout << v ;
        for (int nx : g[v]) {
            if (!isVisit[nx]) {
                cout << ' ' ;
                DFS(nx) ;
            }
        }
    } ;

    // BFS
    fill(isVisit.begin(), isVisit.end(), 0) ;
    isVisit[V] = 1 ;
    cout << "\n" << V ;
    queue<int> q1 ;
    q1.emplace(V) ;

    while (!q1.empty()) {
        for (int i: g[q1.front()]) {
            if (isVisit[i] == 0) {
                q1.emplace(i) ;
                cout << " " << i ;
                isVisit[i] = 1 ;
            }
        }
        q1.pop() ;
    }
}