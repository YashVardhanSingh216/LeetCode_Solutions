// 2409. Count Days Spent Together

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
        unordered_map<string,int>mp;
        mp["01"] = 0;
        mp["02"] = 31;
        mp["03"] = 59;
        mp["04"] = 90;
        mp["05"] = 120;
        mp["06"] = 151;
        mp["07"] = 181;
        mp["08"] = 212;
        mp["09"] = 243;
        mp["10"] = 273;
        mp["11"] = 304;
        mp["12"] = 334;

        // cout<<"ALICE ARRIVED: "<<endl;
        int alice_arrive = mp[arriveAlice.substr(0,2)] + stoi(arriveAlice.substr(3,5)); 
        cout<<alice_arrive<<endl;
        
        // cout<<"ALICE LEAVE: "<<endl;
        int alice_left = mp[leaveAlice.substr(0,2)] + stoi(leaveAlice.substr(3,5));
        cout<<alice_left<<endl;
        
        /// day,present(bool)
        // unordered_map<int,bool>alice;
        // for(int a = alice_arrive; a<= alice_left; a++){
        //     alice[a] = 1;
        // }

        // cout<<"BOB ARRIVED: "<<endl;
        int bob_arrive = mp[arriveBob.substr(0,2)] + stoi(arriveBob.substr(3,5));
        cout<<bob_arrive<<endl;
        
        cout<<"BOB LEAVE: "<<endl;
        int bob_left = mp[leaveBob.substr(0,2)] + stoi(leaveBob.substr(3,5)); 
        cout<<bob_left<<endl;
        
        /// day,present(bool)
        // unordered_map<int,bool>bob;
        // for(int b = bob_arrive; b<= bob_left; b++){
        //     bob[b] = 1;
        // }
        
        int count = 0;
        // for(int i=1; i<=365; i++){

        //     if(alice[i] == 1 && bob[i] == 1){
        //         count++;
        //     }
        // }
        int start = max(alice_arrive,bob_arrive);
        int end = min(alice_left,bob_left);

        count = max(0,end-start+1);
        return count;
    }
};
