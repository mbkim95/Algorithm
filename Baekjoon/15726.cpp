#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    printf("%ld\n", lround(floor(max(a * b / c, a / b * c))));
    return 0;
}