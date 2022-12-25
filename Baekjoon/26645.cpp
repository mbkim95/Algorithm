#include <iostream>
using namespace std;

const int up[] = {0, 8, 4, 2, 1};

int levelUp(int level, int item) {
    int ret = level;
    if(item == 1 && ret < 210)ret++;
    else if(item == 2 && ret < 220) ret++;
    else if(item == 3 && ret < 230) ret++;
    else if(item == 4 && ret < 240) ret++;
    return ret;
}

int main() {
    int n;
    cin >> n;
    int ans = 4;
    int maxLevel = n;
    for(int i=4; i>0; i--) {
        int tmp = n;
        for(int j=0; j<up[i]; j++) tmp = levelUp(tmp, i);
        
        if(maxLevel < tmp) {
            ans = i;
            maxLevel = tmp;
        }
    }
    cout << ans << '\n';
    return 0;
}