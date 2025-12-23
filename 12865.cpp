// https://www.acmicpc.net/problem/12865
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K ; // 개수, 최대 무게
    cin >> N >> K ;

    vector<vector<int>> arr(N, vector<int>(2)) ;
    for (int i = 0 ; i<N ;i++) {
        cin >> arr[i][0] >> arr[i][1] ; // weight, value
    }

    vector<int> dp(K+1, 0) ;

    for (int i = 0; i<N ; i++) {
        int weight = arr[i][0] ;
        int value = arr[i][1] ;
        for (int l = K; l>=weight; l--) {
            dp[l] = max(dp[l], dp[l-weight] + value) ;
        }
    }

    cout << dp[K] << endl;
    return 0;
}