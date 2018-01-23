/**
## 纸牌翻转 HDU 2209
### 题目
给定一个01序列表示每张牌的正(0)反(1). 每翻转一张牌其左右的两张也会跟着翻转, 问能否将至少需要翻转多少次才能使所有的牌都正面朝上,不能则输出'No'.

### 思路
- 每次翻转只考虑最左边的牌, 从左往右扫, 如果第i张为1, 则翻转第i+1张.
- 分第1张牌翻转和不翻转两种情况. <http://blog.csdn.net/lawk97/article/details/52853038>

1011001 -> 0111001 -> 0000001
        -> 0101001 -> 0010001 -> 0001101 -> 0000011 -> 0000000

1111 -> 0011 -> 0000
     -> 0001

0101 -> 0010 -> 0001
     -> 1001 -> 0111 -> 0000

**/

#include <iostream>
#include <string>

using namespace std;

const int INF = 0x7fffff00;

void _ReverseBit(char &ch){
    if(ch == '0') ch = '1';
    else if(ch == '1') ch = '0';
}

void ReversePos(string &seq, int i)
{
    if(i<0 || i>seq.length()-1) return;
    _ReverseBit(seq[i]);
    if(i > 0) _ReverseBit(seq[i-1]);
    if(i < seq.length()-1) _ReverseBit(seq[i+1]);
}


int PokerReverse(string seq)
{
    int len = seq.length();
    int count = 0;
    for(int i = 0; i < len-1; i++){
        if(seq[i] == '1'){
            ReversePos(seq, i+1);
            count += 1;
        }
    }
    if(seq[len-1] == '1') count = INF;
    // cout << seq << endl;
    return count;
}


int main()
{
    string seq;
    while(cin >> seq){
        int res1 = PokerReverse(seq);
        // cout << "res1 " << res1 << endl;
        /* WA
        if(seq[0]=='1'){
            ReversePos(seq, 0);
            int res2 = PokerReverse(seq.substr(1))+1;
            // cout << "res2 " << res2 << endl;
            if(res2 < res1) res1 = res2;
        }
        */
        ReversePos(seq, 0);
        int res2 = PokerReverse(seq)+1;
        if(res2 < res1) res1 = res2;

        if(res1 >= INF) cout << "NO" << endl;
        else cout << res1 << endl;
    }

    return 0;
}
