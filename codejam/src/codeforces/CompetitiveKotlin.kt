//package codeforces
//
//import java.io.*
//import java.util.*
//
//internal class TaskC {
//    fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
//        val n = `in`.nextInt()
//        var ans = 0
//        var max = 0
//        var max2 = 0
//        var res = 0
//        for (i in 0 until n) {
//            val a = `in`.nextInt()
//            if(max2 > a) ans++
//            if(max < a) {
//                max2 = max
//                max = a
//            } else if(max2 < a) {
//                max2 = a
//            }
//
//        }
//
//        out.println(ans)
//    }
//}
//
//internal class TaskB {
//    fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
//        val n = `in`.nextInt()
//
//        for (i in 0 until n) {
//            val s = `in`.next()
//            val t = `in`.next()
//            val len = t.length
//            if(s.length > 2 * len) {
//                out.println("NO")
//                continue
//            }
//            var ans = "YES"
//            var j = 0
//            var k = 0
//            while(j < len && k < s.length) {
////                    out.println(j)
//                if(s[k] == t[j]) {
//                    j++
//                    k++
//                    continue
//                }
//                if(s[k] == '+' && t[j] == '-') {
//                    ans = "NO"
//                    break
//                }
//                if(t[j] == '+' && s[k] == '-' && ((k + 1 >= s.length) || s[k+1] == '+')) {
//                    ans = "NO"
//                    break
//                }
//                k+=2
//                j+=1
//            }
//            if(ans == "YES" && (k != s.length || j != len  )) {
////                    out.println("here")
//                ans = "NO"
//            }
//            out.println(ans)
//        }
//
//    }
//}
//
//internal class TaskA {
//    fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
//        val n = `in`.nextInt()
//
//        for (i in 0 until n) {
//            val a = `in`.nextInt()
//            val b = `in`.nextInt()
//            val mn = Integer.min(a, b)
//            val mx = Math.max(a, b)
//            val x = 1
//            val y = mn - 1;
//            val z = mx - y;
//            out.println("$x $y $z")
//        }
//    }
//
//}
//
//internal class TaskD {
//    fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
//        val n = `in`.nextInt()
//        var mks = 0
//        var lst = mutableListOf<Int>()
//        for(i in 0 until n)  {
//            val a = `in`.nextInt()
//            lst.add(a)
//            if(a == -1) mks++
//        }
//        var ans = mutableListOf<Int>()
//        var fini = 0
//        for(i in 0 until mks) {
//            ans.clear()
//            var j = i
//            while(j < n ) {
//                if(lst[j] == -1) {
//                    fini += 1
//                    break
//                }
//                ans.add(lst[j])
//                j+=(mks-fini)
//            }
//            val sz = ans.size
//            out.print("$sz ")
//            for(q in 0 until ans.size) {
//                val fg = ans[q]
//                out.print("$fg ")
//            }
//            out.println("")
//        }
//
//
//    }
//
//
//}
//internal class InputReader(stream: InputStream) {
//    var reader: BufferedReader
//    var tokenizer: StringTokenizer? = null
//
//    init {
//        reader = BufferedReader(InputStreamReader(stream), 32768)
//        tokenizer = null
//    }
//
//    operator fun next(): String {
//        while (tokenizer == null || !tokenizer!!.hasMoreTokens()) {
//            try {
//                tokenizer = StringTokenizer(reader.readLine())
//            } catch (e: IOException) {
//                throw RuntimeException(e)
//            }
//
//        }
//        return tokenizer!!.nextToken()
//    }
//
//    fun nextInt(): Int {
//        return Integer.parseInt(next())
//    }
//
//
//}
