// Copyright 2025 NNTU-CS

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            int sum = arr[i] + arr[j];
            if (sum == value)
                count++;
            else if (sum > value)
                break;
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
            int l = left + 1;
            int r = right - 1;
            int lCount = 1, rCount = 1;

            while (l <= r && arr[l] == arr[left]) {
                lCount++;
                l++;
            }

            while (r >= l && arr[r] == arr[right]) {
                rCount++;
                r--;
            }

            if (arr[left] == arr[right]) {
                int total = right - left + 1;
                count += total * (total - 1) / 2;
                break;
            } else {
                count += lCount * rCount;
                left += lCount;
                right -= rCount;
            }

        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }

    return count;
}

int findFirstOccurrence(int* arr, int left, int right, int target) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] >= target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;
}

int findLastOccurrence(int* arr, int left, int right, int target) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] <= target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        int target = value - arr[i];
        if (target < arr[i])
            continue;
        int first = findFirstOccurrence(arr, i + 1, len - 1, target);
        int last = findLastOccurrence(arr, i + 1, len - 1, target);
        if (first <= last)
            count += (last - first + 1);
    }
    return count;
}
