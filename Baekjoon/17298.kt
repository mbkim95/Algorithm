import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val n = br.readLine()!!.toInt()
    var st = StringTokenizer(br.readLine())
    val num = IntArray(n)

    for (i in 0 until n) num[i] = st.nextToken().toInt()

    val s = Stack<Int>()
    val ans = IntArray(n)
    s.push(0)

    for (i in 1 until n) {
        if (s.isEmpty()) s.push(i)
        while (!s.isEmpty() && num[s.peek()] < num[i]) {
            ans[s.peek()] = num[i]
            s.pop()
        }
        s.push(i)
    }
    while (!s.isEmpty()) {
        ans[s.peek()] = -1
        s.pop()
    }
    for (i in ans) {
        bw.write("$i ")
    }
    bw.write("\n")
    bw.flush()

}
