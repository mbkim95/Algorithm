#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        int ans = 1;
        
        for(int i=2; i<=n; i++) {
            ans *= i;
            
            while(ans % 10 == 0) {
                 ans /= 10;
            }
            
            if(ans >= 100000) {
               int tmp = ans / 100000;
               tmp *= 100000;
               ans = ans - tmp;
            }
        }
        cout << ans % 10 << '\n';
    }
    return 0;
}
