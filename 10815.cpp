#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int binarysearch(int start, int end, int target) {
    if(start > end) {
        return 0;
    }
    int mid = (start + end) / 2;
    if(v[mid] == target) {
        return 1;
    }
    else if(v[mid] > target) {
        return binarysearch(start, mid - 1, target);
    }
    else {
        return binarysearch(mid + 1, end, target);
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        cout << binarysearch(0, n - 1, tmp) << ' ';
    }

    return 0;
}
