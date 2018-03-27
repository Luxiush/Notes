/**
## leetcode longest-valid-parentheses
### 题目
给一个仅包含'('和')'的字符串，求其左右括号相匹配的最长子串的长度

### 思路
去掉字符串中合法的序列，得到一个断点序列求各个断点之间的最长距离

**/

    int longestValidParentheses(string s) {
        stack<int> S;
        for(int i=0; i<s.size(); ++i){
            if(!S.empty()&&s[S.top()]=='('&&s[i]==')'){
                S.pop();
            }
            else{
                S.push(i);
            }
        }
        int last = s.size();
        int res = 0;
        while(!S.empty()){
            if(last-S.top()-1>res)
                res = last-S.top()-1;
            last = S.top();
            S.pop();
        }
        if(res<last-(-1)-1) res = last;

        return res;
    }
