#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(v) begin(v), end(v)

vector<string> split(const string& s, char del=' ');

void calculate1() {
    string line;
    int num_instances = 0;
    while(getline(cin, line)) {
        vector<string> notes = split(line);

        for(int i = 11; i < 15; i++) {
            for(int len : {2, 4, 3, 7}) {
                if(len == notes[i].length()) {
                    num_instances++;
                    break;
                }
            }
        }
    }
    cout << num_instances << "\n";
}

void calculate2() {
    string line;

    /*
    "order" from 0 - 6 meanings
    TOP
    TOPLEFT
    TOPRIGHT
    MIDDLE
    BOTTOMLEFT
    BOTTOMRIGHT
    BOTTOM
    */
    vector<vector<bool>> all_digs;
    set<vector<bool>> all_digits;
    // vector<bool> digit(7);
    all_digs.push_back({1, 1, 1, 0, 1, 1, 1}); // 0
    all_digs.push_back({0, 0, 1, 0, 0, 1, 0}); // 1
    all_digs.push_back({1, 0, 1, 1, 1, 0, 1}); // 2
    all_digs.push_back({1, 0, 1, 1, 0, 1, 1}); // 3
    all_digs.push_back({0, 1, 1, 1, 0, 1, 0}); // 4
    all_digs.push_back({1, 1, 0, 1, 0, 1, 1}); // 5
    all_digs.push_back({1, 1, 0, 1, 1, 1, 1}); // 6
    all_digs.push_back({1, 0, 1, 0, 0, 1, 0}); // 7
    all_digs.push_back({1, 1, 1, 1, 1, 1, 1}); // 8
    all_digs.push_back({1, 1, 1, 1, 0, 1, 1}); // 9


    // to get the digits from the vector<bool> representations
    // could use either array and convert vector<bool> to binary number
    // like bitset<>m ofc could just use bitset someway
    map<vector<bool>, int> vtbool2digit;
    int number = 0;
    for(vector<bool> digit : all_digs){
        vtbool2digit[digit]=number++;
        all_digits.insert(digit);
    }


    int sum = 0;

    while(getline(cin, line)) {
        vector<string> vals = split(line), signal_patterns, output_values;

        for(int i = 0; i < 10; i++) signal_patterns.push_back(vals[i]);
        for(int i = 11; i < 15; i++) output_values.push_back(vals[i]);

        vector<char> order = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};

        vector<int> char2index(7);


        do {
            for(int i = 0; i < 7; i++)
                char2index[order[i]-'a'] = i;

            for(string pattern : signal_patterns) {
                vector<bool> on(7);
                for(char c : pattern)
                    on[char2index[c-'a']]=1;
                if(all_digits.find(on) == end(all_digits))
                    // if we could not find this in all the digit representations,
                    // the current ordering of segments must be incorrect
                    goto LOOP;
            }
            // this is the unique ordering
            break;
            // other condition
            LOOP: continue;
        } while(next_permutation(all(order)));

        int cur_value = 0;

        for(string value : output_values) {
            vector<bool> on(7);
            for(char c : value)
                on[char2index[c-'a']]=1;

            int cur_dig = vtbool2digit[on];
            cur_value = 10 * cur_value + cur_dig;
        }
        sum += cur_value;

    }
    cout << sum << "\n";
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);


    cout << "P1: "; calculate1();
    // cout << "P2: "; calculate2();


}

vector<string> split(const string& s, char del){
    vector<string> res;
    string n;
    for(char c : s){
        if(c==del) {
            res.push_back((n));
            n="";
        }
        else{
            n+=c;
        }
    }
    if(!n.empty())
        res.push_back((n));
    return res;
}
