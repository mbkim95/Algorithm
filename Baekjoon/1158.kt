import java.util.*

fun main() {
    val (n, k) = readLine()!!.split(" ").map { it.toInt() }
    val q = LinkedList<Int>()
    for (i in 1..n) q.add(i)
    print("<")
    while(q.size > 1){
        for(i in 0 until k-1) {
            q.addLast(q.first)
            q.pop()
        }
        print("${q.first}, ")
        q.pop()
    }
    println("${q.pop()}>")
}