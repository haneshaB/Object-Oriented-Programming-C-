#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Box{
    T data;
    int weight;
    public:
    Box(T d,int w){
        data=d;
        weight=w;
    }
};

template <typename T>
class Storage{
    stack<Box<T>> st;
    int size;
    public:
        storage(){
            size=0;
        }
        void push(T item, int weight) {
            Box<T> b(item,weight);
            st.push(b);
            size++;
        }

        Box<T> pop(){
            if(size==0){

            }else{
                Box<T> top=st.top();
                st.pop();
                return top;
            }
        }

        int currentSize(){
            return size;
        }
};
template <typename T>
class Warehouse{
    private:
        int maxCapacity;
        int maxWeight;
        int currentEnergy;
        int currentWeight;
    public:
        Warehouse(int cap,int mw,int ce){
            maxCapacity=cap;
            maxWeight=mw;
            currentEnergy=ce;
            currentWeight=0;
        }
        void dispatch(){

        }
        void bulkDispatch(int k){
        
        }
};
int main(){
    
}