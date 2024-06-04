#include<iostream>
#include<fstream>
#include<sstream> // provide template and type that enable interoperation between string buffer and string object
#include<string>

using namespace std;

int main() {
    int a, i = 0;
    string text, old, password1, password2, pass, name, password0, age, user, word, word1;
    // creds is used to store credetials information
    // cp is used to store change password
    string creds[2], cp[2];

    cout<<"         Security System "<<endl;
    
    cout<<"______________________________"<<endl<<endl;
    cout<<"|        1. Register         |"<<endl;
    cout<<"|        2. Login            |"<<endl;
    cout<<"|        3. Change Password  |"<<endl;
    cout<<"|________4. End Program______|"<<endl;
    cout<<endl;

    do{
        cout<<endl<<endl;
        cout<<"Enter your choice:- ";
        cin>>a;
        switch(a) {
            case 1: {
                cout<<"_______________________"<<endl;
                cout<<"--------Register-------"<<endl;
                cout<<"_______________________"<<endl;
                cout<<"Please enter username:- ";
                cin>>name;
                cout<<"Please enter password:- ";
                cin>>password0;
                cout<<"Please enter your age:- ";
                cin>> age;

                ofstream of1;
                of1.open("file.txt");
                if(of1.is_open()) {
                    of1<<name<<"\n";
                    of1<<password0<<"\n";
                    of1<<age;
                    cout<<"Registration successfull"<<endl;
                }
                break;
            }
            case 2: {
                i = 0;
                cout<<"_______________________"<<endl;
                cout<<"---------Login---------"<<endl;
                cout<<"_______________________"<<endl;
                // input stream file
                // create input from to some particular file
                ifstream of2;
                of2.open("file.txt");
                cout<<"Please enter the username:- ";
                cin>>user;
                cout<<"Please enter password:- ";
                cin>>pass;

                if(of2.is_open()) {
                    while(!of2.eof()) {
// The getline() function extracts characters from the input stream and appends it to the string object until the delimiting character is encountered.
                        while(getline(of2, text)) {
                            istringstream iss(text);
                            iss>>word;
                            creds[i] = word;
                            i++;
                        }
                        // username will store on 0th pos of creds
                        // password will store on 1st pos of creds
                        if(user == creds[0] && pass == creds[1]) {
                            cout<<"---Login successfull---";
                            cout<<endl;

                            cout<<"Details: "<<endl;
                            cout<<"Username: "+ name<<endl;
                            cout<<"Password: "+ pass<<endl;
                            cout<<"Age: "+ age<<endl;
                        }
                        else {
                            cout<<endl<<endl;
                            // credential is set of unique identifiers - such as username & password 
                            cout<<"Incorrect Credentials"<<endl;
                            cout<<"|     1. Press 2 to Login             |"<<endl;
                            cout<<"|     2. Press 3 to change password   |"<<endl;
                            break;
                        }
                    }
                }
                break;
            }
            case 3: {
                i = 0;
                cout<<"---------------Change Password--------------------"<<endl;
                // ifstream input file stream
                ifstream of0;
                // default value of file open mode is considered depending upon the type of file stream object.
                of0.open("file.txt"); // opened the file
                cout<<"Enter the old password: ";
                cin>>old;
                if(of0.is_open()) {
                    // eof() return nonzero(true) when there are no more data to be read from an input file stream, otherwise return false(zero)
                    while(!of0.eof()) { 
                        while(getline(of0, text)) {
                            istringstream iss(text);
                            iss>>word1;
                            cp[i] = word1;
                            i++;
                        }
                        if(old == cp[1]) {
                            of0.close(); // to free memory space
                            // output stream class and by default write mode in open()
                            ofstream of1;
                            of1.open("file.txt");
                            if(of1.is_open()) {
                                cout<<"Enter your new password: ";
                                cin>>password1;
                                cout<<"Enter your new password again: ";
                                cin>>password2;
                                if(password1 == password2) {
                                    of1<<cp[0]<<"\n";
                                    of1<<password1;
                                    cout<<"Password changed successfully"<<endl;
                                }
                                else {
                                    of1<<cp[0]<<"\n";
                                    of1<<old; // donot update cause password1 and password2 not matched
                                    cout<<"Password do not match"<<endl;
                                }
                            }
                        }
                        else {
                            cout<<"Please enter a valid password"<<endl;
                            break;
                        }
                    }
                }
                break;
            }
            case 4: {
                cout<<"__________________Thankyou!____________________";
                break;
            }
            default:
                cout<<"Enter a valid choice";
        }
    }while(a != 4); 

    return 0;
}