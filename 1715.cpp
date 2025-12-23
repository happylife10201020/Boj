//https://www.acmicpc.net/problem/1715

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n ;
    cin >> n ;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        int num ;
        cin >> num ;
        pq.push(num);
    }

    int sum = 0 ;

    while (pq.size() > 1){

        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();

        int merged = a + b ;
        sum = sum + merged ;
        pq.push(merged);
    }

    cout << sum ;
    return 0 ;
}