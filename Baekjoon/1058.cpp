#include <iostream>
#include <algorithm>
using namespace std;

int n;
char areFriends[50][51];

int main() {
    cin >> n;
    for(int i=0; i<n; i++) scanf("%s", areFriends[i]);

    int ans = 0;

    for(int i=0; i<n; i++) {
        int cnt = 0;
        for(int j=0; j<n; j++) {
            if(i == j) continue;
            if(areFriends[i][j] == 'Y') cnt++;
            else {
                for(int k=0; k<n; k++) {
                    if(k == i || k == j) continue;
                    if(areFriends[i][k] == 'Y' && areFriends[j][k] == 'Y') {
                        cnt++;
                        break;
                    }
                }
            }
        }
        ans = max(ans, cnt);
    }
    printf("%d\n", ans);
    return 0;
}