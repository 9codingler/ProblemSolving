#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int graph[101][101];

int main() {
    int n, m;
    cin >> n >> m;
    fill(&graph[1][1], &graph[100][101], INF);

    for(int i = 0; i < m; i++) {
        int from, to, dist;
        cin >> from >> to >> dist;
        if(dist < graph[from][to]) {
            graph[from][to] = dist;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                graph[i][j] = 0;
            }
        }
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);            
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(graph[i][j] == INF) {
                cout << 0 << ' ';
            }
            else {
                cout << graph[i][j] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
