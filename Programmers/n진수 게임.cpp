#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> num;
const char Hex[] = { 'A', 'B', 'C', 'D', 'E', 'F' };

// n진수로 변환
string dec_to_n(int n, int number) {
    string ret = "";
    while (number / n > 0) {
        int div = number % n;
        if (div >= 10) ret += Hex[div - 10];
        else ret += to_string(number % n);
        number /= n;
    }
    if (number >= 10) ret += Hex[number - 10];
    else ret += to_string(number);
    reverse(ret.begin(), ret.end());
    return ret;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    for (int i = 0; i <= t*m; i++) {
        string tmp = dec_to_n(n, i);
        for (int j = 0; j < tmp.length(); j++)
            num.push_back(tmp[j]);
    }

    for (int i = 0; i < num.size(); i++) {
        if (answer.length() == t) break;
        if ((m == p && (i+1)%m == 0) || (i + 1) % m == p) answer += num[i];
    }
    return answer;
}