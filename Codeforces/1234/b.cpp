#include  <bits/stdc++.h>

using namespace std;
int main(){

    deque<int> noti;
    map<int, bool> aparecendo;
    int n,k;
    int tot = 0;
    cin >> n >> k;
    int id;
    for(int i=0; i<n; i++){
        cin >> id;
        if (aparecendo[id] == 1){
            continue;
        }
        
        if (tot >= k){
            aparecendo[noti.back()] = 0;
            noti.pop_back();
        }
        aparecendo[id] = 1;
        noti.push_front(id);
        tot++;
    }

    cout << noti.size() << endl;
    for(int i=0; i<noti.size()-1; i++)
        cout << noti[i] << " ";
    cout << noti.back() << endl;
}
