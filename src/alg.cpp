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
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            }

            int left_val = arr[left];
            int left_count = 1;
            while (left + 1 < len && arr[left + 1] == left_val) {
                left++;
                left_count++;
            }

            int right_val = arr[right];
            int right_count = 1;
            while (right - 1 >= 0 && arr[right - 1] == right_val) {
                right--;
                right_count++;
            }
            
            count += left_count * right_count;
            left++;
            right--;
        } 
        else if (sum < value) {
            left++;
        } 
        else {
            right--;
        }
    }
    return count;
}

int countOccurrences(int *arr, int left, int right, int target) {
    int first = -1, last = -1;

    int low = left, high = right;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    first = low;

    low = left, high = right;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    last = high;
    
    return (first <= last) ? (last - first + 1) : 0;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int target = value - arr[i];
        count += countOccurrences(arr, i + 1, len - 1, target);
    }
    return count;
}
