#include <cstdio>
#include <algorithm>
using namespace std;

int n, x[100000], q;

int solve(int m,int l,int r){
	int mid;
	while(l <= r){
		mid = (l+r)/2;

		if(x[mid] > m)
			r = mid-1;
		else
			l = mid+1;
	}
	return r+1;
}

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &x[i]);
	
	scanf("%d", &q);
	sort(x, x+n);
	
	int tmp;
	for(int i=0; i<q; i++){
		scanf("%d", &tmp);
  	if(tmp<x[0])
		printf("0\n");
	else 
		printf("%d\n", solve(tmp,0,n-1));
  	
	}
}