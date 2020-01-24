#include <bits/stdc++.h>

using namespace std;


double dp[2][1001][1001];

double calc(int jog, int preto, int branco){

    double b = branco;
    double p = preto;
    
    
    
    if(dp[jog][preto][branco] != -1.0){
        return dp[jog][preto][branco];
    }
    
    //cout << jog << " " << p << " " << b << endl;
    
    double ans;
    
    if(b == 0) return 0;
    if(p == 0) return jog;
    
    if(jog){
        // princesa pegar um rato branco OU (ela pegar um preto E ganhar)
        ans = b/(p+b) + (1 - b/(p+b)) * calc(!jog, p-1, b);   
    } else {
        // dragao pegar rato preto E (sair um rato branco e a princesa ganhar OU sair um rato preto e ela ganhar)
        double chance = (1 - b/(b+p)) * (b/(p+b-1)) * calc(!jog, p-1, b-1);
        
        if(p >= 2)
            chance += ((1 - b/(b+p)) * (1 - b/(p+b-1)) * calc(!jog, p-2, b));
        
        ans = chance;
    }

    dp[jog][preto][branco] = ans;
    
    return ans;
}


int main(){
    
    int b,p;
    
    cin >> b >> p;
    
    fill_n(&dp[0][0][0], 2*1001*1001, -1.0);
    
    cout << setprecision(9);
    cout << calc(1, p, b) << endl;

}
