#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> split(const string& s, char del=' ');

ll calc(int num_days) {
    string s;
    cin >> s;
    vector<ll> fishes = split(s, ','), cnt(9);
    for(ll fish : fishes) {
      ++cnt[fish];
      // cerr << fish << " ";
    }
    // cerr << "\n";

    for(int day = 1; day <= num_days; ++day) {
      for(ll c : cnt)
          cerr << c << " ";
      cerr << "\n";

      ll num0 = cnt[0];
      // 1->0, 2->1, .. 8->7
      for(int i = 1; i <= 8; ++i)
          cnt[i-1]=cnt[i];
       cnt[6] += num0;
       cnt[8] = num0;
    }

    ll numFish = 0;
    for(ll c : cnt) {
      numFish += c;
      cerr << c << " ";
    }
    cerr << "\n";
    return numFish;
}

ll sample() {
    return calc(256);
}

ll p1() {
    return calc(80);
}

ll p2() {
    return calc(256);
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);

    
    // cout << "Sample: " << sample() << "\n";

    freopen("input.in", "r", stdin);
    
    cout << "Part 2: " << p2() << "\n";
    
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
