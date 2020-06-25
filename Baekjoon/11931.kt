import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val nums = arrayListOf<Int>()
    for (i in 1..br.readLine()!!.toInt())
        nums.add(br.readLine()!!.toInt())
    nums.sortDescending()
    for (i in nums) bw.write("$i\n")
    bw.flush()
}