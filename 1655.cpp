// https://www.acmicpc.net/problem/1655
#include<iostream>
#include<queue>
using namespace std ;

int main() {
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    int N ;

    cin >> N ;

    priority_queue<int> q1 ; // 작은거
    priority_queue<int, vector<int>, greater<int>> q2 ; // 큰거

    int num, temp ;
    while (N--) {
        cin >> num ;
        if (q1.empty() or num < q1.top()) { // input이 작은쪽 범위라면
            q1.push(num) ;
            if (q1.size() >= q2.size() + 2) { // 2개 차이나면
                temp = q1.top() ;
                q1.pop() ;
                q2.push(temp) ; // 서로 개수 같게 >> 짝수
            }
        } else if (q2.empty() or q2.top() < num ){ // input이 큰쪽 이라면
            q2.push(num) ;
            if (q2.size() >= q1.size() + 2) {
                temp = q2.top() ;
                q2.pop() ;
                q1.push(temp) ;
            }
        }else { // input이 중간 범위라면
            if (q1.size() <= q2.size()) {
                q1.push(num) ;
            } else {
                q2.push(num) ;
            }
        }

        if (!q2.empty() and q1.size() < q2.size()) {
            cout << q2.top() << "\n" ;
        } else {
            cout << q1.top() << "\n" ;
        }
    }

    return 0 ;
}