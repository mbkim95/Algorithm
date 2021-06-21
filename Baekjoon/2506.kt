fun main() {
    val n = readLine()!!.toInt()
    val num = readLine()!!.split(" ").map { it.toInt() }
    var sum = 0
    var p = 1
    for (i in 0 until n) {
        if (num[i] == 1) sum += p++
        else p = 1
    }
    println(sum)
}