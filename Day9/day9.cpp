#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(v) begin(v), end(v)

// alias ccompile='f(){ g++ -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector "$@".cpp -o "$@"; unset -f f; }; f'
const int di[4]={-1, 0, 1, 0}, dj[4]={0, 1, 0, -1};

vector<string> heightmap;

void calculate1() {
    string s;
    while(cin >> s)
        heightmap.push_back(s);

    int n = heightmap.size(), m = heightmap[0].size();

    int sum = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            bool low = true;
            for(int d = 0; d < 4; d++) {
                int ni = i + di[d],
                    nj = j + dj[d];
                if(0 <= ni && ni < n && 0 <= nj && nj < m)
                    low &= ((heightmap[i][j] - '0') < (heightmap[ni][nj] - '0'));
            }
            if(low) sum += 1 + (heightmap[i][j] - '0');
        }
    }

    cout << sum << "\n";
}

int n=100, m=100;

vector<vector<int>> component(110, vector<int>(110, -1));

int valid(int ni, int nj) {
    return 0 <= ni && ni < n && 0 <= nj && nj < m;
}

void floodfill(int i, int j, int label) {
    if(!valid(i, j) || heightmap[i][j] == '9' || component[i][j] != -1) return;
    component[i][j] = label;

    for(int d = 0; d < 4; d++)
        floodfill(i + di[d], j + dj[d], label);
}

void calculate2() {
    string s;
    while(cin >> s)
        heightmap.push_back(s);

    n = heightmap.size(), m = heightmap[0].size();

    // difference from part 1: condition when found low
    // idea: floodfill from the low points to find basins, stop when we hit a nine

    int num_basin = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            bool low = true;
            for(int d = 0; d < 4; d++) {
                int ni = i + di[d],
                    nj = j + dj[d];
                if(valid(ni, nj))
                    low &= ((heightmap[i][j] - '0') < (heightmap[ni][nj] - '0'));
            }
            if(low) {
                floodfill(i, j, num_basin++);
            }
        }
    }

    cout << num_basin << "\n";
    vector<int> comp_sz(num_basin);
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        if(component[i][j] != -1)
            ++comp_sz[component[i][j]];

    sort(all(comp_sz), greater<int>());

    ll ans = 1;
    for(int i = 0; i < 3; i++) {
        // cout << comp_sz[i] << "\n"; // check overflow (max size is only ~100)
        ans *= 1LL * comp_sz[i];
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);

    // cout << "P1: "; calculate1();
    cout << "P2: "; calculate2();

}
