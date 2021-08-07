fun main() {
    val c = mutableListOf<Int>()
    for (i in 0..8) c.add(readLine()!!.toInt())
    for (i in 0..7)
        for (j in i + 1..8)
            if (c[i] + c[j] == c.sum() - 100) {
                c[i] = -1
                c[j] = -1
            }
    for (i in 0..8) if (c[i] == -1) continue else println(c[i])
}