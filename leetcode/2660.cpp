//2660. Determine the Winner of a Bowling Game

class Solution {
public:
    int helper(vector<int> player){
        int k = 0;
        int sum = 0;
        for(int i = 0 ; i < player.size() ;i++){
            if(player[i] == 10){
                sum += player[i];
                k = 2;
                i++;
                while(k-- && i < player.size()){
                    if(player[i] == 10)
                        k = 2;
                    
                    sum += 2 * player[i++];
                }
                i--;
            }
            else
                sum += player[i];
            
        }
        return sum;
    }
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int sum1 = helper(player1);
        int sum2 = helper(player2);
        // cout << sum1 << " " << sum2 << endl;
        if(sum1 == sum2)
            return 0;
        return sum1 > sum2 ? 1:2;

    }
};
