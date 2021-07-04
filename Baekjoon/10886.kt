fun main() {
    val n = readLine()!!.toInt()
    var sum = 0
    for (i in 0 until n) sum += readLine()!!.toInt()
    println("Junhee is ${if (sum > n / 2) "" else "not "}cute!")
}