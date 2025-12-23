// https://www.acmicpc.net/problem/2579

#include <iostream>
#include <vector>
using namespace std ;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n ;
    cin >> n ;

    int score[301] = {0} ;
    for (int i = 1; i<=n ;i++) {
        cin >> score[i] ;
    }

    int dp[301] = {0} ;

    dp[1] = score[1] ;
    if (n >= 2) {
        dp[2] = score[1] + score[2] ;
    }

    for (int i = 3; i<=n ;i++) {
        dp[i] = max(
            dp[i-2] + score[i],
            dp[i-3] + score[i-1] + score[i]
            ) ;
    }

    cout << dp[n] ;
    return 0;
}