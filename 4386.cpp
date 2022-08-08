#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<pair<int, pair<float, float>>> stars; //star번호, x, y좌표 저장.
vector<pair<float, pair<int, int>>> graph; //거리, fststaridx, sndstaridx 저장.
int parent[101];
int n;

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
    cin >> n;
    //star마다 인덱스 붙여주자.
    for(int i = 1; i <= n; i++) {
        pair<int, pair<float, float>> star; //(star 인덱스, x, y)좌표.
        float x, y;
        scanf("%f %f", &x, &y);
        star = make_pair(i, make_pair(x, y));
        stars.push_back(star);
    }

    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < stars.size(); i++) { // 어차피 nC2개 만큼의 star를 graph에 push해도, dist순대로 내림차순 정렬 && 70,71번째 라인에서 findparent검사를 해주기 때문에, 점을 n개만큼만 선택한 꼴이 된다 -> 최소루트 하나만 정해진다.
        for(int j = i + 1; j < stars.size(); j++) {
            pair<float, float> fststar = stars[i].second;
            int fststaridx = stars[i].first;
            pair<float, float> sndstar = stars[j].second;
            int sndstaridx = stars[j].first;

            float dist = sqrt(pow((sndstar.first - fststar.first) , 2) + pow((sndstar.second - fststar.second) , 2));
            graph.push_back(make_pair(dist, make_pair(fststaridx, sndstaridx)));
        }
    }

    sort(graph.begin(), graph.end());
    float ans = 0;

    for(int i = 0; i < graph.size(); i++) {
        float cost = graph[i].first;
        int a = graph[i].second.first;
        int b = graph[i].second.second;

        if(findParent(a) != findParent(b)) {
            unionParent(a, b);
            ans += cost;
        }
    }

    printf("%.2f", ans);
    return 0;
}
