#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool check_rule(vector<char>& friends, string rule) {
    char a = rule[0]; char b = rule[2];
    char op = rule[3]; int dist = rule[4]-'0';

    for (int i = 0; i < friends.size() - 1; i++) {
        if (friends[i] == a || friends[i] == b) {
            for (int j = i + 1; j < friends.size(); j++) {
                if (friends[j] == a || friends[j] == b) {
                    if (op == '=' && dist != j - i - 1) return false;
                    else if (op == '>' && j - i - 1 <= dist) return false;
                    else if (op == '<' && j - i - 1 >= dist) return false;
                }
            }
        }
    }
    return true;
}

int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char> friends = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
    do {
        bool is_ok = true;
        for (string rule : data) {
            if (!check_rule(friends, rule)) {
                is_ok = false;
                break;
            }
        }
        if (is_ok) answer++;
    } while (next_permutation(friends.begin(), friends.end()));
    return answer;
}