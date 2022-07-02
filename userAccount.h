#include <iostream>
#include <string>
using namespace std;

class User
{   
    private:
        string realName = "";
        string id = "0";
        string birthday = "0";
        string userName = "";
        string password = ""; 

    public:
        string getName()  { return realName;}
        string getId()  { return id;}
        string getBirthday()  { return birthday;}
        string getUserName()  { return userName;}
        string getPassword()  { return password;}

        void setName(string newName)
        {
            realName = newName;
        }
        
        void setId(string newId)
        {
            id = newId;
        }
        void setBirthday(string newBirthday)
        {
            birthday = newBirthday;
        }
        void setUserName(string newUserName)
        {
            userName = newUserName;
        }
        void setPassword(string newPassword)
        {
            password = newPassword;
        }

        void displayInformation()
        {
            cout << "Name: " << getName() << endl;
            cout << "ID: " << getId() << endl;
            cout << "Birthday Year: " <<  getBirthday() << endl;
        }
};
