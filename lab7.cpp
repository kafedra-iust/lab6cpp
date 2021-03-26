#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

struct lnk {
    string name;
    int ph;
    lnk *next;
};

int main1() {
    int nr, n;
    int *k, *p;
    lnk *cR, *fst, *p1;
    string nAr[3];
    int pAr[3];
    cin >> n;
    k = &n;
    p = k;
    *p = *p + 2;
    cout << k << " " << *p << endl;
    nAr[0] = "AAA";
    nAr[1] = "BBBB";
    nAr[2] = "CCCC";
    pAr[0] = 2222;
    pAr[1] = 333;
    pAr[2] = 4444;
    nr = sizeof(lnk);
    fst = nullptr;
    for (int i = 0; i < 3; i++) {
        cR = new lnk;
        cR->name = nAr[i];
        cR->ph = pAr[i];
        cR->next = fst;
        fst = cR;
    }
// --- 1 var ---

    fst->next = fst->next->next;
    cout << cR->ph << endl;
    cR=fst;
    while (cR!=nullptr){
        cout << cR->name << " " << cR->ph << endl;
        cR=cR->next;
    }
    cout << nr << endl;
    cout << " " << fst->name << endl;
}
