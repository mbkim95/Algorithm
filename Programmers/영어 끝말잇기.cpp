#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> s;
    bool dead = false;
    char l = words[0][0];
    int i;
    for(i=0; i<words.size(); i++){
        if(l != words[i][0] || s.count(words[i]) > 0){
            dead = true;
            break;
        }
        s.insert(words[i]);
        l = words[i][words[i].size()-1];
    }
    if(!dead) answer = {0, 0};
    else answer = {i%n+1, i/n+1};
    return answer;
}