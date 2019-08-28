#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void upperCase(string& str) {
	int diff = 'A' - 'a';
	for (int i = 0; i < str.length(); i++) 
		if ('a' <= str[i] && str[i] <= 'z')
			str[i] += diff;
}

bool findCity(vector<string>& list, string city) {
	for (int i = 0; i<list.size(); i++) {
		if (list[i] == city)
			return true;
	}
	return false;
}

void updateList(vector<string>& list, string city) {
	queue<string> q;
	for (int i = 0; i < list.size(); i++) {
		string tmp = list[i];
		if (tmp != city)
			q.push(tmp);
	}
	list.clear();
	while (!q.empty()) {
		list.push_back(q.front());
		q.pop();
	}
	list.push_back(city);
}

void removeCity(vector<string>& list, string del) {
	queue<string> q;
	for (int i = 0; i < list.size(); i++) {
		if (list[i] != del)
			q.push(list[i]);
	}
	list.clear();
	while (!q.empty()) {
		list.push_back(q.front());
		q.pop();
	}
}

int solution(int cacheSize, vector<string> cities) {
	if (cacheSize == 0) return cities.size() * 5;
	vector<string> list;
	int answer = 0;
	for (int i = 0; i<cities.size(); i++) {
		string city = cities[i];
		upperCase(city);
		if (findCity(list, city)) {
			updateList(list, city);
			answer += 1;
		}
		else {
			int size = list.size();
			if (0 < size && size == cacheSize) {
				string del = list[0];
				removeCity(list, del);
			}
			list.push_back(city);
			answer += 5;
		}
	}
	return answer;
}

int main() {
	int cacheSize = 2;
	vector<string> cities = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" };
	cout << solution(cacheSize, cities) << '\n';
	return 0;
}