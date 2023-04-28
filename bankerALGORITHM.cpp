#include<bits/stdc++.h>
using namespace std;
void Calculate();
void Imp();
int allocation[10][3], need[10][3], Max[10][3], available[10][3];
int process,current[3];
bool executed[10],come;
int main(){
    int keep=1;
    cout<<"Enter no of process: ";
    cin>>process;
    cout<<endl;
    cout<<"Enter no of current resources: ";
    cin>>current[0]>>current[1]>>current[2];
    for (int i = 0; i < process; i++)
    {
        cout<<"\n\n\t\t\tProcess P"<<i+1<<"Details\n";
        cout<<"Enter allocation: ";
        cin>>allocation[i][0]>>allocation[i][1]>>allocation[i][2];
        cout<<"Enter max: ";
        cin>>Max[i][0]>>Max[i][1]>>Max[i][2];
        need[i][0]=Max[i][0]-allocation[i][0];
        need[i][1]=Max[i][1]-allocation[i][1];
        need[i][2]=Max[i][2]-allocation[i][2];
    }
    cout<<"\n\n\t\t\t Table\n\n";
    cout<<"Initial Resosurces "<<current[0]<<" "<<current[1]<<" "<<current[2]<<"\n\n";
    cout<<"Process allocation need\n";
    for (int i = 0; i < process; i++)
    {
        cout<<"P"<<i+1<<" ";
        cout<<" "<<"Max"<<" "<<Max[i][0]<<" "<<Max[i][1]<<" "<<Max[i][2];
        cout<<" "<<"Allocation"<<" "<<allocation[i][0]<<" "<<allocation[i][1]<<" "<<allocation[i][2];
        cout<<" "<<"Need"<<" "<<need[i][0]<<" "<<need[i][1]<<" "<<need[i][2];
        cout<<"\n";
    }
    cout<<"\n\n";
    Calculate();
}
void Calculate(){
    Imp();
    int i,j;
    for (int i = 0; i < process; i++)
    {
        for (int j = 0; j< process; j++)
        {
            while(executed[j] && j<process-1){
                j++;
            }
            if(need[j][0]<=current[0] &&need[j][1]<=current[1] &&need[j][2]<=current[2] ){
                if(!executed[j]){
                    executed[j]=true;
                    current[0]+=allocation[j][0];
                    current[1]+=allocation[j][1];
                    current[2]+=allocation[j][2];
                    /*int sum=0;
                    for(int i=0;i<3;i++){
                        sum=sum+current[i];
                    if(sum>30){
                    current[i]==current[i]-1;
                    cout<<"\nprocess p"<<j+1;
                    cout<<"\ncurrent: "<<current[0]<<" "<<current[1]<<" "<<current[2]<<"\n";
                    cout<<"\nprocess executrd without deadlock";
                    come=true;
                    break;
                    }
                    }*/
                    cout<<"\nprocess p"<<j+1;
                    cout<<"\ncurrent: "<<current[0]<<" "<<current[1]<<" "<<current[2]<<"\n";
                    cout<<"\nprocess executrd without deadlock";
                    come=true;
                    break;
                }
            }
        }
        if(!come){
            cout<<"\n\t\tDead lock\n\n";
            break;
        }
        else{
            come=false;
        }
        }
    }
void Imp(){
    come=false;
    for (int i = 0; i < 10; i++)
    {
        executed[i]=false;
    }
    
}
