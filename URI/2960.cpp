#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    
    scanf("%d", &n);
    
    set<char> vogais;
    set<char> total;
    vector<string> palavras;
    
    for(int i=0; i<n; i++){
        string res(""); 
                
        int qtd;
        scanf("%d", &qtd);
        
        for(int x=0; x<qtd; x++){
            char temp[102];
            scanf(" %[^\n]", temp);

            char t = temp[0];
            res += t;
            
            if (t == 'A' || t=='E' || t=='I' || t=='O' || t=='U')
                vogais.insert(t);
            total.insert(t);
        }
        
        palavras.push_back(res);
    }

    string nome("");
    for(auto a: palavras)
        nome += a[0];
    cout << "Nome da Linguagem: " << nome << endl;

    cout << "Lista de Palavras:" << endl;
    for(auto a : palavras){
        for(char x: a)
            printf("%c", tolower(x));
        cout << endl;
    }
    
    cout << "Numero de Vogais: " << vogais.size() << endl;
    cout << "Numero de Consoantes: " << total.size()-vogais.size() << endl;
    cout << "Numero Total de Letras: " << total.size() << endl;
    
    if(total.size() != vogais.size())
        printf("Tempo para aprender: %.1f horas\n", (float)(total.size() + vogais.size()) / (total.size() - vogais.size()));
    else
        cout << "Linguagem Ruim" << endl;

}
