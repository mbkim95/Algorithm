#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int board[500][500], chk[500][500];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

int dfs(int x, int y){
	if(chk[x][y] != -1)
		return chk[x][y];

	if(x>=n || y>=m || x < 0 || y < 0)
		return 0;
	
	if(x == 0 && y == 0)
		return 1;
	
	chk[x][y] = 0;

	for(int i=0; i<4; i++){	
		if(board[x][y] < board[x+dx[i]][y+dy[i]]){
			chk[x][y] += dfs(x+dx[i], y+dy[i]);
		}
	}
	return chk[x][y];
}

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> board[i][j];

	memset(chk, -1, sizeof(chk));
	cout << dfs(n-1, m-1) << endl;
}