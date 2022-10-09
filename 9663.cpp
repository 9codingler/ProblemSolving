// idea : 각 줄마다 queen을 둘 y좌표(열)를 설정하고, 그에 대한 backtracking.
#include <iostream>

using namespace std;

int n;
int ans = 0;
// ys엔 그 인덱스에 해당하는 줄의 y좌표가 저장.
// ex / ys[1] = 2, ys[2] = 3 -> 각각 (1, 2), (2, 3)을 나타냄.
int ys[16];

void solve(int level, int y) {
    // 현재 level과, 집어넣으려는 y좌표에 넣을 수 있는지 없는지 판단.
    for(int i = 1; i < level; i++) {
        // 과거 두었던 퀸이 현재 넣으려는 y좌표에 이미 있는 경우.
        if(ys[i] == y) {
            return;
        }
        // 과거 두었던 퀸이 현재 넣으려는 퀸의 대각선 좌표에 있는 경우.
        if(abs(level - i) == abs(y - ys[i])) {
            return;
        }
    }
    // 마지막 level까지 와서 판단.
    if(level == n) {
        for(int i = 1; i < level; i++) {
            if(ys[i] == y) {
                return;
            }
            if(abs(level - i) == abs(y - ys[i])) {
                return;
            }
        }
        ans++;
        return;
    }
    
    // 모든 제한조건을 통과한 경우 -> 퀸을 해당 level의 y좌표에 둔다.
    ys[level] = y;

    // 다음 level로 dfs.
    for(int i = 1; i <= n; i++) {
        solve(level + 1, i);
    }
}

int main() {
    cin >> n;

    // 모든 y좌표에 대해서 dfs.
    for(int i = 1; i <= n; i++) {
        solve(1, i);
    }

    cout << ans << '\n';
    return 0;
}
