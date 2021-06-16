fun main() {
    var (a, b) = readLine()!!.split(" ").map { it.toInt() }
    b += readLine()!!.toInt()
    while (b >= 60) {
        a = if (a == 23) 0 else a + 1
        b -= 60
    }
    println("$a $b")
}