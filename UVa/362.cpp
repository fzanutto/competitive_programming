#include <bits/stdc++.h>

using namespace std;

int main(){
    int t = 0;
    int bytes;
    while(1){
        cin >> bytes;
        
        if (bytes == 0)
            return 0;
        
        int cont = 0;
        int temp = 0;
        
        cout << "Output for data set "<< ++t <<", " << bytes << " bytes:" << endl;
        
        while(bytes){
            int transf;
            cin >> transf;
            
            temp += transf;
            bytes -= transf;
            
            cont++;
            
            if(cont % 5 == 0){
                if(temp == 0){
                    cout << "   Time remaining: stalled" << endl;
                } else {
                    int est = ceil((bytes)*5.0/temp);
                  
                    cout << "   Time remaining: "<< est <<" seconds" << endl;
                    temp = 0;
                }
            }
        
        }
        cout << "Total time: " << cont << " seconds" << endl << endl;
    }
    return 0;
}
