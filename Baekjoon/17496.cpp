#include <iostream>
using namespace std;

int main(){
    int n, t, c, p;
    cin >> n >> t >> c >> p;
    cout << p * ((n-1) / t * c) << '\n';
    return 0;
}
