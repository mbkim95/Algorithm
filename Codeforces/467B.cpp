#include <iostream>
#include <cstdio>
using namespace std;

int main(){

	int n, m, k;

	cin >> n >> m >> k;
	int army[1001];
	int ret = 0;

	for(int i=0; i<=m; i++){
		cin >> army[i];
	}

	for(int i=0; i<m; i++){
		int tmp = army[i] ^ army[m];
		int cnt = 0;
		for(int i=0; i<20; i++){
			if(tmp&1 == 1)
				cnt++;
			tmp = tmp >> 1;
		}
		if(cnt <= k)
			ret++;
	}

	cout << ret << endl;
}