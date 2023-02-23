fun main() {
    val g = mutableListOf<String>()
    repeat(readln().toInt()) { g.add(readln()) }
    g.sortWith { o1, o2 ->
        if (o1.length < o2.length) -1
        else if (o1.length > o2.length) 1
        else {
            var a = o1.filter { it.isDigit() }.map { it.digitToInt() }
            var b = o2.filter { it.isDigit() }.map { it.digitToInt() }
            if (a.isEmpty()) a = listOf(0)
            if (b.isEmpty()) b = listOf(0)

            if (a.sum() < b.sum()) -1 else if (a.sum() > b.sum()) 1
            else if (o1 < o2) -1
            else 1
        }
    }
    g.forEach { println(it) }
}