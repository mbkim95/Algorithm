#include <cstdio>
#include <algorithm>
using namespace std;

int s[1000];
int chk[1000];
int m[10], bk[10];
int n;

int solve1(){
	int ans = n;
	for(int i=0; i<n; i++){
		if(m[s[i]] != 0){
			chk[i] = 1;
			m[s[i]]--;
			ans--;
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<10; j++){
			if(s[i] < j && m[j] != 0 && chk[i] == 0){
				m[j]--;
				ans--;
				break;
			}
		}
	}
	return ans;
}

int solve2(){
	int ans = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<10; j++){
			if(s[i] < j && m[j] != 0){
				ans++;
				m[j]--;
				break;
			}
		}
	}
	return ans;
}	

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%1d", &s[i]);
	
	for(int i=0; i<n; i++){
		int tmp;
		scanf("%1d", &tmp);
		m[tmp]++;
		bk[tmp]++;
	}	
	sort(s, s+n);
	printf("%d\n", solve1());
	for(int i=0; i<10; i++){
		m[i] = bk[i];
	}
	printf("%d\n", solve2());
}