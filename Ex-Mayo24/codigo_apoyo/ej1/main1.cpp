/* NO MODIFICAR */

#include <iostream>
#include <string>
#include "lista.h"

using namespace std;

void escribe_lista(Lista<int> l) {
    l.imprime(cout);
    cout << "#";
    l.imprime_invertida(cout);
    cout << "#";
    cout << l.longitud();
    cout << endl;
}

bool lee_lista(Lista<int>& l) {
    int n;
    cin >> n;
    if (n == -1) return false;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        l.pon_final(e);
    }
    return true;
}


bool ejecuta_caso() {
        Lista<int> l;
        if (! lee_lista(l)) return false;
        unsigned int k;
        cin >> k;
        l.rotar(k);
        escribe_lista(l);
        return true;
  }


int main() {
    while (ejecuta_caso());
    return 0;
}