#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
	int answer = 1;
	sort(routes.begin(), routes.end());
	for (int i = 0; i < routes.size(); i++)
		cout << routes[i][0] << ' ' << routes[i][1] << '\n';
	int pos = routes[0][1];
	for (int i = 1; i < routes.size(); i++) {
		if (pos > routes[i][1]) 
			pos = routes[i][1];
		else if (pos < routes[i][0]) {
			answer++;
			pos = routes[i][1];
		}
	}
	return answer;
}