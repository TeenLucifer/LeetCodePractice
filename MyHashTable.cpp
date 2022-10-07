//
// Created by Lenovo on 2022/9/9.
//

#include "MyHashTable.h"

namespace openAddressing
{

MyHashTable::MyHashTable()
{

}
MyHashTable::~MyHashTable()
{

}

MyHashTable::MyHashTable(int length)
{
    this->length = length;
    this->data = new int[this->length];
    this->maxPrime = this->getMaxPrime();
    memset(this->delFlag, 0, sizeof(this->delFlag[0] * this->length));
    for(int i = 0; i < this->length; ++i)
    {
        this->data[i] = MAX;
    }
}

bool MyHashTable::isPrime(int num)//质数判定的函数能否进行优化一下
{
    bool flag = true;
    if(num <= 1)
    {
        flag = false;
    }
    else if(num == 2)
    {
        flag = true;
    }
    else
    {
        for(int i = 2; i < num - 1; ++i)
        {
            if(num % i == 0)
            {
                flag = false;
                break;
            }
        }
    }
    return flag;
}

int MyHashTable::getMaxPrime()//计算最大质数的算法能否优化一下
{
    for(int i = this->length - 1; i >= 0; --i)
    {
        if(this->isPrime(i))
        {
            return i;
        }
    }
}

int MyHashTable::hashFunction(int num)
{
    return num % this->maxPrime;
}

bool MyHashTable::insert_linearProbing(int num)
{
    if(this->size == this->length)
    {
        return false;
    }

    int index = this->hashFunction(num);//散列
    if(this->data[index] == MAX)
    {
        this->data[index] = num;
    }
    else
    {
        int i = 1;
        while(this->data[(index + i) % this->length] != MAX)//线性查探
        {
            i++;
        }
        index = (index + i) % this->length;
        this->data[index] = num;
    }
    if(this->delFlag[index] == 1)
    {
        this->delFlag[index] = 0;
    }
    this->size++;
    return true;
}

void MyHashTable::creat_linearProbing(int *num, int size)
{
    for(int i = 0; i < size; ++i)
    {
        this->insert_linearProbing(num[i]);
    }
}

int MyHashTable::find_linearProbing(int num)
{
    int flag = -1;
    int index = this->hashFunction(num);
    if(this->data[index] == num && this->delFlag[index] == 0)
    {
        flag = index;
    }
    else
    {
        int i = 1;
        while (1)
        {
            if(this->delFlag[index + i] == 0)
            {
                if(this->data[index + i] != num)
                {
                    ++i;
                }
                else
                {
                    flag = index + i;
                    break;
                }
            }
            else
            {
                ++i;
            }
        }
    }
    return flag;
}

bool MyHashTable::delete_linearProbing(int num)
{
    int index = this->find_linearProbing(num);
    if(index == -1)
    {
        return false;
    }
    else
    {
        this->delFlag[index] = 1;
        this->size--;
        return true;
    }
}

bool MyHashTable::insert_squareProbing(int num)//平方探测
{
    if(this->size == this->length)
    {
        return false;
    }

    int index = this->hashFunction(num);
    if(this->data[index] == MAX)
    {
        this->data[index] = num;
    }
    else
    {
        int i = 1;
        int symble = -1;
        int q = 1;
        while(this->data[(index + q) % this->length] != MAX)//平方查探
        {
            i++;
            q = symble * ((i / 2) + 1) * ((i / 2) + 1);
            symble = -symble;
        }
        index = (index + i) % this->length;
        this->data[index] = num;
    }
    if(this->delFlag[index] == 1)
    {
        this->delFlag[index] = 0;
    }
    this->size++;
    return true;
}

void MyHashTable::creat_squareProbing(int *num, int size)
{
    for(int i = 0; i < size; ++i)
    {
        this->insert_squareProbing(num[i]);
    }
}

int  MyHashTable::find_squareProbing(int num)
{
    int flag = -1;
    int index = this->hashFunction(num);
    if(this->data[index] = num && this->delFlag[index] == 0)
    {
        flag = index;
    }
    else
    {
        int i = 1;
        int q = 1;
        int symble = -1;
        while(1)
        {
            if(this->delFlag[index + q] == 0)
            {
                if(this->data[index + q] != num)
                {
                    ++i;
                }
                else
                {
                    flag = index + q;
                    break;
                }
            }
            else
            {
                ++i;
            }
            q = symble * ((i / 2) + 1) * ((i / 2) + 1);
            symble = -symble;
        }
    }
    return flag;
}

bool MyHashTable::delete_squareProbing(int num)
{
    int index = this->find_squareProbing(num);
    if(index == -1)
    {
        return false;
    }
    else
    {
        this->delFlag[index] = 1;
        this->size--;
        return true;
    }
}

}

namespace separateChaining
{
    MyHashTable::MyHashTable()
    {}
    MyHashTable::~MyHashTable()
    {}
    MyHashTable::MyHashTable(int length)
    {
        this->length = length;
        listNode.reserve(this->length);
        this->maxPrime = this->getMaxPrime();
        for(int i = 0; i < this->length; ++i)
        {
            this->listNode.push_back(this->createNode(i));
        }
    }

    ListNode* MyHashTable::createNode(int num)
    {
        ListNode* node = new ListNode;
        node->val = num;
        node->next = nullptr;
        return node;
    }
    bool MyHashTable::isPrime(int num)//质数判定的函数能否进行优化一下
    {
        bool flag = true;
        if(num <= 1)
        {
            flag = false;
        }
        else if(num == 2)
        {
            flag = true;
        }
        else
        {
            for(int i = 2; i < num - 1; ++i)
            {
                if(num % i == 0)
                {
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }

    int MyHashTable::getMaxPrime()//计算最大质数的算法能否优化一下
    {
        for(int i = this->length - 1; i >= 0; --i)
        {
            if(this->isPrime(i))
            {
                return i;
            }
        }
    }

    int MyHashTable::hashFunction(int num)
    {
        return num % this->maxPrime;
    }

    ListNode* MyHashTable::attach(ListNode *node1, ListNode *node2)
    {
        ListNode* cur = node1;
        while(cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = node2;
        return node1;
    }

    void MyHashTable::insertElement(int num)
    {
        int index = this->hashFunction(num);
        ListNode* node = nullptr;
        node = createNode(num);
        ListNode* tmp = nullptr;
        tmp = this->listNode[index];
        this->listNode[index] = this->attach(tmp, node);
    }

    void MyHashTable::createTable(int *num, int size)
    {
        for(int i = 0; i < size; ++i)
        {
            this->insertElement(num[i]);
        }
    }

    int MyHashTable::findElement(int num)
    {
        int index = this->hashFunction(num);
        ListNode* node = this->listNode[index];
        while(node->next->val != num)
        {
            node = node->next;
        }
        if(node == nullptr)
        {
            return -1;
        }
        return index;
    }

    bool MyHashTable::deleteElement(int num)
    {
        int index = this->hashFunction(num);
        ListNode* node = this->listNode[index];
        while(node->next->val != num)
        {
            node = node->next;
        }
        if(node == nullptr)
        {
            return false;
        }
        ListNode *tmp = node->next;
        delete tmp;
        return true;
    }
}