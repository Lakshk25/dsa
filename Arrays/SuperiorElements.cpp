vector<int> superiorElements(vector<int>&a) {
    vector<int>ans;

    int num = 0;

    for(int i=a.size()-1; i>=0; i--){
        if(num < a[i]){
            ans.push_back(a[i]);
            num = a[i];
        }
    }
    return ans;
}