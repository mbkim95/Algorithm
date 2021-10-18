import java.io.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val nums = arrayListOf<Int>()
    repeat(br.readLine()!!.toInt()) {
        nums.add(br.readLine()!!.toInt())
    }
    nums.sortDescending()
    for (i in nums) bw.write("$i\n")
    bw.flush()
}