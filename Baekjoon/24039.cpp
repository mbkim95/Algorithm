#include <iostream>
#include <vector>
using namespace std;

const int MAX = 103;
int n, p[MAX + 1];
vector<int> v;

void preCalc() {
    for(int i=2; i<=MAX; i++) p[i] = true;
    for(int i=2; i<=MAX; i++) {
        if(!p[i]) continue;
        
        for(int j=2*i; j<=MAX; j+=i) p[j] = false;
    }
}

int main() {
    cin >> n;
    preCalc();
    for(int i=2; i<=MAX; i++) {
        if(p[i]) v.push_back(i);
    }

    for(int i=0; i<v.size()-1; i++) {
        int c = v[i] * v[i+1];
        if(c > n) {
            cout << c << '\n';
            break;
        }
    }
    return 0;
}