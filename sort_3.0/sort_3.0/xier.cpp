#include<windows.h>
#include <time.h>
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;

void quicksort(vector<int>& vec, int left, int right) {
    if (left < right) {
        int i = left, j = right, pivot = vec[(left + right) / 2];
        while (i <= j) {
            while (vec[i] < pivot) i++;
            while (vec[j] > pivot) j--;
            if (i <= j) {
                swap(vec[i], vec[j]);
                i++; j--;
            }
        }
        thread t1(quicksort, ref(vec), left, j);
        thread t2(quicksort, ref(vec), i, right);
        t1.join();
        t2.join();
    }
}


// 快速排序函数，接受一个vector和两个索引作为参数
void quickSort(vector<int>& vec, int low, int high) {
    // 如果vector为空或只有一个元素，直接返回
    if (low >= high) {
        return;
    }
    // 选择vector的最后一个元素作为基准
    int pivot = vec[high];
    // 定义两个指针，分别指向vector的左右两端
    int i = low;
    int j = high - 1;
    // 重复以下步骤，直到两个指针相遇
    while (i <= j) {
        // 从左向右找到第一个大于等于基准的元素
        while (i <= j && vec[i] < pivot) {
            i++;
        }
        // 从右向左找到第一个小于等于基准的元素
        while (i <= j && vec[j] > pivot) {
            j--;
        }
        // 如果找到了两个元素，交换它们的位置
        if (i <= j) {
            int temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
            // 移动指针
            i++;
            j--;
        }
    }
    // 将基准元素和i指向的元素交换位置，此时i指向的元素是大于等于基准的第一个元素
    int temp = vec[i];
    vec[i] = vec[high];
    vec[high] = temp;
    // 递归地对基准左右两边的子vector进行快速排序
    quickSort(vec, low, i - 1);
    quickSort(vec, i + 1, high);
}

// 快速排序函数，接受一个数组和两个索引作为参数
void quickSort(int arr[], int low, int high) {
    // 如果数组为空或只有一个元素，直接返回
    if (low >= high) {
        return;
    }
    // 选择数组的最后一个元素作为基准
    int pivot = arr[high];
    // 定义两个指针，分别指向数组的左右两端
    int i = low;
    int j = high - 1;
    // 重复以下步骤，直到两个指针相遇
    while (i <= j) {
        // 从左向右找到第一个大于等于基准的元素
        while (i <= j && arr[i] < pivot) {
            i++;
        }
        // 从右向左找到第一个小于等于基准的元素
        while (i <= j && arr[j] > pivot) {
            j--;
        }
        // 如果找到了两个元素，交换它们的位置
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            // 移动指针
            i++;
            j--;
        }
    }
    // 将基准元素和i指向的元素交换位置，此时i指向的元素是大于等于基准的第一个元素
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    // 递归地对基准左右两边的子数组进行快速排序
    quickSort(arr, low, i - 1);
    quickSort(arr, i + 1, high);
}


void bubble_sort(int arr[], int len) {
    int i, j;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}



const int INCRGAP = 3;
void shellSort(int a[], int len)
{
    int insertNum = 0;
    unsigned gap = len / INCRGAP + 1; // 步长初始化,注意如果当len<INCRGAP时，gap为0，所以为了保证进入循环，gap至少为1！！！
    while (gap) // while gap>=1
    {
        for (unsigned i = gap; i < len; ++i) // 分组，在每个子序列中进行插入排序
        {
            insertNum = a[i];//将当前的元素值先存起来方便后面插入
            unsigned j = i;
            while (j >= gap && insertNum < a[j - gap])//寻找插入位置
            {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = insertNum;
        }
        gap = gap / INCRGAP;
    }
}
void shell_sort(int arr[], int len) {
    int gap, i, j;
    int temp;
    for (gap = len >> 1; gap > 0; gap >>= 1)
        for (i = gap; i < len; i++) {
            temp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
                arr[j + gap] = arr[j];
            arr[j + gap] = temp;
        }
}






int main() {
    vector<int> nums;
    int n;
    cout << "请输入数组大小";
    cin >> n;
    int* a = new int[n];
    int nn = n;
    cout << "请输入数据集";
    cout << "1随机";
    cout << "2逆序";
    int data;
    cin >> data;
    cout << "请输入排序方式"<<endl;
    cout << "1-quick sort" << endl;
    cout << "2-quick sort （using thread）" << endl;
    cout << "3-shell sort" << endl;
    int way;
    cin >> way;
    //数据集
    switch (data)
    {
    case 1:
        srand((unsigned)time(0));
        while (nn) {
        int a = rand() / 32767.000000 * 1000000;
        nums.push_back(a);
        nn--;
         }
        break; 
    case 2:
        while (nn) {
            nums.push_back(nn+1);
            nn--;
        }
        break;
    }
    for (int i = 0; i < 50; i++)cout << nums[i] << endl;
    if (way == 3) {
        for (int i = 0; i < n; i++)a[i] = nums[i];
    };

    //for (int i = 0; i < 50; i++)cout << a[i] << endl;


    LARGE_INTEGER freq;// 获取频率
    QueryPerformanceFrequency(&freq);// 获取开始时间
    LARGE_INTEGER start;
    QueryPerformanceCounter(&start);


    switch (way)
    {
    case 1:quickSort(nums, 0, n - 1);
        break;
    case 2: {
        thread t(quicksort, ref(nums), 0, n - 1);
        t.join();
    } 
        break;
    case 3:shellSort(a,n-1);
        break;
    }
    //排序
    //快速排序多线程
   /**/
    //普通快速排序
    
    //bubble_sort(a, n);
    //


    LARGE_INTEGER end;// 获取结束时间
    QueryPerformanceCounter(&end);
    // 计算运行时间
    double elapsed = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart * 1000000;
    // 输出结果
    cout << "程序运行时间为：" << elapsed << " μs" << endl;

    //for (int i = 0; i < 50; i++)cout << a[i] << endl;
    cout <<  "分层抽样10个\n";
    switch (way)
    {
    case 1:for (int i = 0; i < nums.size(); i += int(nums.size() / 10.00))
        cout << nums[i] << "\n";
        break;
    case 2:for (int i = 0; i < nums.size(); i += int(nums.size() / 10.00))
        cout << nums[i] << "\n";
        break;
    case 3:for (int i = 0; i < n; i += int(n / 10.00))
        cout << a[i] << "\n";
        break;
    }
    return 0;
}

















