#include <string>
#include <vector>
#define REMOVE 3
using namespace std;

int N, M;
bool finish = false;
int chk[31][31];

// 2x2 사각형을 검사하는 함수
void checkBlock(vector<string>& board, int x, int y) {
    char c = board[y][x];
    if (c == ' ') return;
    // 2x2 사각형이 모두 같은 값을 가지면 chk 배열에 체크한다
    if (board[y + 1][x] == c && board[y][x + 1] == c && board[y + 1][x + 1] == c) {
        chk[y][x] = REMOVE;
        chk[y + 1][x] = REMOVE;
        chk[y][x + 1] = REMOVE;
        chk[y + 1][x + 1] = REMOVE;
        finish = false;
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    N = n;
    M = m;
    while (!finish) {
        finish = true;

        // board를 순회하면서 제거 가능한 블록 확인
        for (int i = 0; i < M - 1; i++)
            for (int j = 0; j < N - 1; j++)
                checkBlock(board, j, i);

        // 제거 가능한 블록인 경우 board에서 제거
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < M; i++) {
                // chk 배열에 제거해야할 블록이라고 저장되어있는 경우
                if (chk[i][j] == REMOVE) {
                    // 보드를 빈칸으로 변경
                    board[i][j] = ' ';
                    chk[i][j] = 0;
                    answer++;
                }
            }

            // 블록이 떨어지는걸 구현
            // 아래서부터 위로 올라가면서 탐색한다
            for (int i = M - 1; i >= 0; i--) {
                // 빈칸인 경우
                if (board[i][j] == ' ') {
                    int idx = i - 1;
                    // 빈칸이 아닐 때까지 탐색
                    while (idx >= 0 && board[idx][j] == ' ')
                        idx--;
                    // 빈칸이 아닌 블록을 찾은 경우
                    if (idx >= 0) {
                        board[i][j] = board[idx][j];
                        board[idx][j] = ' ';
                    }
                }
            }
        }
    }
    return answer;
}