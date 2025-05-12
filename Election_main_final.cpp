#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;
class Main_Welcome
{
public:
    Main_Welcome()
    {
        cout << "------------------------------" << endl;
        cout << "Welcome to the Election System" << endl;
        cout << "------------------------------" << endl;
    }
    ~Main_Welcome()
    {
        cout << "------------------------------" << endl;
        cout << "Thank you for using our system" << endl;
        cout << "------------------------------" << endl;
    }
};

class Voting
{
public:
    void voteInDelhi();
    void display_result();
};
void Voting::voteInDelhi()
{
    int count1=0;
    int count2=0;
    int count3=0;
    ifstream file;
    ifstream file1;
    ifstream file2;
    ofstream filea;
    ofstream fileb;
    ofstream filec;
    file.open("votecount_for_BJP.txt",ios::in);
    file1.open("votecount_for_AAP.txt",ios::in);
    file2.open("votecount_for_Congress.txt",ios::in);
    file.read((char *)&count1, sizeof(count1));
    file1.read((char *)&count2, sizeof(count2));
    file2.read((char *)&count3, sizeof(count3));
    file.close();
    file1.close();
    file2.close();
    cout << "-----------------------------------------------------------------------------------------------------"<<endl;
    cout << "Vote for your favourite party" << endl;
    cout << "1. vote for BJP " << endl;
    cout << "2. vote for AAP " << endl;
    cout << "3. vote for Congress " << endl;
    cout << "-----------------------------------------------------------------------------------------------------"<<endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        char name[20];
        ifstream BJP;
        BJP.open("candidate_BJP.txt");
        BJP.read(name, sizeof(name));
        cout << "You have voted for " << name <<" from BJP" <<endl;
        BJP.close();
        count1++;
    }
    else if (choice == 2)
    {
        char name[20];
        ifstream AAP;
        AAP.open("candidate_AAP.txt");
        AAP.read(name, sizeof(name));
        cout << "You have voted for " << name<<" from AAP" << endl;
        AAP.close();
        count2++;
    }
    else if (choice == 3)
    {
        char name[20];
        ifstream Congress;
        Congress.open("candidate_Congress.txt");
        Congress.read(name, sizeof(name));
        cout << "You have voted for " << name <<" from Congress"<< endl;
        Congress.close();
        count3++;
    }
    else
    {
        cout << "Invalid choice" << endl;
    }
    filea.open("votecount_for_BJP.txt");
    fileb.open("votecount_for_AAP.txt");
    filec.open("votecount_for_Congress.txt");
    filea.write((char*)&count1, sizeof(count1));
    fileb.write((char*)&count2, sizeof(count2));
    filec.write((char*)&count3, sizeof(count3));
    filea.close();
    fileb.close();
    filec.close();
    cout << "-----------------------------------------------------------------------------------------------------"<<endl;    
    cout <<"Score Board"<<endl;
    cout << "BJP: " << count1 << endl;
    cout << "AAP: " << count2 << endl;
    cout << "Congress: " << count3 << endl;
    cout << "-----------------------------------------------------------------------------------------------------"<<endl;
    cout << "Thank you for voting" << endl;
    cout << "-----------------------------------------------------------------------------------------------------"<<endl;
}
void Voting::display_result()
{
    int count1;
    int count2;
    int count3;
    ifstream file;
    ifstream file1;
    ifstream file2;
    file.open("votecount_for_BJP.txt");
    file1.open("votecount_for_AAP.txt");
    file2.open("votecount_for_Congress.txt");
    file.read((char *)&count1, sizeof(count1));
    file1.read((char *)&count2, sizeof(count2));
    file2.read((char *)&count3, sizeof(count3));
    cout << "-----------------------------------------------------------------------------------------------------"<<endl;
    cout << "Result" << endl;
    cout << "BJP: " << count1 << endl;
    cout << "AAP: " << count2 << endl;
    cout << "Congress: " << count3 << endl;
    cout << "-----------------------------------------------------------------------------------------------------"<<endl;
    if (count1 > count2 && count1 > count3)
    {
        cout << "BJP wins" << endl;
    }
    else if (count2 > count1 && count2 > count3)
    {
        cout << "AAP wins" << endl;
    }
    else if (count3 > count1 && count3 > count2)
    {
        cout << "Congress wins" << endl;
    }
    else
    {
        cout << "It's a tie" << endl;
    }
    cout << "-----------------------------------------------------------------------------------------------------"<<endl;
    file.close();
    file1.close();
    file2.close();
}

class VoterPov
{
private:
    char name[20];            
    char address[100];         
    char dob[15];             
    char state[10] = "Delhi"; 
    char username[16];        
    char password[16];        
    int age;

public:
    void get_data();
    void display_data();
    void write_data();
    void login();
    void delete_data();
    void update_data();
};
void VoterPov::get_data()
{
    
    cout << "Enter your name: ";
    cin.ignore();        
    cin.getline(name, 20); 
    cout << "Enter your address: ";
    cin.getline(address, 100); 
    cout << "Enter your date of birth: ";
    cin.getline(dob, 15); 
ReEnterAge:
    cout << "Enter your age: ";
    cin >> age;
    try
    {
        if (age < 18)
        {
            throw "Age should be greater than 18";
        }
    }
    catch (const char *msg)
    {
        cout << msg << endl;
        goto ReEnterAge;
    }
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    cout << "Create Your Username And Password" << endl;
    reUser:
    cout << "Enter your username: ";
    cin.ignore();
    cin>>username;
    int size=sizeof(username)/sizeof(username[0]);
        // if (strlen(username) < 6 && strlen(username) > 16)
        if(size<6&&size>16)
        {
            cout<< "Username should be greater than 6 characters";
            goto reUser;
        }
    rePass:
    cout << "Enter your password: ";
    cin.getline(password, 16);
    try
    {
        if (strlen(password) > 6 && strlen(password) < 16)
        {
            throw "Password should be greater than 6 characters";
        }
    }
    catch(const char* e)
    {
        cout << e << endl;
    }
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    write_data();
}
void VoterPov::write_data()
{
    ofstream file;
    file.open("voter_data_Delhi.txt",ios::binary | ios::app);
    file.write(username, sizeof(username));
    file.write(password, sizeof(password));
    file.write(name, sizeof(name));
    file.write(address, sizeof(address));
    file.write(dob, sizeof(dob));
    file.write((char *)&age, sizeof(age));
    file.write(state, sizeof(state));
    file.close();

}
void VoterPov::display_data()
{
    ifstream file;
    file.open("voter_data_Delhi.txt");
    cout << "Enter Username And Password To View Your Details" << endl;
    cout << "Enter your username: ";
    cin.ignore();       
    char input_username[16];
    cin.getline(input_username, 16);   
    cout << "Enter your password: ";
    char input_password[16];
    cin.getline(password, 100);
    while(file.read(username, sizeof(username)) && file.read(password, sizeof(password)) && file.read(name, sizeof(name)) && file.read(address, sizeof(address)) && file.read(dob, sizeof(dob)) && file.read((char *)&age, sizeof(age)) && file.read(state, sizeof(state)))
    {
        if (strcmp(input_username, username) == 0 && strcmp(input_password, password) == 0)
        {
            cout << "Name: " << name << endl;
            cout << "Address: " << address << endl;
            cout << "Date of Birth: " << dob << endl;
            cout << "Age: " << age << endl;
            cout << "State: " << state << endl;
            cout << "----------------------------------------" << endl;
            break;
        }
        else if(file.eof())
        {
            cout << "Invalid Username And Password" << endl;
            break;
        }
    }
    
    file.close();
}
void VoterPov::login()
{
    Voting vote;
    cout << "Enter Username And Password To Login" << endl;
    cout << "Enter your username: ";
    cin.ignore();
    char input_username[16];
    cin.getline(input_username, 16); 
    cout << "Enter your password: ";
    char input_password[16];
    cin.getline(input_password, 16);
    ifstream file;
    file.open("voter_data_Delhi.txt");
    while(file.read(username, sizeof(username)) && file.read(password , sizeof(password)))
    {
        if (strcmp(input_username, username) == 0 && strcmp(input_password, password) == 0)
        {
            cout << "Login Successful";
            for (int i = 0; i < 3; i++)
            {
                cout<<".";
                Sleep(900);
            }
            
            vote.voteInDelhi();
            break;  
        }
        else if(file.eof())
        {
            cout << "Invalid Username And Password" << endl;
            break;
        }
    }
    file.close();
}
void VoterPov::delete_data()
{
    cout << endl<< "Enter Username And Password To Delete Your Details" << endl;
    cout << "Enter your username: ";
    cin.ignore();          
    char input_username[16];
    cin.getline(input_username, 16); 
    cout << "Enter your password: ";
    char input_password[16];
    cin.getline(input_password, 16); 
    ifstream file;
    ofstream file1;
    file.open("voter_data_Delhi.txt");
    file1.open("temp.txt");
    while(file.read(username, sizeof(username)) && file.read(password, sizeof(password)) && file.read(name, sizeof(name)) && file.read(address, sizeof(address)) && file.read(dob, sizeof(dob)) && file.read((char *)&age, sizeof(age)) && file.read(state, sizeof(state)))
    {
        if (strcmp(username, input_username) == 0 && strcmp(password, input_password) == 0)
        {
            file.read(username, sizeof(username));
            file.read(password, sizeof(password));
            file.read(name, sizeof(name));
            file.read(address, sizeof(address));
            file.read(dob, sizeof(dob));
            file.read((char *)&age, sizeof(age));
            file.read(state, sizeof(state));
        }
        else
        {
            file1.write(username, sizeof(username));
            file1.write(password, sizeof(password));
            file1.write(name, sizeof(name));
            file1.write(address, sizeof(address));
            file1.write(dob, sizeof(dob));
            file1.write((char *)&age, sizeof(age));
            file1.write(state, sizeof(state));
        }
    }
    file.close();
    file1.close();
    remove("voter_data_Delhi.txt");
    rename("temp.txt", "voter_data_Delhi.txt");
}
void VoterPov::update_data()
{
    cout << "Enter Username And Password To Update Your Details" << endl;
    cout << "Enter your username: ";
    cin.ignore();          
    char input_username[16];
    cin.getline(input_username, 16);
    cout << "Enter your password: ";
    char input_password[16];
    cin.getline(input_password, 16);
    ifstream file;
    ofstream file1;
    file.open("voter_data_Delhi.txt");
    file1.open("temp.txt");
    while(file.read(username, sizeof(username)) && file.read(password, sizeof(password)) && file.read(name, sizeof(name)) && file.read(address, sizeof(address)) && file.read(dob, sizeof(dob)) && file.read((char *)&age, sizeof(age)) && file.read(state, sizeof(state)))
    {
        if (strcmp(username, input_username) == 0 && strcmp(password, input_password) == 0)
        {
            cout<<"Enter your name: ";
            cin.getline(name, 20);
            cout<<"Enter your address: ";
            cin.getline(address, 100);
            cout<<"Enter your date of birth: ";
            cin.getline(dob, 15);
            cout<<"Enter your age: ";
            cin>>age;
            cin.ignore();
            cout<<"Enter your state: ";
            cin.getline(state, 10);
            file1.write(username, sizeof(username));
            file1.write(password, sizeof(password));
            file1.write(name, sizeof(name));
            file1.write(address, sizeof(address));
            file1.write(dob, sizeof(dob));
            file1.write((char *)&age, sizeof(age));
            file1.write(state, sizeof(state));
        }
        else
        {
            file1.write(username, sizeof(username));
            file1.write(password, sizeof(password));
            file1.write(name, sizeof(name));
            file1.write(address, sizeof(address));
            file1.write(dob, sizeof(dob));
            file1.write((char *)&age, sizeof(age));
            file1.write(state, sizeof(state));
        }
    }
    file.close();
    file1.close();
    remove("voter_data_Delhi.txt");
    rename("temp.txt", "voter_data_Delhi.txt");
}

class CandidatePov
{
private:
    char name[20]; // Change string to char array
    char party_name[20]; // Change string to char array
    char state[10] = "Delhi"; // Change string to char array
    char username[16]; // Change string to char array
    char password[16]; // Change string to char array
    int age;

public:
    void get_data();
    void display_data();
    void write_data();
    void login();
    void delete_data();
    void update_data();
};;
void CandidatePov::get_data()  
{
    cout << "Enter your name: ";
    cin.ignore();
    cin.getline(name, 20);
    cout << "Enter your party name: "<<endl;
    cout << "1. AAP" << endl;
    cout << "2. BJP" << endl;
    cout << "3. Congress" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        strcpy(party_name, "AAP");  
    }
    else if (choice == 2)
    {
        strcpy(party_name, "BJP");
    }
    else if (choice == 3)
    {
        strcpy(party_name, "Congress");
    }
    else
    {
        cout << "Invalid choice" << endl;
    }
ReEnterAge:
    cout << "Enter your age: ";
    cin >> age;
    try
    {
        if (age < 25)
        {
            throw "Age should be greater than 25";
        }
    }
    catch (const char *msg)
    {
        cout << msg << endl;
        goto ReEnterAge;
    }
    cin.ignore();
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    cout << "Create Your Username And Password"<<endl;
    cout << "Enter your username: ";
    cin.getline(username, 16);
    cout << "Enter your password: ";
    cin.getline(password, 16); 
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    write_data();
}
void CandidatePov::write_data()
{
    ofstream file;
    ofstream file1;
    ofstream file2;
    file.open("candidate_BJP.txt", ios::binary | ios::app);
    file1.open("candidate_AAP.txt", ios::binary | ios::app);
    file2.open("candidate_Congress.txt", ios::binary | ios::app);
    if (strcmp(party_name, "BJP") == 0)
    {
        file.write(username, sizeof(username));
        file.write(password, sizeof(password));
        file.write(name, sizeof(name));
        file.write(party_name, sizeof(party_name));
        file.write((char *)&age, sizeof(age));
        file.write(state, sizeof(state));
    }
    else if (strcmp(party_name, "AAP") == 0)
    {
        file1.write(username, sizeof(username));
        file1.write(password, sizeof(password));
        file1.write(name, sizeof(name));
        file1.write(party_name, sizeof(party_name));
        file1.write((char *)&age, sizeof(age));
        file1.write(state, sizeof(state));
    }
    else if (strcmp(party_name, "Congress") == 0)
    {
        file2.write(username, sizeof(username));
        file2.write(password, sizeof(password));
        file2.write(name, sizeof(name));
        file2.write(party_name, sizeof(party_name));
        file2.write((char *)&age, sizeof(age));
        file2.write(state, sizeof(state));
    }
}
void CandidatePov::display_data()
{
    ifstream file;
    ifstream file1;
    ifstream file2;
    file.open("candidate_BJP.txt");
    file1.open("candidate_AAP.txt");
    file2.open("candidate_Congress.txt");
    cout << "Enter Username And Password To View Your Details" << endl;
    cout << "Enter your username: ";
    cin.ignore();
    char input_username[16];
    cin.getline(input_username, 16);
    cout << "Enter your password: ";
    char input_password[16];
    cin.getline(input_password, 16);
    while (file.read(username, sizeof(username)) && file.read(password, sizeof(password)) && file.read(name, sizeof(name)) && file.read(party_name, sizeof(party_name)) && file.read((char *)&age, sizeof(age)) && file.read(state, sizeof(state)))
    {
        if (strcmp(input_username, username) == 0 && strcmp(input_password, password) == 0)
        {
            cout << "Name: " << name << endl;
            cout << "Party Name: " << party_name << endl;
            cout << "Age: " << age << endl;
            cout << "State: " << state << endl;
            cout << "----------------------------------------" << endl;
            break;
        }
        else if (file.eof())
        {
            cout << "Invalid Username And Password" << endl;
            break;
        }
    }
    while (file1.read(username, sizeof(username)) && file1.read(password, sizeof(password)) && file1.read(name, sizeof(name)) && file1.read(party_name, sizeof(party_name)) && file1.read((char *)&age, sizeof(age)) && file1.read(state, sizeof(state)))
    {
        if (strcmp(input_username, username) == 0 && strcmp(input_password, password) == 0)
        {
            cout << "Name: " << name << endl;
            cout << "Party Name: " << party_name << endl;
            cout << "Age: " << age << endl;
            cout << "State: " << state << endl;
            cout << "----------------------------------------" << endl;
            break;
        }
        else if (file1.eof())
        {
            cout << "Invalid Username And Password" << endl;
            break;
        }
    }
    while (file2.read(username, sizeof(username)) && file2.read(password, sizeof(password)) && file2.read(name, sizeof(name)) && file2.read(party_name, sizeof(party_name)) && file2.read((char *)&age, sizeof(age)) && file2.read(state, sizeof(state)))
    {
        if (strcmp(input_username, username) == 0 && strcmp(input_password, password) == 0)
        {
            cout << "Name: " << name << endl;
            cout << "Party Name: " << party_name << endl;
            cout << "Age: " << age << endl;
            cout << "State: " << state << endl;
            cout << "----------------------------------------" << endl;
            break;
        }
        else if (file2.eof())
        {
            cout << "Invalid Username And Password" << endl;
            break;
        }
    }
    file.close();
    file1.close();
    file2.close();
}
void CandidatePov::login()
{
    cout << "Enter Username And Password To Login" << endl;
    cout << "Enter your username: ";
    cin.ignore();
    cin.getline(username, 16);
    cout << "Enter your password: ";
    cin.getline(password, 16);
    ifstream file;
    ifstream file1;
    ifstream file2;
    file.open("candidate_BJP.txt");
    file1.open("candidate_AAP.txt");
    file2.open("candidate_Congress.txt");
    while (file.read(username, sizeof(username)) && file.read(password, sizeof(password)) && file.read(name, sizeof(name)) && file.read(party_name, sizeof(party_name)) && file.read((char *)&age, sizeof(age)) && file.read(state, sizeof(state)))
    {
        if (strcmp(username, username) == 0 && strcmp(password, password) == 0)
        {
            cout << "Login Successful" << endl;
            break;
        }
        else if (file.eof())
        {
            break;
        }
    }
    while (file1.read(username, sizeof(username)) && file1.read(password, sizeof(password)) && file1.read(name, sizeof(name)) && file1.read(party_name, sizeof(party_name)) && file1.read((char *)&age, sizeof(age)) && file1.read(state, sizeof(state)))
    {
        if (strcmp(username, username) == 0 && strcmp(password, password) == 0)
        {
            cout << "Login Successful" << endl;
            break;
        }
        else if (file1.eof())
        {
            break;
        }
    }
    while (file2.read(username, sizeof(username)) && file2.read(password, sizeof(password)) && file2.read(name, sizeof(name)) && file2.read(party_name, sizeof(party_name)) && file2.read((char *)&age, sizeof(age)) && file2.read(state, sizeof(state)))
    {
        if (strcmp(username, username) == 0 && strcmp(password, password) == 0)
        {
            cout << "Login Successful" << endl;
            break;
        }
        else if (file2.eof())
        {
            break;
        }
    }
    file.close();
    file1.close();
    file2.close();
}
void CandidatePov::delete_data()
{
    cout << endl<< "Enter Username And Password To Delete Your Details" << endl;
    cout << "Enter your username: ";
    cin.ignore();           // Ignore the newline character
    char input_username[16];
    cin.getline(input_username, 16);
    cout << "Enter your password: ";
    char input_password[16];
    cin.getline(input_password, 16);
    ifstream file;
    ofstream file1;
    ifstream file2;
    ofstream file3;
    ifstream file4;
    ofstream file5;
    file.open("candidate_BJP.txt");
    file1.open("temp.txt");
    file2.open("candidate_AAP.txt");    
    file3.open("temp1.txt");
    file4.open("candidate_Congress.txt");
    file5.open("temp2.txt");
    while (file.read(username, sizeof(username)) && file.read(password, sizeof(password)) && file.read(name, sizeof(name)) && file.read(party_name, sizeof(party_name)) && file.read((char *)&age, sizeof(age)) && file.read(state, sizeof(state)))
    {
        if (strcmp(username, input_username) == 0 && strcmp(password, input_password) == 0)
        {
            file.read(username, sizeof(username));
            file.read(password, sizeof(password));
            file.read(name, sizeof(name));
            file.read(party_name, sizeof(party_name));
            file.read((char *)&age, sizeof(age));
            file.read(state, sizeof(state));
        }
        else
        {
            file1.write(username, sizeof(username));
            file1.write(password, sizeof(password));
            file1.write(name, sizeof(name));
            file1.write(party_name, sizeof(party_name));
            file1.write((char *)&age, sizeof(age));
            file1.write(state, sizeof(state));
        }
    }
    while (file2.read(username, sizeof(username)) && file2.read(password, sizeof(password)) && file2.read(name, sizeof(name)) && file2.read(party_name, sizeof(party_name)) && file2.read((char *)&age, sizeof(age)) && file2.read(state, sizeof(state)))
    {
        if (strcmp(username, input_username) == 0 && strcmp(password, input_password) == 0)
        {
            file2.read(username, sizeof(username));
            file2.read(password, sizeof(password));
            file2.read(name, sizeof(name));
            file2.read(party_name, sizeof(party_name));
            file2.read((char *)&age, sizeof(age));
            file2.read(state, sizeof(state));
        }
        else
        {
            file3.write(username, sizeof(username));
            file3.write(password, sizeof(password));
            file3.write(name, sizeof(name));
            file3.write(party_name, sizeof(party_name));
            file3.write((char *)&age, sizeof(age));
            file3.write(state, sizeof(state));
        }
    }
    while (file4.read(username, sizeof(username)) && file4.read(password, sizeof(password)) && file4.read(name, sizeof(name)) && file4.read(party_name, sizeof(party_name)) && file4.read((char *)&age, sizeof(age)) && file4.read(state, sizeof(state)))
    {
        if (strcmp(username, input_username) == 0 && strcmp(password, input_password) == 0)
        {
            file4.read(username, sizeof(username));
            file4.read(password, sizeof(password));
            file4.read(name, sizeof(name));
            file4.read(party_name, sizeof(party_name));
            file4.read((char *)&age, sizeof(age));
            file4.read(state, sizeof(state));
        }
        else
        {
            file5.write(username, sizeof(username));
            file5.write(password, sizeof(password));
            file5.write(name, sizeof(name));
            file5.write(party_name, sizeof(party_name));
            file5.write((char *)&age, sizeof(age));
            file5.write(state, sizeof(state));
        }
    }
    file.close();
    file1.close();
    file2.close();
    file3.close();
    file4.close();
    file5.close();
    remove("candidate_BJP.txt");
    rename("temp.txt", "candidate_BJP.txt");
    remove("candidate_AAP.txt");
    rename("temp1.txt", "candidate_AAP.txt");
    remove("candidate_Congress.txt");
    rename("temp2.txt", "candidate_Congress.txt");
}
void CandidatePov::update_data()
{
    cout << "Enter Username And Password To Update Your Details" << endl;
    cout << "Enter your username: ";
    cin.ignore();
    char input_username[16];
    cin.getline(input_username, 16);
    cout << "Enter your password: ";
    char input_password[16];
    cin.getline(input_password, 16);
    ifstream file;
    ofstream file1;
    ifstream file2;
    ofstream file3;
    ifstream file4;
    ofstream file5;
    file.open("candidate_BJP.txt");
    file1.open("temp.txt");
    file2.open("candidate_AAP.txt");
    file3.open("temp1.txt");
    file4.open("candidate_Congress.txt");
    file5.open("temp2.txt");
    while (file.read(username, sizeof(username)) && file.read(password, sizeof(password)) && file.read(name, sizeof(name)) && file.read(party_name, sizeof(party_name)) && file.read((char *)&age, sizeof(age)) && file.read(state, sizeof(state)))
    {
        if (strcmp(username, input_username) == 0 && strcmp(password, input_password) == 0)
        {
            cout << "Enter your name: ";
            cin.getline(name, 20);
            cout << "Enter your party name: ";
            cout << "1. AAP" << endl;
            cout << "2. BJP" << endl;
            cout << "3. Congress" << endl;
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            if (choice == 1)
            {
                strcpy(party_name, "AAP");
            }
            else if (choice == 2)
            {
                strcpy(party_name, "BJP");
            }
            else if (choice == 3)
            {
                strcpy(party_name, "Congress");
            }
            else
            {
                cout << "Invalid choice" << endl;
            }
            cout << "Enter your age: ";
            cin >> age;
            cin.ignore();
            file1.write(username, sizeof(username));
            file1.write(password, sizeof(password));
            file1.write(name, sizeof(name));
            file1.write(party_name, sizeof(party_name));
            file1.write((char *)&age, sizeof(age));
            file1.write(state, sizeof(state));
        }
        else
        {
            file1.write(username, sizeof(username));
            file1.write(password, sizeof(password));
            file1.write(name, sizeof(name));
            file1.write(party_name, sizeof(party_name));
            file1.write((char *)&age, sizeof(age));
            file1.write(state, sizeof(state));
        }
    }
    while (file2.read(username, sizeof(username)) && file2.read(password, sizeof(password)) && file2.read(name, sizeof(name)) && file2.read(party_name, sizeof(party_name)) && file2.read((char *)&age, sizeof(age)) && file2.read(state, sizeof(state)))
    {
        if (strcmp(username, input_username) == 0 && strcmp(password, input_password) == 0)
        {
            cout << "Enter your name: ";
            cin.getline(name, 20);
            cout << "Enter your party name: ";
            cout << "1. AAP" << endl;
            cout << "2. BJP" << endl;
            cout << "3. Congress" << endl;
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            if (choice == 1)
            {
                strcpy(party_name, "AAP");
            }
            else if (choice == 2)
            {
                strcpy(party_name, "BJP");
            }
            else if (choice == 3)
            {
                strcpy(party_name, "Congress");
            }
            else
            {
                cout << "Invalid choice" << endl;
            }
            cout << "Enter your age: ";
            cin >> age;
            cin.ignore();
            file3.write(username, sizeof(username));
            file3.write(password, sizeof(password));
            file3.write(name, sizeof(name));
            file3.write(party_name, sizeof(party_name));
            file3.write((char *)&age, sizeof(age));
            file3.write(state, sizeof(state));
        }
        else
        {
            file3.write(username, sizeof(username));
            file3.write(password, sizeof(password));
            file3.write(name, sizeof(name));
            file3.write(party_name, sizeof(party_name));
            file3.write((char *)&age, sizeof(age));
            file3.write(state, sizeof(state));
        }
    }
    while (file4.read(username, sizeof(username)) && file4.read(password, sizeof(password)) && file4.read(name, sizeof(name)) && file4.read(party_name, sizeof(party_name)) && file4.read((char *)&age, sizeof(age)) && file4.read(state, sizeof(state)))
    {
        if (strcmp(username, input_username) == 0 && strcmp(password, input_password) == 0)
        {
            cout << "Enter your name: ";
            cin.getline(name, 20);
            cout << "Enter your party name: ";
            cout << "1. AAP" << endl;
            cout << "2. BJP" << endl;
            cout << "3. Congress" << endl;
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            if (choice == 1)
            {
                strcpy(party_name, "AAP");
            }
            else if (choice == 2)
            {
                strcpy(party_name, "BJP");
            }
            else if (choice == 3)
            {
                strcpy(party_name, "Congress");
            }
            else
            {
                cout << "Invalid choice" << endl;
            }
            cout << "Enter your age: ";
            cin >> age;
            cin.ignore();
            file5.write(username, sizeof(username));
            file5.write(password, sizeof(password));
            file5.write(name, sizeof(name));
            file5.write(party_name, sizeof(party_name));
            file5.write((char *)&age, sizeof(age));
            file5.write(state, sizeof(state));
        }
        else
        {
            file5.write(username, sizeof(username));
            file5.write(password, sizeof(password));
            file5.write(name, sizeof(name));
            file5.write(party_name, sizeof(party_name));
            file5.write((char *)&age, sizeof(age));
            file5.write(state, sizeof(state));
        }
    }
}



class admin
{
public:
    void admin_login();
    void admin_menu();
    void add_voter();
    void add_candidate();
    void display_voter();
    void display_candidate();
    void delete_voter();
    void delete_candidate();
    void display_result();
    void update_voter();
    void update_candidate();
};
void admin::admin_login()
{
    char user[16];
    char pass[16];
    cout << "Enter username: ";
    cin >> user;
    cout << "Enter password: ";
    cin >> pass;
    if (strcmp(user, "admin") == 0 && strcmp(pass, "admin") == 0)
    {
        cout << "Login Successful";
        for (int i = 0; i < 3; i++)
        {
            cout<<".";
            Sleep(900);
        }
        admin_menu();
    }
    else
    {
        cout << "Login Failed" << endl;
    }
}
void admin::update_voter()
{
    VoterPov voter;
    voter.update_data();
}
void admin::update_candidate()
{
    CandidatePov candidate;
    candidate.update_data();
}
void admin::add_voter()
{
    VoterPov voter;
    voter.get_data();
}
void admin::add_candidate()
{
    CandidatePov candidate;
    candidate.get_data();
}
void admin::display_voter()
{
    VoterPov voter;
    voter.display_data();
}
void admin::display_candidate()
{
    CandidatePov candidate;
    candidate.display_data();
}
void admin::delete_voter()
{
    VoterPov voter;
    voter.delete_data();
}
void admin::delete_candidate()
{
    CandidatePov candidate;
    candidate.delete_data();
}
void admin::display_result()
{
    Voting vote;
    vote.display_result();
}

int main()
{
    
    Main_Welcome welcome;
    CandidatePov candidate;
    VoterPov voter;
    Voting vote;
    admin admin;
    int choice;
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    cout << "1. Voter" << endl;
    cout << "2. Admin" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    switch (choice)
    {
    case 1:
    ReEnter:
    
        cout << "1. Register" << endl;
        cout << "2. Login For Vote" << endl;
        cout << "3. Back" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "-----------------------------------------------------------------------------------------------------" << endl;
        switch (choice)
        {
        case 1:
            voter.get_data();
            break;
        case 2:
            voter.login();
            break;
        case 3:
            main();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
            goto ReEnter;
        }
        break;
    case 2:
        admin.admin_login();
        break;
    case 3:
        exit(0);
    default:
        cout << "Invalid choice" << endl;
    }
    return 0;
}
void admin::admin_menu()
{
    int choice;
    while (1)
    {
        
        cout << "-----------------------------------------------------------------------------------------------------" << endl;
        cout << "1. Add Voter" << endl;
        cout << "2. Add Candidate" << endl;
        cout << "3. Display Voter" << endl;
        cout << "4. Display Candidate" << endl;
        cout << "5. Delete Voter" << endl;
        cout << "6. Delete Candidate" << endl;
        cout << "7. Display Result" << endl;
        cout << "8. Update Voter" << endl;
        cout << "9. Update Candidate" << endl;
        cout << "10. Back" << endl;
        cout << "11. Exit" << endl;
        cout << "-----------------------------------------------------------------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            add_voter();
            break;
        case 2:
            add_candidate();
            break;
        case 3:
            display_voter();
            break;
        case 4:
            display_candidate();
            break;
        case 5:
            delete_voter();
            break;
        case 6:
            delete_candidate();
            break;
        case 7:
            display_result();
            break;
        case 8:
            update_voter();
            break;
        case 9:
            update_candidate();
            break;
        case 10:
            main();
            break;
        case 11:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    }
}