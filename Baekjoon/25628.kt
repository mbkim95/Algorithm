import kotlin.math.*

fun main() {
    val h=readLine()!!.split(" ").map{it.toInt()}
    print(min(h[0]/2,h[1]))
}