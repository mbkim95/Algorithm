fun main() {
    for (i in 0 until readLine()!!.toInt()) {
        val s = readLine()!!
        println("${s[0]}${s[s.length - 1]}")
    }
}