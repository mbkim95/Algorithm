#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, ans = 0;
    cin >> n;
    for(int i=0; i<5; i++){
        int tmp;
        cin >> tmp;
        if(tmp == n)
            ans++;
    }
    cout << ans << '\n';
    return 0;
}