// https://www.acmicpc.net/problem/9935
#include<iostream>
#include<string>
#include<vector>
using namespace std ;

int main() {
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    vector<char>vec ;
    string str, bomb ;
    cin >> str >>bomb;
    const auto length = bomb.length() ;

    for (char c: str) {
        vec.emplace_back(c) ;
        if (vec.size() < length) {
            // cout << "passed! \n" ;
            continue ;
        }
        int veclen = vec.size();

        // cout << veclen << endl ;
        bool isSame = true ;
        for (int i = 0; i<length; i++) {
            if (vec[veclen - 1 - i] != bomb[length - 1 - i]) {
                // cout << vec[veclen - 1 - i] << " " << bomb[length - 1 - i] << endl ;
                isSame = false ;
                break ;
            }
        }
        if (isSame) {
            // cout << "erase!" ;
            vec.erase(vec.end() - length , vec.end()) ;
        }
    }
    // cout << endl ;
    for (char c: vec) {
        cout << c ;
    }
    if (vec.empty()) {
        cout << "FRULA" ;
    }
}