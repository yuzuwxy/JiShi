#include<bits/stdc++.h>

using namespace std;

const int MAXN=500010;

int c[MAXN];
int n,m,k,a,b;

int lowbit(int x)
{
    return x&(-x);
}

void update(int x,int v)
{
    while(x<=n)
    {
        c[x]+=v;
        x+=lowbit(x);
    }
}

int sum(int x)
{
    int res=0;
    while(x>0)
    {
        res+=c[x];
        x-=lowbit(x);
    }
    return res;
}

int main()
{
    int v;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&v);
        update(i,v);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&k,&a,&b);
        if(k==2)
          printf("%d\n",sum(b)-sum(a-1));
        else 
          update(a,b);
    }
    return 0;
}