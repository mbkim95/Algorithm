fun main() {
    var total = readLine()!!.toInt()
    for (i in 0..8) total -= readLine()!!.toInt()
    println(total)
}