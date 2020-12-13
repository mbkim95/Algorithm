#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int carry = 0;
int num;
string x, y;
string result = "";

string sum() {
    for (int i = 0; i < x.length(); i++) {
        int sum = x[i] - '0' + y[i] - '0' + carry;
        num = sum % 10;
        result += to_string(num);
        carry = sum / 10;
    }

    if (carry != 0) result += to_string(carry);
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> x >> y;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    while (x.length() < y.length()) {
        x += '0';
    }

    while (x.length() > y.length()) {
        y += '0';
    }
    sum();
    reverse(result.begin(), result.end());
    cout << result << '\n';
    return 0;
}
