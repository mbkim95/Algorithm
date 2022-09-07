fun main() {
    while (true) {
        val s = readLine()!!
        if (s == "#") break
        println(s.lowercase().filter { it in setOf('a', 'e', 'i', 'o', 'u') }.length)
    }
}