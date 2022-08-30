#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#define MAX 101
#define INF 1e9
using namespace std;

int map[51][51];
int dist[101]; //집의 갯수는 2n개를 넘지 않는다.
vector<pair<int, int>> chicken;
pair<int, int> result[14][14]; //최대 13개를 뽑을 것이므로. [x개 뽑는 경우.][첫번째, 두번째 ... x번째 index]
vector<pair<int, pair<int, int>>> homes; //{집 번호, {x, y좌표}} vec.
int n, m;
int ans = INF;
int homenum = 0;

void combination(int r, int index, int depth, int selecsize) {
    //combination 한번 종료되면, 그때의 치킨거리 구해서 ans 반영시키자.
    //selecsize 변수는 치킨집 몇개를 선택했는지, result의 인덱스를 참조하기 위한 매개인자.(main의 for문에서 입력받는다.)
    if(r == 0) {
        int sum = 0;
        
        //매 조합마다 각각의 가정집까지의 거리를 MAX초기화 필요.
        fill(dist, dist + 101, MAX);
        for(int i = 0; i < homes.size(); i++) { // 각 가정집마다 치킨집까지의 최소거리 구하기.
            int homenum = homes[i].first;
            for(int j = 0; j < selecsize; j++) {
                sum = abs(result[selecsize][j].first - homes[i].second.first) + abs(result[selecsize][j].second - homes[i].second.second);
                dist[homenum] = min(dist[homenum], sum);
            }
        }

        int anssum = 0;
        for(int i = 1; i <= homenum; i++) {
            anssum += dist[i];
        }

        ans = min(ans, anssum);
    }

    else if(depth == chicken.size()) {
        return;
    }

    else {
        // 치킨집 선택한 경우.
        result[selecsize][index] = chicken[depth];
        combination(r - 1, index + 1, depth + 1, selecsize);
        
        // 치킨집 선택하지 않은 경우.
        combination(r, index, depth + 1, selecsize);
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2) {
                chicken.push_back({i, j});
            }
            if(map[i][j] == 1) {
                ++homenum;
                homes.push_back({homenum, {i, j}});
            }
        }
    }

    // 출력문.
    // for(int i = 0; i < homes.size(); i++) {
    //     cout << homes[i].first << "x : " << homes[i].second.first << ' ' << "y : " << homes[i].second.second << '\n';
    // }

    for(int i = 1; i <= m; i++) { //최대 m개를 고르는 것이므로, 1부터 m개까지 brute force.
        combination(i, 0, 0, i);
    }

    cout << ans << '\n';
    return 0;
}
