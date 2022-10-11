#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string to_binary(int n) {
    if(n == 0) return "0";

    string ret = "";
    while(n > 0) {
        ret += ('0' + n % 2);
        n/=2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<char> ans;

    int turn = 1, num = 0;
    while(ans.size() < 5) {
        string binary = to_binary(num++);
        for(int i=0; i<binary.length(); i++) {
            if(turn == k) ans.push_back(binary[i]);
            if(++turn > n) turn = 1;
        }
    }
    for(int i=0; i<5; i++) cout << ans[i] << ' ';
    return 0;
}