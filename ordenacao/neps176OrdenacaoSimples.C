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
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

vector <ll> v;
int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
 	int n;
 	cin >> n;
 	para(i,n)
 	{	
 		ll x;
 		cin >> x;
 		v.pb(x);
 	}
 	sort(all(v));
 	para(i,v.size())
 	{
 		cout << v[i];
 		if (i < v.size() - 1)
 			cout << " ";
 	}
 	cout << endl;
  
	return 0;
}
