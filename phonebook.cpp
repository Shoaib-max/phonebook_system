#include<iostream>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<bits/stdc++.h>
#include<string>
using namespace std;
// using system;

void addnumber();
void displayrecord();
void deleterecord();
void modifyrecord();
void searchrecord();

class phonebook{
    private:

    int srno;
    char name[30];
    char mobileno[30];
    char emailid[30];

    public: 
    int getsrno(){
        return srno; 

    }
    void storedata(){

        cout<<"\n                              ....................................................\n";
                                    cout<<"\n    ......    creating phone data      ................. \n";
        cout<<"\n        ...........................................................................\n"; 

        cout<<"enter serial number :";
        cin>>srno;
        cin.ignore();

        cout<<"\n enter the record name :";
        cin.getline(name,30);

        cout<<"\n entre the email for record :";
        cin.getline(emailid,30);

         cout<<"\n entre the mobile for record :";
         cin.getline(mobileno,30);                            
    }
    void showdata(){
        cout<<"\n                   ............... showing record data .................. \n ";
        cout<<"srno is :"<<srno;
        cout<<endl;
        cout<<"name is :"<<name;
        cout<<endl;
        cout<<"mobileno is :"<<mobileno;
        cout<<endl;
        cout<<"emailid is :"<<emailid<<endl;
    }

}b;

int main(){
    cout<<" :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
        cout<<"        :::::::::::::::::::::: Phonebook systems ::::::::::::::::::::::::::::::\n";
        cout<<".................********************************...............................\n";
           int ch;
           do{
        cout<<"\n                                        0.Exit \n";
        cout<<"\n                                        1.Save Record \n";
        cout<<"\n                                        2.display all existing  Record \n";
        cout<<"\n                                        3.delete Record \n";
        cout<<"\n                                        4.modify Record \n";
        cout<<"\n                                        5.search record \n";
        cout<<"\n                                          enter your choice :";
        cin>>ch;
        switch(ch){
            case 0:
            break;
            case 1:
            system("color 9");
            addnumber();
            break;
            case 2:
            system("color 0d");
            displayrecord(); 
            break;
            case 3:
            system("color 4");
            deleterecord();
            break;
            case 4:
            modifyrecord();
            break;
            case 5:
            searchrecord();
            break; 
        }
        }while(ch);
        return 0;
}
void addnumber(){
    ofstream out;
    out.open("phone.txt",ios::in | ios:: binary | ios:: app);
    b.storedata();
    out.write((char*) &b,sizeof(b));
//    out<<"\n";
    out.close();
    cout<<"\n record saved in file \n";
}
void displayrecord(){
    ifstream fin;
    fin.open("phone.txt",ios::out | ios::binary | ios::app);
    while(fin.read((char*)&b,sizeof(b))){
        b.showdata();
        //system("pause");
    }
    fin.close();
    cout<<"\n record displayed successfully \n";
}
void searchrecord(){
    int n,flag=0;
    fstream fin;
    fin.open("phone.txt",ios::out | ios::binary | ios::app);
    cout<<"\n enter serial number to search record :";
    cin>>n;
    fin.seekg(0);
    while(fin){
        if(n==b.getsrno()){
            b.showdata();
            flag++;
            cout<<"\n record search successfully: ";
        }
        fin.close();
        if(flag==0)
        cout<<"\n no search item found ";
    }
    //fin.close();
}
void modifyrecord(){
    int n,flag=0,pos;
    fstream fin;
    fin.open("phone.txt",ios::out | ios::binary | ios::in);
    cout<<"\n enter data of serial no to  be modified :";
    cin>>n;
    while(fin){

        pos=fin.tellg();
        if(n==b.getsrno()){
            cout<<"\n deleted item is ";
            b.showdata();
            flag++;
            cout<<"\n enter the new details: ";
            b.storedata();
            fin.seekg(pos-sizeof(b));
            fin.write((char*)&b,sizeof(b));
            cout<<"\n modified successfully ";
        }

    }
    fin.close();
    if(flag==0)
    cout<<"\n no data found \n";
    
}


void deleterecord(){
    int n;
    int flag=0;
//
//    ifstream fin;
//    ofstream fout;
fstream  file,temp;

    file.open("phone.txt",ios::in | ios::binary | ios::out);
    temp.open("temp.txt",ios::out | ios:: binary);

    cout<<"\n enter the serial no to delete the record :";
    cin>>n;
    while(file.read((char*)&b,sizeof(b))){
        
        if(n==b.getsrno()){
            cout<<"\n deleted data is : \n";
            b.showdata();
            flag++;
            
        }
        else { 
//        	fout.read((char*)&b,sizeof(b));
            temp.write((char*)&b,sizeof(b));
        }
        

        cout<<"\n data deleted record :\n ";
     
          
    }
    file.close();
        temp.close();
 	remove("phone.txt");
    rename("temp.txt","phone.txt");
}

