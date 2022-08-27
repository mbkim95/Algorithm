fun main() {
    var total = readLine()!!.toInt()
    var isCorrect = true
    for (i in 1..readLine()!!.toInt()) {
        val l = readLine()!!.split(" ").map { it.toInt() }
        total -= l[0] * l[1]
        if (total < 0) {
            isCorrect = false
            break
        }
    }
    println(if (isCorrect && total == 0) "Yes" else "No")
}