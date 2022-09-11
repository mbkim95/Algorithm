fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        print("Pairs for $n:")
        var isFirst = true
        for(i in 1..11) for(j in i+1..12) if(i + j == n) {
            print("${if(isFirst) " " else ", "}$i $j")
            isFirst = false
        }
        println()
    }
}