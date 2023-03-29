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


// ����������������һ��vector������������Ϊ����
void quickSort(vector<int>& vec, int low, int high) {
    // ���vectorΪ�ջ�ֻ��һ��Ԫ�أ�ֱ�ӷ���
    if (low >= high) {
        return;
    }
    // ѡ��vector�����һ��Ԫ����Ϊ��׼
    int pivot = vec[high];
    // ��������ָ�룬�ֱ�ָ��vector����������
    int i = low;
    int j = high - 1;
    // �ظ����²��裬ֱ������ָ������
    while (i <= j) {
        // ���������ҵ���һ�����ڵ��ڻ�׼��Ԫ��
        while (i <= j && vec[i] < pivot) {
            i++;
        }
        // ���������ҵ���һ��С�ڵ��ڻ�׼��Ԫ��
        while (i <= j && vec[j] > pivot) {
            j--;
        }
        // ����ҵ�������Ԫ�أ��������ǵ�λ��
        if (i <= j) {
            int temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
            // �ƶ�ָ��
            i++;
            j--;
        }
    }
    // ����׼Ԫ�غ�iָ���Ԫ�ؽ���λ�ã���ʱiָ���Ԫ���Ǵ��ڵ��ڻ�׼�ĵ�һ��Ԫ��
    int temp = vec[i];
    vec[i] = vec[high];
    vec[high] = temp;
    // �ݹ�ضԻ�׼�������ߵ���vector���п�������
    quickSort(vec, low, i - 1);
    quickSort(vec, i + 1, high);
}

// ����������������һ�����������������Ϊ����
void quickSort(int arr[], int low, int high) {
    // �������Ϊ�ջ�ֻ��һ��Ԫ�أ�ֱ�ӷ���
    if (low >= high) {
        return;
    }
    // ѡ����������һ��Ԫ����Ϊ��׼
    int pivot = arr[high];
    // ��������ָ�룬�ֱ�ָ���������������
    int i = low;
    int j = high - 1;
    // �ظ����²��裬ֱ������ָ������
    while (i <= j) {
        // ���������ҵ���һ�����ڵ��ڻ�׼��Ԫ��
        while (i <= j && arr[i] < pivot) {
            i++;
        }
        // ���������ҵ���һ��С�ڵ��ڻ�׼��Ԫ��
        while (i <= j && arr[j] > pivot) {
            j--;
        }
        // ����ҵ�������Ԫ�أ��������ǵ�λ��
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            // �ƶ�ָ��
            i++;
            j--;
        }
    }
    // ����׼Ԫ�غ�iָ���Ԫ�ؽ���λ�ã���ʱiָ���Ԫ���Ǵ��ڵ��ڻ�׼�ĵ�һ��Ԫ��
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    // �ݹ�ضԻ�׼�������ߵ���������п�������
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
    unsigned gap = len / INCRGAP + 1; // ������ʼ��,ע�������len<INCRGAPʱ��gapΪ0������Ϊ�˱�֤����ѭ����gap����Ϊ1������
    while (gap) // while gap>=1
    {
        for (unsigned i = gap; i < len; ++i) // ���飬��ÿ���������н��в�������
        {
            insertNum = a[i];//����ǰ��Ԫ��ֵ�ȴ���������������
            unsigned j = i;
            while (j >= gap && insertNum < a[j - gap])//Ѱ�Ҳ���λ��
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
    cout << "�����������С";
    cin >> n;
    int* a = new int[n];
    int nn = n;
    cout << "���������ݼ�";
    cout << "1���";
    cout << "2����";
    int data;
    cin >> data;
    cout << "����������ʽ"<<endl;
    cout << "1-quick sort" << endl;
    cout << "2-quick sort ��using thread��" << endl;
    cout << "3-shell sort" << endl;
    int way;
    cin >> way;
    //���ݼ�
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


    LARGE_INTEGER freq;// ��ȡƵ��
    QueryPerformanceFrequency(&freq);// ��ȡ��ʼʱ��
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
    //����
    //����������߳�
   /**/
    //��ͨ��������
    
    //bubble_sort(a, n);
    //


    LARGE_INTEGER end;// ��ȡ����ʱ��
    QueryPerformanceCounter(&end);
    // ��������ʱ��
    double elapsed = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart * 1000000;
    // ������
    cout << "��������ʱ��Ϊ��" << elapsed << " ��s" << endl;

    //for (int i = 0; i < 50; i++)cout << a[i] << endl;
    cout <<  "�ֲ����10��\n";
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

















