fun main() {
    val n = readLine()!!
    var left = 0
    var right = 0

    for (i in 0 until n.length / 2) {
        left += n[i].toInt()
    }

    for (i in n.length / 2 until n.length) {
        right += n[i].toInt()
    }

    if (left == right) println("LUCKY")
    else println("READY")
}