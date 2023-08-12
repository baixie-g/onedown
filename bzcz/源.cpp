//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<queue>
//using namespace std;
//
//
//
//// 生成包含 n 个元素，逆序对数量为 inversions 的数组
//std::vector<int> generateArray(int n, int inversions) {
//    std::vector<int> arr(n);
//
//    // 生成有序数组
//    for (int i = 0; i < n; i++) {
//        arr[i] = i + 1;
//    }
//
//    // 随机交换元素，生成逆序对
//    for (int i = 0; i < inversions; i++) {
//        int index1 = rand() % n;
//        int index2 = rand() % n;
//        std::swap(arr[index1], arr[index2]);
//    }
//
//    return arr;
//}
//
//
//
//
//
////用于计算逆序对
//int merge(std::vector<int>& arr, int l, int m, int r) {
//    int inversions = 0;
//    std::vector<int> temp(r - l + 1);
//
//    int i = l, j = m + 1, k = 0;
//
//    while (i <= m && j <= r) {
//        if (arr[i] <= arr[j]) {
//            temp[k++] = arr[i++];
//        }
//        else {
//            temp[k++] = arr[j++];
//            inversions += m - i + 1;
//        }
//    }
//
//    while (i <= m) {
//        temp[k++] = arr[i++];
//    }
//
//    while (j <= r) {
//        temp[k++] = arr[j++];
//    }
//
//    std::copy(temp.begin(), temp.end(), arr.begin() + l);
//
//    return inversions;
//}
//
//int mergeSort(std::vector<int>& arr, int l, int r) {
//    int inversions = 0;
//
//    if (l < r) {
//        int m = (l + r) / 2;
//        inversions += mergeSort(arr, l, m);
//        inversions += mergeSort(arr, m + 1, r);
//        inversions += merge(arr, l, m, r);
//    }
//
//    return inversions;
//}
//
//int countInversions(std::vector<int>& arr) {
//    return mergeSort(arr, 0, arr.size() - 1);
//}
//
//
//
//
//
//
//
//
////1.冒泡排序(升序)
//void Bubble_Sort(vector<int>& arr) {
//    for (int i = 0; i < arr.size() - 1; i++)
//        for (int j = 0; j < arr.size() - i - 1; i++)
//            if (arr[j] > arr[j + 1])
//                swap(arr[j], arr[j + 1]);
//}
//void Bubble_Sort_2(vector<int>& arr) {
//    for (int i = 0, cnt; i < arr.size() - 1; i++) {
//        cnt = 0;
//        for (int j = 0; j < arr.size() - i - 1; i++)
//            if (arr[j] > arr[j + 1]) {
//                swap(arr[j], arr[j + 1]); cnt++;
//            }
//        if (cnt == 0)break;
//    }
//}//优化，当待排序区域没有发生交换时，证明已经有序（只有在一些特殊的排序方式下才会有优化效果）
///// 当数据离散化比较严重时不会有优化效果
//void Recursive_BubbleSort(vector<int>& arr, int n) //递归实现
//{
//    if (n == 1) return;
//    for (int i = 0; i < arr.size() - 1; i++) {
//        if (arr[i] > arr[i + 1])
//            swap(arr[i], arr[i + 1]);
//    }
//
//    Recursive_BubbleSort(arr, n - 1);
//}
////2.选择排序
//
//void selection_sort(int* arr, int l, int r) {
//    for (int i = l, I = r - 1; i < I; i++) {
//        int ind = i;
//        for (int j = i + 1; j < r; j++) {
//            if (arr[j] < arr[ind]) ind = j;
//        }
//        swap(arr[i], arr[ind]);
//    }
//    return;
//}
////3.归并排序
//void Merge(vector<int>& arr, int left, int mid, int right) {
//    int i = left;
//    int j = mid + 1;
//    int k = 0;
//    vector<int> temp(right - left + 1);
//    while (i <= mid && j <= right)
//        temp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
//
//    while (i <= mid)
//        temp[k++] = arr[i++];
//
//    while (j <= right)
//        temp[k++] = arr[j++];
//
//    for (int m = 0; m < temp.size(); m++)
//        arr[left + m] = temp[m];
//}
//void MergeSort(vector<int>& arr, int left, int right) {
//    if (left >= right) return;
//
//    int mid = left + (right - left) / 2;
//    MergeSort(arr, left, mid);
//    MergeSort(arr, mid + 1, right);
//    Merge(arr, left, mid, right);
//}
////4.快速排序
//int partition(vector<int>& arr, int left, int right) {
//    int pivot = right;
//    int location = left;
//    for (int i = left; i < right; i++) {
//        if (arr[i] < arr[pivot]) {
//            int temp = arr[i]; arr[i] = arr[location]; arr[location] = temp;
//            location++;
//        }
//    }
//    int temp = arr[pivot]; arr[pivot] = arr[location]; arr[location] = temp;
//    return location;
//}
//
//
//void QuickSort(vector<int>& arr, int left, int right) {
//    if (left >= right) return;
//
//    int pivot = partition(arr, left, right);
//    QuickSort(arr, left, pivot - 1);
//    QuickSort(arr, pivot + 1, right);
//}
////5.希尔排序
//void shell_sort(vector<int>& arr) {
//
//    for (int gap = arr.size() / 2; gap > 0; gap /= 2) {
//        for (int i = gap; i < arr.size(); i++) {
//            int temp = arr[i];
//            int j;
//            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
//                arr[j] = arr[j - gap];
//            }
//
//            arr[j] = temp;
//        }
//    }
//}
////6.堆排序
//void heapify(vector<int>& arr, int n, int i)
//{
//    int largest = i;
//    int l = 2 * i + 1;
//    int r = 2 * i + 2;
//
//    if (l < n && arr[l] > arr[largest])
//        largest = l;
//
//    if (r < n && arr[r] > arr[largest])
//        largest = r;
//
//    if (largest != i)
//    {
//        swap(arr[i], arr[largest]);
//        heapify(arr, n, largest);
//    }
//}
//
//void heapSort(vector<int>& arr, int n)
//{
//    for (int i = n / 2 - 1; i >= 0; i--)
//        heapify(arr, n, i);
//
//    for (int i = n - 1; i >= 0; i--)
//    {
//        swap(arr[0], arr[i]);
//        heapify(arr, i, 0);   //堆的数量减一
//    }
//}
////7.基数排序
//int maxbit(vector<int> arr) //求数据的最大位数
//{
//    int max = arr[0];
//    for (auto x : arr)
//        if (x > max)
//            max = x;
//
//    int bit = 1;
//
//    while (max >= 10)
//    {
//        max /= 10;
//        ++bit;
//    }
//    return bit;
//}
//
//void radixsort(vector<int>& arr) //基数排序
//{
//    int bit = maxbit(arr);
//    vector<int> tmp(arr.size());
//    vector<int> count(10); //0-9计数器
//    int i, j, k;
//    int radix = 1;
//    for (i = 1; i <= bit; i++) //进行bit次排序
//    {
//        for (j = 0; j < 10; j++)
//            count[j] = 0; //每次分配前清空计数器
//        for (j = 0; j < arr.size(); j++)
//        {
//            k = (arr[j] / radix) % 10;
//            count[k]++;
//        }
//        for (j = 1; j < 10; j++)
//            count[j] = count[j - 1] + count[j];
//
//        for (j = arr.size() - 1; j >= 0; j--)
//        {
//            k = (arr[j] / radix) % 10;
//            tmp[count[k] - 1] = arr[j];
//            count[k]--;
//        }
//
//        for (j = 0; j < arr.size(); j++)
//            arr[j] = tmp[j];
//        radix = radix * 10;
//    }
//}
