#include<bits/stdc++.h>
using namespace std;
 
#define in         int t; cin>>t; while(t--)
#define ff         first
#define ss         second
#define pb         push_back
#define pp         pop_back
#define mp         make_pair
#define ll         long long
#define Green      ios::sync_with_stdio(false);
#define Apple      cin.tie(NULL);

//Cal u
float uCal(float u, int n){
    float temp = u;
    for(int i=1; i<n; i++){
        temp = temp*(u-i);
    }
    return temp;
}

float bCal(float u, int n){
    float temp = u;
    for(int i=1; i<n; i++){
        temp = temp*(u+i);
    }
    return temp;
}

int fact(int n){
    int a = 1;
    for(int i = 2; i<= n; i++)
        a *= i;
    return a;
}

void forwardk(float sum,int value,int n,float *x, float *point){
    float u = (value - x[0]) / (x[1] - x[0]);
    for (int i = 1; i < n; i++) {
        sum = sum + (uCal(u, i) * (*(point+(i)))) /fact(i);        
    }

    cout<<"\n Value at "<< value << " is "<< sum << endl;
}

void backwardk(float sum,int value, int n, float *x, float *point){
    float u = (value - x[n - 1]) / (x[1] - x[0]);
    for (int i = 1; i < n; i++) {
        sum = sum + (bCal(u, i) * (*(point+(n)*(n - 1)+i))) / fact(i);
    }
 
    cout << "\n Value at " << value << " is "<< sum << endl ;
}


int main()
{ 

int n;
cout<<"Enter No of column in your Data: ";
cin>>n;
float x[n];
float app[n][n];
float bacc[n][n];

cout<<"Insert First Row: "<<endl;
for(int i=0;i<n;i++){
    cout<<i+1<<" -> ";
    cin>>x[i];
}

cout<<"\nInsert Second Row: "<<endl;
for(int i=0;i<n;i++){
    cout<<i+1<<" -> ";
    cin>>app[i][0];
    bacc[i][0]=app[i][0];
}

//Calculating Forward diff table

for(int i=1; i<n; i++){
    for (int j = 0; j < n-i; j++)
    {
        app[j][i] = app[j+1][i-1] - app[j][i-1];
    }
    
}
//Backward Diff table

for(int i=1; i<n;i++){
    for(int j = n-1; j>=i;j--)
        bacc[j][i] = bacc[j][i-1] - bacc[j-1][i-1];
}

// Display Forward
cout<<"\n--------------Forward-----------------------\n";

cout<<"Forward Difference!\n";
for(int i=0; i<n;i++){
    cout<< setw(4) << x[i] <<"\t";

    for(int j=0; j<n-i;j++)
        cout<<setw(4)<<app[i][j]<<"\t";

    cout<<endl;
}

// Display Backward
cout<<"\n--------------Backward-----------------------\n";

cout<<"Backward Difference!\n";
for(int i=0; i<n;i++){
    cout<< setw(4) << x[i] <<"\t";
    for(int j=0; j<=i;j++)
        cout<<setw(4)<<bacc[i][j]<<"\t";
    cout<<endl;
}

int key=1;
while(key){
    cout<<"\n----------------Menu-----------------------\n";

    cout<<"\n1. Calculate Forward Difference";
    cout<<"\n2. Calculate Backward Difference";
    cout<<"\n3. Exit";
    cout<<"\nEnter Choice: ";
    cin>>key;
    cout<<"\n--------------------------------------------\n";

    switch (key)
    {
    case 1:{
        int v,temp;
        cout<<"\nHow Many Values You Want to Interpolate: ";
        cin>>v;
        cout<<"\nEnter Values:"<<endl;
        for(int i=0;i<v;i++){
            cout<<i+1<<" -> ";
            cin>>temp;
            forwardk(app[0][0],temp,n,x,*app);
        }
    }
        break;
    case 2:{
        int v,temp;
        cout<<"\nHow Many Values You Want to Interpolate: ";
        cin>>v;
        cout<<"\nEnter Values:"<<endl;
        for(int i=0;i<v;i++){
            cout<<i+1<<" -> ";
            cin>>temp;
            backwardk(bacc[n-1][0],temp,n,x,*bacc);
        }
    }   
    break;
    case 3:{
        cout<<"\n---------------Green Apple-----------------\n";
        return 0;
    }
    
    default:
        break;
    }

}
return 0;
}