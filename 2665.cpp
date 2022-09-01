#include <iostream>
#include <queue>
#include <cstring>
#define MAX 51
using namespace std;

int dx[] = {0, 1, 0, -1}; // 동 남 서 북
int dy[] = {1, 0, -1, 0};
int map[51][51];
int ans[51][51]; //dist

int n;

void dijkstra() {
    fill(&ans[0][0], &ans[50][51], MAX);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    ans[1][1] = 0;
    pq.push({0, {1, 1}});

    while(!pq.empty()) {
        int cur_count = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if(ans[x][y] < cur_count) {
            continue;
        }

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || nx > n || ny < 1 || ny > n) {
                continue;
            }

            if(map[nx][ny] == 1) {
                if(ans[nx][ny] <= cur_count) {
                    continue;
                } 
                ans[nx][ny] = cur_count;
                pq.push({cur_count, {nx, ny}});
            }

            else if(map[nx][ny] == 0) {
                if(ans[nx][ny] <= cur_count + 1) {
                    continue;
                }
                ans[nx][ny] = cur_count + 1;
                pq.push({cur_count + 1, {nx, ny}});
            }
        }
    }

    cout << ans[n][n] << '\n';
    return;
}   

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    dijkstra();

    // 출력문.
    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         cout << ans[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    return 0;
}
