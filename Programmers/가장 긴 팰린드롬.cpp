#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int solution(string s)
{
    int answer=1;
    int i;
    for(i=1; i<s.length()-1; i++){
        int idx = 1;
        int tmp = 1;
        while(true){
            if(i - idx == -1 || i + idx == s.length()) break;
            if(s[i - idx] != s[i + idx]) break;
            tmp+=2;
            idx++;
        }
        answer = max(answer, tmp);
    }
    for(int i=0; i<s.length()-1; i++){
        if(s[i] == s[i+1]){
            int idx = 0;
            int tmp = 0;
            while(true){
                if(i-idx == -1 || i+1+idx == s.length()) break;
                if(s[i-idx] != s[i+1+idx]) break;
                tmp+=2;
                idx++;
            }
            answer = max(answer, tmp);
        }
    }
    return answer;
}