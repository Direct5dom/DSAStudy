#include <stdio.h>
#include <iostream>

// 定义最大长度
#define MaxSize 10

// 定义结构体，并赋予别名
typedef struct
{
    // 用静态的“数组”存放数据元素
    int data[MaxSize];
    // 顺序表当前长度
    int length;
} SqList;

// 基本操作——初始化顺序表
void InitList(SqList &L)
{
    // 初始化操作可以省略（因为长度初始为0）
    // for (int i = 0; i < MaxSize; i++)
    //     // 将所有数据元素设置为默认初始值
    //     L.data[i] = 0;
    // 顺序表初始长度为0
    L.length = 0;
}

// 基本操作——插入
bool ListInsert(SqList &L, int i, int e)
{
    // 判断参数合法性
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= MaxSize)
        return false;
    // 从最后一位开始，i之后的都想后移动一位
    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.length++;
    return true;
}

// 基本操作——删除
bool ListDelete(SqList &L, int i, int &e)
{
    // 判断参数合法性
    if (i < 1 || i > L.length)
        return false;
    // 将被删除的元素赋值给e
    e = L.data[i - 1];
    // 从i之后一位开始，i之后的都想前移动一位
    for (int j = i; j < L.length; j++)
        L.data[j - 1] = L.data[j];
    L.length--;
    return true;
}

// 基本操作——按位查找
int GetElem(SqList L, int i)
{
    // 位序从1开始，下标从0开始
    return L.data[i - 1];
}

// 基本操作——按值查找
int LocateElem(SqList L, int e)
{
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i + 1;
    return 0;
}

// 遍历数组
void Traversal(SqList L)
{
    for (int i = 0; i < L.length; i++)
        std::cout << "data[" << i << "] = " << L.data[i] << std::endl;
}

int main()
{
    SqList L;
    InitList(L);
    // 在前三个位置写入数据
    ListInsert(L, 1, 11);
    ListInsert(L, 2, 22);
    ListInsert(L, 3, 33);

    printf("插入操作前:\n");

    // 遍历顺序表
    Traversal(L);
    printf("————————\n");

    // 在第二个位置插入数据
    ListInsert(L, 2, 3);

    printf("插入操作后:\n");

    // 遍历顺序表
    Traversal(L);
    printf("————————\n");

    // 用变量e把删除的元素“带回来”
    int e = -1;
    ListDelete(L, 2, e);

    printf("删除操作后:\n");
    printf("删除了元素%d\n", e);

    // 遍历顺序表
    Traversal(L);
    printf("————————\n");

    // 查询第一个位置的元素
    printf("第一个位置的元素是: %d\n", GetElem(L, 1));
    // 查询22所在位置
    printf("22所在位置是: %d\n", LocateElem(L, 22));

    return 0;
}