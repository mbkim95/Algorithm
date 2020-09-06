#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> map;
    for (vector<string> cloth : clothes)
        map[cloth[1]]++;

    for (auto it : map)
        answer *= (it.second + 1);
    
    return answer - 1;
}