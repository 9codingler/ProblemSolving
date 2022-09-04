#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int arr[1000001];
int ans[1000001];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(ans, ans + 1000001, -1);
    stack<int> s;
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {
        while(!s.empty() && arr[s.top()] < arr[i]) {
            ans[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    
    for(int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}
