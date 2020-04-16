#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    int idx1 = 0, idx2 = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[idx1] < B[idx2]) {
            answer++;
            idx2++;
        }
        idx1++;
    }
    return answer;
}