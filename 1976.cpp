#include <iostream>
#include <vector>
using namespace std;
int parent[201];
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

    if(a < b) {
        parent[b] = a;
    }

    else {
        parent[a] = b;
    }
}

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int city;
            cin >> city;
            if(city == 1) {
                unionParent(i, j);
            }
        }
    }

    vector<int> tripcity;
    for(int i = 0; i < m; i++) {
        int city;
        cin >> city;
        tripcity.push_back(city);
    }
    
    bool flag = false;
    for(int i = 0; i < tripcity.size(); i++) {
        for(int j = i + 1; j < tripcity.size(); j++) {
            if(findParent(tripcity[i]) != findParent(tripcity[j])) {
                flag = true;
                break;
            }
        }
    }

    if(!flag) {
        cout << "YES" << '\n';
        return 0;
    }

    else {
        cout << "NO" << '\n';
        return 0;
    }
}
