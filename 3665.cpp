#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int t, n, m;
int indegree[501];
bool graph[501][501];

int main() {
    cin >> t;
    for(int test = 0; test < t; test++) {
        fill(indegree, indegree + 501, 0);
        for(int i = 0; i < 501; i++) {
            fill(graph[i], graph[i] + 501, false);
        }

        cin >> n;
        vector<int> v;
        for(int i = 0; i < n; i++) {
            int rank;
            cin >> rank;
            v.push_back(rank);
        }

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                graph[v[i]][v[j]] = true;
                indegree[v[j]]++;
            }
        }

        cin >> m;
        for(int i = 0; i < m; i++) {
            int one, two;
            cin >> one >> two;
            if(graph[one][two]) { // 간선이 one에서 two로 간다면,
                graph[one][two] = false;
                graph[two][one] = true;
                indegree[one]++; //one의 순위는 높아지고(간선이 two에서 one으로 들어오고),
                indegree[two]--; //two의 순위는 낮아진다(간선이 one에서 two로 들어간다).
            }
            else{
                graph[two][one] = false;
                graph[one][two] = true;
                indegree[two]++;
                indegree[one]--;
            }
        }

        //topology.
        vector<int> result;
        queue<int> q;

        for(int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        bool certain = false; //위상정렬 결과가 오직 하나인지.
        bool cycle = false; //그래프에 사이클 있는지.

        for(int i = 0; i < n; i++) {
            if(q.size() == 0) {
                cycle = true;
                break;
            }

            if(q.size() >= 2) {
                certain = true;
                break;
            }

            int now = q.front();
            q.pop();
            result.push_back(now);
            for(int j = 1; j <= n; j++) {
                if(graph[now][j]) {
                    indegree[j]--;
                    if(indegree[j] == 0) {
                        q.push(j);
                    }
                }
            }
        }
        if(cycle) {
            cout << "IMPOSSIBLE" << '\n';
            continue;
        }

        else if (certain) {
            cout << "?" << '\n';
            continue;
        }

        else{
            for(int i = 0; i < result.size(); i++) {
                cout << result[i] << ' ';
            }
            cout << '\n';
        }
    }

    
}
