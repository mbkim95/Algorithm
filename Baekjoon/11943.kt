fun main() {
    println(List(2) { readLine()!!.split(" ").map { it.toInt() } }.let { Math.min(it[0][0] + it[1][1], it[0][1] + it[1][0]) })
}