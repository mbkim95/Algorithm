fun main() {
    val d = readLine()!!.split(" ").map { it.toInt() }.toList().sorted()
    if (d[0] == d[1] && d[1] == d[2]) println("${10000 + d[1] * 1000}")
    else if(d[0] == d[1]) println("${1000 + d[0] * 100}")
    else if(d[1] == d[2]) println("${1000 + d[1] * 100}")
    else if(d[0] == d[2]) println("${1000 + d[2] * 100}")
    else println("${d[2] * 100}")
}