// https://www.acmicpc.net/problem/3190

#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
using namespace std ;

int main() {
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int N, K ;
    cin >> N ;
    cin >>  K ;

    vector<pair<int, int>> list(K, pair(0, 0)) ; // 사과가 있는 위치
    for (int i = 0; i<K ; i++) {
        cin >> list[i].first >> list[i].second ;
    }

    int L ;
    cin >> L ;
    queue<pair<int, char>> cmd ; // first초에 second방향
    for (int i = 0; i < L ; i ++) {
        pair<int, char>temp ;
        cin >> temp.first >> temp.second ;
        cmd.emplace(temp) ;
    }

    vector<pair<short, short>> dirAdd (4) ; // 방향 help변수
    dirAdd[0] = pair(1, 0) ;
    dirAdd[1] = pair(0, 1) ;
    dirAdd[2] = pair(-1, 0) ;
    dirAdd[3] = pair(0, -1) ;

    vector<vector<short>> gameMap(N+1, vector<short>(N+1, 0)) ; // 게임 맵
    for (auto a : list) {
        gameMap[a.first][a.second] = 1 ; // 1: 사과가 있음 2: 내가 있음 0: 아무것도 없음
    }

    queue<pair<short, short>> q ;
    q.emplace(pair(1, 1)) ;

    int dirNum = 0 ;
    pair<short, short> userPlace(pair(1, 1)) ;
    short gameTime = 0 ;
    gameMap[1][1] = 2 ;


    // for (int i = 1; i <= N ;i++) {
    //     for (int j = 1; j <= N ; j++) {
    //         cout<< gameMap[i][j] << " " ;
    //     }
    //     cout << endl ;
    // }
    while (q.size() <= N * N) {
        gameTime++ ;
        dirNum = (dirNum + 4) % 4 ; // 범위 조정

        userPlace.first += dirAdd[dirNum].second ;
        userPlace.second += dirAdd[dirNum].first ;

        q.emplace(userPlace) ;

        if (userPlace.first <= 0 or userPlace.first > N or
            userPlace.second <= 0 or userPlace.second > N) {
            // cout << "wall \n" ;
            // cout << userPlace.first << " " << userPlace.second << "\n" ;
            break ; // 벽에 부딛치면 break
            }

        if (gameMap[userPlace.first][userPlace.second] == 2) {
            // cout << "me \n" ;
            break ; // 나에게 부딛치면 break
        }

        if (gameMap[userPlace.first][userPlace.second] == 0) {
            gameMap[q.front().first][q.front().second] = 0 ;
            // cout << "here "  ;
            q.pop() ;
        } else {
            // cout << "increase len at " << gameTime << "\n" ;
        }
        gameMap[userPlace.first][userPlace.second] = 2 ;

        if (cmd.front().first == gameTime) {
            switch (cmd.front().second) {
                case 'L' :
                    dirNum-- ;
                    break ;
                case 'D' :
                    dirNum++ ;
                    break ;
                default:
                    break ;
            }
            // cout << "changed dir at " << gameTime << " to " << cmd.front().second << '\n';
            // cout << "dirNum is " << dirNum << "\n" ;
            // for (int i = 1; i <= N ;i++) {
            //     for (int j = 1; j <= N ; j++) {
            //         cout<< gameMap[i][j] << " " ;
            //     }
            //     cout << endl ;
            // }
            cmd.pop() ;
        }
    }

    // for (int i = 1; i <= N ;i++) {
    //     for (int j = 1; j <= N ; j++) {
    //         cout<< gameMap[i][j] << " " ;
    //     }
    //     cout << endl ;
    // }
    cout << gameTime ;
}