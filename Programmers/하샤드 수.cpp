#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int div = 0;
    int tmp = x;
    while(tmp > 0){
        div += (tmp % 10);
        tmp /= 10;
    }
    answer = x % div == 0 ? true : false;
    return answer;
}