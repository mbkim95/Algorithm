#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int sum1, sum2;
int q;
double ans;
char s1[11];
char s2[11];

void solve(int sum, int cnt){
	if(cnt == q){
		if(sum == sum1)
			ans+=1;
		return;
	}
	solve(sum+1, cnt+1);
	solve(sum-1, cnt+1);
}

int main(){
	scanf("%s", s1);
	scanf("%s", s2);

	for(int i=0; i<strlen(s1); i++){
		if(s1[i] == '+')
			sum1++;
		else
			sum1--;
	}

	for(int i=0; i<strlen(s2); i++){
		if(s2[i] == '+')
			sum2++;
		else if(s2[i] == '-')
			sum2--;
		else
			q++;
	}
	solve(sum2, 0);
	double cnt = pow(2, q);
	
	printf("%1.12f\n", ans/cnt);
}