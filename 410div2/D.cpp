#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int INF=1e9+10;

struct Node
{
    ll a,b;int id;
    friend bool operator<(Node A,Node B)
    {
        return A.a>B.a;
    }
};Node p[maxn];int n;

int main()
{
    freopen("in.txt","r",stdin);
    while(cin>>n){
        for(int i=1;i<=n;i++) scanf("%I64d",&p[i].a);
        for(int i=1;i<=n;i++) scanf("%I64d",&p[i].b),p[i].id=i;
        sort(p+1,p+n+1);
        vector<int> ans;
        ans.push_back(p[1].id);
        for(int i=2;i<n;i+=2){
            if(p[i].b>=p[i+1].b) ans.push_back(p[i].id);
            else ans.push_back(p[i+1].id);
        }
        if(n%2==0) ans.push_back(p[n].id);
        printf("%d\n",(int)ans.size());
        for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);puts("");
    }
    return 0;
}





