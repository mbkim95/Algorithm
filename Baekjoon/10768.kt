fun main() {
    val m = readLine()!!.toString().toInt()
    val d = readLine()!!.toString().toInt()
    if (m < 2) println("Before")
    else if (m == 2) {
        if (d < 18) println("Before")
        else if (d == 18) println("Special")
        else println("After")
    } else println("After")
}