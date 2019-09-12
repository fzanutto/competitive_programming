#include <bits/stdc++.h>

using namespace std;

int main(){

    set<string> dicionario;

    char texto[201];
    char ch;
    int i=0;

    while(scanf("%c", &ch) != EOF){
        if (isalpha(ch)){
            texto[i++] = tolower(ch);
            continue;
        }

        if(i){
            texto[i] = '\0';
            string a(texto);
            dicionario.insert(a);
            i=0;
        }
    }

    for(auto a: dicionario){
        cout << a << endl;
    }
}
