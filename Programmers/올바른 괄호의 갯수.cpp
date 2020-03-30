#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> s;
    for(int i=0; i<n; i++){
        s.push_back(1);
        s.push_back(-1);
    }
    do{
        answer++;        
        int sum = 0;
        for(int i=0; i<2*n; i++){
            sum += s[i];
            if(sum < 0){
                answer--;
                break;
            }
        }
    }while(next_permutation(s.begin(), s.end()));
    return answer;
}