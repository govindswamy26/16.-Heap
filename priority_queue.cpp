#include <bits/stdc++.h>

using namespace std;

int main(){

    // priority_queue<int,vector<int>,greater<int>>pq;

    // pq.push(1);
    // pq.push(4);
    // pq.push(9);
    // pq.push(1000);
    // pq.push(898);
    // cout<<"size : ";
    // cout<<pq.size()<<endl;
    // while(pq.empty() == false){
    //     cout<<pq.top();
    //     pq.pop();
    //     cout<<endl;
    // }

    vector<int>arr = {13,1,45,2,54,134,235,89};
    priority_queue<int,vector<int>,greater<int>>pq(arr.begin(),arr.end());
    while(pq.empty() == false){
        cout<<pq.top()<<endl;
        pq.pop();
    }
}