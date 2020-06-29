fun main() {
    val (start, p) = readLine()!!.split(' ').map { it.toInt() }
    val nums = arrayListOf(start)
    val set = mutableSetOf(start)
    var tmp = 0
    var index = 0

    while (true) {
        tmp = 0
        nums[index].toString().forEach {
            tmp += Math.pow((it - '0').toDouble(), p.toDouble()).toInt()
        }
        if (set.contains(tmp)) break

        nums.add(tmp)
        set.add(tmp)
        index++
    }
    println(nums.indexOf(tmp))
}