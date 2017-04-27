#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int INF=1e9+10;

int n;
char s[60][60];

int main()
{
    //freopen("in.txt","r",stdin);
    while(cin>>n){
        int m;
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        m=strlen(s[1]+1);
        int res=INF;
        for(int i=1;i<=n;i++){
            int tmp=0;
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                int cnt=0;
                bool flag=0;
                for(int st=1;st<=m;st++){
                    int x=1;
                    bool tag=1;
                    for(int y=st;y<=m;y++){
                        if(s[i][x++]==s[j][y]) continue;
                        tag=0;break;
                    }
                    for(int y=1;y<=st-1;y++){
                        if(s[i][x++]==s[j][y]) continue;
                        tag=0;break;
                    }
                    //cout<<"i="<<i<<" j="<<j<<" st="<<st<<" tag="<<tag<<endl;
                    if(tag==0) continue;
                    cnt=st-1;
                    flag=1;
                    break;
                }
                //cout<<" i="<<i<<" j="<<j<<" flag="<<flag<<endl;
                if(flag) tmp+=cnt;
                else{
                    tmp=-1;break;
                }
            }
            if(tmp!=-1) res=min(res,tmp);
        }
        if(res==INF) puts("-1");
        else cout<<res<<endl;
    }
    return 0;
}
