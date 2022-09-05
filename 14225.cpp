#include <iostream>
#include <vector>
#define MAX 20000001
using namespace std;

vector<int> v;
int n;
int result[20];
bool arr[MAX];

void combination(int r, int index, int depth, int size) {
    if(r == 0) {
        int num = 0;
        for(int i = 0; i < size; i++) {
            num += result[i]; 
        }
        arr[num] = true;
        return;
    }

    else if (depth == n) {
        return;
    }

    else {
        result[index] = v[depth];
        combination(r - 1, index + 1, depth + 1, size);

        combination(r, index, depth + 1, size);
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    for(int i = 1; i <= n; i++) {
        combination(i, 0, 0, i);
    }

    for(int i = 1; i <= MAX; i++) {
        if(!arr[i]) {
            cout << i << '\n';
            return 0;
        }
    }
}
