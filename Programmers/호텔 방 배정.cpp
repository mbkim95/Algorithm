#include <string>
#include <vector>
#include <map>

using namespace std;

map<long, long> m;

// 배정 가능한 번호를 찾는 함수
long long find(long long u){
    if(!m[u]) return u;
    return m[u] = find(m[u]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for(int i=0; i<room_number.size(); i++){
        long long cur = room_number[i];
        // 원하는 방 번호 배정이 가능할 때
        if(!m[cur]){
            answer.push_back(cur);
            m[cur] = find(cur+1);
        }else{
            long long tmp = find(cur);
            answer.push_back(tmp);
            m[tmp] = find(tmp + 1);
        }
    }
    return answer;
}