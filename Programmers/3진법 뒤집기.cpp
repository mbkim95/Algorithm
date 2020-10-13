#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string tranlate(int n) {
    string ret = "";
    while (n > 0) {        
        ret += '0' + (n % 3);
        n /= 3;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int solution(int n) {
    int answer = 0;
    string ret = tranlate(n);   
    for (int i = 0; i < ret.length(); i++) {
        char c = ret[i];
        int mul = 1;
        for (int j = 0; j < i; j++)
            mul *= 3;
        answer += ((c - '0') * mul);
    }
    return answer;
}