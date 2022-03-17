#include <bits/stdc++.h>

using namespace std;

void merge(double arr[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = arr[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = arr[mid + 1 + j];

    auto indexOfSubArrayOne = 0,
        indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne) {
        arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSort(double arr[], int const begin, int const end)
{
    if (begin >= end)
        return;
    auto mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}

void heapify(double arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(double arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void quickSort(double arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      double pivot = arr[(left + right) / 2];
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);

}
int n;
double base[1000005];
double a[1000005];
char test_case_inp[10][100] = {
    "test1.txt",
    "test2.txt",
    "test3.txt",
    "test4.txt",
    "test5.txt",
    "test6.txt",
    "test7.txt",
    "test8.txt",
    "test9.txt",
    "test10.txt"};

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("test.out", "w", stdout);
	for (int test_case = 1; test_case <= 10; test_case++)
    {
        cout << "Test case " << test_case << "\n";
        freopen(test_case_inp[test_case - 1],"r",stdin);
        int n = 1000000;
        for (int i = 0; i < n; i++)
            cin >> base[i];

        for (int i = 0; i < n; i++)
            a[i] =  base[i];
        clock_t begin_quick_sort = clock();
        quickSort(a, 0, n - 1);
        clock_t end_quick_sort = clock();
        cout << "quick sort: "
         << end_quick_sort - begin_quick_sort << " ms \n";

        for (int i = 0; i < n; i++)
            a[i] =  base[i];
        clock_t begin_c_sort = clock();
        sort(a, a + n);
        clock_t end_c_sort = clock();
        cout << "c++ sort: "
         << end_c_sort - begin_c_sort << " ms \n";

        for (int i = 0; i < n; i++)
            a[i] =  base[i];
        clock_t begin_heap_sort = clock();
        heapSort(a, n - 1);
        clock_t end_heap_sort = clock();
        cout << "heap sort: "
         << end_heap_sort - begin_heap_sort << " ms \n";

        for (int i = 0; i < n; i++)
            a[i] =  base[i];
        clock_t begin_merge_sort = clock();
        mergeSort(a, 0, n - 1);
        clock_t end_merge_sort = clock();
        cout << "merge sort: "
         << end_merge_sort - begin_merge_sort << " ms \n";

        cout << "\n";
    }
	return 0;
}
