struct Item{
    int value;
    int weight;
};

class Solution {
  public:
       static bool comp(Item a, Item b) {
        double a1 = (double)a.value / (double)a.weight;
        double a2 = (double)b.value / (double)b.weight;
        return a1 > a2;
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<Item> items(n);
        
        for (int i = 0; i < n; i++) {
            items[i] = {val[i], wt[i]};
        }

        sort(items.begin(), items.end(), comp);

        double totalVal = 0;
        double curW = 0;

        for (int i = 0; i < n; i++) {
            if (curW + items[i].weight <= capacity) {
                curW += items[i].weight;
                totalVal += items[i].value;
            } else {
                int remain = capacity - curW;
                totalVal += ((double)items[i].value / (double)items[i].weight) * (double)remain;
                break;
            }
        }

        return totalVal;
    }
};
