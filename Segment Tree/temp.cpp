#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

typedef long long            ll;
typedef long double          ld;
#define pb                   push_back
#define cy                   cout << "Yes\n"
#define cn                   cout << "No\n"
#define all(v)               v.begin(), v.end()
const ll N=2e4+7;

ll n,q; vector<ll>v, sgt;

void build(ll node, ll start, ll end){
    if(start==end){
        sgt[node]=v[start];
        return;
    }

    ll mid=(start+end)/2;
    build(node*2,start,mid);
    build(node*2+1,mid+1,end);

    sgt[node]=sgt[2*node]+sgt[2*node+1];
}

void update(ll node, ll start, ll end, ll ti, ll tv){
    if(start==end){
        sgt[node] = tv;
        return;
    }

    ll mid=(start+end)/2;
    if(ti>mid) update(node*2+1, mid+1, end, ti, tv);
    else update(2*node, start,mid,ti,tv);

    sgt[node]=sgt[2*node]+sgt[2*node+1];
}

ll query(ll node, ll start, ll end, ll ql, ll qr){
    // in out half

    if(ql <= start && end <= qr)
        return sgt[node];

    if(ql>end || qr<start) return 0;

    ll mid=(start+end)/2;
    ll ans1=query(2*node, start,mid, ql,qr);
    ll ans2=query(2*node+1, mid+1,end,ql,qr);
    return ans1+ans2;
}

void solve() {
    cin>>n>>q;
    v.resize(n+1); sgt.resize(4*n);
    for(ll i=1;i<=n;i++)cin>>v[i];

    build(1,1,n);


    while(q--){
        ll a,b,c; cin>>a>>b>>c;
        if(a==1){
            update(1,1,n,b,c);
        }
        else{
            
           cout<<query(1,1,n,b,c)<<endl;
        }
    }
}

int main() {
    optimize();
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
