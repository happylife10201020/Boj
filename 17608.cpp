// https://www.acmicpc.net/problem/17608
#include<bits/stdc++.h>
using namespace std ;

int main() {
    int N ;
    cin >> N ;
    stack<int> s ;
    while (N--) {
        int temp ;
        cin >> temp ;
        s.emplace(temp) ;
    }
    int max = s.top() ; s.pop() ;
    int count = 1 ;
    while (!s.empty()) {
        if (s.top() > max) {
            count ++ ;
            max = s.top() ;
        }
        s.pop() ;
    }
    cout << count ;
}