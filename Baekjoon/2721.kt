fun main() {
    var t = IntArray(302)
    t[0] = 0
    for(i in 1..301) t[i] = t[i-1] + i
    repeat(readLine()!!.toInt()) {
        var s = 0
        for(i in 1..readLine()!!.toInt()) s += i*t[i+1]
        println(s)
    }
}
