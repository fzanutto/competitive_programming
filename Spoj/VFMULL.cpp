#include <bits/stdc++.h>

using namespace std;

#define cd complex<double>
const double PI = acos(-1);

void fft(vector<cd> &a, bool invert){
    int n = a.size();
    
    if (n == 1) return;
    
    vector<cd> a0(n/2), a1(n/2);
    
    for(int i=0; i*2 < n; i++){
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    
    fft(a0, invert);
    fft(a1, invert);
    
    
    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    
    for(int i=0; 2*i < n; i++){
        a[i] = a0[i] + w * a1[i];
        a[i+n/2] = a0[i] - w * a1[i];
        if (invert){
            a[i] /= 2;
            a[i+n/2] /= 2;
        }
        w *= wn;
    }

}

vector<int> multiply(vector<int> const &a, vector<int> const &b){
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());   
    
    int n = 1;
    while(n < (int)a.size() + (int)b.size())
        n <<= 1;
        
    fa.resize(n);
    fb.resize(n);
    
    fft(fa, false);
    fft(fb, false);
    
    for(int i=0; i<n; i++)
        fa[i] *= fb[i];

    fft(fa, true);
    
    vector<int> result(n);
    int carry = 0;
    for(int i=0; i <n; i++){
        result[i] = round(fa[i].real());
        
        result[i] += carry;
        carry = result[i]/10;
        result[i] %= 10;
    }
    
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    string a,b;
    
    cin >> t;
    
    while(t--){
    
        cin >> a >> b;

        vector<int> fa, fb;
        
        for(int i=a.size()-1; i>=0; i--){
            fa.push_back(a[i] - '0');
        }
        
        for(int i=b.size()-1; i>=0; i--){
            fb.push_back(b[i] - '0');
        }
        
        vector<int> res = multiply(fa, fb);
        
        /*
        for(auto x: res)
            cout << x;
        cout << endl << endl;
        */
        
        int i;
        for(i = res.size() - 1; i>0; i--){
            if(res[i])
                break;
        }
        
        for(int j=i; j>=0; j--)
            cout << res[j];

        cout << endl;
            
    }
}
