// Copyright 2025 NNTU-CS
#include <algorithm>

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                int num = right - left + 1;
                count += num * (num - 1) / 2;
                break;
            }
            int left_val = arr[left];
            int right_val = arr[right];
            int left_count = 0, right_count = 0;
            while (left < len && arr[left] == left_val) {
                left++;
                left_count++;
            }
            while (right >= 0 && arr[right] == right_val) {
                right--;
                right_count++;
            }
            count += left_count * right_count;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int binarySearchCount(int *arr, int left, int right, int target) {
    int first_pos = -1;
    int low = left, high = right;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    first_pos = low;

    low = left, high = right;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    int last_pos = high;

    if (first_pos <= last_pos) {
        return last_pos - first_pos + 1;
    }
    return 0;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int target = value - arr[i];
        int matches = binarySearchCount(arr, i + 1, len - 1, target);
        count += matches;
    }
    return count;
}
