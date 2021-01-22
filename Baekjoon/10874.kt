fun main() {
    val answer = arrayListOf<Int>()
    for (i in 0..9) answer.add((i % 5) + 1)

    var t = readLine()!!.toInt()
    val ans = mutableListOf<Int>()
    for (c in 1..t) {
        val s = readLine()!!.split(' ').map { it.toInt() }.toList()
        var isCheated = true
        for (i in s.indices) {
            if (s[i] != answer[i]) {
                isCheated = false
                break
            }
        }
        if (isCheated) ans.add(c)
    }
    for (i in ans) println(i)
}
