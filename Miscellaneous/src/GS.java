import java.util.Stack;

public class GS {
    public static void main(String[] args) {
//       System.out.print(iterFib(6));
//        System.out.print(isPalindrome(404));
//        System.out.println(isAnagram("doogr", "rood"));
        System.out.print(checkIfBinaryTreeIsBST(buildBinaryTree()));
    }

    public static int recursiveFib(int n) {
        if(n == 0) return 0;
        if(n == 1 ) return 1;
        return recursiveFib(n-1) + recursiveFib(n-2);
    }

    public static int iterFib(int n) {
        int[] ans = new int[n+2];
        ans[0] = 0; ans[1] = 1;
        for(int i = 2; i<=n; i++) {
            ans[i] = ans[i-1] + ans[i-2];
        }
        return ans[n];
    }

    public static boolean isPalindrome(int n) {
        int stag = n;
        int target = 0;
        while(n > 0) {
           target = (target * 10) + (n % 10);
           n /= 10;
        }
        return target == stag;
    }

    public static boolean isAnagram(String word, String target)  {
        word = word.toLowerCase(); target = target.toLowerCase();
        if(word.length() != target.length()) return false;
        int[] map = new int[26]; int[] targ = new int[26];
        for(int i = 0; i<word.length(); i++) {
            map[word.charAt(i) - 'a'] += 1;
            targ[target.charAt(i) - 'a'] += 1;
        }
        for(int i = 0; i<26; ++i) {
            if(map[i] != targ[i]) return false;
        }
        return true;
    }

    public static int depths(Node root) {
        int visited = 0; int level = 0;
        //non-null root

    }

   static  int curr = 0;
    public static boolean checkIfBinaryTreeIsBST(Node root) {
        if(root == null) return true;

        checkIfBinaryTreeIsBST(root.left);

        if(curr > root.data) return false;
        curr = root.data;
        checkIfBinaryTreeIsBST(root.right);
        return true;
    }
    public static Node buildBinaryTree() {
         Node root = new Node(3);
         Node first = new Node(2);
         Node third = new Node ( 5);
         root.left = first;
         root.right = third;
         return root;
    }
    static class Node {
        int data;
        Node left;
        Node right;
        Node(int n) {
            data = n;
        }
    }
 }
