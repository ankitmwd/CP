#include <bits/stdc++.h>
using namespace std;
pair<long long,string> MaximumGainSubstring(string str,vector<int> values){
    int n=str.size();
    stack<int> left;
    vector<int> posl(n);
    for(int i=0;i<n;i++){
        while(left.size()&&str[left.top()]>=str[i]) left.pop();
        posl[i]=(left.size()?left.top():-1);
        left.push(i);
    }
    stack<int> right;
    vector<int> posr(n);
    for(int i=n-1;i>=0;i--){
        while(right.size()&&str[right.top()]>=str[i]) right.pop();
        posr[i]=(right.size()?right.top():n);
        right.push(i);
    }
    vector<long long> pref(n);
    pref[0]=values[str[0]-'a'];
    for(int i=1;i<n;i++){
        pref[i]=pref[i-1]+values[str[i]-'a'];
    }
    long long res=0;
    int leftpos=-1,rightpos=n;
    for(int i=0;i<n;i++){
        long long currleft=(posl[i]==-1?0:pref[posl[i]]);
        long long currright=pref[posr[i]-1];
        long long diff=currright-currleft;
        if(diff*(str[i]-'a'+1)>res){
            res=diff*(str[i]-'a'+1);
            leftpos=posl[i]+1;
            rightpos=posr[i]-1;
        }
    }
    return make_pair(res,str.substr(leftpos,rightpos-leftpos+1));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    {
        string str="vju";
        vector<int> values={2,3,4,4,2,2,1,5,3,5,3,5,3,2,4,3,4,1,1,1,2,1,5,4,1,4};
        pair<long long,string> solution=MaximumGainSubstring(str,values);
        cout<<solution.first<<" "<<solution.second<<"\n";
    }
    return 0;
}