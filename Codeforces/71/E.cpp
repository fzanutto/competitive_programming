#include <bits/stdc++.h>
 
using namespace std;

string v[] =  {"","H","He","Li","Be","B","C","N","O","F","Ne","Na", "Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti", "V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se", "Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd", "Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La","Ce", "Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb", "Lu","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb", "Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa","U","Np","Pu", "Am","Cm","Bk","Cf","Es","Fm"};

map<string, int> m;

int n,k;

int sum[1<<18];
int dp[1<<18];
int previous[1<<18];

vector<int> initial, ending;


void calc(int mask){
    int a = mask;
    int ans = 0;
    int i = 0;
    
    while(a > 0){
        if(a & 1)
            ans += initial[i];
        a >>= 1;
        i++;
    }
    
    sum[mask] = ans;
}


void calc2(int s){ 
    int full = (1<<n)-1;

    if(dp[s] != -1){
        int c = s^full;
        int c2 = c;

        while(c2 > 0){

            if(sum[c2] == ending[dp[s]]){
                dp[s ^ c2] = dp[s]+1;
                previous[s^c2] = s;
            }

            c2 = (c2-1) & c;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    
    for(int i=1; i <= 100; i++){
        m[v[i]] = i;
    }
    
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        
        initial.push_back(m[s]);
    }
   

    for(int i=0; i<k; i++){
        string s;
        cin >> s;
        
        ending.push_back(m[s]);
    }
    
    
    int full = (1<<n) - 1;
    int mask = full;
    
    while(mask > 0){
        calc(mask);
        mask--;
    }

    memset(dp, -1, sizeof(dp));
    dp[0] = 0;

    mask = 0;    
    while(mask <= full){
        calc2(mask);
        mask++;
    }
    
    if(dp[full] != k){
        cout << "NO" << endl;
        return 0;
    }
    
    
    cout << "YES" << endl;
    
    int ind = k-1;
    int current = full;
    
    while(current){
        int dif = current ^ previous[current];
        int j=0;
        for(int i=0; i< n; i++){
            if(dif & (1 << i)){
                if(j++) cout << "+";
                cout << v[initial[i]];    
            }
        }
        cout << "->" << v[ending[ind--]] << endl;
        current = previous[current];
    
    }
    
    
    return 0;
}
