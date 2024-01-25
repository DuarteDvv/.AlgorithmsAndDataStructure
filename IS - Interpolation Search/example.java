public class InterpolationSearch {

   public static void main(String[] args) {
       int[] arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
       int n = arr.length;
       int x = 15;
       int index = interpolationSearch(arr, n, x);
       if (index != -1) System.out.println("Element found at index " + index);
       else System.out.println("Element not found in the array");
   }

   public static int interpolationSearch(int[] arr, int n, int x) {
       int low = 0, high = n - 1;
       while (low <= high && x >= arr[low] && x <= arr[high]) {
           if (low == high) {
               if (arr[low] == x) return low;
               return -1;
           }

           int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));
           pos = Math.min(pos, high - 1);

           if (arr[pos] == x) return pos;
           if (arr[pos] < x) low = pos + 1;
           else high = pos - 1;
       }
       return -1;
   }
}
