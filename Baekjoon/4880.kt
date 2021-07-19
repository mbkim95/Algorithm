fun main() {
    while (true) {
        val (a, b, c) = readLine()!!.split(" ").map { it.toInt() }
        if (a == 0 && b == 0 && c == 0) break
        if (a + c == 2 * b) println("AP ${c + b - a}")
        else if (a * c == b * b) println("GP ${c * b / a}")
    }
}