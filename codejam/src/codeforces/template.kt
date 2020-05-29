//package codeforces
import java.io.IOException
import java.io.InputStream
import java.io.PrintWriter
import java.util.Arrays
import java.util.StringTokenizer
import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Integer.min
import java.lang.Math.max

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
fun main() {
    val inputStream = System.`in`
    val outputStream = System.out
    val `in` = Main.InputReader(inputStream)
    val out = PrintWriter(outputStream)
    val solver = Main.TaskB()
    solver.solve(1, `in`, out)
    out.close()
}

object Main {
    @JvmStatic
    fun main(args: Array<String>) {
        val inputStream = System.`in`
        val outputStream = System.out
        val `in` = InputReader(inputStream)
        val out = PrintWriter(outputStream)
        val solver = TaskB()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class TaskSample {
        fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
            val n = `in`.nextInt()

            for (i in 0 until n) {
                val a = `in`.nextInt()
                val b = `in`.nextInt()
                val mn = Integer.min(a, b)
                val mx = Math.max(a, b)
                val x = 1
                val y = mn - 1;
                val z = mx - y;
                out.println("$x $y $z")
            }
        }

    }

    internal class TaskB {
        fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
            val n = `in`.nextInt()

            for (i in 0 until n) {
                val a = `in`.nextInt()
                val b = `in`.nextInt()
                val c = `in`.nextInt()
                val s = `in`.next()
                out.println(a)
                var ans = 0
//                if(s[0] == '1') {ans += b}
                var sings = 0
                var st = 0
                var j = 0
                out.println(s)
                while (j < a) {
                    4
                    4 5 7
                    1011
                    4 4 10
                    0101
                    5 3 4
                    11011
                    6 4 6
                    011101
                    if ((j == a - 1 && s[j] == '1') || s[j] == '1' && s[j + 1] == '0') {
                        ans += b
                        j++

                    }
//                    else {
//                        var start = j
//                        while (j < a && s[j] != '0') {
//                            j++
//                        }
//                        var end = j
//                        var num = end - start
//                        var red = num / 2
//                        var rem = num - red
//                        ans += (b * rem) + ((c - b) * red)
//                    }
                }
                out.println(ans)
            }

        }
    }

    internal class TaskA {
        fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
            val n = `in`.nextInt()

            for (i in 0 until n) {
                val a = `in`.nextInt()
                val b = `in`.nextInt()
                var w = 0
                var x = 0
                var y = 0
                var z = 0
                while ((w + x + y + z) != a) {
                    w += 1
                    x = w * b
                    y = x * b
                    z = y * b
                }
                out.println("$w $x $y $z")
            }
        }

    }


    internal class InputReader(stream: InputStream) {
        var reader: BufferedReader
        var tokenizer: StringTokenizer? = null

        init {
            reader = BufferedReader(InputStreamReader(stream), 32768)
            tokenizer = null
        }

        operator fun next(): String {
            while (tokenizer == null || !tokenizer!!.hasMoreTokens()) {
                try {
                    tokenizer = StringTokenizer(reader.readLine())
                } catch (e: IOException) {
                    throw RuntimeException(e)
                }

            }
            return tokenizer!!.nextToken()
        }

        fun nextInt(): Int {
            return Integer.parseInt(next())
        }


    }
}