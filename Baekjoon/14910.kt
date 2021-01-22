fun main() {
    val nums = readLine()!!.split(' ').map { it.toInt() }.toList()
    var prev = -1000001
    var isGood = true
    for (i in nums) {
        if (prev > i) {
            isGood = false
            break
        }
        prev = i
    }
    println(if (isGood) "Good" else "Bad")
}
