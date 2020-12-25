import java.util.*

fun main() {
    fun gcd(a: Int, b: Int): Int = if (a % b == 0) b else gcd(b, a % b)

    val n = readLine()!!.toInt()
    val num = mutableListOf<Int>()
    val st: StringTokenizer = StringTokenizer(readLine())

    for (i in 1..n)
        num.add(st.nextToken().toInt())

    var g = gcd(num[0], num[1])
    if (n == 3) g = gcd(g, num[2])

    for (i in 1..g)
        if (g % i == 0)
            println(i)
}
