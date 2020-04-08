#include <string>
#include <vector>
#include <iostream>
using namespace std;

void precalc(vector<bool>& prime, int n){
    prime[1] = false;
    for(int i=2; i*i<=n; i++){
        if(prime[i] == true)
        for(int j=i*i; j<=n; j+=i){
            if(prime[j] == true) prime[j] = false;
        }
    }
}

int solution(int n) {
    int answer = 0;
    vector<bool> prime(n+1, true);
    precalc(prime, n);
    for(int i=2; i<=n; i++)
        if(prime[i])
            answer++;
    return answer;
}