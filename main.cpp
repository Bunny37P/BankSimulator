#include <iostream>
#include "bank_acc.h"
#include "transactions.h"
using namespace std;

int main() {
    int C;
    cin >> C;
    bank_acc accs;
    transactions tr;

    for (int i = 0; i < C; i++) {
        int num;
        cin >> num;
        accs.insert(num);
    }

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, c;
        char b;
        cin >> a >> b >> c;
        if (accs.isPresent(a)) {
            tr.insert(a, b, c);
        }
    }

    while (1) {
        char c;
        cin >> c;
        if (c == 'F') {
            int x;
            cin >> x;
            tr.nextX(x, accs);
        } else if (c == 'R') {
            int y;
            cin >> y;
            tr.undoY(y, accs);
        } else if (c == 'I') {
            int a, c, k;
            char b;
            cin >> a >> b >> c >> k;
            tr.itk(k, a, b, c, accs);
        } else if (c == 'D') {
            int a, m;
            cin >> a >> m;
            tr.dam(m, a, accs);
        } else if (c == 'C') {
            tr.processAll(accs);
        } else if (c == 'S') {
            int y;
            cin >> y;
            tr.printProcessed(y);
        } else if (c == 'G') {
            int x;
            cin >> x;
            accs.print_count(x);
        } else if (c == 'M') {
            accs.print_max();
        } else if (c == 'V') {
            int x;
            cin >> x;
            accs.print_balance(x);
        } else if (c == 'E') {
            break;
        }
    }
    return 0;
}
