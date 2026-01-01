// https://www.acmicpc.net/problem/2667
#include<bits/stdc++.h>
using namespace std ;

int main() {
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    int N ;
    cin >> N ;
    vector<vector<char>> vec(N) ;
    for (auto &a : vec) {
        string str ;
        cin >> str ;
        // cout << str << endl ;
        for (const auto c : str) {
            a.emplace_back(c) ;
        }
    }


    vector<int> dist ;

    const vector addNum = {pair(0, 1), pair(1, 0), pair(-1, 0), pair(0, -1)};

    for (int i = 0; i<N; i++) {
        for (int l = 0; l<N; l++) {
            if (vec[i][l] == '1') {
                // BFS
                queue<pair<int, int>> q ;
                q.emplace(pair(i, l)) ;
                int num = 1 ;
                vec[i][l] = '0' ;
                while (!q.empty()) {
                    for (auto addN : addNum) {
                        int a = q.front().first + addN.first ;
                        int b = q.front().second + addN.second ;
                        if (0 <= a and a < N
                            and 0 <= b and b < N) {
                            if (vec[a][b] == '1') {
                                q.push(pair(a, b)) ;
                                vec[a][b] = '0' ;
                                num ++ ;
                            }
                        }
                    }
                    q.pop() ;
                    if (q.empty()) {
                        dist.emplace_back(num) ;
                    }
                }
            }
        }
    }

    sort(dist.begin(), dist.end()) ;
    cout << dist.size() ;
    for (const auto i : dist) {
        cout << "\n" << i ;
    }
}