int countPairs(int arr[], int n, int target) {
    int hashMap[200001] = {0}, count = 0;

    for (int i = 0; i < n; i++) {
        count += hashMap[target - arr[i] + 100000]; 
        hashMap[arr[i] + 100000]++;
    }

    return count;
}