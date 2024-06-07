#include "bank_acc.h"

snode::snode(int x) : acc(x), money(1000), next(nullptr) {}

bank_acc::bank_acc() : first(nullptr), last(nullptr), len(0) {}

void bank_acc::insert(int x){
    snode* tba = new snode(x);
    if(first == nullptr){
        first = last = tba;
    } else {
        last->next = tba;
        last = tba;
    }
}

void bank_acc::process(int x, char op, int c){
    snode* tbp = first;
    while(tbp != nullptr){
        if(tbp->acc == x) break;
        tbp = tbp->next;
    }
    if(tbp == nullptr) return;
    if(op == 'W'){
        tbp->money -= c;
    }
    if(op == 'D'){
        tbp->money += c;
    }
}

bool bank_acc::isPresent(int x){
    snode* temp = first;
    while(temp != nullptr){
        if(temp->acc == x) return true;
        temp = temp->next;
    }
    return false;
}

void bank_acc::print_count(int x){
    int c = 0;
    snode* temp = first;
    while(temp != nullptr){
        if(temp->money >= x) c++;
        temp = temp->next;
    }
    cout << c << endl;
}

void bank_acc::print_balance(int x){
    snode* temp = first;
    while(temp != nullptr){
        if(temp->acc == x) cout << temp->money << endl;
        temp = temp->next;
    }
}

int bank_acc::maxb(){
    snode* temp = first;
    int max = first->money;
    while(temp != nullptr){
        if(temp->money > max) max = temp->money;
        temp = temp->next;
    }
    return max;
}

void bank_acc::print_max(){
    int max = maxb();
    snode* temp = first;
    while(temp != nullptr){
        if(max == temp->money){
            cout << temp->acc << " ";
        }
        temp = temp->next;
    }
    cout << endl;
}
