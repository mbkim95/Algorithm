fun main() {
    for (i in 0..2) {
        when (readLine()!!.split(' ').map { it.toInt() }.count { n -> n == 0 }) {
            0 -> println("E")
            1 -> println("A")
            2 -> println("B")
            3 -> println("C")
            else -> println("D")
        }
    }
}