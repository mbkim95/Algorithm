#include <string>
#include <algorithm>
using namespace std;

int N;

bool comp(string a, string b){
    return a[N] == b[N] ? a < b :  a[N] < b[N];
}

vector<string> solution(vector<string> strings, int n) {
    N = n;
    sort(strings.begin(), strings.end(), comp);
    return strings;
}