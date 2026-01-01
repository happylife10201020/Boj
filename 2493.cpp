// https://www.acmicpc.net/problem/2493
#include<iostream>
#include<stack>
#include<vector>
using namespace std ;

int main() {
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int N ;
    stack<pair<int, int>> st ;

    cin >> N ;
    int x ;

    // 큰 애들 중에 가장 최근에 push된 node 의 index를 print
    /*
     * naive : 하나 받을 때 마다 스택에 추가하고
     * 스택의 top값이랑 비교해서 top값이 크거나 같으면 그 값을 print
     *  O(n^2) ?
     *
     */
    vector<int> ans(N, 0) ;
    for (int i = 0; i<N; i++) {
        cin >> x ;
        while (!st.empty()) {
            if (st.top().first < x) {
                st.pop() ;
            } else {
                ans[i] = st.top().second + 1;
                break ;
            }
        }
        st.emplace(x, i) ;
    }

    cout << ans[0] ;
    for (int i = 1; i<N; i++) {
        cout << " " << ans[i] ;
    }
}