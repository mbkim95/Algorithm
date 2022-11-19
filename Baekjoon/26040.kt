fun main() {
    val a = readLine()!!
    val b = readLine()!!.split(" ").toSet()
    a.forEach { print("${if (b.contains(it.toString())) it.lowercase() else it}") }
    println()
}