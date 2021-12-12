import java.util.*

fun main() {
    val t = readLine()!!.toList()
    val s = LinkedList<Char>()
    t.forEach { s.add(it) }
    val c = s.listIterator(s.size)
    repeat(readLine()!!.toInt()) {
        val cmd = readLine()!!.split(" ").toList()
        when (cmd[0]) {
            "P" -> c.add(cmd[1][0])
            "L" -> if (c.hasPrevious()) c.previous()
            "D" -> if (c.hasNext()) c.next()
            "B" -> if (c.hasPrevious()) {
                c.previous()
                c.remove()
            }
        }
    }
    println(s.joinToString(""))
}