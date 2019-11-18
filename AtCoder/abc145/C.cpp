#include <bits/stdc++.h>

using namespace std;

long double sum;
int n;
pair<int,int> coord[10];

long long dist(pair<int,int> p1, pair<int,int> p2){
    int x = p1.first - p2.first;
    int y = p1.second - p2.second;
    
    return (x*x + y*y);
}

int fact(int x){
    if (x<=1) return 1;
    return x * fact(x-1);
}

int main(){

    cin >> n;
    
    for(int i=0; i<n; i++)
        cin >> coord[i].first >> coord[i].second;    

    for(int x=0; x<fact(n); x++){
        for(int i=1; i<n; i++){
            sum += sqrt(dist(coord[i], coord[i-1]));
        }
        next_permutation(coord, coord+n);
    }
    
    cout << setprecision(20);
    cout << sum << endl;
    cout << sum/fact(n)<<endl;
}
