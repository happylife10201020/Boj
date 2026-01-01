// https://www.acmicpc.net/problem/11286
#include<iostream>
#include<queue>
using namespace std ;

int main() {
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    int N ;
    cin >> N ;

    struct cmp {
        bool operator()(const int &a, const int &b) const {
            if (abs(a) != abs(b))
                return abs(a) > abs(b) ;
            return a > b ;
        }
    };
    priority_queue<int, vector<int>, cmp> pq ;
    int temp ;

    while (N--) {
        cin >> temp ;
        if (temp != 0) {
            pq.emplace(temp) ;
            continue ;
        }
        if (pq.empty()) {
            cout << "0\n" ;
            continue ;
        }
        cout << pq.top() << "\n" ; pq.pop() ;
    }
}