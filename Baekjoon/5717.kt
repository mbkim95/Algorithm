fun main() {
    while (true) {
        val s = readLine()!!.split(" ").sumOf { it.toInt() }
        if (s == 0) break
        println(s)
    }
}