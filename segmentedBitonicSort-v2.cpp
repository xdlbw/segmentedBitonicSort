#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
using namespace std;

void segmentedBitonicSort(float* data, int* seg_id, int* seg_start, int n, int m){
    //输入数据错误情况
    if(n <= 0 || m <= 0 || m > n || seg_start[m] != n || seg_id[0] != 0 || seg_id[n - 1] != m - 1)  
        return;   
    //对每一段进行双调排序
    for(int step = 0; step < m; step++){         
        float* num = data + seg_start[step];                    
        int len = 1;
        int seg_len = seg_start[step + 1] - seg_start[step];    
        while(len < seg_len){                       
            len = len << 1;                         
        }
        float array[10010];
        for(int i = 0; i < len; i++){
            if(i < seg_len){
                array[i] = num[i];
            }
            else{
                array[i] = INT_MAX;
            }
        }
        for(int k = 2; k <= len; k *= 2){               //k控制待排序区间的长度（从2开始递增）
            for(int j = k >> 1; j > 0; j >>= 1){        //j用于将当前区间拆分成两个相邻的子区间（长度为j和k-j）
                for(int p = 0; p < len; p++){           //循环遍历当前待排序区间中的所有元素
                    int pxj = p ^ j;                    //找到与p相差j个的元素
                    if(pxj > p){
                        //应该要递增的子序列，小的元素放在前头
                        if(((p & k) == 0) && ((array[pxj] != array[pxj]) || (array[p] > array[pxj]))){
                            float temp = array[pxj];
                            array[pxj] = array[p];
                            array[p] = temp;
                        }
                        //应该要递减的子序列，大的元素放在前头
                        if(((p & k) != 0) && ((array[p] != array[p]) || (array[p] < array[pxj]))){
                            float temp = array[pxj];
                            array[pxj] = array[p];
                            array[p] = temp;
                        }
                    }
                }
            }
        }
        for(int i = 0; i < seg_len; i++){
            num[i] = array[i];
        }
    } 
}

int main(){
    float data[5] = {0.8, 0.2, 0.4, 0.6, 0.5};
    int seg_id[5] = {0, 0, 1, 1, 1};
    int seg_start[3] = {0, 2, 5};
    int n = 5, m = 2;

    /*float data[12] = {0.8, -1, sqrt(-1.f), 0.5, 100, 2324, -1, sqrt(-1.f), sqrt(-1.f), 0, -1, 0};
    int seg_id[12] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2};
    int seg_start[4] = {0, 4, 10, 12};
    int n = 12, m = 3;*/

    segmentedBitonicSort(data, seg_id, seg_start, n, m);
    cout << "data:"; 
    for(int i = 0; i < n; i++){
        cout << data[i] << " ";
    }
    return 0;
}