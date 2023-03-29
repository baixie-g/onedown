//#include <iostream>
//#include <vector>
#include <time.h>
//#include<stdlib.h>
#include<windows.h>
//#include <thread>
//#include <algorithm>
//using namespace std;
//
//// 分割数组的函数
//int partition(std::vector<int>& arr, int left, int right) {
//    int pivot = arr[left];
//    int i = left + 1, j = right;
//    while (i <= j) {
//        while (i <= j && arr[i] < pivot) i++;
//        while (i <= j && arr[j] > pivot) j--;
//        if (i <= j) {
//            std::swap(arr[i], arr[j]);
//            i++;
//            j--;
//        }
//    }
//    swap(arr[left], arr[j]);
//    return j;
//}
//
//// 排序子数组的函数
//void quick_sort(vector<int>& arr, int left, int right, int depth) {
//    if (left >= right) return;
//    int pivot_index = partition(arr, left, right);
//
//    // 判断是否需要创建新线程
//    if (depth <= 0) {
//        quick_sort(arr, left, pivot_index - 1, depth + 1);
//        quick_sort(arr, pivot_index + 1, right, depth + 1);
//    }
//    else {
//        thread t1(quick_sort,ref(arr), left, pivot_index - 1, depth + 1);
//        thread t2(quick_sort,ref(arr), pivot_index + 1, right, depth + 1);
//        t1.join();
//        t2.join();
//    }
//}
//
//// 快速排序函数的包装
//void quick_sort(vector<int>& arr) {
//    quick_sort(arr, 0, arr.size() - 1, 0);
//}
//
//int main() {
//    vector<int> nums;
//    int n;
//    cout << "请输入数组大小：";
//    cin >> n;
//
//    while (n) {
//        int a = rand() / 32767.000000 * 1000000;
//        nums.push_back(a);
//        n--;
//    }
//    DWORD a;
//    a = GetTickCount64();
//    //std::vector<int> arr = { 5, 3, 8, 6, 2, 7, 1, 4 };
//    quick_sort(nums);
//  /*  for (int num : arr) {
//        std::cout << num << " ";
//    }*//*
//    std::cout << std::endl;*/
//    cout << "runtime:" << GetTickCount64() - a << "ms\t分层抽样10个\n";
//    for (int i = 0; i < nums.size(); i += int(nums.size() / 10.00))
//        cout << nums[i] << "\n";
//    return 0;
//}



#include <iostream>
#include <thread>
#include <vector>
using namespace std;
// 单个函数快速排序（多线程版本）
void quicksort_mt(std::vector<int>& arr, int left, int right, int depth) {
    if (left >= right) {
        return;
    }

    // 判断当前递归深度是否超过阈值，如果没有，则创建新线程处理子数组
    if (depth <= 0) {
        std::thread th1(quicksort_mt, std::ref(arr), left, right, depth + 1);
        std::thread th2(quicksort_mt, std::ref(arr), left, right, depth + 1);
        th1.join();
        th2.join();
        return;
    }

    int i = left, j = right, pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    // 递归处理左右子数组
    if (left < j) {
        quicksort_mt(arr, left, j, depth);
    }
    if (i < right) {
        quicksort_mt(arr, i, right, depth);
    }
}

// 测试
int main() {
    std::vector<int> arr;int n;cout << "请输入数组大小：";cin >> n;while (n) {
            int a = rand() / 32767.000000 * 1000000;
            arr.push_back(a);
            n--;
        }
    DWORD a = GetTickCount64();
    quicksort_mt(arr, 0, arr.size() - 1, 0); cout << "runtime:" << GetTickCount64() - a << "ms\t分层抽样10个\n"; for (int i = 0; i < arr.size(); i += int(arr.size() / 10.00))cout << arr[i] << "\n";
    std::cout << std::endl;
    return 0;
}/*
/ int main() {*/
    //    vector<int> nums;
    //    
    //    
    //    
    //
        
    //    
    //    a = GetTickCount64();
    //    //std::vector<int> arr = { 5, 3, 8, 6, 2, 7, 1, 4 };
    //    quick_sort(nums);
    //  /*  for (int num : arr) {
    //        std::cout << num << " ";
    //    }*//*
    //    std::cout << std::endl;*/
    //    cout << "runtime:" << GetTickCount64() - a << "ms\t分层抽样10个\n";
    //    for (int i = 0; i < nums.size(); i += int(nums.size() / 10.00))
    //        cout << nums[i] << "\n";
    //    return 0;
    //}
