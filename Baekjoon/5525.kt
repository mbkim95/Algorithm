fun main() {
    val n = readLine()!!.toInt()
    val m = readLine()!!.toInt()
    val str = readLine()!!

    var answer = 0

    var i = -1
    while (true) {
        i++
        if (i == m) break

        var length = 1

        if (str[i] == 'O') continue
        else {
            while (i + 2 < str.length && str[i + 1] == 'O' && str[i + 2] == 'I') {
                length += 2
                if (length == 2 * n + 1) {
                    answer++
                    length -= 2
                }
                i += 2
            }
        }
    }
    println(answer)
}