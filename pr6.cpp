#include<iostream>
using namespace std;
int main(){
    int n,i,j;
    int mat[20][20] = {0,0};
    cout<<"Enter no of cities - ";
    cin>>n;
    string city[n];
    for(i=0; i<n; i++){
        cout<<"Enter city "<<i+1<<" name - ";
        cin>>city[i];
    }
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            cout<<"Enter time between "<<city[i]<<" & "<<city[j]<<" - ";
            cin>>mat[i][j];
            mat[j][i] = mat[i][j];
        }
    }
    cout<<"\n---- Adjancency Matrix ----- \n\n";
    for(i=0; i<n; i++){
        cout<<"\t\t"<<city[i];
    }
    cout<<"\n";
    for (i=0; i<n; i++){
        cout<<city[i];
        for(j=0; j<n; j++){
            cout<<"\t\t"<<mat[i][j];
        }
        cout<<"\n";
    }

    cout<<"\n---- Adjancency List ----- \n\n";
    for (i=0; i<n; i++){
        cout<<city[i];
        for(j=0; j<n; j++){
            if(mat[i][j] == 0)
                continue;
            cout<<"->"<<city[j];
        }
        cout<<"\n";
    }
    cout<<"\n\n";
}