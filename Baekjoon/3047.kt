fun main() {
    val num = readLine()!!.split(" ").map { it.toInt() }.sorted()
    println(readLine()!!.map { num[it - 'A'] }.joinToString(" "))
}