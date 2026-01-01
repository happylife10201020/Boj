// https://www.acmicpc.net/problem/13335
#include<iostream>
#include<queue>
using namespace std ;

int main() {
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    int n, w, L ; // 개수, 길이, 최대하중
    cin >> n >> w >> L ;

    queue<int> q1, q2 ;
    int temp ;

    while (n--) {
        cin >> temp ;
        q1.push(temp) ;
    }

    int mTime = 0 ;
    int qSum = 0 ;
    while (w--) {
        q2.push(0) ;
    }

    while (!q1.empty() or qSum  > 0) {

        // 한칸씩 왼쪽으로
        qSum -= q2.front() ; q2.pop() ; mTime ++ ;
        if (!q1.empty() and qSum + q1.front() <= L) {
            q2.push(q1.front()) ;
            qSum += q1.front() ;
            q1.pop() ;
        } else {
            q2.push(0) ;
        }
    }
    cout << mTime ;
}