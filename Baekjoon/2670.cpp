#include <iostream>
#include <algorithm>
using namespace std;

int n;
double num[10000];

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%lf", &num[i]);

    double ans = num[0];
    for(int i=1; i<n; i++) {
        if(num[i] * num[i-1] >= num[i]) num[i] *= num[i-1];
        ans = max(ans, num[i]);
    }
    printf("%.3lf\n", ans);
    return 0;
}