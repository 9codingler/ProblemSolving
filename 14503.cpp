#include <iostream>
using namespace std;

int n, m, x, y, direction;

int map[50][50];
bool visited[50][50];

int dx[] = {-1, 0, 1, 0}; // 북 동 남 서.
int dy[] = {0, 1, 0, -1};

void rotate() {
    direction--;
    if(direction < 0) {
        direction = 3;
    }    
}

int main() {
    int ans = 0;
    cin >> n >> m;
    cin >> x >> y >> direction;

    visited[x][y] = true;
    ans++;

    for(int i = 0; i < n; i++) { //문제보면 x, y를 위에서 몇번째 떨어졌는지로 표기하므로, i, j를 1이 아닌 0부터 써야함.
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int rotatesum = 0;

    while(1) {
        rotatesum++; // 회전시키고 회전카운트 늘리면 if(rotatesum == 5) 부분에서 회전시키지 말아야 하는데 회전이 된다.
                     // 또한 첫번째if문을 밑으로 두면 두번째 if문에서 계속 continue 뜰수도 있어서 이대로 두는게 안전하더라.
                     // => 회전함수는 if(rotatesum == 5) 밑에 && if(rotatesum == 5)문은 윗부분에 두는게 맞다.
        if(rotatesum == 5) {
            if(direction == 0) {
                x++;
            }
            if(direction == 1) {
                y--;
            }
            if(direction == 2) {
                x--;
            }
            if(direction == 3) {
                y++;
            }
            if(map[x][y] == 1) {
                break;
            }
            rotatesum = 0;
            continue;
        }

        rotate();
        int nx = x + dx[direction];
        int ny = y + dy[direction]; 

        if(visited[nx][ny] || map[nx][ny] == 1 || nx < 0 || ny < 0 || nx >= n || ny >= m) {
            continue;
        }

        x = nx;
        y = ny;

        rotatesum = 0;
        visited[x][y] = true;
        ans++;
    }

    cout << ans << '\n';
    return 0;
}
