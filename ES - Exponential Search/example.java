import java.util.Arrays;

public class ExponentialSearch {
    static int binarySearch(int arr[], int l, int r, int x) {
        if (r >= l) {
            int mid = l + (r - l) / 2;

            if (arr[mid] == x)
                return mid;

            if (arr[mid] > x)
                return binarySearch(arr, l, mid - 1, x);

            return binarySearch(arr, mid + 1, r, x);
        }

        return -1;
    }

    static int exponentialSearch(int arr[], int n, int x) {
        if (arr[0] == x)
            return 0;

        int i = 1;
        while (i < n && arr[i] <= x)
            i = i * 2;

        return binarySearch(arr, i / 2, Math.min(i, n - 1), x);
    }

    public static void main(String args[]) {
        int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
        int n = arr.length;
        int x = 11;
        int result = exponentialSearch(arr, n, x);
        if (result != -1)
            System.out.println("Element found at index: " + result);
        else
            System.out.println("Element not found in the array");
    }
}
