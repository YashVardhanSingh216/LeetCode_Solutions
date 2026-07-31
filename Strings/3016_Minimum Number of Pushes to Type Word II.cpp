class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        cout<<"Size of word: "<<n<<endl;

        // counting  the frequency
        unordered_map<char,int>mp;
        for(int i=0; i<n; i++){
            mp[word[i]]++;
        }


        vector<int>p;
        for(int i=0; i<n; i++){
            p.push_back(int(word[i]));
        }
        sort(p.begin(),p.end());

        string new_word = "";
        for(int i=0; i<p.size(); i++){
            new_word += char(p[i]);
        }
        cout<<"New Word: "<<new_word<<endl;


        string s = "";

        for(int i=0; i<n; i++){

            if(s.size() == 0 || s.back() != new_word[i])
            s += new_word[i];
        }
        cout<<s<<endl;
        cout<<"Size of new string: "<<s.size()<<endl;

        vector<pair<char,int>>temp;

        for(int i=0; i<s.size(); i++){
            temp.push_back({s[i],mp[s[i]]});
        }
        for(int i=0; i<s.size(); i++){
            cout<<"{"<<temp[i].first<<","<<temp[i].second<<"}"<<" ";
        }
        cout<<endl;
        sort(temp.begin(), temp.end(), []( pair<char,int>a , pair<char,int>b){
            return a.second > b.second;
        });
        for(int i=0; i<s.size(); i++){
            cout<<"{"<<temp[i].first<<","<<temp[i].second<<"}"<<" ";
        }

        // int result = 0;
        // if(temp.size() <= 8){
        //     result += 
        // }

        string new_s = "";

        for(int i=0; i<temp.size(); i++){
            new_s += temp[i].first;
        }
        cout<<endl<<"Newest string: "<<new_s<<endl;
        cout<<endl<<"Size of Newest string: "<<new_s.size()<<endl;

        int ans = 0;

        for(int i=0; i<new_s.size(); i++){
            ans += ((i/8)*mp[new_s[i]] + mp[new_s[i]]);
            cout<<ans<<" ";
        }
        cout<<endl<<ans<<endl;



        return ans;


    }
};
