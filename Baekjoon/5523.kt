fun main() {
    var a = 0
    var b = 0
    repeat(readln().toInt()) {
        val s = readln().split(" ").map { it.toInt() }
        if (s[0] > s[1]) a++
        else if (s[0] < s[1]) b++
    }
    println("$a $b")
}