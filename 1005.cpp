#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, w;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int test = 0; test < t; test++) {
        int indegree[1001];
        vector<int> graph[1001];
        int ans[1001];
        int timegraph[1001];

        fill(indegree, indegree + 1001, 0);

        cin >> n >> k;

        for(int i = 1; i <= n; i++) {
            cin >> timegraph[i];
            ans[i] = timegraph[i];
        }

        for(int i = 0; i < k; i++) {
            int first, second;
            cin >> first >> second;
            graph[first].push_back(second);
            indegree[second]++;
        }
        
        // topology.
        
        queue<int> q;
        for(int i = 1; i <= n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int cur_node = q.front();
            q.pop();

            for(int i = 0; i < graph[cur_node].size(); i++) {
                int next = graph[cur_node][i];
                indegree[next]--;
                ans[next] = max(ans[next], ans[cur_node] + timegraph[next]);
                if(indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        cin >> w;
        cout << ans[w] << '\n';

        //테케끝나고 indegree, graph 초기화해주기.
    }
}
