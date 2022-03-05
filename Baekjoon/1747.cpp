#include <iostream>
using namespace std;

const int MAX = 1003001;
int n;
bool ans[MAX + 1];

void check_prime() {
    for (int i = 2; i <= MAX; i++) ans[i] = true;

    for (int i = 2; i * i <= MAX; i++) {
        if (!ans[i]) continue;

        for (int j = 2 * i; j <= MAX; j += i) ans[j] = false;
    }
}

void check_palindrome() {
    for (int i = 2; i <= MAX; i++) {
        if (!ans[i]) continue;

        string num = to_string(i);

        int l = 0, r = num.length() - 1;

        while (l < r) {
            if (num[l] != num[r]) {
                ans[i] = false;
                break;
            }
            l++;
            r--;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;

    check_prime();
    check_palindrome();

    for (int i = n; i <= MAX; i++)
        if (ans[i]) {
            cout << i << '\n';
            break;
        }
    return 0;
}