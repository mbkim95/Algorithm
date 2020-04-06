#include <string>
#include <vector>

using namespace std;

long long fib[81];

long long solution(int N) {
    long long answer = 0;
    fib[1] = 1;
    fib[2] = 1;
    for(int i=3; i<=N; i++)
        fib[i] = fib[i-1] + fib[i-2];
    if(N == 1) answer = 4;
    else answer = 4 * fib[N] + 2 * fib[N-1];
    return answer;
}