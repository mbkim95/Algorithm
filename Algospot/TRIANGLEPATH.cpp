#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int t[100][100];
int cache[100][100];

int solve(int x, int y){
	if(y == n)
		return 0;

	int& ret = cache[y][x];
	
	if(ret != -1)
		return ret;
	
	ret = t[y][x] + max(solve(x, y+1), solve(x+1, y+1));
	return ret;
}

int main(){
	int c;
	cin >> c;
	
	while(c--){
		cin >> n;
		for(int i=0; i<n; i++){
			for(int j=0; j<=i; j++){
				cin >> t[i][j];
			}
		}
		memset(cache, -1, sizeof(cache));
		cout << solve(0, 0) << endl;

	}
}