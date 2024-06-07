#ifndef BANK_ACC_H
#define BANK_ACC_H

#include <iostream>
using namespace std;

class snode{
private:
    int acc;
    int money;
    snode* next;

public:
    snode(int x);
    friend class bank_acc;
};

class bank_acc{
private:
    snode* first;
    snode* last;
    int len;

    int maxb();

public:
    bank_acc();
    void insert(int x);
    void process(int x, char op, int c);
    bool isPresent(int x);
    void print_count(int x);
    void print_balance(int x);
    void print_max();

    friend class transactions;
};

#endif // BANK_ACC_H
