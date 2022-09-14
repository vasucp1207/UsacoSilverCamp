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
 
int main(){
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	int n;
	cin >> n;
	vector<pair<int, int> > a;
	int u, v;
	for(int i = 0; i < n; i++){
		cin >> u >> v;
		a.pb(make_pair(u, 1));
		a.pb(make_pair(v, -1));
	}
	
	sort(a.begin(), a.end());
	
	int mx = 0;
	int res = 0;
	for(int i = 0; i < a.size(); i++){
		if(a[i].se == 1) mx++;
		else mx--;
		
		res = max(res, mx);
	}
	cout << res << endl;
		
	
 
    return 0;
}
