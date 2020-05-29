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
    val solver = Main.TaskA()
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
                val sum = `in`.nextInt()
                val  r= `in`.nextInt()
                var w = 1
                var x = 1
                var y = 1
                var z = 1
                if(r != 1) {
                   val rpow : Int = r*r*r*r
                    w = ((1-r)*sum) / (1 - rpow)
                    x = w*r
                    y = x* r
                    z= y*r
                } else {
                    w = sum / 4
                    x = w
                    y = w
                    z  = w
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