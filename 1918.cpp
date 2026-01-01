// https://www.acmicpc.net/problem/1918

#include<iostream>
#include <stack>
using namespace std ;

int prec(const char &op) {
    if (op == '*' or op == '/') return 2 ;
    if (op == '+' or op == '-') return 1 ;
    return 0 ;
}

int main() {
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    string s ;
    cin >> s ;

    stack<char> st ;
    string out ;

    for (char c : s) {
        if ('A' <= c and c <= 'Z') {
            out += c ;
        }else if (c == '(') {
            st.push(c) ;
        }else if (c == ')') {
            while (!st.empty() and st.top() != '(') {
                out += st.top() ;
                st.pop() ;
            }
            if (!st.empty() and st.top() == '(') st.pop() ;
        }else {
            while (!st.empty() and prec(st.top()) >= prec(c)) {
                if (st.top() == '(') break ;
                out += st.top() ;
                st.pop() ;
            }
            st.push(c) ;
        }
    }

    while (!st.empty()) {
        if (st.top() != '(') out += st.top() ;
        st.pop() ;
    }

    cout << out << "\n" ;
    return 0 ;
}