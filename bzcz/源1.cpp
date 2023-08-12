#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <functional>
#include <algorithm>
#include<random>
#include<string>
#include<Windows.h>
#include <fstream>

void random_swap(std::vector<int>& arr, int n) {
    // 构造随机数生成器
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, arr.size() - 1);

    // 选取 n 个位置，并将这些位置对应的元素进行交换
    for (int i = 0; i < n; i++) {
        int pos1 = dis(gen);
        int pos2 = dis(gen);
        std::swap(arr[pos1], arr[pos2]);
    }
}


// 生成包含 n 个元素，逆序对数量为 inversions 的数组
std::vector<int> generateArray(int n, int inversions) {
    std::vector<int> arr(n);

    // 生成有序数组
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    // 从数组末尾开始，不断向前遍历数组，生成指定数量的逆序对
    int count = 0;
    std::random_device rd;
    std::mt19937 gen(rd());
    for (int i = n - 1; i >= 0 && count < inversions; i--) {
        std::uniform_int_distribution<> dis(0, i - 1);
        int j = dis(gen);
        std::swap(arr[i], arr[j]);
        count += i - j;
    }

    return arr;
}

// 冒泡排序
void Bubble_Sort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 改进版冒泡排序
void Bubble_Sort_2(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped = false;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

// 递归版冒泡排序
void Recursive_BubbleSort(std::vector<int>& arr) {
    int n = arr.size()-1;
    Recursive_BubbleSort1(arr,n);
}
void Recursive_BubbleSort1(std::vector<int>& arr, int n) {
    if (n == 1) {
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            std::swap(arr[i], arr[i + 1]);
        }
    }
    Recursive_BubbleSort1(arr, n - 1);
}

// 选择排序
void selection_sort(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        int min_idx = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(arr[i], arr[min_idx]);
    }
}

// 归并排序
void Merge(std::vector<int>& arr, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = 0;
    std::vector<int> temp(right - left + 1);
    while (i <= mid && j <= right)
        temp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (int m = 0; m < temp.size(); m++)
        arr[left + m] = temp[m];
}
void MergeSort1(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    MergeSort1(arr, left, mid);
    MergeSort1(arr, mid + 1, right);
    Merge(arr, left, mid, right);
}
void MergeSort(std::vector<int>& arr) {
    int l = 0;
    int r = arr.size();
    MergeSort1(arr, l, r-1);
}

    // 快速排序
    int partition(std::vector<int>&arr, int left, int right) {
        int pivot = arr[right];
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (arr[j] <= pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[right]);
        return i + 1;
    }

    void QuickSort1(std::vector<int>&arr, int left, int right) {
        if (left >= right) {
            return;
        }
        int pivot_idx = partition(arr, left, right);
        QuickSort1(arr, left, pivot_idx - 1);
        QuickSort1(arr, pivot_idx + 1, right);
    }
    void QuickSort(std::vector<int>& arr) {
        QuickSort1(arr, 0, arr.size() - 1);
    }

    // 希尔排序
    void shell_sort(std::vector<int>&arr) {
        int n = arr.size();
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }

    // 堆排序
    void heapify(std::vector<int>&arr, int n, int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n && arr[l] > arr[largest]) {
            largest = l;
        }
        if (r < n && arr[r] > arr[largest]) {
            largest = r;
        }
        if (largest != i) {
            std::swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void heapSort(std::vector<int>&arr) {
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
        for (int i = n - 1; i >= 0; i--) {
            std::swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

    // 基数排序
    void countingSort(std::vector<int>&arr, int exp) {
        int n = arr.size();
        std::vector<int> output(n);
        std::vector<int> count(10, 0);
        for (int i = 0; i < n; i++) {
            count[(arr[i] / exp) % 10]++;
        }
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }

    void radixsort(std::vector<int>&arr) {
        int n = arr.size();
        int max_val = *std::max_element(arr.begin(), arr.end());
        for (int exp = 1; max_val / exp > 0; exp *= 10) {
            countingSort(arr, exp);
        }
    }



    void generateFile(const std::string& filename, int numIntegers,int n) {
        std::ofstream file(filename);
        std::vector<int> numbers;
        if (file.is_open()) {
            for (int i = 1; i <= numIntegers; ++i) {
                numbers.push_back(i);
            }
            random_swap(numbers, n);
            for (int i = 1; i <= numIntegers; ++i) {
                file << i << '\n';
            }
            file.close();
            std::cout << "生成 " << filename << " 完成\n";
        }
        else {
            std::cerr << "无法创建文件: " << filename << '\n';
        }
    }

    int main() {
        // 定义要生成的逆序对数量,0 0.3 0.6 1.1
        std::vector<int> inversions = { 0, 300,600,1100, 
                                        0,30000,60000,1100000, 
                                       0, 3000000,6000000 ,110000000 ,};

        // 定义要生成的数组规模
        std::vector<int> n_values = { 1000, 100000, 10000000 };
        // 定义文件名前缀
        std::vector<std::string> file_prefixes = { "1000.0","1000.1","1000.2","1000.3",
                                                   "100000.0","100000.1","100000.2","100000.3" ,
                                                   "10000000.0","10000000.1","10000000.2","10000000.3"};
        // 定义排序函数指针数组
        std::function<void(std::vector<int>&)> sorting_functions[] = { Bubble_Sort, Bubble_Sort_2, Recursive_BubbleSort, selection_sort,
                                                                       MergeSort, QuickSort, shell_sort, heapSort, radixsort };

        // 遍历函数指针数组，依次运行每个排序函数
        for (auto sorting_function : sorting_functions) {
            for (int i = 0; i < inversions.size(); i++) {
                std::string file_name = file_prefixes[i] + std::to_string(n_values[i]) + ".txt";
                for (const std::string& filename : file_name) {
                    std::vector<int> arr = readFile(filename);
                    auto startTime = std::chrono::high_resolution_clock::now();
                    sorting_function(arr);
                    auto endTime = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
                    std::cout << "Filename: " << filename << std::endl;
                    std::cout << "Runtime: " << duration << " ms" << std::endl;

                    std::cout << std::endl;
                }
            }
        }
        

        return 0;
    }