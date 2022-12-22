fun main() {
    while (true) {
        val n = readln().toInt()
        if (n == 0) break

        val list = mutableListOf<String>()
        repeat(n) {
            list.add(readln())
        }
        list.sortWith { a, b ->
            if (a.lowercase() < b.lowercase()) -1
            else 1
        }
        println(list[0])
    }
}