#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int n, a[101], max_ans = -INT_MAX, min_ans = INT_MAX;
int op[4];

void dfs(int idx, int ret){
	if(idx == n){
		max_ans = max(max_ans, ret);
		min_ans = min(min_ans, ret);
		return;
	}
	
	for(int i=0; i<4; i++){
		if(op[i] > 0){
			op[i]--;
			int next = ret;
			if(i == 0) next += a[idx];
			if(i == 1) next-= a[idx];
			if(i == 2) next *= a[idx];
			if(i == 3) next /= a[idx];
			dfs(idx+1, next);
			op[i]++;
		}
	}
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < 4; i++) cin >> op[i];
  dfs(1, a[0]);
  cout << max_ans << '\n' << min_ans << '\n';
  return 0;
}
