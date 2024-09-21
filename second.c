#include <stdio.h>

void arrangePosNeg(int arr[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        // Move left pointer until a negative number is found
        while (arr[left] > 0 && left < right) {
            left++;
        }

        // Move right pointer until a positive number is found
        while (arr[right] < 0 && left < right) {
            right--;
        }

        // If left is still less than right, swap the elements
        if (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
}

int main() {
    int arr[] = {12, -7, 5, -3, -9, 19, 4, -2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    arrangePosNeg(arr, n);

    printf("Array after rearranging: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
