//
// Created by Lee on 25. 9. 26.
//

# include <iostream>
using namespace std;

struct data {
    int fibonacciNum ;
    int zeroNum ;
    int oneNum ;
};

int fibonacci(int n, int& a, int& b) {
    if (n == 0) {
        a++ ;
        return 0 ;
    }else if (n == 1) {
        b++ ;
        return 1;
    }else {
        return fibonacci(n-1, a ,b) + fibonacci(n-2, a, b);
    }
}

int main() {
    int T;
    cin >> T;

    int arr[41][3]  = {-1, };


    arr[0][0] = 0 ;
    arr[0][1] = 1 ;
    arr[0][2] = 0 ;

    arr[1][0] = 1 ;
    arr[1][1] = 0 ;
    arr[1][2] = 1 ;


    for (int i = 2; i<41; i++) {
        arr[i][0] = arr[i-1][0] + arr[i-2][0] ;
        arr[i][1] = arr[i-1][1] + arr[i-2][1] ;
        arr[i][2] = arr[i-1][2] + arr[i-2][2] ;
    }

    for (int i = 1; i <= T; i++) {
        int num;
        cin >> num ;
        cout << arr[num][1] << ' ' << arr[num][2] << endl;
    }
}
