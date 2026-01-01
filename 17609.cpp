// https://www.acmicpc.net/problem/17609
#include<iostream>
using namespace std ;

int main() {
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    int N ;
    cin >> N ;

    while (N--) {
        string str ;
        cin >> str ;

        // cout << str.at(0) << endl ;
        int result = 0 ;

        size_t i = 0, j = str.length() - 1 ;

        while (i < j) {
            if (str.at(i) == str.at(j)) {
                i++ ; j-- ;
                continue ;
            }
            if (result == 0 and str.at(i + 1) == str.at(j)) {// abbab 이면 2나옴
                if (str.at(i) == str.at(j-1)) {
                    // 두 조건 다 만족시킬 때
                    // case1, 2로 나누어서 생각

                    size_t i2 = i, j2 = j-1 ;
                    bool isOk = true ;

                    while (i2 < j2) {
                        if (str.at(i2) == str.at(j2)) {
                            i2++; j2-- ;
                        } else {
                            isOk = false ;
                            break ;
                        }
                    }
                    if (isOk) {
                        result = 1 ;
                        break ;
                    }
                    isOk = true ;
                    i2 = i + 1; j2 = j ;
                    while (i2 < j2) {
                        if (str.at(i2) == str.at(j2)) {
                            i2++; j2-- ;
                        } else {
                            isOk = false ;
                            break ;
                        }
                    }
                    if (isOk) {
                        result = 1 ;
                        break ;
                    }
                    result = 2 ;
                    break ;

                } else {
                    // 여기서는 i+1 ~ j 가 싹 회문이면 1 아니면 2
                    i += 2 ; j-- ;
                    result = 1 ;
                }
            }else if (result == 0 and str.at(i) == str.at(j-1)) {
                // 여기서는 i ~ j-1 가 싹 회문이면 1 아니면 2
                i++ ; j -= 2 ;
                result = 1 ;

            } else{
                result = 2 ;
                break ;
            }
        }
        cout << result << endl ;
    }
}