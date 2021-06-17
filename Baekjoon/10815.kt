fun main() {
    readLine()!!.toInt()
    val num = hashSetOf<Int>()
    readLine()!!.split(" ").map { it.toInt() }.forEach { num.add(it) }
    readLine()!!.toInt()
    readLine()!!.split(" ").map { it.toInt() }.forEach { print("${if (num.contains(it)) 1 else 0} ") }
}