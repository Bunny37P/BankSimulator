#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include "bank_acc.h"

class Node{
private:
    int num;
    char op;
    int change;
    Node* next;
    Node* prev;

public:
    Node();
    Node(int a, char b, int c);

    friend class transactions;
};

class transactions{
private:
    Node* header;
    Node* trailer;
    int len;
    Node* cursor;

public:
    transactions();
    void insert(int a, char b, int c);
    void nextX(int x, bank_acc& a);
    void undoY(int y, bank_acc& a);
    void deleteP(Node* tbd);
    void itk(int k, int num, char b, int c, bank_acc& a);
    void dam(int m, int acc_num, bank_acc& a);
    void processAll(bank_acc& a);
    void printProcessed(int y);
};

#endif // TRANSACTIONS_H
