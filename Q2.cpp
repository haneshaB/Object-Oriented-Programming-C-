#include <bits/stdc++.h>
using namespace std;

template <typename T> 
vector<T> filterGreater(const vector<T>& data, T threshold){
    vector<T> val;
    for(auto v:data){
        if(v>threshold){
            val.push_back(v);
        }
    }
    return val;
}

class Service{
public:
    virtual double calculateCost() const = 0;
};

class HourlyService: public Service{
public:
    double rate,hours;
    HourlyService(double r,double h){
        rate=r;
        hours=h;
    }

    double calculateCost() const override{
        return rate*hours;
    }
};

class ProjectService: public Service{
public:
    double fee,materials;
    ProjectService(double x,double y){
        fee=x;
        materials=y;
    }
    double calculateCost() const override{
        return fee+materials;
    }
};

double calculateTotalBill(const vector<Service*>&services){
    double sum=0;
    for(int i=0;i<services.size();i++){
        sum+=services[i]->calculateCost();
    }
    return sum;
}

vector<int> findValleys(const vector<int>& elevations){
    vector<int> x;
    for(int i=1;i<elevations.size()-1;i++){
        if(elevations[i]<elevations[i-1] && elevations[i]<elevations[i+1]){
            x.push_back(elevations[i]);
        }
    }
    return x;
}

//////////////////////////////////////////////////////////
// FIXED COLLISION FUNCTION (STACK-BASED)
//////////////////////////////////////////////////////////
vector<int> collideParticles(const vector<int>& particles){
    vector<int> st;

    for(int p : particles){
        bool destroyed = false;

        while(!st.empty() && st.back() > 0 && p < 0){
            if(abs(p) > abs(st.back())){
                st.pop_back();       // previous destroyed
                continue;
            }
            else if(abs(p) == abs(st.back())){
                st.pop_back();       // both destroyed
                destroyed = true;
                break;
            }
            else{
                destroyed = true;    // current destroyed
                break;
            }
        }

        if(!destroyed){
            st.push_back(p);
        }
    }

    return st;
}

//////////////////////////////////////////////////////////

int main(){
    int choice;
    while(cin>>choice){
        if(choice==5){
            break;
        }

        if(choice==1){
            int n;
            cin>>n;
            vector<double> arr(n);
            for(int i=0;i<n;i++){
                cin>>arr[i];
            }
            double threshold;
            cin>>threshold;

            vector<double> x=filterGreater(arr,threshold);
            for(int i=0;i<x.size();i++){
                cout<<x[i]<<" ";
            }
            cout<<endl;
        }

        else if(choice==2){
            int n;  
            cin>>n;
            vector<Service*> serve;

            for(int i=0;i<n;i++){
                int type;
                cin>>type;
                Service* x;

                if(type==1){
                    double rate,hour;
                    cin>>rate>>hour;
                    x=new HourlyService(rate,hour);
                }
                else{
                    double fee,material;
                    cin>>fee>>material;
                    x=new ProjectService(fee,material);
                }
                serve.push_back(x);
            }   

            double sum=calculateTotalBill(serve);
            cout<<sum<<endl;

            // cleanup
            for(auto s:serve) delete s;
        }

        else if(choice==3){
            int n;
            cin>>n;
            vector<int> depth(n);
            for(int i=0;i<n;i++){
                cin>>depth[i];
            }

            vector<int> valley=findValleys(depth);
            for(int i=0;i<valley.size();i++){
                cout<<valley[i]<<" ";
            }
            cout<<endl;
        }

        else if(choice==4){
            int n;
            cin>>n;
            vector<int> x(n);
            for(int i=0;i<n;i++){
                cin>>x[i];
            }

            vector<int> final=collideParticles(x);
            for(int i=0;i<final.size();i++){
                cout<<final[i]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}