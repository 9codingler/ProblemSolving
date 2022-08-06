#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[1001];
vector<int> v;
int n, m;

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

    // for(int i = 1; i <= n; i++) {
    //     cout << "i = " << i << "parent[i] = " << parent[i] << '\n';
    // }

    if(a < b) {
        parent[b] = a;
        for(int i = 1; i <= n; i++) { //만약 b를 부모로 가지는 노드가 있다면, 그 노드의 부모도 a로 가리키게 바꿔준다.
            if(parent[i] == b) {
                parent[i] = a;
            }
        }
    }
    else {
        parent[a] = b;
        for(int i = 1; i <= n; i++) { // 29line과 동일한 논리.
            if(parent[i] == a) {
                parent[i] = b;
            }
        }
    }
}


int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        unionParent(a, b);
    }

    // for(int i = 1; i <= n; i++) {
    //     cout << parent[i] << ' ';
    // }
    // cout << '\n';
    for(int i = 1; i <= n; i++) {
        if(find(v.begin(), v.end(), parent[i]) == v.end()) {
            v.push_back(parent[i]);
        }
    }

    cout << v.size() << '\n';
    return 0;
}
