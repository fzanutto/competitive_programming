#include <bits/stdc++.h>

using namespace std;

int t,n,c;
long long tree[20*100010];
long long valUp[20*100010];

void propagate(int root, int l, int r) {
    tree[root]+=(long long)(r-l+1)*valUp[root];

    if (l<r) {
        valUp[2*root+1]+=valUp[root];
        valUp[2*root+2]+=valUp[root];
    }

    valUp[root]=0;
}

long long query(int root, int l, int r, int ql, int qr) {
    propagate(root,l,r);

    if (ql<=l && qr>=r)
        return tree[root];

    int mid=(l+r)/2;
    long long sum=0;

    if (ql<=mid)
        sum+=query(2*root+1,l,mid,ql,min(qr,mid));
    if (qr>mid)
        sum+=query(2*root+2,mid+1,r,max(ql,mid+1),qr);

    return sum;
}

void update(int root, int l, int r, int ql, int qr, int val) {
    if (ql<=l && qr>=r) {
        tree[root]+=(long long)val*(r-l+1);

        if (l<r) {
            valUp[2*root+1]+=val;
            valUp[2*root+2]+=val;
        }
        return;
    }

    int mid=(l+r)/2;

    if (ql<=mid)
        update(2*root+1,l,mid,ql,min(qr,mid),val);
    if (qr>mid)
        update(2*root+2,mid+1,r,max(mid+1,ql),qr,val);

    propagate(2*root+1,l,mid);
    propagate(2*root+2,mid+1,r);

    tree[root]=tree[2*root+1]+tree[2*root+2];
}

int main() {

  
    memset(tree,0,sizeof(tree));
    memset(valUp,0,sizeof(valUp));
	
	
	//n numero de elementos do array
	//p e q indices que serao atualizados/buscados
	//v valor para atualizar os indices
	int p,q,v;
	p = 2;
	q = 4;
	v = 5
	update(0,0,n-1,p-1,q-1,v);
	
	printf("%lld\n", query(0,0,n-1,p-1,q-1));


    return 0;
}
