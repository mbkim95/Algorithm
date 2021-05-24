fun main() {
    var sum = 0
    for (i in 0..4) {
        val s = readLine()!!.toInt()
        sum += if (s < 40) 40 else s
    }
    println(sum / 5)
}