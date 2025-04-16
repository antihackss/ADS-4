// Copyright 2025 NNTU-CS

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            } else if (arr[i] + arr[j] > value) {
                break;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0, right = len - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == value) {
            int lVal = arr[left];
            int rVal = arr[right];
            int lCount = 0, rCount = 0;

            while (left < right && arr[left] == lVal) {
                lCount++;
                left++;
            }
            while (right >= left && arr[right] == rVal) {
                rCount++;
                right--;
            }

            if (lVal == rVal) {
                count += (lCount * (lCount - 1)) / 2;
            } else {
                count += lCount * rCount;
            }
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }

    return count;
}

int findFirstOccurrence(int* array, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (array[mid] >= target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int findLastOccurrence(int* array, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (array[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return right;
}

int countOccurrences(int* arr, int left, int right, int target) {
    int first = findFirstOccurrence(arr, left, right, target);
    int last = findLastOccurrence(arr, left, right, target);
    if (first <= last) {
        return last - first + 1;
    }
    return 0;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        int complement = value - arr[i];
        if (complement < arr[i]) break;
        int occurrences = countOccurrences(arr, i + 1, len - 1, complement);
        count += occurrences;
    }
    return count;
}
