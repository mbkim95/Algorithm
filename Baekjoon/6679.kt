fun calc(num: Int, base: Int): Int {
    var ret = 0
    var tmp = num
    while (tmp > 0) {
        ret += tmp % base
        tmp /= base
    }
    return ret
}

fun main() = (1000..9999).asSequence().filter {
    calc(it, 10) == calc(it, 12) && calc(it, 12) == calc(it, 16)
}.forEach { println(it) }
