#include<bits/stdc++.h>
using namespace std;



int totalCombinations(vector<int>&dice1, vector<int>dice2){
    
    return dice1.size()*dice2.size();
}

void generateCombinationDistribution(vector<int>&diceA, vector<int>diceB) {
    vector<vector<int>>combinationsDistribution(diceA.size(),vector<int>(diceA.size(),0));
    for(int i =0;i<diceA.size();i++){
        for(int j=0;j<diceA.size();j++){
            combinationsDistribution[i][j] = diceA[i]+diceB[j];
        }
    }
    cout<<"Combinations Distribution:"<<endl;
    for(int i =0;i<diceA.size();i++){
        for(int j =0;j<diceA.size();j++){
            cout<<combinationsDistribution[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

void probabiltyAllSum(vector<int>&diceA, vector<int>diceB){
    map<int,int> mp;
    for(int i =1;i<=diceA.size();i++){
        for(int j =1;j<=diceB.size();j++){
            mp[i+j]++;
        }
    }
    for(auto x: mp){
        cout<<"P(Sum = " << x.first << ") = " << x.second << "/36"<<endl;
    }
}

int main(){
    vector<int>diceA = {1,2,3,4,5,6};
    vector<int>diceB = {1,2,3,4,5,6};
    cout<<"The total number of combinations are: "<<totalCombinations(diceA,diceB)<<endl;
    generateCombinationDistribution(diceA,diceB);
    cout<<"The probability of all the sums are: "<<endl;
    probabiltyAllSum(diceA,diceB);
    return 0;
    
}