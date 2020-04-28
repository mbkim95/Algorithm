#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int cnt = 0;
    int size = number.length();
    while (cnt < size - k) {
        char max_num = 0;
        int max_idx = 0;
        for (int i = 0; i < number.size() - (size - k - cnt - 1); i++) {
            if (max_num < number[i]) {
                max_num = number[i];
                max_idx = i;
            }
        }
        cnt++;
        answer += number[max_idx];
        number = number.substr(max_idx + 1);
    }
    return answer;
}