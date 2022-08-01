#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dx[] = {-1, 0, 1, 0}; //북 동 남 서
int dy[] = {0, 1, 0, -1};
int map[9][9]; //0행과 0열은 다 1로 초기화하자.(벽 느낌으로.)
int copymap[9][9];
int n, m, ans = 0;
vector<pair<int, int>> v;

void bfs() {
    queue<pair<int, int>> q;

    for(int j = 0; j < v.size(); j++) {
        q.push(v[j]);
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (map[nx][ny] == 1 || map[nx][ny] == 2 || nx > n || ny > m || nx < 1 || ny < 1) { //map[nx][ny]가 0이나 2일경우 2로 만들어줌.
                    continue;
                }

                map[nx][ny] = 2;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for(int x = 1; x < n + 1; x++) {
        for(int y = 1; y < m + 1; y++) {
            cin >> map[x][y];
            copymap[x][y] = map[x][y];
            if(map[x][y] == 2) {
                v.push_back(make_pair(x, y));
            }
        }
    }

    for(int x1 = 1; x1 < n + 1; x1++) {
        for(int y1 = 1; y1 < m + 1; y1++) {
            if(map[x1][y1] != 0) continue;
            for(int x2 = 1; x2 < n + 1; x2++) {
                for(int y2 = 1; y2 < m + 1; y2++) {
                    if(map[x2][y2] != 0) continue;
                    if (x1 == x2 && y1 == y2) continue;
                    for(int x3 = 1; x3 < n + 1; x3++) {
                        for(int y3 = 1; y3 < m + 1; y3++) {
                            if(map[x3][y3] != 0) continue;
                            if (x1 == x2 && y1 == y2) continue;
                            if (x1 == x3 && y1 == y3) continue;
                            if (x2 == x3 && y2 == y3) continue;
                            int sum = 0;
                            map[x1][y1] = 1;
                            map[x2][y2] = 1;
                            map[x3][y3] = 1;
                            bfs();
                            for(int i = 1; i < n + 1; i++) {
                                for(int j = 1; j < m + 1; j++) {
                                    if (map[i][j] == 0) {
                                        sum++;
                                    }
                                    map[i][j] = copymap[i][j];
                                }
                            }
                            ans = max(ans, sum);
                        }
                    }
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
    
}
