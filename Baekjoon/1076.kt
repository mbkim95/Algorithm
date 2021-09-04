fun main() {
    val v = hashMapOf(
        "black" to 0,
        "brown" to 1,
        "red" to 2,
        "orange" to 3,
        "yellow" to 4,
        "green" to 5,
        "blue" to 6,
        "violet" to 7,
        "grey" to 8,
        "white" to 9
    )
    val m = hashMapOf(
        "black" to 1,
        "brown" to 10,
        "red" to 100,
        "orange" to 1000,
        "yellow" to 10000,
        "green" to 100000,
        "blue" to 1000000,
        "violet" to 10000000,
        "grey" to 100000000,
        "white" to 1000000000
    )
    var sum: Long = 0
    for (i in 0..2) {
        when (i) {
            0 -> sum += v[readLine()]!!
            1 -> sum = 10 * sum + v[readLine()]!!
            else -> sum *= m[readLine()]!!
        }
    }
    println(sum)
}