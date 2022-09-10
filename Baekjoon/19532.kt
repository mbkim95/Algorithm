fun main() {
    val n = readLine()!!.split(" ").map { it.toInt() }
    for (i in -999..999) {
        var find = false
        for (j in -999..999) {
            if (n[0] * i + n[1] * j == n[2] && n[3] * i + n[4] * j == n[5]) {
                println("$i $j")
                find = true
                break
            }
        }
        if (find) break
    }
}
