import java.util.*

fun main() {
    var st = StringTokenizer(readLine())
    val n = st.nextToken().toInt()
    val m = st.nextToken().toInt()
    val helmet = arrayListOf<Int>()
    val vest = arrayListOf<Int>()
    st = StringTokenizer(readLine())
    for (i in 0 until n) helmet.add(st.nextToken().toInt())
    st = StringTokenizer(readLine())
    for (i in 0 until m) vest.add(st.nextToken().toInt())

    println(helmet.maxOrNull()?.plus(vest.maxOrNull()!!))
}
