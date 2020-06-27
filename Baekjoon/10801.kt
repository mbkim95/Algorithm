fun main() {
    val cardA = readLine()!!.split(" ").map { it.toInt() }
    val cardB = readLine()!!.split(" ").map { it.toInt() }
    var winA = 0
    var winB = 0
    for (i in 0..9) {
        if (cardA[i] > cardB[i]) winA++
        if (cardA[i] < cardB[i]) winB++
    }
    if (winA > winB) println("A")
    if (winA < winB) println("B")
    if (winA == winB) println("D")
}