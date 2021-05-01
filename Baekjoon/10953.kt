fun main() {
    val n = readLine()!!.toInt()
    for(i in 0 until n){
        println(readLine()!!.split(',').map { it.toInt() }.sum())
    }
}