// https://www.acmicpc.net/problem/17298

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N ;
    cin >> N ;

    vector<int> arr(N) ;
    for (int i = 0; i<N ; i++) {
        cin >> arr[i] ;
    }

    stack<int> stk ;
    vector<int> ans(N, -1) ;
    for (int i = 0; i<N ;i++) {
        while (!stk.empty() and arr[stk.top()] < arr[i]) {
            ans[stk.top()] = arr[i] ; stk.pop() ;
        }
        stk.push(i) ;
    }

    cout << ans[0]  ;
    for (int i = 1; i<N ;i++) {
        cout << ' ' << ans[i] ;
    }
}