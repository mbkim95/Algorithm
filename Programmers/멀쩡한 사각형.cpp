#include <algorithm>
using namespace std;

int gcd(int a, int b){
    if(a % b == 0) return b;
    return gcd(b, a%b);
}

long long solution(int w, int h)
{
	long long sum = (long long)w * (long long)h;
    if(w < h) swap(w, h);
	int g = gcd(w, h);	
	return sum - (w + h - g);
}