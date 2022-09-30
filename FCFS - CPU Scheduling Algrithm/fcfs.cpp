#include <iostream>

using namespace std;

class Process{
  
  public:
    int id;
    float AT; // Arrival Time
    float BT; // Brust Time
    float CT; // Completion Time
    float TAT; // Turn Around Time
    float WT;  // Waiting Time
};

// Sort the process based on their arrival time
void sortByAT(Process p[], int n){
    for(int i = 0 ; i < n; i++){
    Process temp;
    for(int j = 0; j < n; j++){
      if(p[i].AT < p[j].AT){
        temp = p[i];
        p[i] = p[j];
        p[j] = temp;
      }
    }
  }
}

// Sort the processes from s to n having AT less than CT
void sortByID(Process p[], int s, int n, float CT){
  for(int i = s ; i < n; i++){
    Process temp;
    for(int j = s; j < n; j++){
      if( CT > p[i].AT && CT > p[j].AT && p[i].id < p[j].id){
        temp = p[i];
        p[i] = p[j];
        p[j] = temp;
      }
    }
  }
}

int main(){
  int n;
  cout << "Enter the number of process: " << endl;
  cin >> n;
  
  Process p[n];
  
  for(int i = 0; i < n; i++){
    cout << "Enter the Process ID: " << endl;
    cin >> p[i].id;
    cout << "Enter the Arrival Time :" << endl;
    cin >> p[i].AT;
    cout << "Enter the Burst Time :" << endl;
    cin >> p[i].BT;
  }
  
  sortByAT(p,n);
  
  cout << "ID" << "\t" << "AT" << "\t" << "BT" << "\t" <<"CT" << "\t" << "TAT" << "\t" << "WT" << endl;
  for(int i = 0; i < n; i++){
    if(i == 0){
      p[i].CT = p[i].AT + p[i].BT;
    }else if(p[i-1].CT > p[i].AT){
      sortByID(p,i,n,p[i-1].CT);
      p[i].CT = p[i - 1].CT + p[i].BT;
    }else{
      p[i].CT = p[i].AT + p[i].BT;
    }
    p[i].TAT = p[i].CT - p[i].AT;
    p[i].WT = p[i].TAT - p[i].BT;
    cout << p[i].id << "\t" << p[i].AT << "\t" << p[i].BT << "\t" << p[i].CT << "\t" << p[i].TAT << "\t" << p[i].WT <<endl;
  }

  float totalTurnAroundTime = 0;
  float totalWaitingTime = 0;
  for(int i =0; i < n; i++){
    totalTurnAroundTime += p[i].TAT;
    totalWaitingTime += p[i].WT;
  }

  cout << "Average Turn Around time is:- " << totalTurnAroundTime/n << endl;
  cout << "Average Turn Waiting time is:- " << totalWaitingTime/n << endl;
}