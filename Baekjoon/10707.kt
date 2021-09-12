fun main() {
    val a = readLine()!!.toInt()
    val b = readLine()!!.toInt()
    val c = readLine()!!.toInt()
    val d = readLine()!!.toInt()
    val p = readLine()!!.toInt()
    val ap = a * p
    val bp = if (p > c) b + (p - c) * d else b
    println(if (ap > bp) bp else ap)
}