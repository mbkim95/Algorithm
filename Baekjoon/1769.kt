fun main() {
    var n = readLine()!!
    var cnt = 0
    while(n !in setOf("1", "2", "3", "4", "5", "6", "7", "8", "9")) {
        var s = 0
        for(c in n) s += (c - '0')
        n = s.toString()
        cnt++
    }
    println("$cnt\n${if(n.toInt() % 3 == 0) "YES" else "NO"}")
} 
