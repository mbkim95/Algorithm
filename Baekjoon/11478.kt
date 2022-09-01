fun main() {
    val set = hashSetOf<String>()
    val str = readLine()!!

    for (i in 1..str.length)
        for (j in 0..str.length - i)
            set.add(str.substring(j, j + i))
    println(set.size)
}