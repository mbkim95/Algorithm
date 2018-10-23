#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int x[100000];
int d[100000];
int cache[100000];
int n, s = 1000000, e;

int upper(int cur, int dir){
	if(x[cur] + d[cur] < x[cur+1])
		return 1;
	return 0;
}

int lower(int cur, int dir){
	if(cur == 0)
		return 2;
	if(dir == 1){
		if(x[cur] - d[cur] > x[cur-1] + d[cur-1])
			return 2;

	}else{
		if(x[cur] - d[cur] > x[cur-1])
			return 2;
	}
	return 0;
}

int solve(int cur, int dir){
	if(cur == n-1)
		return cache[cur] = 1;

	int& ret = cache[cur];

	if(ret != -1)
		return ret;

	ret = 0;
	int flag = 0;
	
	flag = lower(cur, dir);

	if(flag == 0){
		flag = upper(cur, dir);
	}
	if(flag != 0)
		ret = 1;
	ret = ret + solve(cur+1, flag);
	return ret;
}

int main(){
	cin >> n;

	for(int i=0; i<n; i++){
		cin >> x[i] >> d[i];
	}
	
	memset(cache, -1, sizeof(cache));
	cout << solve(0, 2) << endl;
}