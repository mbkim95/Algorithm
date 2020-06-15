#include <iostream>
using namespace std;

int main() {
    int m[9], sum = 0;
    
    for (int i = 0; i < 9; i++) {
        cin >> m[i];
        sum += m[i];
    }

    bool find = false;
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            if ((sum - (m[i] + m[j])) == 100) {
                for (int k = 0; k < 9; k++)
                    if (k != i && k != j)
                        cout << m[k] << '\n';
                find = true;
                break;
            }
        }
        if (find) break;
    }
	return 0;
}