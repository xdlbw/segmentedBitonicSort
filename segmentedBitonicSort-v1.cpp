#include <iostream>
#include <stdlib.h>
#include <limits.h>
using namespace std;

void SortUp(int, int);
void SortDown(int, int);
void MergeUp(int, int);
void MergeDown(int, int);
void Exchange(int, int);
float* arr;

void SortUp(int m, int n){
    if(n == 1)  return;
    SortUp(m, n >> 1);
    SortDown(m + n >> 1, n >> 1);
    MergeUp(m, n);
}

void SortDown(int m, int n){
    if(n == 1)  return;
    SortUp(m, n >> 1);
    SortDown(m + n >> 1, n >> 1);
    MergeDown(m, n);
}

void MergeUp(int m, int n){
    if(n == 1)  return;
    int HalfN = n >> 1;
    for(int i = m; i < m + HalfN; i++){
        if(arr[i] > arr[i + HalfN]){
            Exchange(i , i + HalfN);
        }
    }
    MergeUp(m, HalfN);
    MergeUp(m + HalfN, HalfN);
}

void MergeDown(int m, int n){
    if(n == 1)  return;
    int HalfN = n >> 1;
    for(int i = m; i < m + HalfN; i++){
        if(arr[i] < arr[i + HalfN]){
            Exchange(i , i + HalfN);
        }
    }
    MergeDown(m, HalfN);
    MergeDown(m + HalfN, HalfN);
}

void Exchange(int i, int j){
    float temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp; 
}

void segmentedBitonicSort(float* data, int* seg_id, int* seg_start, int n, int m){
    //输入数据错误情况
    if(n <= 0 || m <= 0 || m > n || seg_start[m] != n || seg_id[0] != 0 || seg_id[n - 1] != m - 1)  
        return;   

    int cur = 0, step = 0;                              //cur为当前data数据下标，step为第几段
    
    while(cur < n){
        if(step < m && cur == seg_start[step]){         //新的一段的开始
            float* num = data + cur;                    //num[0]为新段的开头
            int len = 1;
            int seg_len = seg_start[step + 1] - seg_start[step];    //此段的数据个数
            //上述的排序和合并算法是基于数组长度为2的幂，如果不是，就要考虑填充数组，使数组长度为2的幂
            //故每一段的长度确定下来之后，额外使用一个变量len与每一段的长度seg_len进行比较，确定最终每一段需要的长度
            while(len < seg_len){                       
                len = len << 1;                         //左移即数值*2
            }
            //填充数组
            float* array = new float[len];
            for(int i = 0; i < len; i++){
                if(i < seg_len){
                    array[i] = num[i];
                }
                else{
                    array[i] = INT_MAX;
                }
            }
            arr = array;
            SortUp(0, len);
            //将排序后的结果从array数组复制回原来的段中
            for(int i = 0; i < seg_len; i++){
                num[i] = array[i];
            }
            delete []array;
            step++;
        }
        cur++;
    }
}

int main(){
    float data[5] = {0.8, 0.2, 0.4, 0.6, 0.5};
    int seg_id[5] = {0, 0, 1, 1, 1};
    int seg_start[3] = {0, 2, 5};
    int n = 5, m = 2;
    segmentedBitonicSort(data, seg_id, seg_start, n, m);
    cout << "data:"; 
    for(int i = 1; i < 3; i++){
        for(int j = seg_start[i - 1]; j < seg_start[i]; j++){
            cout << data[j] << " ";
        }
    }
    return 0;
}