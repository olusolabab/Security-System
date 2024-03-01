#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int a, i = 0;
    string text, old, password1, password2, pass, name, password0, age, user, word, word1;

    string creds[2], cp[2];

    cout << "           Security System " << endl;

    cout << "___________________________________" << endl << endl;
    cout <<"|            1. Register            |" << endl;
    cout <<"|            2. Login               |" << endl;
    cout <<"|            3. Change Password     |" << endl;
    cout <<"|____________4. End Program_________|" << endl;

    do{
        cout << endl << endl;
        cout << "Enter your choice:- ";
        cin >> a;

        switch(a){
            case 1: {
                cout << "___________________________________" << endl << endl;
                cout << "|-------------Register-------------|" << endl;
                cout << "|__________________________________|" << endl << endl;

                cout << "Enter your Name:- ";
                cin >> name;
                cout << "Enter your Password:- ";
                cin >> password0;
                cout << "Enter your Age:- ";
                cin >> age;

                ofstream of1;
                of1.open("user.txt");
                if(of1.is_open()){
                    of1 << name << "\n";
                    of1 << password0;
                    cout << "User registered successfully" << endl;
                }
                break;
            }

            case 2: {
                i = 0;

                cout << "___________________________________" << endl << endl;
                cout << "|--------------Login---------------|" << endl;
                cout << "|__________________________________|" << endl << endl;

                ifstream of2;
                of2.open("user.txt");
                cout << "Enter your Username:- ";
                cin >> user;
                cout << "Enter your Password:- ";
                cin >> pass;

                if(of2.is_open()){
                    while(!of2.eof()){
                        while(getline(of2, text)){
                            istringstream iss(text);
                            iss >> word;
                            creds[i] = word;
                            i++;
                        }

                        if(user == creds[0] && pass == creds[1]){
                            cout << "-------Login successful-------" << endl;
                            cout << endl << endl;

                            cout << "Details of User:- " << endl;

                            cout << "Username: "+ name << endl;
                            cout << "Password: "+ pass << endl;
                            cout << "Age: "+ age << endl;

                            cout << "___________________________________" << endl << endl;
                            cout << "|__________________________________|" << endl << endl;
                        }

                        else{
                            cout << "Username or Password incorrect" << endl;
                            cout << "|         1. Press 2 to Login                 |" << endl;
                            cout << "|         2. Press 3 to change Password       |" << endl;
                            cout << "_______________________________________________" << endl << endl;
                            cout << "|_____________________________________________|" << endl << endl;
                            break;
                        }
                    }
                }
                break;
            }

            case 3: {
                i = 0;

                cout << "-----------------------Change Password-----------------------" << endl;

                ifstream of0;
                of0.open("user.txt");
                cout << "Enter the old password:- ";
                cin >> old;

                if(of0.is_open()){
                    while (of0.eof()){

                        while(getline(of0, text)){
                            istringstream iss(text);
                            iss >> word1;
                            cp[i] = word1;
                            i++;
                        }

                        if(old == cp[1]) {
                            of0.close();

                            ofstream of1;
                            if(of1.is_open()){
                                cout << "Enter the new password:- ";
                                cin >> password1;
                                cout << "Enter the new password again:- ";
                                cin >> password2;

                                if(password1 == password2){
                                    of1 << cp[0] << "\n";
                                    of1 << password1;
                                    cout << "Password changed successfully" << endl;
                                }

                                else{
                                    of1 << cp[0] << "\n";
                                    of1 << old;
                                    cout << "Passwords do not match" << endl;
                                }
                            }

                        }
                        else{
                            cout << "Please enter a valid password" << endl;
                            break;
                        }
                    }
                }

                break;
            }

            case 4: {
                cout << "_______________Thank you!_______________" << endl << endl;
                break;
            }

            default: {
                cout << "Enter a valid choice" << endl << endl;
            }

        }
    }
    while(a!= 4);

    return 0;
}

