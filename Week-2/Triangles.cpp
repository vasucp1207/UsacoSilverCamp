#include<iostream>
#include <string>
#include <vector>
#include <utility>
#include <cstring>
#include <climits>
#include <cstdio>
#include <map>
#include <unordered_map>
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
#define ln "\n"
#define all(x) (x).begin(), (x).end()
const int mod = 1e9 + 7;

using namespace std;

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n;
	cin >> n;
	
	vector<int> x(n), y(n);
	unordered_map<int, vector<pair<int, int> > > xmap, ymap;
	
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
		ymap[y[i]].pb(make_pair(x[i], i));
		xmap[x[i]].pb(make_pair(y[i], i));
	}
	
	vector<int> xsum(n, 0), ysum(n, 0);
	
	for(auto p: xmap){
		vector<pair<int, int> > ys = p.se;
		sort(ys.begin(), ys.end());
		
		ll sum = 0;
		for(int i = 0; i < ys.size(); i++){
			sum += ys[i].fi - ys[0].fi;
		}
		ysum[ys[0].se] = sum;
		
		for(int i = 1; i < ys.size(); i++){
			int dist = ys[i].fi - ys[i - 1].fi;
			sum += i * dist;
			sum -= (ys.size() - i) * dist;
			ysum[ys[i].se] = sum;
		}
	}
	
	for(auto p: ymap){
		vector<pair<int, int> > xs = p.se;
		sort(xs.begin(), xs.end());
		
		ll sum = 0;
		for(int i = 0; i < xs.size(); i++){
			sum += xs[i].fi - xs[0].fi;
		}
		xsum[xs[0].se] = sum;
		
		for(int i = 1; i < xs.size(); i++){
			int dist = xs[i].fi - xs[i - 1].fi;
			sum += i * dist;
			sum -= (xs.size() - i) * dist;
			xsum[xs[i].se] = sum;
		}
	}
	
	ll ans = 0;
	for(int i = 0; i < n; i++){
		ans += xsum[i] * ysum[i];
		ans = ans % mod;
	}
	
	cout << ans << endl;
	
	

    return 0;
}
