import kotlin.math.max
import kotlin.math.min

class Solution {
    val dx = listOf(-1, 0, 1, 0)
    val dy = listOf(0, -1, 0, 1)
    var r = 0
    var c = 0

    fun inRange(x: Int, y: Int): Boolean {
        if (x < 0 || x >= c || y < 0 || y >= r) return false
        return true
    }

    // 이길 수 있는지, 이동한 횟수
    fun turnA(board: Array<IntArray>, aloc: IntArray, bloc: IntArray, cnt: Int): Pair<Boolean, Int> {
        if (board[aloc[0]][aloc[1]] == -1) return Pair(false, cnt)

        board[aloc[0]][aloc[1]] = -1

        var canMove = false
        var canWin = false
        var maxCnt = cnt
        var minCnt = 987654321
        for (i in 0..3) {
            val nx = aloc[1] + dx[i]
            val ny = aloc[0] + dy[i]
            if (!inRange(nx, ny) || board[ny][nx] != 1) continue
            val result = turnB(board, intArrayOf(ny, nx), bloc, cnt + 1)

            if (result.first) {
                maxCnt = max(maxCnt, result.second)
            } else if (!result.first) {
                canWin = true
                minCnt = min(minCnt, result.second)
            }
        }
        board[aloc[0]][aloc[1]] = 1

        return if (canWin) Pair(canWin, minCnt) else Pair(canWin, maxCnt)
    }

    // 이길 수 있는지, 이동한 횟수
    fun turnB(board: Array<IntArray>, aloc: IntArray, bloc: IntArray, cnt: Int): Pair<Boolean, Int> {
        if (board[bloc[0]][bloc[1]] == -1) return Pair(false, cnt)

        board[bloc[0]][bloc[1]] = -1

        var canMove = false
        var canWin = false
        var maxCnt = cnt
        var minCnt = 987654321
        for (i in 0..3) {
            val nx = bloc[1] + dx[i]
            val ny = bloc[0] + dy[i]
            if (!inRange(nx, ny) || board[ny][nx] != 1) continue
            val result = turnA(board, aloc, intArrayOf(ny, nx), cnt + 1)

            if (result.first) {
                maxCnt = max(maxCnt, result.second)
            } else if (!result.first) {
                canWin = true
                minCnt = min(minCnt, result.second)
            }
        }
        board[bloc[0]][bloc[1]] = 1

        return if (canWin) Pair(canWin, minCnt) else Pair(canWin, maxCnt)
    }

    fun solution(board: Array<IntArray>, aloc: IntArray, bloc: IntArray): Int {
        r = board.size
        c = board[0].size
        return turnA(board, aloc, bloc, 0).second
    }
}