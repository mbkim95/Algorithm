fun Int.isPrime(): Boolean {
    var isPrime = true
    var i = 2
    while (true) {
        if (i * i >= this) break
        if (this % i == 0) {
            isPrime = false
            break
        }
        i++
    }
    return isPrime
}

fun main() {
    val n = readln().split(" ")
    val num = "${n[1]}${n[0]}".toInt()
    println(if (n[0].toInt().isPrime() && num.isPrime()) "Yes" else "No")
}