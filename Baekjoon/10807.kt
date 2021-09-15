fun main() {
    readLine()!!.toInt()
    val l = readLine()!!.split(" ").map { it.toInt() }
    val v = readLine()!!.toInt()
    println(l.filter { it == v }.count())
}