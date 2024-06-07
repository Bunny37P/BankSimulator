#include "transactions.h"

Node::Node() : num(-1), op('0'), change(0), next(nullptr), prev(nullptr) {}

Node::Node(int a, char b, int c) : num(a), op(b), change(c), next(nullptr), prev(nullptr) {}

transactions::transactions() {
    header = new Node();
    trailer = new Node();
    header->next = trailer;
    trailer->prev = header;
    len = 0;
    cursor = header;
}

void transactions::insert(int a, char b, int c) {
    Node* tba = new Node(a, b, c);
    tba->next = trailer;
    tba->prev = trailer->prev;
    tba->prev->next = tba;
    trailer->prev = tba;
    len++;
}

void transactions::nextX(int x, bank_acc& a) {
    Node* tbp = cursor->next;
    while(x-- && tbp != trailer) {
        a.process(tbp->num, tbp->op, tbp->change);
        tbp = tbp->next;
    }
    if(tbp == trailer) {
        cursor = trailer->prev;
    } else {
        cursor = tbp->prev;
    }
}

void transactions::undoY(int y, bank_acc& a) {
    Node* tbp = cursor;
    while(y-- && tbp != header) {
        a.process(tbp->num, tbp->op, -1 * tbp->change);
        tbp = tbp->prev;
    }
    if(tbp != header) cursor = tbp;
}

void transactions::deleteP(Node* tbd) {
    if(tbd != header && tbd != trailer) {
        tbd->prev->next = tbd->next;
        tbd->next->prev = tbd->prev;
        delete tbd;
        len--;
    }
}

void transactions::itk(int k, int num, char b, int c, bank_acc& a) {
    if(a.isPresent(num) && len >= k) {
        int flag = 1;
        Node* tba = new Node(num, b, c);
        Node* temp = header;
        for(int i = 0; i < k; i++) {
            temp = temp->next;
            if(cursor == temp) flag = 0;
        }
        if(flag == 1 && cursor != header) a.process(num, b, c);

        tba->next = temp->next;
        tba->prev = temp;
        temp->next = tba;
        tba->next->prev = tba;
    }
}

void transactions::dam(int m, int acc_num, bank_acc& a) {
    if(m > 0) {
        Node* temp = cursor->next;
        for(int i = 0; i < m && temp != trailer;) {
            if(temp->num == acc_num) {
                Node* tbd = temp;
                temp = temp->prev;
                deleteP(tbd);
                i++;
            }
            temp = temp->next;
        }
    } else {
        m = -1 * m;
        Node* temp = cursor->prev;
        for(int i = 0; i < m && temp != header;) {
            if(temp->num == acc_num) {
                a.process(temp->num, temp->op, -1 * temp->change);
                Node* tbd = temp;
                temp = temp->next;
                deleteP(tbd);
                i++;
            }
            temp = temp->prev;
        }
    }
}

void transactions::processAll(bank_acc& a) {
    cursor = cursor->next;
    while(cursor != trailer) {
        a.process(cursor->num, cursor->op, cursor->change);
        cursor = cursor->next;
    }
    if(cursor == trailer) {
        cursor = cursor->prev;
    }
}

void transactions::printProcessed(int y) {
    Node* temp = header->next;
    while(temp != cursor->next) {
        if(temp->num == y) {
            cout << temp->num << " " << temp->op << " " << temp->change << endl;
        }
        temp = temp->next;
    }
}
