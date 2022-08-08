#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> graph[32001];
int indegree[32001];
int n, m;

void topologySort() {
    queue<int> q;
    vector<int> result;
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
            result.push_back(i);
        }
    }

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for(int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];
            indegree[next]--;
            if(indegree[next] == 0) {
                q.push(next);
                result.push_back(next);
            }
        }
    }

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }

    return;
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int smaller, taller;
        cin >> smaller >> taller;
        graph[smaller].push_back(taller);
        indegree[taller]++;
    }

    topologySort();
    return 0;
}
