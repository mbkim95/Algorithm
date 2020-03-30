#include <string>
#include <vector>
#include <iostream>

using namespace std;

int n;

bool canFill(int x, int y, vector<vector<int>>& board){
    for(int i=0; i<y; i++)
        if(board[i][x] != 0) return false;
    return true;
}

bool find(int x, int y, int w, int h, vector<vector<int>>& board){
    int v = -1;
    int empty = 0;
    for(int i=y; i<y+h; i++){
        for(int j=x; j<x+w; j++){
            if(board[i][j] == 0){
                if(!canFill(j, i, board)) return false;
                empty++;
                if(empty > 2) return false;
            }else{
                if(v != -1 && board[i][j] != v) return false;
                v = board[i][j];
            }
        }
    }
    for(int i=y; i<y+h; i++)
        for(int j=x; j<x+w; j++)
            board[i][j] = 0;
    return true;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    n = board.size();
    int cnt;
    do{
        cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(j <= n-2 && i <= n-3 && find(j, i, 2, 3, board)){
                    cnt++;
                }else if(j <= n-3 && i <= n-2 && find(j, i, 3, 2, board)){
                    cnt++;
                }
            }
        }
        answer += cnt;
    }while(cnt > 0);
    return answer;
}