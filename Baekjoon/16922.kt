var n = 0
var check = BooleanArray(1001) { false }
var num = intArrayOf(1, 5, 10, 50)

fun pick(cnt: Int, idx: Int, sum: Int) {
    if(cnt == n) {
        check[sum] = true
        return
    }
    for(i in idx..3) pick(cnt+1, i, sum + num[i])
}

fun main() {
    n = readLine()!!.toInt()
    pick(0, 0,0)
    println(check.filter { it }.size)
}
