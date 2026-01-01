// https://www.acmicpc.net/problem/2178
#include<bits/stdc++.h>
using namespace std ;

int main() {
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    int N, M ;
    cin >> N >> M ;
    vector<string> vec ;
    vector<vector<int>> minNum(N) ;

    for (auto &v : minNum) {
        for (int i = 0; i<M; i++ ) {
            v.emplace_back(INT_MAX) ;
        }
    }
    for (int i = 0; i<N; i++) {
        string str ;
        cin >> str ;
        vec.emplace_back(str) ;
    }

    minNum[0][0] = 1 ;

    const vector adNum = {pair(1, 0), pair(0, 1), pair(-1, 0), pair(0, -1)} ;

    function<void(pair<int, int>)> graphSearch = [&] (const pair<int, int> &p) {
        for (auto adN : adNum) {
            int a = p.first + adN.first ;
            int b = p.second + adN.second ;
            if (0 <= a and a < N
                and 0<= b and b < M) {
                // cout << vec[a].at(b) << " ";
                // cout << minNum[a][b] << " " << minNum[p.first][p.second] << endl;
                // cout << (vec[a].at(b) == '1' ) << endl ;
                    //minNum[a][b] > minNum[p.first][p.second] + 1) << endl ;
                if (vec[a].at(b) == '1' and
                    minNum[a][b] > minNum[p.first][p.second] + 1) {
                    minNum[a][b] = minNum[p.first][p.second] + 1 ;
                    // cout << "goto Recursive " << endl ;
                    graphSearch(pair(a, b)) ;
                }
            }
        }
    } ;

    graphSearch(pair(0, 0)) ;
    cout << minNum[N-1][M-1] ;
}