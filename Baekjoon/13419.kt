fun main() = repeat(readln().toInt()) {
    val s = readln()
    val len = s.length
    if (len == 1) {
        println("$s\n$s")
    } else {
        val even = s.filterIndexed { idx, _ -> idx % 2 == 0 }
        val odd = s.filterIndexed { idx, _ -> idx % 2 == 1 }
        if (len % 2 == 0) {
            println("$even\n$odd")
        } else {
            println("$even$odd\n$odd$even")
        }
    }
}