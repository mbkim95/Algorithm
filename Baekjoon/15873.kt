fun main() {
    val n = readLine()!!
    if (n.length == 2) println(n.toInt() / 10 + n.toInt() % 10)
    else if (n.length == 3) {
        if (n.indexOf('0') == 1) println((n[0] - '0') * 10 + (n[2] - '0'))
        else println(n[0] - '0' + (n[1] - '0') * 10)
    } else println(20)
}