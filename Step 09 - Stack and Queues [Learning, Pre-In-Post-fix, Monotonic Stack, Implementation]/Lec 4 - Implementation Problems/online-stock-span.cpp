// brute 
class StockSpanner {
    public:
            vector<int> arr;
        StockSpanner() {
        }
        
        int next(int price) {
            arr.push_back(price);
            int cnt = 1;
            int n = arr.size();
            for(int i=n-2; i>=0; i--){
                if(arr[i]<=price) cnt ++;
                else break;
            }
            return cnt;
        }
    };

    
// optimal

#include <stack>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> st;
    int ind = -1;
    
    StockSpanner() {}

    int next(int price) {
        ind += 1;
        int ans;
        
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }
        
        ans = ind - (st.empty() ? -1 : st.top().second);
        st.push({price, ind}); 

        return ans;
    }
};
