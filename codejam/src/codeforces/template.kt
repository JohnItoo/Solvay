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
        val solver = TaskA()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class TaskB {
        fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
            val n = `in`.nextInt()
            var ans = 0
            var max = 0
            var max2 = 0
            var res = 0
            for (i in 0 until n) {
                val a = `in`.nextInt()
                if(max2 > a) ans++
                if(max < a) {
                    max2 = max
                    max = a
                } else if(max2 < a) {
                    max2 = a
                }

            }

            out.println(ans)
        }
    }

    internal class TaskA {
        fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
            val n = `in`.nextInt()

            for (i in 0 until n) {
                val a = `in`.nextInt()
                val b = `in`.nextInt()
                val mn = min(a, b)
                val mx = max(a,b)
                val x = 1
                val y = mn - 1;
                val z = mx - y;
                out.println("$x $y $z")
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