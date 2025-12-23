#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

int main() {
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int N, M ;
    cin >> N ;
    vector<int> A(N) ;

    for (int i = 0; i<N; i++) {
        cin >> A[i] ;
    }

    sort(A.begin(), A.end()) ;

    cin >> M ;
    while (M--) {
        int x ;
        cin >> x ;
        cout << binary_search(A.begin(), A.end(), x) << "\n" ;
    }
}