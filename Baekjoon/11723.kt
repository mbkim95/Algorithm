import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    var s = 0
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    repeat(br.readLine().toInt()) {
        val cmd = br.readLine().split(" ")
        when {
            cmd[0] == "add" -> s = s or (1 shl cmd[1].toInt())
            cmd[0] == "remove" -> s = s and (-1 xor (1 shl cmd[1].toInt()))
            cmd[0] == "check" -> bw.write("${if (s and (1 shl cmd[1].toInt()) != 0) 1 else 0}\n")
            cmd[0] == "toggle" -> s = s xor (1 shl cmd[1].toInt())
            cmd[0] == "all" -> s = -1
            cmd[0] == "empty" -> s = 0
        }
    }
    bw.flush()
}