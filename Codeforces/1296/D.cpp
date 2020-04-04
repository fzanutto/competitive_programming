#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

int N,A,B,K;
int monster[200001];

int main(){
    cin >> N >> A >> B >> K;
    
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        
        int hits = temp/(A+B);
        if(hits * (A+B) == temp)
            hits--;
        
        int vida = temp - (A+B)*hits;
        vida -= A;
        
        int esp = ceil((float)vida / (float)A);
        monster[i] = esp;
    } 
    
    sort(monster, monster+N);
    
    int ans = 0;
    for(int i=0; i<N; i++){
        K -= monster[i];
        
        if(K < 0)
            break;
        
        ans++;
    
    }
    
    
    cout << ans << endl;
}


