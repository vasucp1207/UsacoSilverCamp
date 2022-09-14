#include<iostream>
#include <string>
#include <vector>
#include <utility>
#include <cstring>
#include <climits>
#include <cstdio>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <math.h>
#include <algorithm>
#include <iomanip>
#include <cmath>

#define lb lower_bound
#define ub upper_bound
#define ll long long
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define nl "\n"
#define all(x) (x).begin(), (x).end()
const int mod = 1e9 + 7;

using namespace std;

ll total_area;

void transpose(vector<pair<ll, ll> > &cow){
	for(ll i = 0; i < cow.size(); i++){
		swap(cow[i].fi, cow[i].se);
	}
}

void update(map<ll, ll> &m, ll key, ll val){
	// frequency of y vals
	if(!m.count(key)){
		m[key] = 0;
	}
	
	ll next = m[key] + val;
	if(next == 0){
		m.erase(key);
	}
	else{
		m[key] = next;
	}
}

ll solve(vector<pair<ll, ll> > &cow){
	sort(cow.begin(), cow.end()); 
	
	map<ll, ll> rhs;
	for(auto curr: cow){
		update(rhs, curr.se, 1);
	}
	
	ll ret = total_area = (cow[cow.size() - 1].fi - cow[0].fi) 
				 * ((*rhs.rbegin()).fi - (*rhs.begin()).fi);
	
	map<ll, ll> lhs;
	for(ll i = 0; cow[i].fi < cow[cow.size() - 1].fi;){
		ll j = i + 1;
		while(j < cow.size() && cow[i].fi == cow[j].fi){
			// all the points having same x
			j++;
		}
		
		// sliding the boundary by one coordinate
		for(ll k = i; k < j; k++){
			update(rhs, cow[k].se, -1);
			update(lhs, cow[k].se, 1);
		}
		
		ret = min(ret, (cow[i].fi - cow[0].fi) * ((*lhs.rbegin()).fi - (*lhs.begin()).fi)
			  + (cow[cow.size() - 1].fi - cow[j].fi) * ((*rhs.rbegin()).fi - (*rhs.begin()).fi));
		
		i = j;
	}
	
	return ret;
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n;
	cin >> n;
	vector<pair<ll, ll> > cow;
	ll u, v;
	for(ll i = 0; i < n; i++){
		cin >> u >> v;
		cow.pb(make_pair(u, v));
	}
	
	ll res1 = solve(cow);
	transpose(cow);
	ll fans = min(res1, solve(cow));
	cout << total_area - fans << nl;
		
	

    return 0;
}
