#include <iostream>
#define INF 1e9

using namespace std;

int map[101][101];

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < 101; i++) {
        for(int j = 0; j < 101; j++) {
            map[i][j] = INF;  
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int k;
            cin >> k;
            if(k == 1) {
                map[i][j] = k;
            }
        }
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }

    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         cout << map[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(map[i][j] < INF) {
                cout << 1 << ' ';
            }
            else {
                cout << 0 << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
