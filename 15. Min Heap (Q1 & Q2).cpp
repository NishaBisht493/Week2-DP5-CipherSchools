#include<bits/stdc++.h>
using namespace std;

class MinHeap{
    int capacity;
    int size;
    int *heap;

    int parent(int index){
        return (index - 1) / 2;
    }

    int leftChild(int index){
        return (2 * index + 1);
    }

    int rightChild(int index){
        return (2 * index + 2);
    }

    void minHeapify(int index){
        int smallest = index;
        int l = leftChild(index), r = rightChild(index);
        if(l < this->size && this->heap[index] > this->heap[l]){
            smallest = l;
        }

        if(r < this->size && this->heap[index] > this->heap[r]){
            smallest = r;
        }

        if(smallest != index){
            swap(this->heap[index], this->heap[smallest]);
            minHeapify(smallest);
        }
    }

    public:
    MinHeap(int capacity){
        this->capacity = capacity;
        this->size = 0;
        this->heap = new int[this->capacity];
    }

    void push(int key){
        if(this->size == this->capacity){
            return;
        }
        this->size++;
        int index = this->size - 1;
        this->heap[index] = key;

        while(index != 0 && this->heap[index] < this->heap[parent(index)]){
            swap(this->heap[index], this->heap[parent(index)]);
            index = parent(index);
        }
    }

    int top(){
        return this->size == 0 ? -1 : this->heap[0];
    }

    void pop(){
        if(this->size == 0){
            return;
        }
        if(this->size == 1){
            this->size--;
            return;
        }
        swap(this->heap[0], this->heap[this->size - 1]);
        this->size = this->size - 1;
        minHeapify(0);
    }
};

int main(){

}