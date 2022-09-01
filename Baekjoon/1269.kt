fun main() {
    readLine()
    val s = hashSetOf<Int>()
    readLine()!!.split(" ").map { it.toInt() }.forEach { s.add(it) }
    readLine()!!.split(" ").map { it.toInt() }.forEach {
        if (s.contains(it)) s.remove(it)
        else s.add(it)
    }
    println(s.size)
}