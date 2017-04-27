#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int INF=1e9+10;

char s[maxn];int len;

int main()
{
    //freopen("in.txt","r",stdin);
    while(~scanf("%s",s)){
        len=strlen(s);
        int l=0,r=len-1,cnt=0;
        while(l<r){
            if(s[l]!=s[r]) cnt++;
            l++;r--;
        }
        puts(cnt==1||cnt==0&&(len&1)?"YES":"NO");
    }
    return 0;
}
