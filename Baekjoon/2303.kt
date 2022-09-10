fun main() {
    var maxValue = 0
    var user = 1
    for (t in 1..readLine()!!.toInt()) {
        val c = readLine()!!.split(" ").map { it.toInt() }
        var s = 0

        for (i in 0..2) for (j in i + 1..4) for (k in j + 1..4) {
            val t = c[i] + c[j] + c[k]
            if (s < t % 10) s = t % 10
        }

        if (maxValue <= s) {
            user = t
            maxValue = s
        }
    }
    println(user)
}
