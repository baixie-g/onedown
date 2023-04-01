#include <iostream>
#include <list>
#include <vector>
using namespace std;

void traverseList(list<int>::iterator it, list<int>::iterator end) {
    if (it == end) {
        return;
    }
    cout << *it << " ";
    traverseList(++it, end);
}
void traverseVector(vector<int>::iterator it, vector<int>::iterator end) {
    if (it == end) {
		return;
	}
	cout << *it << " ";
	traverseVector(++it, end);
}

int main() {
    list<int> myList = { 1, 2, 3, 4, 5 };
    traverseList(myList.begin(), myList.end());
    
    vector<int> myVector = { 1, 2, 3, 4, 5 };
    traverseVector(myVector.begin(), myVector.end());
    return 0;
}
//#include <iostream>
//#include <thread>
//#include <vector>
//#include <algorithm>
//#include <chrono>
//#include <random>
//using namespace std;
//
//void quickSort(int arr[], int left, int right);
//
//void parallelQuickSort(int arr[], int left, int right, int depthRemaining) {
//    if (left < right) {
//        int i = left, j = right;
//        int tmp;
//        int pivot = arr[(left + right) / 2];
//
//        // 分割数组
//        while (i <= j) {
//            while (arr[i] < pivot)
//                i++;
//            while (arr[j] > pivot)
//                j--;
//            if (i <= j) {
//                tmp = arr[i];
//                arr[i] = arr[j];
//                arr[j] = tmp;
//                i++;
//                j--;
//            }
//        };
//
//        // 创建新线程进行排序
//        if (depthRemaining > 0) {
//            thread t1(parallelQuickSort, arr, left, j, depthRemaining - 1);
//            thread t2(parallelQuickSort, arr, i, right, depthRemaining - 1);
//            t1.join();
//            t2.join();
//        }
//        // 递归排序左半部分
//        else {
//            quickSort(arr, left, j);
//            quickSort(arr, i, right);
//        }
//    }
//}
//
//void quickSort(int arr[], int left, int right) {
//    int i = left, j = right;
//    int tmp;
//    int pivot = arr[(left + right) / 2];
//
//    // 分割数组
//    while (i <= j) {
//        while (arr[i] < pivot)
//            i++;
//        while (arr[j] > pivot)
//            j--;
//        if (i <= j) {
//            tmp = arr[i];
//            arr[i] = arr[j];
//            arr[j] = tmp;
//            i++;
//            j--;
//        }
//    };
//
//    // 递归排序左半部分
//    if (left < j)
//        quickSort(arr, left, j);
//    // 递归排序右半部分
//    if (i < right)
//        quickSort(arr, i, right);
//}
//
//int main() {
//    const int n = 100000000;
//    int* arr = new int[n];
//    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//    uniform_int_distribution<int> dist(1, n);
//    for (int i = 0; i < n; i++)
//        arr[i] = dist(rng);
//
//    // 确定线程数量
//    int numThreads = thread::hardware_concurrency();
//    if (numThreads == 0)
//        numThreads = 2;
//
//    auto start = chrono::steady_clock::now();
//
//    // 创建线程并执行快速排序
//    vector<thread> threads;
//    threads.reserve(numThreads);
//    threads.emplace_back(parallelQuickSort, arr, 0, n - 1, log2(numThreads));
//    for_each(threads.begin(), threads.end(), [](thread& t) {
//        t.join();
//        });
//
//    auto end = chrono::steady_clock::now();
//    auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);
//    
//    cout << "Sorted " << n << " numbers in " << elapsed.count() << " ms" << endl;
//
//
//    delete[] arr;
//
//    return 0;
//}