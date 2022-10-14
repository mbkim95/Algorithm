#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    double a1, p1, r1, p2;
    cin >> a1 >> p1;
    cin >> r1 >> p2;
    double s = a1 / p1;
    double w = r1 * r1 * 3.14159265358979 / p2;
    if(w > s) cout << "Whole pizza\n";
    else cout << "Slice of pizza\n";
    return 0;
}