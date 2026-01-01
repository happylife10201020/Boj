// https://www.acmicpc.net/problem/15591
#include<iostream>
#include <vector>
#include<climits>
using namespace std ;

/* graph, 출발 노드, 가중치값, 가중치 기준, 출력
 * */
void dfs( vector<pair<vector<pair<int, int>>, bool>> &g, int n, int val, int &kValue,int &rec){
    g[n].second = true ;
    for (auto v: g[n].first) {
        // cout << "start at " << n << "\n" ;
        if (g[v.first].second == true) {
            // cout << "passed \n" ;
            continue ;
        }
        if (min(val, v.second) >= kValue) {
            // cout << "added at " << n << " " << v.first << "\n" ;
            rec ++ ;
        }else {
            continue ;
        }
        dfs(g, v.first, min(val, v.second), kValue, rec) ;
    }
}

int main() {
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    int P, Q ;
    cin >> P >> Q ;

    /* 한 정점에서 모든 정점으로의 길이
     * Bellmanford?
     * 경로는 오직 한개임
     * bfs, dfs
     *
     * 경로 v1 -> v2 -> v3
        는 경로의 유사도중 최소값을 v1->v3의 유사도로 선택
     *
     * 양방향 그래프로 입력받고 dfs
     */

    vector<pair<vector<pair<int, int>>, bool>> vec(P+1) ;
    int x, y, z ;
    for (int i = 0; i<P-1 ; i++) {
        cin >> x >> y >> z ;
        vec[x].first.emplace_back(y,z) ;
        vec[y].first.emplace_back(x, z) ;
    }

    int k, v ;
    for (int i = 0; i<Q; i++) {
        // 모든 노드 방문 x로 만들기
        cin >> k >> v ; // 유사도 k이고, 현재 동영상 v를 보고 있을 때

        int recVdCnt = 0 ;
        for (int l = 0; l<=P; l++) {
            vec[l].second = false ;
        }
        dfs(vec, v, INT_MAX, k, recVdCnt) ;
        cout << recVdCnt << "\n" ;
    }
}