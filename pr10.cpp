#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<string> pt;
    queue<string> pr;
    string name;
    int n,ch,p;
    while(1){
        cout<<"\n1. Add patient";
        cout<<"\n2. Show patients";
        cout<<"\n3. Exit";
        cout<<"\nEnter your choice - ";
        cin>>ch;
        switch (ch)
        {
        case 1: cout<<"Enter no of patients - ";
                    cin>>n;
                    for (int i=0; i<n; i++){
                        cout<<"\nEnter name of patient - ";
                        cin>>name;
                        pt.push(name);
                        cout<<"( 1-Serious; 2-Non Serious; 3-General checkup )";
                        cout<<"\nEnter priority  - ";
                        cin>>p;
                        switch (p)
                        {
                        case 1:
                            pr.push("SERIOUS");
                            break;
                        case 2:
                            pr.push("NON-SERIOUS");
                            break;
                        case 3:
                            pr.push("CHECKUP");
                            break;
                        default:
                            break;
                        }
                    }
            break;
        case 2 : if(pt.empty())
                        cout<<"\nQueue is empty !\n";
                    else
                        while(!pt.empty()){
                            cout<<"\nPatient name : "<<pt.front();
                            // pt.pop();
                            cout<<"  -  "<<pr.front();
                            // pr.pop();
                        }
                        cout<<"\n";
            break;
        case 3: exit(1);
        default: cout<<"\nInvalid choice !\n\n";
            break;
        }
    }
}
