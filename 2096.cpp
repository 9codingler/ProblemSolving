#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int map[100000][3];
int maxdp[3][3];
int mindp[3][3];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> map[i][j];
        }
    }

    if(n == 1) {
        cout << max({map[0][0], map[0][1], map[0][2]}) << ' ' << min({map[0][0], map[0][1], map[0][2]}) << '\n';
        return 0;
    }

    for(int j = 0; j < 3; j++) {
        maxdp[0][j] = map[0][j];
        mindp[0][j] = map[0][j];
    }

    for(int i = 1; i < n; i++) {
        maxdp[1][0] = max(maxdp[0][0], maxdp[0][1]) + map[i][0];
        maxdp[1][1] = max({maxdp[0][0], maxdp[0][1], maxdp[0][2]}) + map[i][1];
        maxdp[1][2] = max(maxdp[0][1], maxdp[0][2]) + map[i][2];

        mindp[1][0] = min(mindp[0][0], mindp[0][1]) + map[i][0];
        mindp[1][1] = min({mindp[0][0], mindp[0][1], mindp[0][2]}) + map[i][1];
        mindp[1][2] = min(mindp[0][1], mindp[0][2]) + map[i][2];
        
        for(int j = 0; j < 3; j++) {
            maxdp[0][j] = maxdp[1][j];
            mindp[0][j] = mindp[1][j];
        }
    }

    cout << max({maxdp[1][0], maxdp[1][1], maxdp[1][2]}) << ' ' << min({mindp[1][0], mindp[1][1], mindp[1][2]}) << '\n';
    return 0;   
}
