#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<>> pq;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int from, to;
        cin >> from >> to;
        v.push_back(make_pair(from, to));
    }

    sort(v.begin(), v.end());

    pq.push(v[0].second); //첫번째 수업이 끝나는 시간을 pq.push.

    for(int i = 1; i < v.size(); i++) {
        if(pq.top() <= v[i].first) { //그 다음 수업이 pq에 있는 수업의 종료시간보다 크거나 같다면 == 같은 강의실을 쓸 수 있다. 
            pq.pop();
            pq.push(v[i].second);
        }
        else {
            pq.push(v[i].second);
        }
    }

    cout << pq.size() << '\n';
    return 0;
}
