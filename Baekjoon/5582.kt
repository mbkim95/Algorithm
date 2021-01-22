import java.lang.Integer.max

fun main() {
    val dp = Array(4001) { IntArray(4001) { 0 } }

    val a = readLine()!!
    val b = readLine()!!
    var ans = 0
    for (i in 1..a.length) {
        for (j in 1..b.length) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1
                ans = max(ans, dp[i][j])
            }
        }
    }
    println(ans)
}
