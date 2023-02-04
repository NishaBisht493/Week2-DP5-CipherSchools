#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &S, int x){
    if(S.empty()){
        S.push(x);
    }
    else{
        int temp = S.top();
        S.pop();
        insertAtBottom(S, x);
        S.push(temp);
    }
}

void reverse(stack<int> &S){
    if(S.empty()){
        return;
    }
    else{
        int temp = S.top();
        S.pop();
        reverse(S);
        insertAtBottom(S, temp);
    }
}

int main(){

}