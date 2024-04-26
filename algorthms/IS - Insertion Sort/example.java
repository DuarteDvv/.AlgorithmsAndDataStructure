import java.util.Arrays;

public class InsertionSort {
    public static void insertionSort(int[] arr) {
        int n = arr.length;

        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;

            // Move elements greater than key ahead
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                --j;
            }

            // Insert key at the correct position
            arr[j + 1] = key;
        }
    }

    public static void main(String[] args) {
        // Example usage
        int[] arr = {12, 11, 13, 5, 6};

        System.out.print("Array before sorting: ");
        System.out.println(Arrays.toString(arr));

        insertionSort(arr);

        System.out.print("Array after sorting: ");
        System.out.println(Arrays.toString(arr));
    }
}
