#include <bits/stdc++.h>

using namespace std;

long long int swaps = 0;
using namespace std;

void merge_conta(long long int a[], long long int temp[], int p, int q, int r) {
    for(int i = p; i <= q; i++) {
        temp[i] = a[i];
    }
    for(int j = q + 1; j <= r; j++) {
        temp[r + q + 1 - j] = a[j];
    }
    int i = p;
    int j = r;
    for(int k = p; k <= r; k++) {
        if(temp[i] <= temp[j]) {
            a[k] = temp[i];
            i++;
        } else {
            a[k] = temp[j];
            j--;
            swaps += (q - i + 1);
        }
    }
}

//copia array
void merge_sort(long long int a[], long long int temp[], int i, int f) {
    if(i < f) {
        int m = (i + f) / 2;
        merge_sort(a, temp, i, m);
        merge_sort(a, temp, m + 1, f);
        merge_conta(a, temp, i, m, f);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long int x, y, temp, valor;
    cin >> x >> y;
    long long int h, v;
    cin >> h >> v;
    long long int ch[h];
    long long int temph[h];
    map<int, int> maph;
     map<int, int> mapv;
    long long int cv[v];
    long long int tempv[v];
    swaps = 0;
    for(int i = 0; i < h; i++) {
        cin >> temp;
        cin >> valor;
        maph[temp] = valor;
    }
    int i = 0;
    for(auto a : maph) {
        ch[i] = a.second;
        i++;
    }
    for(int i = 0; i < v; i++) {
        cin >> temp;
        cin >> valor;
        mapv[temp] = valor;
    }
    i = 0;
    for(auto a : mapv) {
        cv[i] = a.second;
        i++;
    }

    merge_sort(ch, temph, 0, h - 1);
    merge_sort(cv, tempv, 0, v - 1);
    cout << swaps + (h + 1)*(v + 1) << endl;

}
