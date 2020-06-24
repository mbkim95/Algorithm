fun main() {
    var t = readLine()!!.toInt()
    while (t-- > 0) {
        val (_n, str) = readLine()!!.split(" ")
        val n = _n.toInt()
        println(str.let { it.slice(0 until n - 1) + it.slice(n until it.length) })
    }
}