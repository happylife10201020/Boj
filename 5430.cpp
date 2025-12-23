// https://www.acmicpc.net/problem/5430

#include <iostream>
#include <deque>
using namespace std ;

int main() {
    int T ;
    cin >> T ;

    while (T--) {
        string p ; int n ;
        cin >> p >> n ;

        string arr ;
        cin >> arr ;

        // parsing
        deque<int> dq ;
        for (int i = 1; i<arr.size(); i++) {
            string temp = "";
            while ('0' <= arr[i] and arr[i] <= '9') {
                temp += arr[i++] ;
            }
            if (temp.size() > 0) {
                dq.push_back(stoi(temp)) ;
            }
        }


        bool rev = false ;
        bool err = false ;
        for (char c: p) {
            if (err) break ;
            switch (c) {
                case 'R' :
                    rev = !rev ;
                    break ;
                case 'D' :
                    if (dq.empty()) {
                        err = true ;
                        break ;
                    }
                    if (rev) {
                        dq.pop_back();
                    }
                    else {
                        dq.pop_front();
                    }
            }
        }

        if (err) {
            cout << "error" << endl ;
            continue ;
        }

        cout << "[" ;
        if (!dq.empty()) {
            if (!rev) {
                cout << dq.front() ;
                dq.pop_front();
                while (!dq.empty()) {
                    cout << "," << dq.front() ; dq.pop_front();
                }
            } else {
                cout << dq.back() ;
                dq.pop_back();
                while (!dq.empty()) {
                    cout << "," << dq.back() ; dq.pop_back();
                }
            }
        }
        cout << "]" << endl ;
    }
}