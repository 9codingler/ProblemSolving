#include <iostream>
#include <queue>

using namespace std;

int n;
int indegree[501];
vector<int> graph[501];
int timegraph[501];
int ans[501];

void topologySort() {
    queue<int> q;

    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];
            indegree[next]--;
            ans[next] = max(ans[next], timegraph[next] + ans[now]);
            if(indegree[next] == 0) {
                q.push(next);
            }
        }
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int time;
        cin >> time;
        timegraph[i] = time;
        while(1) {
            int sunsu;
            cin >> sunsu;
            if(sunsu == -1) {
                break;
            }
            graph[sunsu].push_back(i);
            indegree[i]++;
        }
    }

    for(int i = 1; i <= n; i++) { // 수업을 끝낼라면 기본적으로 자신의 수업번호에 해당하는 시간을 소요해야 하기 때문에.
        ans[i] = timegraph[i];
    }
    topologySort();

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
