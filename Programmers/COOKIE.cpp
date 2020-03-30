#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    vector<int> sum(cookie.size());
    sum[0] = cookie[0];
    for(int i=0; i<sum.size(); i++)
        sum[i] = sum[i-1] + cookie[i];
    
    for(int i=0; i<sum.size() - 1; i++){
        int n1 = sum[i];
        for(int j=i+1; j<sum.size(); j++){
            int n2 = sum[j] - sum[i];
            if(answer >= n2) continue;
            if(n2 > n1) break;
            else if(n1 == n2){
                answer = max(answer, n1);
                break;
            }else{
                for(int l=0; l<i; l++){
                    int tmp = n1 - sum[l];
                    if(n2 > tmp)
                        break;
                    
                    if(tmp == n2){
                        answer = max(answer, tmp);
                        break;
                    }
                }
            }
        }
    }
    return answer;
}