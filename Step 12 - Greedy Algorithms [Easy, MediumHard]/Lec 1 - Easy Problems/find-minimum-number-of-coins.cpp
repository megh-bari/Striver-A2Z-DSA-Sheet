vector<int> minPartition(int N) {
    
    vector<int> denomination = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    
    vector<int> result; 

   
    for (int i = 0; i < denomination.size(); i++) {
        while (N >= denomination[i]) { 
            N -= denomination[i];  
            result.push_back(denomination[i]); 
        }
    }
    
    return result;
}