class Solution {
public:
    //不妨设在第x个左括号后面有k个右括号
    vector<string> generateParenthesis(int n) {
        queue<pair<string, int>> temp;
        vector<string> ans;
        string lefts[8];
        string rights[9];
        string s = "(";
        for (int i = 0; i < 8; i++) {
            lefts[i] = s;
            s += "(";
        }
        s = "(";
        for (int i = 0; i < 9; i++) {
            rights[i] = s;
            s += ")";
        }

        for (int i = 1; i <= n; i++) {
            temp.push(make_pair(rights[i], n - i));
        }

        for (int i = n - 1; i > 0; i--) {

            queue<pair<string, int>> temp2;

            while (!temp.empty()) {
                int need = temp.front().second;
                string s = temp.front().first;
                temp.pop();
                if (need == 0) {
                    ans.push_back(lefts[i-1] + s);
                }
                else {
                    int start = 0;
                    if (need == i) {
                        start = 1;
                    }

                    for (int j = 0; j <= need; j++) {
                        if (j < start) {
                            ;
                        }
                        else {
                            temp2.push(make_pair(rights[j] + s, need - j));
                        }
                    }
                }
            }
            temp.swap(temp2);
        }
        while (!temp.empty()) {
            int need = temp.front().second;
            string s = temp.front().first;
            temp.pop();
            if (need == 0) {
                ans.push_back( s);
            }
        }
        return ans;
    }
};