fun main() {
    val n = readLine()!!.toInt()
    val map = hashMapOf<String, Int>()

    for (i in 1..n) {
        val tmp = readLine()!!
        map[tmp] = if (map[tmp] == null) 1 else map[tmp]!! + 1
    }

    var cnt = 0
    val ans = mutableListOf<String>()
    for (i in map) {
        if (cnt < i.value) {
            cnt = i.value
            ans.clear()
            ans.add(i.key)
        } else if (cnt == i.value) ans.add(i.key)
    }
    ans.sort()
    println(ans[0])
}
