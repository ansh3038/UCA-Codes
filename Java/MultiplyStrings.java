import java.util.Arrays;

class Solution {
    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) {
            return "0";
        }

        StringBuilder st1 = new StringBuilder(num1).reverse();
        StringBuilder st2 = new StringBuilder(num2).reverse();

        int[] arr = new int[num1.length() + num2.length()];

        for (int i = 0; i < st1.length(); i++) {
            for (int j = 0; j < st2.length(); j++) {
                int a = (st1.charAt(i) - '0') * (st2.charAt(j) - '0');
                arr[i + j] += a;
                arr[i + j + 1] += arr[i + j] / 10;
                arr[i + j] %= 10;
            }
        }

        StringBuilder result = new StringBuilder();
        int i = num1.length() + num2.length() - 1;
        while (i >= 0 && arr[i] == 0) {
            i--;
        }

        while (i >= 0) {
            result.append(arr[i]);
            i--;
        }

        return result.toString();
    }
}
