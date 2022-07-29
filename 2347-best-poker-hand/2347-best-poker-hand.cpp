class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        if(count(suits.begin(), suits.end(), suits[0]) ==5)
            return "Flush";
        for(int i=0; i < 5;i++)
            if(count(ranks.begin(), ranks.end(), ranks[i]) >=3)
                return "Three of a Kind";
        for(int i =0; i< 5; i++)
            if(count(ranks.begin(), ranks.end(), ranks[i]) >=2)
                return "Pair";
        return "High Card";
    }
};