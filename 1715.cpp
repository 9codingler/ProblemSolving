#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n;
    priority_queue<int, vector<int>, greater<>> pq;

    cin >> n;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }
    int ans = 0;
    while(1) {
        if(pq.size() == 1) {
            break;
        }
        int one = pq.top();
        ans += one;
        pq.pop();
        
        int two = pq.top();
        ans += two;
        pq.pop();

        int sum = one + two;
        pq.push(sum);
    }

    cout << ans << '\n';
    return 0;
}
