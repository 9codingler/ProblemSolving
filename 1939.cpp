#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#define INF 1e9
using namespace std;

vector<pair<int, int>> graph[10001];
bool visited[10001];

int start, target, maxlimit = -1;  
int ans = -1;

bool bfs(int cur_limit) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        if(cur == target) {
            return true;
        }

        for(int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].second;
            int next_limit = graph[cur][i].first;

            if(visited[next] == false && cur_limit <= next_limit) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return false; //cur이 target에 도달하지 못하고 while문 빠져나왔으므로..
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int from, to, limit;
        cin >> from >> to >> limit;
        graph[from].push_back(make_pair(limit, to));
        graph[to].push_back(make_pair(limit, from));

        maxlimit = max(maxlimit, limit);
    }

    cin >> start >> target;

    int low = 0;
    int high = maxlimit;

    while(low <= high) {
        memset(visited, false, sizeof(visited)); // 매 mid마다 bfs 실행할 것이므로 그때마다 visited false로 초기화.
        int mid = (low + high) / 2;
        if(bfs(mid)) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << high << '\n';
    return 0;
}
