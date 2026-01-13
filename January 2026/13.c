#include <stdio.h>
#include <stdbool.h>

bool canServe(int arr[], int n) {
    int five = 0, ten = 0;

    for (int i = 0; i < n; ++i) {
        if (arr[i] == 5) {
            five++;
        } else if (arr[i] == 10) {
            if (five == 0) return false;
            five--;
            ten++;
        } else if (arr[i] == 20) {
            if (ten > 0 && five > 0) {
                ten--;
                five--;
            } else if (five >= 3) {
                five -= 3;
            } else {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int arr[] = {5, 5, 5, 10, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%s\n", canServe(arr, n) ? "true" : "false");  // Output: true
    return 0;
}
