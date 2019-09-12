#include <bits/stdc++.h>

using namespace std;

int main(){

    float a,b;
    int q, r;
    cin >> a >> b;



    if (b < 0){
        q  = ceil(a/b);
    } else {
        q = floor(a/b);
    }

    r = a - b*q;

    cout << q << " " << r << endl;

}
