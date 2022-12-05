#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(v) begin(v), end(v)


vector<char> opening_chars = {'{', '(', '[', '<'};
vector<char> closing_chars = {'}', ')', ']', '>'};
map<char, char> opp_char = {{'{', '}'}, {'[', ']'}, {'(', ')'}, {'<', '>'},
                            {'}', '{'}, {']', '['}, {')', '('}, {'>', '<'}};

void calculate1() {
    map<char, int> score = {{')', 3}, {']', 57}, {'}', 1197}, {'>', 25137}};
    /*
    first illegal character is what we take score as
    ): 3 points.
    ]: 57 points.
    }: 1197 points.
    >: 25137 points.
    */
    
    int ans = 0;
    string s;
    while(cin >> s) {
        // concept for corrupted: stacks for last pos of each type
        map<char, stack<int>> stacks = {
            {'{', stack<int>()},
            {'[', stack<int>()},
            {'<', stack<int>()},
            {'(', stack<int>()},
        };
        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
            if(c == '{' || c == '[' || c == '<' || c == '(') {
                stacks[c].push(i);
            } else {
                if(stacks[opp_char[c]].empty()) {
                    ans += score[c];
                    break;
                } else {
                    bool bad = false;
                    for (auto& [bracket, stk] : stacks) {
                        if(!stk.empty() && stk.top() > stacks[opp_char[c]].top()) {
                            ans += score[c];
                            bad = true;
                            break;
                        }
                    }
                    if(bad) break;
                    // if we get here, then we have a valid closing bracket
                    stacks[opp_char[c]].pop();
                }
            }
        }
        cout << s << " " << "\n";
    }
    
    cout << ans << "\n";
}


void calculate2() {
    map<char, int> point = {{')', 1}, {']', 2}, {'}', 3}, {'>', 4}};
    vector<string> tool_contest_completions;
    string s;
    while(cin >> s) {
        map<char, stack<int>> stacks = {
            {'{', stack<int>()},
            {'[', stack<int>()},
            {'<', stack<int>()},
            {'(', stack<int>()}
        };
        bool corrupted = false;
        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
            if(c == '{' || c == '[' || c == '<' || c == '(') {
                stacks[c].push(i);
            } else { // c E closing bracket
                if(stacks[opp_char[c]].empty()) {
                    // ans += score[c];
                    corrupted = true;
                    break;
                } else {
                    bool bad = false;
                    for (auto& [bracket, stk] : stacks) {
                        if(!stk.empty() && stk.top() > stacks[opp_char[c]].top()) {
                            // ans += score[c];
                            bad = true;
                            break;
                        }
                    }
                    if(bad) {
                        corrupted = true;
                        break;
                    }
                    // if we get here, then we have a valid closing bracket
                    stacks[opp_char[c]].pop();
                }
            }
        }
        
        if(corrupted) 
           continue;

        // OK so we have passed and said this is uncorrupted
        // now we just need to see the order of necesary closing brackets (for incomplete lines)
        /*
        while there is a stack that is not empty
            pop the top of the stack that has the max top of the non-empty stacks
            add the point of the bracket to 5 times the current score
        */
        
        // ll score = 0; This Will NOT work since we will overflow!!
        // what to do?
        // we notice this looks like base-5 so we will save the strings and sort them by custom comparator and then convert to score for numerical answer
        //
        string compl_string = "";
        while(!stacks['{'].empty() || !stacks['['].empty() || !stacks['<'].empty() || !stacks['('].empty()) {
            char max_char;
            int max_val = -1;
            for (auto& [bracket, stk] : stacks) {
                if(!stk.empty() && stk.top() > max_val) {
                    max_val = stk.top();
                    max_char = bracket;
                }
            }
            stacks[max_char].pop();
            compl_string += to_string(point[opp_char[max_char]]);
        }
        if(compl_string != "") {
            tool_contest_completions.push_back(compl_string);
        }
    }
    
    sort(all(tool_contest_completions), [](string& a, string& b) {
        if(a.length() != b.length()) {
            return a.length() < b.length();
        } else {
            return a < b;
        }
    });
    
    // for(int i = 0; i < tool_contest_completions.size(); i++) {
    //     cout << tool_contest_completions[i] << "\n";
    // }

    auto base5_to_score = [](string s) {
        ll score = 0;
        for(int i = 0; i < s.length(); i++) {
            score *= 5;
            score += s[i] - '0';
        }
        return score;
    };

    // middle element (sz guaranteed to be odd)
    cout << "ans: " << base5_to_score(tool_contest_completions[tool_contest_completions.size() / 2])<< "\n";
    
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);

    freopen("input.in", "r", stdin);
    
    // cout << "P1: "; calculate1();
    
    cout << "P2: "; calculate2();

}
