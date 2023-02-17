fun main() {
    var prev: Int? = null
    while (true) {
        val s = readln()
        if (prev == null) prev = s.toInt()
        else {
            if (s == "=") {
                println(prev)
                break
            }
            when (s) {
                "+" -> prev += readln().toInt()
                "-" -> prev -= readln().toInt()
                "*" -> prev *= readln().toInt()
                "/" -> prev /= readln().toInt()
            }
        }
    }
}