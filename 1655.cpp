#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int> lower; //maxheap
    priority_queue<int, vector<int>, greater<>> higher; //minheap
    int mid, n;
    cin >> n;

    //nlogn
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if(i == 0) {
            mid = tmp;
            cout << mid << '\n';
            continue;
        }

        if(tmp > mid) {
            higher.push(tmp);
            if(higher.size() > lower.size()) {
                lower.push(mid);
                mid = higher.top();
                higher.pop();
                cout << lower.top() << '\n';
            }
            else {
                cout << mid << '\n';
            }
        }
        else if (tmp <= mid) {
            lower.push(tmp);
            if(lower.size() >= higher.size() + 2) {
                higher.push(mid);
                mid = lower.top();
                lower.pop();
                cout << mid << '\n';
            }
            else {
                cout << lower.top() << '\n';
            }
        }
    }

    return 0;
}
