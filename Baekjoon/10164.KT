fun main() {
    val (n, m, k) = readLine()!!.split(" ").map { it.toInt() }
    val dp1 = Array(n) { Array(m) { 1 } }
    val dp2 = Array(n) { Array(m) { 1 } }
    val r: Int
    val c: Int
    if (k == 0) {
        r = n - 1
        c = m - 1
    } else {
        r = if (k % m == 0) k / m - 1 else k / m
        c = k - 1 - r * m
    }
    for (j in 1..c)
        for (i in 1..r)
            dp1[i][j] = dp1[i][j - 1] + dp1[i - 1][j]

    for (j in c + 1 until m)
        for (i in r + 1 until n)
            dp2[i][j] = dp2[i][j - 1] + dp2[i - 1][j]
    println(dp1[r][c] * dp2[n - 1][m - 1])
}