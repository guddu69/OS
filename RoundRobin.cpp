#include<iostream>
using namespace std;
void print(int i, int at[], int bt[], int ct){
    int tat=ct-at[i];
    int wt=tat-bt[i];
    cout<<"P"<<i+1<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<tat<<"\t"<<wt<<"\t"<<ct<<endl;
}
int main(){
    int ct=0,nop,tq,i;
    int total_wt=0,total_tat=0;
    cout<<"Enter number of processes(NOP): ";
    cin>>nop;
    int at[nop],bt[nop],rt[nop];
    int count=nop;
    
    cout<<"Enter time quantum: ";
    cin>>tq;
    cout<<"Enter Arival time(AT) & Brust time(BT) of processes: ";
    for(i=0;i<nop;i++){
        cin>>at[i];
        cin>>bt[i];
 
        rt[i]=bt[i];  //remaining time = brust time at start
    }
    cout<<"ID\tAT\tBT\tTAT\tWt\tCT"<<endl;
    for(i=0;count!=0;){ //until count(processes) not equal to 0
        if(rt[i]<=tq && rt[i]>0){
            ct=ct+rt[i];
            rt[i]=0;
            count--;
            print(i,at,bt,ct);
            int tat=ct-at[i];
            int wt=tat-bt[i];
            total_tat=total_tat+tat;
            total_wt=total_wt+wt;
        }
        else if(rt[i]>0){
            rt[i]=rt[i]-tq;
            ct=ct+tq;
        }
        if(i==nop-1){
            i=0;
        }
        else if(at[i+1]<=ct){
            i++;
        }
        else{
            i=0;
        }
    }
    cout<<"Average TAT: "<<(float)total_tat/nop<<endl;
    cout<<"Average WT: "<<(float)total_wt/nop<<endl;
}