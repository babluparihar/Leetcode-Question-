class Solution {
public:
    string removeDigit(string number, char digit) {
        vector<string>vec;
        for(int i=0;i<number.size();i++)
        {
            if(number[i]==digit)
            {
                string s=number.substr(0,i)+number.substr(i+1);
                vec.push_back(s);
            }
        }
        sort(vec.rbegin(),vec.rend());
        return vec[0];
    }
};