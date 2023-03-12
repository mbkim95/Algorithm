fun main() = repeat(readln().toInt()) {
    val s = mutableListOf<Pair<String, Int>>()
    repeat(readln().toInt()) {
        val (a, b) = readln().split(" ")
        s.add(Pair(a, b.toInt()))
    }
    s.sortWith { o1, o2 ->
        if (o1.second > o2.second) -1 else 1
    }
    println(s[0].first)
}