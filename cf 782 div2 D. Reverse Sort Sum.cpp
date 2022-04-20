#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007
#define mod2 998244353



int main()
{_
    ll t=1,ca=1;
    cin>>t;
    while(t--){///https://codeforces.com/contest/1659/problem/D
        ll n;
        cin>>n;
        ll a[n+1];
        ll kata[n+1];
        set<pair<ll,ll>>st;
        set<ll>st2;
        ll mn=1e9,mn2=1e9,p,p2,s=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            s+=a[i];
            kata[i]=0;
        }
        s/=n;p=n-s;
        for(int i=n;i>=n-s+1;i--){
            pair<ll,ll>z={a[i],i};
            if(!st2.count(a[i]))st.insert(z);
            st2.insert(a[i]);
        }

        s=n-s;
        ll c=1;
        while(c<=n&&a[c]==0)s-=1,kata[c]=1,c++;
        ll sum=0;
        for(int i=p;i>=1;i--){
            if(s==0)break;
            pair<ll,ll>z=*st.begin();
            kata[z.second]=1;
            sum=z.first;
            st.erase(st.begin());
            st2.erase(st2.begin());
            sum+=a[i];
            if(!st2.count(sum)){
                st2.insert(sum);
                st.insert({sum,i});
            }
            s-=1;
        }
        for(int i=1;i<=n;i++){
            if(a[i]>0&&kata[i]!=1)cout<<1<<" ";
            else cout<<0<<" ";
        }cout<<endl;
    }
}
