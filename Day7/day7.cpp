#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> split(const string& s, char del=' ');

void calculate(bool constant_burn=true) {
    string s;
    cin >> s;
    // cout << s << "\n";
    vector<ll> crabs = split(s, ',');
    // cout << crabs.size() << "\n";
    ll mx = -1, mn = 1e9;
    for(ll crab : crabs) {
      mx = max(mx, crab);
      mn = min(mn, crab);
    }
    // cout << mx << " " << mn << "\n";
    ll mincost = 2e9;
    for(ll pos = mn; pos <= mx; pos++) {
        ll cost = 0;
        for(ll crab : crabs){
          ll n = abs(pos - crab);
          if(constant_burn) cost += n;
          else cost += n*(n+1)/2; // sum from 1..n
        }
        mincost = min(mincost, cost);
    }
    cout << mincost << "\n";
}


void sample() {
    freopen("AdventOfCode2021/Day7/sample.in", "r", stdin);
    calculate();
}

void p1() {
    freopen("AdventOfCode2021/Day7/input.in", "r", stdin);
    calculate();
}

void p2() {
    freopen("AdventOfCode2021/Day7/input.in", "r", stdin);
    calculate(false);
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);

    cout << "Sample: ";
    sample();
    cout << "p1: ";
    p1();
    cout << "p2: ";
    p2();

}

vector<ll> split(const string& s, char del){
    vector<ll> res;
    string n;
    for(char c : s){
        if(c==del) {
            res.push_back(stoll(n));
            n="";
        }
        else{
            n+=c;
        }
    }
    if(!n.empty())
        res.push_back(stoll(n));
    return res;
}
