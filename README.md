# segmentedBitonicSort
GAPS编程测试

`segmentedBitonicSort-v1`为递归版本实现

`segmentedBitonicSort-v2`为非递归版本实现

分段双调排序.md、分段双调排序.pdf为报告

## 问题说明

给出分成 m 段的 n 个浮点数，输入数据已按段号有序，但每段内部无序。用C/C++ 编写一个分段双调排序(Bitonic sort)函数，对每一段内部的浮点数进行排序，但不要改变段间的位置。

## 接口方式

`void segmentedBitonicSort(float* data, int* seg_id, int* seg_start, int n, int m);`

输入数据中，data包含需要分段排序的 n 个 float值，seg_id 给出 data 中 n 个元素各自所在的段编号。seg_start 共有 m+1 个元素，前m 个分别给出 0..m-1 共 m 个段的起 始位置，seg_start[m] 保证等于 n。seg_id 中的元素保证单调不下降，即对任意的 seg_id 所有元素均在 0 到 m-1 范围内。

输出结果覆盖 data，保证每一段内排序，但不改变段间元素的顺序。

注意：

1、必须使用双调排序算法进行排序。

2、可以直接使用从网上下载的双调排序代码，但须注明出处。

## 样例输入

```c++
float data[5]={0.8, 0.2, 0.4, 0.6, 0.5};

int seg_id[5]={0,   0,   1,   1,   1}

int seg_start[3]={0,2,5};

int n=5;

int m=2;
```

## 样例输出

```c++
float data[5]={0.2, 0.8, 0.4, 0.5, 0.6};
```

## 加分挑战（非必需）

1、不递归：`segmentedBitonicSort`函数及其所调用的任何其他函数都不得直接或间接地进行递归。

2、不调用函数：`segmentedBitonicSort`不调用除标准库函数外的任何其他函数。

3、内存高效：`segmentedBitonicSort`及其所调用的任何其他函数都不得进行动态内存分配，包括malloc、new和静态定义的STL容器。

4、可并行：`segmentedBitonicSort`涉及到的所有时间复杂度O(n)以上的代码都写在for循 环中，而且每个这样的for循环内部的循环顺序可以任意改变，不影响程序结果。注：自己测试时可以用`rand()`决定循环顺序。

5、不需内存：`segmentedBitonicSort`不调用任何函数（包括C/C++标准库函数），不使用全局变量，所有局部变量都是int、float或指针类型，C++程序不使用new关键字。

6、绝对鲁棒：在输入数据中包含NaN时（例如`sqrt(-1.f)`），保证除NaN以外的数据正确排序，NaN的个数保持不变。

你的程序每满足以上的一个条件都可以获得额外的加分。

## 应提交的结果

a) 算法描述；

b) 尝试过和完成了的加分挑战；

c) 可以独立运行的源代码；

d) 测试数据；

e) 性能分析；

f) 测试的起始和完成时间以及实际使用的时间。

提示：

1. 利用好网上资源。

2. 尽量利用输入中的冗余信息。

3. 利用好位操作。  
