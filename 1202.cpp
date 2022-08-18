#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
typedef long long ll;
using namespace std;

priority_queue<pair<int, int>> ans;
vector<pair<int, int>> jewel; //무게 오름차순 정렬.
vector<int> backpack;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;

    ll sum = 0;
    cin >> n >> k;
    int value, weight, maxweight;

    for(int i = 0; i < n; i++) {
        cin >> weight >> value; 
        jewel.push_back(make_pair(weight, value));
    }

    for(int i = 0; i < k; i++) {
        cin >> maxweight;
        backpack.push_back(maxweight);
    }

    sort(jewel.begin(), jewel.end()); //무게순 오름차순 정렬.
    sort(backpack.begin(), backpack.end());

    int jidx = 0;
    for(int i = 0; i < backpack.size(); i++) {
        while(1) {
            if(jidx == jewel.size()) {
                break;
            }
            if(jewel[jidx].first > backpack[i]) {
                break;
            }
            ans.push(make_pair(jewel[jidx].second, jewel[jidx].first)); //가치, 무게 순 push.
            jidx++;
        }
        if(!ans.empty()) {
            sum += ans.top().first;
            ans.pop();
        }
    }

    cout << sum << '\n';
    return 0;
}
