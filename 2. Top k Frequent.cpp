#include<bits/stdc++.h>
using namespace std;

class comparator{
    public:
    bool operator()(const pair<int, int> &a, pair<int, int> &b){
        return a.second > b.second;
    }
};

vector<int> topKFrequent(vector<int> &vec, int K){
    unordered_map<int, int> hash;
    for(int i = 0; i < vec.size(); i++){
        hash[vec[i]]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;

    for(auto itr = hash.begin(); itr != hash.end(); itr++){
        if(pq.size() < K){
            pq.push(pair<int, int>{itr->first, itr->second});
        }
        else{
            if(pq.top().second < itr->second){
                pq.pop();
                pq.push(pair<int, int>{itr->first, itr->second});
            }    
        }
    }    

    vector<int> result(K);
    int i = 0;
    while(!pq.empty()){
        result[i++] = pq.top().first;
        pq.pop();
    }

    return result;
}

int main(){

}