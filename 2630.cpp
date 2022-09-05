// divide && conquer.   
#include <iostream>

using namespace std;

int n;
int whiteans = 0, blueans = 0;
int map[129][129];

void fun(int startx, int starty, int endx, int endy) {
    int color = map[startx][starty]; // 첫 색깔.
    bool ansflag = true;

    for(int i = startx; i <= endx; i++) {
        for(int j = starty; j <= endy; j++) {
            if(map[i][j] != color) {
                ansflag = false;
                break;
            }
        }
    }

    if(!ansflag) {
        fun(startx, starty, (startx + endx) / 2, (starty + endy) / 2); // 좌측상단.
        fun((startx + endx) / 2 + 1, starty, endx, (starty + endy) / 2); // 좌측하단.
        fun(startx, (starty + endy) / 2 + 1, (startx + endx) / 2, endy); // 우측상단.
        fun((startx + endx) / 2 + 1, (starty + endy) / 2 + 1, endx, endy); // 우측하단.
    }

    else {
        if(color == 1) {
            blueans++;
        }
        else {
            whiteans++;
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }

    fun(1, 1, n, n);
    cout << whiteans << '\n';
    cout << blueans << '\n';
    return 0;
}
