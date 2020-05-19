#include <iostream>
using namespace std;

int main() {
    int n, m, h;
    cin >> n >> m >> h;
    for (int i=0; i<n; i++) {
    	int tmp;
        cin >> tmp;
        if (tmp * tmp <= m * m + h * h) cout << "DA\n";
        else cout << "NE\n";
	}
    return 0;
}