//
// Created by Lenovo on 2022/9/9.
//

#ifndef DATASTRUCTURE_MYHASHTABLE_H
#define DATASTRUCTURE_MYHASHTABLE_H

#include "headers.h"

namespace openAddressing
{
    class MyHashTable
    {
    private:
        const int MAX = 65535;
        int length;
        int size;
        int *data;
        int maxPrime;// 最大素数
        int *delFlag;//删除标志

    public:
        MyHashTable();
        MyHashTable(int length);
        ~MyHashTable();
        bool isPrime(int num);
        int getMaxPrime();
        int hashFunction(int num);
        bool insert_linearProbing(int num);//插入，利用线性探测
        void creat_linearProbing(int *num, int size);
        int find_linearProbing(int num);
        bool delete_linearProbing(int num);

        bool insert_squareProbing(int num);//平方探测
        void creat_squareProbing(int *num, int size);
        int find_squareProbing(int num);
        bool delete_squareProbing(int num);
    };
}

namespace separateChaining
{
    class MyHashTable
    {
    private:
        vector<ListNode*> listNode;
        int length;
        int maxPrime;
    public:
        MyHashTable();
        MyHashTable(int length);
        ~MyHashTable();

        ListNode* createNode(int num);
        bool isPrime(int num);
        int getMaxPrime();
        int hashFunction(int num);
        ListNode* attach(ListNode* node1, ListNode* node2);
        void insertElement(int num);
        void createTable(int *num, int size);
        int findElement(int num);
        bool deleteElement(int num);
    };
}




#endif //DATASTRUCTURE_MYHASHTABLE_H
