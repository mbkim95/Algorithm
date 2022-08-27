import java.io.*
import java.util.Collections.binarySearch

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    br.readLine().toInt()
    val s = mutableSetOf<Int>()
    val tmp = mutableListOf<Int>()
    val nums = br.readLine().split(" ").map { it.toInt() }
    nums.forEach {
        if (!s.contains(it)) {
            s.add(it)
            tmp.add(it)
        }
    }
    tmp.sort()
    nums.forEach {
        bw.write("${binarySearch(tmp, it)} ")
    }
    bw.flush()
}