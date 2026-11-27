/*
LC 3946 - Maximum Number of Items From Sale I
Hours Effort: 01:07:28
*/

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        vector<int> sortQss (items.size(), 0);
        for (int i = 0; i < sortQss.size();i ++) {
            sortQss[i] = i;
        }
        for (int i = 0; i < sortQss.size();i ++) {
            for (int j = i + 1 ; j < sortQss.size() ;j ++) {
                if (items[sortQss[i]][1] > items[sortQss[j]][1]) {
                    int tmp = sortQss[i];
                   sortQss[i] = sortQss[j]; 
                    sortQss[j] = tmp;
                } 
            }
        }
        for (int i = 0; i < sortQss.size() ;i ++) {
            cout<<" "<<sortQss[i];
        }
        cout<<endl;
        int sum = 0;
        int min_idx = INT_MAX;
        int m =  budget / items[sortQss[0]][1];
        for (int i = 0 ; i < sortQss.size(); i++) {
            cout<<"________\n";
            cout<<"sortQss[i]: "<<sortQss[i]<<endl;
            bool sb = false;
            int count_gift = 0;
            for (int j = 0 ; j <  sortQss.size(); j ++) {
                if (i == j) continue;
                if (items[sortQss[j]][0] % items[sortQss[i]][0] == 0){
                    count_gift ++;
                    sb = true;
                }
            }
            cout<<"count_gift: "<<count_gift<<endl;

            if (!sb) continue;
            if (budget - items[sortQss[i]][1] < 0) continue;
            if (i == 0) m = m + count_gift;
            sum =  sum + 1 +  count_gift;

            budget -= items[sortQss[i]][1];
            cout<<"sum: "<<sum<<endl;
            cout<<"budget: "<<budget<<endl;
        }
        cout <<"sum_af_gift: "<<sum<<endl;
        cout <<"min_price_idx: "<<min_idx<<endl;
        while (budget > 0) {
           if (budget - items[sortQss[0]][1] < 0) break;
           sum ++;
           budget -= items[sortQss[0]][1];
           cout<<"budget: "<<budget<<endl;
        }
        return (m > sum) ? m : sum;
    }
};