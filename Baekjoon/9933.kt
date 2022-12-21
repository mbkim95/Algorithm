fun main() {
    val pw = hashSetOf<String>()
    repeat(readln().toInt()) {
        pw.add(readln())
    }
    for (p in pw) {
        if (pw.contains(p.reversed())) {
            println("${p.length} ${p[p.length / 2]}")
            break
        }
    }
}