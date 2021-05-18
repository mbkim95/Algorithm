fun main() {
    val num = readLine()!!.split(' ').map { it.toInt() }
    var sum = 0
    for (i in num) sum += i * i
    println(sum % 10)
}