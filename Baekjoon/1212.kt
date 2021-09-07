import java.io.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val o = arrayListOf("0", "1", "10", "11", "100", "101", "110", "111")
    val t = arrayListOf("000", "001", "010", "011", "100", "101", "110", "111")
    val s = br.readLine()
    for (i in s.indices) bw.write(if (i == 0) o[s[i] - '0'] else t[s[i] - '0'])
    bw.flush()
}