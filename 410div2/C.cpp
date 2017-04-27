#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int INF=1e9+10;

int n;
int a[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    while(cin>>n){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int d=0;
        for(int i=1;i<=n;i++) d=__gcd(a[i],d);
        int res=0;
        if(d>1) res=0;
        else{
            for(int i=1;i<=n;){
                if(a[i]%2==0) i++;
                else if(i!=n){
                    int x=abs(a[i]-a[i+1]),y=abs(a[i]+a[i+1]);
                    a[i]=x;a[i+1]=y;
                    res++;
                    if(a[i]%2){
                        x=abs(a[i]-a[i+1]),y=abs(a[i]+a[i+1]);
                        a[i]=x;a[i+1]=y;
                        res++;
                    }
                }
                else{
                    int x=abs(a[i]-a[i-1]),y=abs(a[i]+a[i-1]);
                    a[i]=x;a[i-1]=y;
                    res++;
                    if(a[i]%2){
                        x=abs(a[i]-a[i-1]),y=abs(a[i]+a[i-1]);
                        a[i]=x;a[i-1]=y;
                        res++;
                    }
                }
            }
        }
        puts("YES");
        cout<<res<<endl;
    }
    return 0;
}
