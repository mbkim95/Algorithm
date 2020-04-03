#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    for(int i=0; i<moves.size(); i++){
        int pick = moves[i] - 1;
        int h = 0;
        while(h < board.size() && board[h][pick] == 0) h++;
        if(h < board.size() && board[h][pick] != 0){
            if(!s.empty() && s.top() == board[h][pick]) {
                answer += 2;
                s.pop();
            }
            else s.push(board[h][pick]);
            board[h][pick] = 0;
        }
    }
    return answer;
}