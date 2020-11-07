#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;
    int turn = 0;
    
    string before = s;
    string after = s;
    while(after != "1"){
        before = after;
        after = "";
        for(int i=0; i<before.length(); i++)
            if(before[i] == '1') after += before[i];
        cnt += (before.length() - after.length());
        
        int len = after.length();
        string tmp = "";
        while(len > 0){
            if(len % 2 == 1) tmp += '1';
            else tmp += '0';
            len /= 2;
        }
        reverse(tmp.begin(), tmp.end());
        after = tmp;
        turn++;
    }    
    return {turn, cnt};
}