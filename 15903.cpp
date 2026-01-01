// https://www.acmicpc.net/problem/15903
#include<iostream>
#include<queue>
using namespace std ;

int main() {
    int N, M ;
    cin >> N >> M ;

    priority_queue<long long, vector<long long>, greater<>> pq ;
    long long temp ;
    while (N--) {
        cin >> temp ;
        pq.emplace(temp);
    }

    while (M--) {
        long long x = pq.top(); pq.pop() ;
        const long long y = pq.top() ; pq.pop() ;
        x = x + y ;
        pq.emplace(x) ;
        pq.emplace(x) ;
    }

    long long sum = 0 ;
    const int m = pq.size() ;
    for (int i = 0; i < m ; i++) {
        sum += pq.top() ;
        pq.pop() ;
    }
    cout << sum ;
}