void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {

    // Choose middle element as pivot
    int mid = low + (high - low) / 2;

    // Move pivot to the end
    swap(&arr[mid], &arr[high]);

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {

        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // Put pivot in its correct position
    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

void quickSort(int arr[], int low, int high) {

    if (low < high) {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

bool containsDuplicate(int* nums, int numsSize) {

    quickSort(nums, 0, numsSize - 1);

    // Check adjacent elements
    for (int i = 0; i < numsSize - 1; i++) {

        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }

    return false;
}