import java.util.Arrays;
import java.util.*;

class Bubble_Sort {

  static void bubbleSort(int arr[], int size) {

    for (int i = 0; i < size - 1; i++)
      for (int j = 0; j < size - i - 1; j++)
        if (arr[j] > arr[j + 1]) {
          int temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
  }

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();

    int[] data = new int[n];
    for (int i = 0; i < n; i++) {
      int x = sc.nextInt();
      data[i] = x;
    }

    Bubble_Sort.bubbleSort(data,n);

    
    System.out.println(Arrays.toString(data));
  }
}
