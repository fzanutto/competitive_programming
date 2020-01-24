#include <bits/stdc++.h>

#define MAXN 200005
#define K 20

using namespace std;

int monsters[MAXN];
int N;
int st[MAXN][K+1];
int LOG[MAXN+1]; //will store logs for use in RMQ

int RMQ(int L, int R){
    int j = LOG[R-L+1];
    int ans = max(st[L][j], st[R-(1<<j)+1][j]);
    return ans;
}

void build_st(){
    for(int i=0; i<N;i++)
        st[i][0] = monsters[i];
        
    for(int j=1; j<= K; j++){
        for(int i=0; i+ (1<<j) <= N; i++){
            st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    
    int h;
    
    LOG[1] = 0;
    for(int i=2; i <= MAXN; i++)
        LOG[i] = LOG[i/2] + 1;
        
    vector<pair<int,int>> h2(MAXN),h3(MAXN);
    
    while(t--){
        cin >> N;

        for(int i=0; i<N; i++){
            cin >> monsters[i];
        }
        
        build_st();
        
        cin >> h;
                
        for(int i=0; i<h; i++){
            int x,y; // x = power, y = stamina
            cin >> x >> y;
            h3[i] = {y,x};
        }
        
        sort(h3.begin(), h3.begin()+h, greater<pair<int, int>>());
        
        h2[0] = h3[0];
        int sizeH = 0;
        for(int i=1; i<h; i++){
            if(h3[i].second > h2[sizeH].second)
                h2[++sizeH] = h3[i];
        }
        
        int days = 0; // current day
        int k = 0; // current monster
        
        while(k < N-1){
            /*
            int l = -1;
            int r = h2.size()-1;
            bool ok = false;
            while (l<r){
                int mid = (l+r)/2;
                //cout << "mid: "<<mid << endl;
                if (h2[mid].second >= RMQ(k,k+h2[mid].first)){
                    r = mid;
                    ok = true;
                    //cout << "rmq:"<<RMQ(k,k+h2[mid].first) << endl;
                } else
                    l = mid+1;
            }*/
            int cont = -1;
            for(int i=sizeH; i>=0;i--){
                if(h3[i].second >= RMQ(k, k+h3[i].first))
                    cont = h3[i].first;
                else
                    break;
            }
            if(cont == -1){
                days = -1;
                break;
            }
            else{
                days++;
                //cout << "add: " << h2[l].first << endl;
                k += cont;
            }
        }
        cout << days << endl;
                
    }
}
