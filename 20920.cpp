#include<iostream>
#include<vector>
#include <algorithm>
#include <unordered_map>
using namespace std ;

struct word {
    string name ;
    int num ;

    bool operator <(const word &d) const {
        if (num == d.num) {
            return name > d.name ;
        }
        return num > d.num ;
    }
};

int main() {
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int N, M ;
    cin >> N >> M ;


    unordered_map<string, int> um ;
    for (int i = 0; i<N; i++) {
        string temp ;
        cin >> temp ;

        if (temp.length() < M) continue ;

        if (um.find(temp) != um.end()) {
            um[temp]++ ;
        }else {
            um.insert(pair(temp, 1)) ;
        }
    }

    vector<pair<string, int>>vec ;
    for (auto & p: um) {
        vec.push_back(p) ;
    }
    sort(vec.begin(), vec.end(), [](pair<string, int>& a, pair<string, int>& b)  {
        if (a.second == b.second) {
            if ( a.first.length() == b.first.length()) {
                return a.first < b.first ;
            }
            return a.first.length() > b.first.length() ;
        }
        return a.second > b.second ;
    }) ;

    for (auto &a: vec) {
        cout << a.first  << "\n" ;
    }
}