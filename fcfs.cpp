// fcfs
#include<iostream>
using namespace std;
void find_wt(int bt[],int wt[],int size){
    wt[0]=0;
    for(int i=1;i<size;i++)
    wt[i]=wt[i-1]+bt[i-1];
}
void find_tat(int bt[] ,int wt[],int tat[],int size){
    for(int i=0;i<size;i++)
    tat[i]=wt[i]+bt[i];
}
void fcfs(int arr[], int bt[], int size){
    int wt[size],tat[size];
    int total_wt=0,total_tat=0;
    find_wt(bt,wt,size);
    find_tat(bt,wt,tat,size);

    cout<<"ID \t BT \t WT \t TAT"<<endl;
    for(int i=0; i<size; i++){
        total_tat=total_tat+tat[i];
        total_wt=total_wt+wt[i];

        cout<<" "<<(i+1);
        cout<<" \t"<<bt[i];
        cout<<" \t"<<wt[i];
        cout<<" \t"<<tat[i]<<endl;
    }
    cout<<"Averege WT: "<<((float)total_wt/size)<<endl;
    cout<<"Averege TAT: "<<((float)total_tat/size)<<endl;
}
int main(){
    int size,i;
    cout<<"Enter number of proccesses: ";
    cin>>size;
    int arr[size], bt[size];
    cout<<"Enter the ID of each process: ";
    for(i=0;i<size;i++)
        cin>>arr[i];
    cout<<"Enter the burst time of each process: ";
    for(i=0;i<size;i++)
        cin>>bt[i];

    fcfs(arr,bt,size);
    return 0;
}