fun main() {
    val h = IntArray(9) { 0 }
    var sum = 0
    for (i in 0 until 9) {
        h[i] = readLine()!!.toInt()
        sum += h[i]
    }
    h.sort()
    Loop@ for (i in 0 until 8) {
        for (j in i + 1 until 9) {
            if (sum - h[i] - h[j] == 100) {
                for (k in 0 until 9) {
                    if (k == i || k == j) continue
                    println(h[k])
                }
                break@Loop
            }
        }
    }
}
