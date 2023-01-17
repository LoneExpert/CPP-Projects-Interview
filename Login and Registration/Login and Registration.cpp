#include<iostream>
#include<string>
#include<fstream>
using namespace std;

bool loggedin(){

    string username,password,name,pass;
    cout<<"Enter the username"<<endl;
    cin>>username;
    cout<<"Enter the password"<<endl;
    cin>>password;

    ifstream read("data\\"+username+".txt");
    getline(read,name);
    getline(read,pass);

    if(name==username && pass==password){
        return true;
    }
    else{
        return false;
    }
}

int main(){

    int choice;
    cout<<"1: Register\n2: Login\nYour Choice: "<<endl;
    cin>>choice;
    if(choice==1){
        string username, password;
        cout<<"Select a username: "<<endl;
        cin>>username;
        cout<<"Select a password: "<<endl;
        cin>>password;

        ofstream file;
        file.open("data\\" + username+".txt");
        file<<username<<endl<<password;
        file.close();

        main();
    }
    else if(choice==2){

        bool status = loggedin();

        if(!status){
            cout<<"False logged"<<endl;
            system("PAUSE");
            return 0;
        }
        else{
            cout<<"Success logged in"<<endl;
            system("PAUSE");
            return 1;

        }
    }
}
