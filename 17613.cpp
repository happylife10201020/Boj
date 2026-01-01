// https://www.acmicpc.net/problem/17613
#include<bits/stdc++.h>
using namespace std ;

int main() {
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    int T ;
    cin >> T ;

    vector<int> vec ;
    vec.emplace_back(0) ;
    auto num = 1;
    while (num < 1000000000) {
        vec.emplace_back(num) ;
        num = num * 2 ;
    }
    map<int, int> m ;
    for (int i = 0; i<vec.size() ;i ++) {
        m.emplace(i, vec.at(i)) ;
    }

    while (T--) {
        long long x, y ;
        cin >> x >> y ; // 구간 [x, y] 에서 J(i)의 최댓값

        //Greedy

    }
}