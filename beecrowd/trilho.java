import java.util.*;

public class trilho {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            int n = sc.nextInt();
            if (n == 0) break;

            while (true) {
                int first = sc.nextInt();
                if (first == 0) {
                    System.out.println(); 
                    break;
                }
                int[] desired = new int[n];
                desired[0] = first;
                for (int i = 1; i < n; i++) {
                    desired[i] = sc.nextInt();
                }

                System.out.println(pilha(n, desired) ? "Yes" : "No");
            }
        }
    }
    public static boolean pilha(int n, int[] desired) {
        Stack<Integer> stack = new Stack<>();
        int vagao = 1;  
        int index = 0;    

        while (vagao <= n || !stack.isEmpty()) {
            if (!stack.isEmpty() && stack.peek() == desired[index]) {
                stack.pop();
                index++;
            } else if (vagao <= n) {
                stack.push(vagao++);
            } else {
                return false;
            }
        }

        return true;
    }
}
