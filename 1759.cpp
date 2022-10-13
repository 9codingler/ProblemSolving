#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> v;
bool visited[15];
char ans[15];
int l, c;

void dfs(int count, int start) {
    if(count == l) {
        int v_count = 0;
        int c_count = 0;
        for(int i = 0; i < l; i++) {
            if(ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u') {
                v_count++;
            }
            else {
                c_count++;
            }
        }
        if(v_count < 1 || c_count < 2) {
            return;
        }
        else {
            for(int i = 0; i < l; i++) {
                cout << ans[i];
            }
            cout << '\n';
        }
    }

    else {
        // i는 0이 아닌, 항상 재귀 시작할 때 방문이 완료된 인덱스의 다음부터 시작해야 한다.
        for(int i = start; i < c; i++) {
            if(visited[i]) {
                continue;
            }
            ans[count] = v[i];
            visited[i] = true;
            dfs(count + 1, i + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> l >> c;
    char h;

    for(int i = 0; i < c; i++) {
        cin >> h;
        v.push_back(h);    
    }

    sort(v.begin(), v.end());

    dfs(0, 0);

    return 0;
}
