#include <bits/stdc++.h>

using namespace std;


vector<int> group[305];

int main(){


    int n;
    cin >> n;
    
    int step = -1;
    int pos = 0;
    for(int i=0; i<n*n; i++){

        if(i % n == 0){
            pos += step;
            step *= -1;
        }
        pos += step;        

        group[pos%n].push_back(i+1);
    }

    int i,j;
    for(i=0; i<n; i++){

        for(j=0; j<n-1; j++){
            cout << group[i][j] << " ";
        }
        cout << group[i][j] << endl;
    }
    
    return 0;
}   
