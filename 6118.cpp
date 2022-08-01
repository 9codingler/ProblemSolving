#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;

vector<int> graph[20001]; //다음노드 삽입.
bool visited[20001];
int d[20001];

void bfs() {
    queue<pair<int, int>> q; //(다음 노드까지의 거리, 다음노드)
    q.push(make_pair(0, 1));
    visited[1] = true;

    while(!q.empty()) {
        int dist = q.front().first;
        int cur_node = q.front().second;
        q.pop();

        for(int i = 0; i < graph[cur_node].size(); i++) {
            int next_node = graph[cur_node][i];
            if(!visited[next_node]) { //결국 최단거리는 이전노드까지의 거리 + 1이므로 거리 한번만 입력하고 visited = true로 바꿔줘도 문제 없다.
                int next_dist = dist + 1;
                q.push(make_pair(next_dist, next_node));
                visited[next_node] = true;
                d[next_node] = next_dist;
            }
        }
    }
}

int main() {
    int n, m;   
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int A_i, B_i;
        cin >> A_i >> B_i;

        graph[A_i].push_back(B_i);
        graph[B_i].push_back(A_i);
    }

    d[1] = 0;
    bfs();

    int ans = -1;
    int sum = 0;
    int ansnode;
    bool flag = false;

    for(int i = 1; i <= 20000; i++) {
        ans = max(ans, d[i]); 
    }

    for(int i = 1; i <= 20000; i++) {
        if (d[i] == ans) {
            sum++;
            if(!flag) {
                ansnode = i;
                flag = true;
            }
        }
    }

    cout << ansnode << ' ' << ans << ' ' << sum << '\n';
    return 0;
}
