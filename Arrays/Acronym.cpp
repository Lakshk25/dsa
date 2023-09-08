#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
bool isAcronym(vector<string> &words, string s)
{
    string ans = "";

    for (auto x : words){
        ans.push_back(x[0]);
    }
    if(ans.compare(s) == 0)
        return true;
    
    return false;
}
int main()
{
    vector<string> words = {"never", "gonna", "give", "up", "on", "you"};
    cout<<isAcronym(words, "ngguoy");
}