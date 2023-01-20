#include <iostream>
using namespace std;

int main() {
    while(true) {
        int n, k, c;
        if(scanf("%d %d", &n, &k) == -1) break;
        c = n;
        while(c / k) {
            n += c / k;
            c = c / k + c % k;
        }
        printf("%d\n", n);
    }
    return 0;
}