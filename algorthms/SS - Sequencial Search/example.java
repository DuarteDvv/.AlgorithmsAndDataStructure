public class Main {
    public static void main(String[] args) {
        int[] arr = {1, 4, 6, 8, 10};
        int n = arr.length;
        int x = 6;
        int result = sequentialSearch(arr, n, x);
        if (result == -1) {
            System.out.println("Element is not present in array");
        } else {
            System.out.println("Element is present at index " + result);
        }
    }

    static int sequentialSearch(int[] arr, int n, int x) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == x)
                return i;
        }
        return -1;
    }
}
