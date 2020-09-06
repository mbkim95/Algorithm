#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    for (string name : participant) m[name]++;
    for (string name : completion)
        if (m[name] > 1) m[name]--;
        else m.erase(name);
    for (auto it : m) {
        answer = it.first;
        break;
    }
    return answer;
}