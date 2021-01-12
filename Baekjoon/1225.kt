fun main() {
    val (a, b) = readLine()!!.split(' ')

    var tmp: Long = 0
    var tmp2: Long = 0

    for (i in a.indices) tmp += a[i] - '0'
    for (i in b.indices) tmp2 += b[i] - '0'
    println(tmp * tmp2)
}
