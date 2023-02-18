fun main() {
    val s = readln().split(" ")
    val result = s[0].toInt() + s[2].toInt() == s[4].toInt()
    println(if (result) "YES" else "NO")
}