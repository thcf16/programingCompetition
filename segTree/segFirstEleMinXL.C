#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define para(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define paraIni(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rpara(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define unicos(X) (X).erase(unique(all(X)),(X).end())
#define NL <<"\n"
#define EPS 1e-6
#define MOD 1000000007
#define iinf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
typedef int item;
// struct item
// {
//     ll i;
    
// };

struct segtree 
{
    ll size;
    vector<item> value;

    item NEUTRAL_ELEM = INT_MIN;
    void init(ll n)
    {
        size=1;
        while(size<n)
            size*=2;
        value.resize(2*size);

    }
    item merge(item a, item b)
    {
        return max(a,b);
    }

    item single(ll v)
    {
        return v;
    }
    pair <int, int> child(int x)
    {
        return {2*x+1, 2*x+2};
    }
    void build(vector<ll> &a, ll x, ll lx, ll rx)
    {
        if (rx-lx == 1)
        {
            if (lx < (int)a.size())
            {
                value[x] = single(a[lx]);
            }
            return;
        }
        ll m = (lx+rx)/2;
        build(a,2*x+1, lx, m);
        build(a,2*x+2, m, rx);
        value[x] = merge(value[2*x+1],  value[2*x+2]);

    }

    void build(vector<ll> &a)
    {
        build(a, 0, 0, size);
    }

    void set(ll i,ll v, ll x, ll lx, ll rx)
    {
        if (rx-lx==1)
        {
            value[x] = single(v);
            return;
        }
        ll m = (lx+rx)/2;
        if (i < m)
        {
            set(i,v,2*x+1, lx, m);
        }
        else
        {
            set(i,v,2*x+2, m, rx);
        }
        value[x] = merge(value[2*x+1],  value[2*x+2]);
    }
    void set(ll i, ll v)
    {
        set(i,v,0,0,size);
    }

    int find(ll k, ll l, ll x, ll lx, ll rx)
    {
        // printf("%d %d %d %d %d\n",k,x,lx,rx, value[x] );
        if (value[x] < k)
            return -1;
        if (rx <= l )
            return -1;
        if (rx-lx==1)
        {
            return (lx);
        }

        ll m = (lx+rx)/2;
        int val = find(k,l,x*2+1,lx,m);
        if (val!=-1) 
            return val;
        return find(k,l,x*2+2,m,rx);
    }

    int find(ll k, ll l)
    {
        return find(k,l,0,0,size);
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;

    segtree st;
    st.init(n);
    vector <ll> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];        
    }
    st.build(a);
    // printf("%lld\n",st.size );
    // for (int i = 0; i < st.value.size(); ++i)
    // {
    //     printf("%lld ",st.value[i] );
    // }
    while(m--)
    {
        int op;
        cin >> op;
        if (op==1)
        {
            int i,v;
            cin >> i >> v;
            st.set(i,v);
        }
        else
        {
            int k,l;
            cin >> k >> l;
            int val = st.find(k,l);
            printf("%d\n",val );
            // cout << val << '\n';
            // item ans = st.find(l,r);
            // cout << ans.m << " " <<ans.c << '\n';
        }
    }
  
    return 0;
}
