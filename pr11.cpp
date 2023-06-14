#include<iostream>
#include<fstream>
using namespace std;
class Student{
    public:
    char name[20];
    int roll;
    char div;
    char add[20];

    void get(){
        cout<<"\nEnter name - ";
        cin>>name;
        cout<<"Enter roll no - ";
        cin>>roll;
        cout<<"Enter division - ";
        cin>>div;
        cout<<"Enter address - ";
        cin>>add;
    }

    void put(){
        cout<<"\n\nName - "<<name;
        cout<<"\nRoll no - "<<roll;
        cout<<"\nDivision - "<<div;
        cout<<"\nAddress - "<<add;
    }
    int  get_roll(){
        return roll;
    }
};
void write_record(){
    Student obj;
    ofstream file("record.dat", ios::binary | ios::app);
    obj.get();
    file.write((char*)&obj, sizeof(obj));
    file.close();
}

void delete_record(int n)
{
	Student obj;
	ifstream inFile;
	inFile.open("record.dat", ios::binary);
	ofstream outFile;
	outFile.open("temp.dat", ios::binary | ios::app);
	while(inFile.read((char*)&obj, sizeof(obj)))
	{
		if(obj.get_roll() != n)
			outFile.write((char*)&obj, sizeof(obj));
	}
	inFile.close();
	outFile.close();
	remove("record.dat");
	rename("temp.dat", "record.dat");
}

void display_record(){
    Student obj;
    ifstream file("record.dat", ios::binary);
    while (file.read((char*)&obj, sizeof(obj))){
        obj.put();
    }
    file.close();
}

void search_record(int n){
	ifstream inFile;
	Student obj;
	inFile.open("record.dat", ios::binary | ios::app);
	while(inFile.read((char*)&obj, sizeof(obj))){
		if(obj.get_roll() != n)
			continue;
        else
            obj.put();
	}
	inFile.close();
}
int  main(){
    int ch,n,roll;
    while(1){
        cout<<"\n\n1. Enter data";
        cout<<"\n2. Delete data";
        cout<<"\n3. Display data";
        cout<<"\n4. Search data";
        cout<<"\n5. Exit";
        cout<<"\nEnter choice - ";
        cin>>ch;
        switch (ch)
        {
        case 1: cout<<"Enter no of records - ";
                    cin>>n;
                    for( int i=0; i<n ; i++){
                        write_record();
                    }
            break;
        case 2: cout<<"Enter roll no  - ";
                    cin>>roll;
                    delete_record(n);
            break;
        case 3: display_record();
            break;
        case 4: cout<<"Enter roll no - ";
                    cin>>roll;
                    search_record(n);
            break;
        case 5: exit(1);
            break;
        default: cout<<"Invalid choice !";
            break;
        }
    }
}