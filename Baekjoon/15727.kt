fun main() {
    var l = readLine()!!.toInt()
    var ans = if (l % 5 == 0) l / 5 else l / 5 + 1
    println(ans)
}
