#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, pair<int, int>>> v;
int m, n;
int parent[200001];
int sum = 0, sum2 = 0;

int findParent(int x) {
    if(parent[x] == x) {
        return x;
    }
    else {
        return parent[x] = findParent(parent[x]);
    }
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if(a < b) {
        parent[b] = a;
    }

    else {
        parent[a] = b;
    }
}

int main() {
    while(1) {
        cin >> m >> n;
        if(m == 0 && n == 0) {
            return 0;
        }
        else {
            sum = 0;
            sum2 = 0;
            vector<pair<int, pair<int, int>>>().swap(v); //다음 테케를 위해 벡터 초기화.
        }

        for(int i = 1; i <= m; i++) {
            parent[i] = i;
        }

        int from, to, cost;
        for(int i = 0; i < n; i++) {
            cin >> from >> to >> cost;
            sum += cost;
            v.push_back(make_pair(cost, make_pair(from, to)));
        }

        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++) {
            int cost = v[i].first;
            int from = v[i].second.first;
            int to = v[i].second.second;

            if(findParent(from) != findParent(to)) {
                unionParent(from, to);
                sum2 += cost;
            }
        }
        cout << sum - sum2 << '\n'; //"절약한 비용" 출력이므로 원래의 cost값에서 최소스패닝트리의 간선의 합을 빼준다.
    }
}
