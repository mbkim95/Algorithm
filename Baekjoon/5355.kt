fun main() = repeat(readLine()!!.toInt()) {
    val m = readLine()!!.split(" ")
    var a = m[0].toFloat()
    for (i in 1 until m.size) if (m[i] == "@") a *= 3 else if (m[i] == "%") a += 5 else a -= 7
    println(String.format("%.2f", a))
}