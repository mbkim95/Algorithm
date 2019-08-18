#include <iostream>
#include <vector>
#include <string>
using namespace std;

void clockRotate(vector<vector<char>>& face) {
	vector<vector<char>> tmp = face;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			face[i][j] = tmp[2 - j][i];
}

void F(vector<vector<vector<char>>>& cube) {
	// 1 -> 2 -> 3 -> 4
	vector<vector<char>> tmp = cube[1];
	cube[1] = cube[4];
	cube[4] = cube[3];
	cube[3] = cube[2];
	cube[2] = tmp;
	clockRotate(cube[2]); clockRotate(cube[2]); clockRotate(cube[2]);
	clockRotate(cube[3]); clockRotate(cube[3]); clockRotate(cube[3]);
	clockRotate(cube[4]); clockRotate(cube[4]); clockRotate(cube[4]);
	clockRotate(cube[0]); clockRotate(cube[0]); clockRotate(cube[0]);
	clockRotate(cube[1]); clockRotate(cube[1]); clockRotate(cube[1]);
	clockRotate(cube[5]);

}

void U(vector<vector<vector<char>>>& cube) {
	// 0 -> 2 -> 5 -> 4
	vector<vector<char>> tmp = cube[0];
	cube[0] = cube[4];
	cube[4] = cube[5];
	cube[5] = cube[2];
	cube[2] = tmp;
	clockRotate(cube[5]); clockRotate(cube[5]);
	clockRotate(cube[4]); clockRotate(cube[4]);
	clockRotate(cube[1]);
	clockRotate(cube[3]); clockRotate(cube[3]); clockRotate(cube[3]);
}

void L(vector<vector<vector<char>>>& cube) {
	// 1 -> 5 -> 3 -> 0
	char tmp;
	for (int i = 0; i < 3; i++) {
		tmp = cube[0][i][0];
		cube[0][i][0] = cube[3][i][0];
		cube[3][i][0] = cube[5][i][0];
		cube[5][i][0] = cube[1][i][0];
		cube[1][i][0] = tmp;
	}	
	clockRotate(cube[4]);
}

void R(vector<vector<vector<char>>>& cube) {
	// 1 -> 0 -> 3 -> 5
	char tmp;
	for (int i = 0; i < 3; i++) {
		tmp = cube[0][i][2];
		cube[0][i][2] = cube[1][i][2];
		cube[1][i][2] = cube[5][i][2];
		cube[5][i][2] = cube[3][i][2];
		cube[3][i][2] = tmp;
	}
	clockRotate(cube[2]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int m;
		cin >> m;
		vector<vector<vector<char>>>cube;
		cube.push_back(vector<vector<char>>(3, vector<char>(3, 'w')));
		cube.push_back(vector<vector<char>>(3, vector<char>(3, 'r')));
		cube.push_back(vector<vector<char>>(3, vector<char>(3, 'b')));
		cube.push_back(vector<vector<char>>(3, vector<char>(3, 'o')));
		cube.push_back(vector<vector<char>>(3, vector<char>(3, 'g')));
		cube.push_back(vector<vector<char>>(3, vector<char>(3, 'y')));
		while (m--) {
			string cmd;
			cin >> cmd;
			int k = 1;
			if (cmd[1] == '-') k = 3;
			if (cmd[0] == 'U') {
				U(cube)
				for (int i = 0; i < k; i++) R(cube);
				for (int i = 0; i < 3; i++) U(cube);
			}
			else if (cmd[0] == 'D') {
				U(cube);
				for (int i = 0; i < k; i++)L(cube);
				for (int i = 0; i < 3; i++)U(cube);
			}
			else if (cmd[0] == 'F') {
				F(cube);
				for (int i = 0; i < k; i++)R(cube);
				for (int i = 0; i < 3; i++)F(cube);
			}
			else if (cmd[0] == 'B') {
				F(cube);
				for (int i = 0; i < k; i++)L(cube);
				for (int i = 0; i < 3; i++)F(cube);
			}
			else if (cmd[0] == 'L') {
				for (int i = 0; i < k; i++)L(cube);
			}
			else if (cmd[0] == 'R') {
				for (int i = 0; i < k; i++)R(cube);
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				cout << cube[0][i][j];
			cout << '\n';
		}
	}
	return 0;
}