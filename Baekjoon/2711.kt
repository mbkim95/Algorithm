fun main() {
    for (t in 0 until readLine()!!.toInt()) {
        var (i, s) = readLine()!!.split(" ")
        println(s.filterIndexed { index, c -> index != (i.toInt() - 1) })
    }
}
