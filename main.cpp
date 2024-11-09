#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <fstream>
#include<iomanip>
#include<string>
#include"Linked_List.h"
using namespace std;

class Address
{
public:
    Address() : streetnum("0"), streetname("NULL"), town("NULL"), state("NULL") {}

    Address(string streetnum, string streetname, string town, string state)
    {
        this->streetnum = streetnum;
        this->streetname = streetname;
        this->town = town;
        this->state = state;
    }
    Address(Address &a)
    {
        streetnum = a.streetnum;
        streetname = a.streetname;
        town =a.town;
        state = a.state;
    }

    ~Address() {}

    void set_streetnum(string streetnum)
    {
        this->streetnum = streetnum;
    }

    string get_streetnum() const
    {
        return streetnum;
    }

    void set_streetname(string streetname)
    {
        this->streetname = streetname;
    }

    string get_streetname() const
    {
        return streetname;
    }

    void set_town(string town)
    {
        this->town = town;
    }

    string get_town() const
    {
        return town;
    }

    void set_state(string state)
    {
        this->state = state;
    }

    string get_state() const
    {
        return state;
    }

    friend ostream & operator<<(ostream & output, const Address & addr)
    {
        output<< addr.streetnum<<" "<< addr.streetname<<" "<<addr.town<<" "<<left<<setw(7)<< addr.state<<" ";
        return output;
    }


    friend istream & operator>>(istream & input, Address & addr)
    {
        input >> addr.streetnum>> addr.streetname>> addr.town>>addr.state;
        return input;
    }

    bool operator==(const Address& a) const
    {
        return (streetnum == a.streetnum && streetname == a.streetname && town == a.town && state == a.state);
    }

    Address& operator=(const Address& a)
    {
        if (this != &a)   // Check for self-assignment
        {
            streetnum = a.streetnum;
            streetname = a.streetname;
            town = a.town;
            state = a.state;
        }
        return *this;
    }

private:
    string streetnum;
    string streetname;
    string town;
    string state;
};




class Person
{
public:


    Person() : first_name("NULL"), last_name("NULL"), num_phone(2), num_mail(2), fav(0), Class(4)
    {

        phone = new string[num_phone];
        mail = new string[num_mail];
        for (int i = 0; i < num_phone; i++)
        {
            phone[i] = "NULL";
        }
        for (int j = 0; j < num_mail; j++)
        {
            mail[j] = "NULL";
        }

    }

    Person(Address &a) : first_name("NULL"), last_name("NULL"), fav(0), Class(4)
    {
        address = a;
        id=++count_object;
        num_phone = 2;
        num_mail = 2;
        phone = new string[num_phone];
        mail = new string[num_mail];
        for (int i = 0; i < num_phone; i++)
        {
            this->phone[i] = "NULL";
        }
        for (int j = 0; j < num_mail; j++)
        {
            this->mail[j] = "NULL";
        }
    }
    bool search_by_last_name(const string laNa)const
    {
        if(last_name==laNa)
            return true;
        return false;

    }
    bool search_by_classification(const size_t classifi)const
    {
        if(Class==classifi)
            return true;
        return false;
    }
    Person(const string first_name, const string last_name, int num_phone, string *phone, int num_mail, string *mail, int Class, int fav, Address &address)
    {
        this->address = address;
        this->first_name = first_name;
        this->last_name = last_name;
        this->num_phone = num_phone;
        this->num_mail = num_mail;
        this->phone = new string[num_phone];
        this->mail = new string[num_mail];
        for (int i = 0; i < num_phone; i++)
        {
            this->phone[i] = phone[i];
        }
        for (int j = 0; j < num_mail; j++)
        {
            this->mail[j] = mail[j];
        }
        this->Class = Class;
        this->fav = fav;
    }

// Copy constructor
    Person(const Person &p)
    {

        first_name = p.first_name;
        last_name = p.last_name;
        num_phone = p.num_phone;
        phone = new string[num_phone];
        for (int i = 0; i < num_phone; i++)
        {
            phone[i] = p.phone[i];
        }
        num_mail = p.num_mail;
        mail = new string[num_mail];
        for (int i = 0; i < num_mail; i++)
        {
            mail[i] = p.mail[i];
        }
        address = p.address;
        Class = p.Class;
        fav = p.fav;
    }
    ~Person()
    {
        delete[] phone;
        delete[] mail;


    }
    void set_address(const Address &address)
    {
        this->address = address;
    }

    void setFirst_name(const string &first_name)
    {
        this->first_name = first_name;
    }

    string getFirst_name() const
    {
        return first_name;
    }

    void setLast_name(const string &last_name)
    {
        this->last_name = last_name;
    }

    string getLast_name() const
    {
        return last_name;
    }

    void setPhone(string *phone, int num_phone)
    {
        this->num_phone = num_phone;
        delete[] this->phone; // Release old memory
        this->phone = new string[num_phone];
        for (int i = 0; i < num_phone; i++)
        {
            this->phone[i] = phone[i];
        }
    }

    string getPhone(int index) const
    {
        return phone[index];
    }

    void setmail(string *mail, int num_mail)
    {
        this->num_mail = num_mail;
        delete[] this->mail; // Release old memory
        this->mail = new string[num_mail];
        for (int i = 0; i < num_mail; i++)
        {
            this->mail[i] = mail[i];
        }
    }

    string getmail(int index) const
    {
        return mail[index];
    }

    void set_classification(int Class)
    {
        this->Class = Class;
    }

    int get_classification() const
    {
        return Class;
    }
    string get_classification_by_string(size_t classifi)const{
     switch(classifi)
        {
        case 1:
            return "Friend";
        case 2:
            return "Work";
        case 3:
           return "Family";
        case 4:
           return "Other";
        }
    }

    void set_fav(int fav)
    {
        this->fav = fav;
    }

    int get_fav() const
    {
        return fav;
    }

    void detials_address()
    {
        string snu,sna,t,s;
        cout << "Number of Street: ";
        cin>>snu;
        address.set_streetnum(snu);
        cout << "Street Name: ";
        cin>>sna;
        address.set_streetname(sna);
        cout << "Town: ";
        cin>>t;
        address.set_town(t);
        cout << "State: ";
        cin>>s;
        address.set_state(s);


    }




// Overloading operator (cin >>)
    friend istream &operator>>(istream &input, Person &p)
    {
        bool check=0;
        cout << "First Name: ";
        input >> p.first_name;
        cout << "Last Name: ";
        input >> p.last_name;

        delete[] p.phone;
        delete[] p.mail;

        cout << "How many phone numbers (1 or 2) ? ";
        do{
                check=0;
           input >> p.num_phone;
            if(p.num_phone>2||p.num_phone<1){
                cout<<"Maximum 2 Phones ! Try again ... \n";
                check=1;
            }
        }while(check);

        p.phone = new string[p.num_phone];
        if(p.num_phone==1)
        {

            cout<<"Phone : ";
            input>>p.phone[0];

        }
        else
        {
            p.phone=new string[p.num_phone];
            for(int i=0; i<p.num_phone; i++)
            {
                cout<<"Phone "<<i+1<<" : ";
                input>>p.phone[i];
            }

        }
        cout << "How many emails (1 or 2) ? ";
        do{
                check=0;
            input >> p.num_mail;
            if(p.num_mail>2||p.num_mail<1){
                cout<<"Maximum 2 Emails ! Try again ... \n";
                check=1;
            }
        }while(check);
        p.mail = new string[p.num_mail];
        if(p.num_mail==1)
        {

            cout<<"Email : ";
            input>>p.mail[0];
        }
        else
        {
            p.mail=new string[p.num_mail];
            for(int i=0; i<p.num_mail; i++)
            {
                cout<<"Email "<<i+1<<" : ";
                input>>p.mail[i];
            }
        }
        cout<<"Classification(Press 1(friend),2(work),3(family),4(other))";
        do
        {
            check=0;
            input>>p.Class;
            if(p.Class>=1&&p.Class<=4)check=1;
            else cout<<"...Wrong! please Press 1(friend),2(work),3(family),4(other)... ";
        }
        while(!check);

        cout<<"Set as Favorite (press 1(Fav) oR 0(Not)";

        do
        {
            check=0;
            input>>p.fav;
            if(p.fav==0||p.fav==1)check=1;
            else cout<<"...Wrong! please press 1(YES) oR 0(Not)... ";
        }
        while(!check);

        p.detials_address();
        return input;
    }
// Overloading operator (cout <<)
    friend ostream &operator<<(ostream &output, const Person &p)
    {
        output<<left<<setw(10)<<p.first_name<<left<<setw(10)<<p.last_name;
       output<<left<<setw(20)<< p.get_classification_by_string(p.Class);
        output<<left<<setw(10);
        if(p.fav==1) output<<"YES";
        else output<<"NO";
        output<<p.address;
        if(p.num_phone==2)
            output<<left<<setw(5)<<" "<<right<<setw(12)<<p.phone[0]<<", "<<left<<setw(13)<<p.phone[1];
        else output<<left<<setw(25)<<p.phone[0];
        if(p.num_mail==2)
            output<<right<<setw(14)<<p.mail[0]<<", "<<left<<setw(12)<<p.mail[1];
        else output<<right<<setw(26)<<p.mail[0];

        cout<<"\n-----------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;

        return output;
    }

    void save()
    {
        ofstream output("Person.txt", ios::app);
        output <<id <<","<<first_name << "," << last_name << "," << num_phone << ",";
        for (int i = 0; i < num_phone; i++)
        {
            output << phone[i] << ",";
        }
        output << num_mail << ",";
        for (int i = 0; i < num_mail; i++)
        {
            output << mail[i] << ",";
        }
        output << Class << "," << fav << ",";
        output << address.get_streetnum()<<","<< address.get_streetname()<<","<< address.get_town()<<","<< address.get_state()<<"\n";
        output.close();
    }






    bool operator==(const Person &p)const
    {
        if(first_name!=p.first_name&&last_name!=p.last_name&&num_phone!=p.num_phone&&num_mail!=p.num_mail&&Class!=p.Class&&fav!=p.fav )
            return false;
        for(int i=0,j=0; i<num_phone,j<num_mail; i++,j++)
        {
            if(phone[i]!=p.phone[i] && mail[j]!=p.mail[j])
                return false;
        }
        if(address==p.address)
            return true;
        return false;

    }
    Person& operator=(const Person &p)
    {
        if(this !=&p) //if p!=p
        {

            id=p.id;
            first_name=p.first_name;
            last_name=p.last_name;
            num_phone=p.num_phone;
            num_mail=p.num_mail;
            delete[] phone;
            delete[] mail;
            phone = new string[p.num_phone];
            mail = new string[p.num_mail];
            for (int i = 0; i < p.num_phone; i++)
            {
                phone[i] = p.phone[i];
            }
            for (int j = 0; j < p.num_mail; j++)
            {
                mail[j] = p.mail[j];
            }

            Class=p.Class;
            fav=p.fav;
            address=p.address;
        }
        return *this;
    }

protected:
    Address address;
    int id;
    static int count_object;
    string first_name;
    string last_name;
    int num_phone;
    string *phone;
    int num_mail;
    string *mail;
    int Class;
    int fav;
    bool check; // Check variable to use check in the program
};
void main_menu()
{
    cout<<"\t\t\t======================================================================\n";
    cout<<"\t\t\tContacts Book Menu : \n";
    cout<<"\t\t\t------------------------------\n";
    cout<<"\t\t\t1. Add a new contact \n";
    cout<<"\t\t\t2. Search by last Name (Enter LastName Correctly)\n";
    cout<<"\t\t\t3. Search by Classification ( friend , work ,family ,other )\n";
    cout<<"\t\t\t4. Print All Contacts \n";
    cout<<"\t\t\t5. Print Fav Contacts \n";
    cout<<"\t\t\t6. Save to File \n";
    cout<<"\t\t\t7. Load from File \n";
    cout<<"\t\t\t8. Delete Contacts \n";
    cout<<"\t\t\t9. Update Contact Information\n";
    cout<<"\t\t\t10. Share Contact with other \n";
    cout<<"\t\t\t11. Reverse Contacts book\n";
    cout<<"\t\t\t12. Exit\n";
    cout<<"\t\t\t======================================================================\n";
}
void title_print()
{
    cout<<"\t----Contacts Information----\n";
    cout<<"\t\t\t\t\t------------------------------------------------------------------\n\n";
    cout<<left<<setw(5)<<"ID"<<left<<setw(10)<<"FName"<<left<<setw(10)<<"LName"<<left<<setw(20)<<"Classification";
    cout<<left<<setw(14)<<"Fav"<<left<<setw(26)<<"Address";
    cout<<left<<setw(32)<<"Phones Number"<<left<<setw(20)<<"Emails";
    cout<<"\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";

}
int Person::count_object = 0;

Sll<Person> load() {
    ifstream input("Person.txt");
    if (!input.is_open()) {
        cout << "File could not be opened.\n";
        return Sll<Person>();
    }

    Sll<Person> loading;
    int id, n_phone, n_mail, classifi, favo;
    string frt_name, lst_name;
    string* load_phone;
    string* load_mail;
    string addr, line, temp;

    while (getline(input, line)) {
        size_t position = line.find(",");

        id = stoi(line.substr(0, position));
        line = line.substr(position + 1);

        position = line.find(",");
        frt_name = line.substr(0, position);
        line = line.substr(position + 1);

        position = line.find(",");
        lst_name = line.substr(0, position);
        line = line.substr(position + 1);

        position = line.find(",");
        n_phone = stoi(line.substr(0, position));
        line = line.substr(position + 1);

        load_phone = new string[n_phone];
        for (int i = 0; i < n_phone; i++) {
            position = line.find(",");
            load_phone[i] = line.substr(0, position);
            line = line.substr(position + 1);
        }

        position = line.find(",");
        n_mail = stoi(line.substr(0, position));
        line = line.substr(position + 1);

        load_mail = new string[n_mail];
        for (int i = 0; i < n_mail; i++) {
            position = line.find(",");
            load_mail[i] = line.substr(0, position);
            line = line.substr(position + 1);
        }

        position = line.find(",");
        classifi = stoi(line.substr(0, position));
        line = line.substr(position + 1);

        position = line.find(",");
        favo =stoi( line.substr(0, position));
        line = line.substr(position + 1);

        position = line.find(",");
        string strnum = line.substr(0, position);
        line = line.substr(position + 1);

        position = line.find(",");
        string stname = line.substr(0, position);
        line = line.substr(position + 1);

        position = line.find(",");
        string tow = line.substr(0, position);
        line = line.substr(position + 1);
        string sta = line;

        Address a(strnum, stname, tow, sta);
        Person p(frt_name, lst_name, n_phone, load_phone, n_mail, load_mail, classifi, favo, a);

        loading.Append(p);

        delete[] load_phone;
        delete[] load_mail;
    }

    input.close();
    return loading;
}

int main()
{
    bool ifExit=0;
    int choice;
    Sll<Person>contact;
    while(!ifExit)
    {
       do{
             main_menu();
        cout<<"Enter your choice : ";
        cin>>choice;
        if(choice>1&&choice<12&&choice!=7){
                if(contact.get_size()==0)
                cout<<"No contacts\n";
        }else if(choice>12 || choice<1){
        cout<<"Wrong...!\n";
        }else break;
        } while(contact.get_size()==0||choice>12 || choice<1);

        switch(choice)
        {
        case 1:
        {
            Person p;
            cout<<"---- Add a New contact ----\n";
            cin>>p;
            contact.Append(p);
        }
        break;
        case 2:
        {
            string ln;
            cout<<"Enter Last name : ";
            cin>>ln;
            size_t n=contact.get_size();
            bool if_found=1;

            for(size_t i=1; i<=n; i++)
                if(contact.get_element(i).search_by_last_name(ln))
                {
                    if(if_found){
                         title_print();
                         if_found=0;
                    }
                    cout<<left<<setw(5)<<i<<contact.get_element(i);
                }
             if(if_found)cout<<"\nThere is no contact with the last name "<<ln<<" .\n";

        }
        break;
        case 3:
        {
            size_t classifi;
             bool if_found=1;
            cout<<"Classification(Press 1(friend),2(work),3(family),4(other))";
            do{
                cin>>classifi;
                if(classifi>4||classifi<1){
                    cout<<"...Wrong! please Press 1(friend),2(work),3(family),4(other)... ";
                    if_found=0;
                }
            }while(!if_found);

            size_t n=contact.get_size();
            if_found=1;
            for(size_t i=1; i<=n; i++){
                if(contact.get_element(i).search_by_classification(classifi))
                {
                    if(if_found){
                         title_print();
                         if_found=0;
                    }
                    cout<<left<<setw(5)<<i<<contact.get_element(i);
                }
            }
             if(if_found)cout<<"\nThere is no contact in Classification of "<<contact.get_element(1).get_classification_by_string(classifi)<<" .\n";

        }
        break;
        case 4:
        {

            size_t n=contact.get_size();
            title_print();
            for(size_t i=1; i<=n; i++)
                cout<<left<<setw(5)<<i<<contact.get_element(i);
        }
        break;
        case 5:
        {
            size_t n=contact.get_size();
            bool if_one_fav=1;

            for(size_t i=1; i<=n; i++){
                if(contact.get_element(i).get_fav()==1)
                {
                    if(if_one_fav){
                            title_print();
                            if_one_fav=0;
                    }
                    cout<<left<<setw(5)<<i<<contact.get_element(i);
                }
            }
            if(if_one_fav)cout<<"\nNo Contact Favorite .\n";
        }
        break;
        case 6:
        {
            cout<<"Data save at file .\n";
            size_t n=contact.get_size();
            for(size_t i=1; i<=n; i++)
            {
                contact.get_element(i).save();
            }
        }
        break;
        case 7:
        {
            Sll<Person>called=load();
             size_t n=called.get_size();
            for(size_t i=1;i<=n;i++){
                contact.Append(called.get_element(i));
            }
            cout<<"\nLoaded from file .\n";
        }
        break;
        case 8:
        {
            size_t position;
            bool flag=1;
            size_t n=contact.get_size();
            if(n==0){
                cout<<"No contacts\n";
                break;
            }
            cout<<"What is contact do you need delete ? (write id)\n";
            while(flag)
            {
                cin>>position;
                if(position<=n&&position>=1)
                {
                    contact.delete_from_position(position);
                    flag=0;
                    cout<<"\nDone delete contact .\n";
                }
                else cout<<"\nWrong ...!\nTry again :";
            }

        }
        break;
        case 9:
        {
            size_t position;
            bool flag=1;
            size_t n=contact.get_size();

            cout<<"What is contact do you need update information ? (write id)\n";
            while(flag)
            {
                cin>>position;
                if(position<=n&&position>=1)
                {
                    Person contact_update;
                    cin>>contact_update;
                    contact.insert_from_position(position,contact_update);
                    cout<<"\nDone Update information .\n";
                    flag=0;
                }
                else cout<<"\nWrong ...!\nTry again :";
            }
        }
        break;

        case 10:
        {
            size_t position;
            bool flag=1;
            size_t n=contact.get_size();

            cout<<"What is contact do you need share ? (write id)\n";
            while(flag)
            {
                cin>>position;
                if(position<=n && position>=1)
                {
                    title_print();
                    cout<<left<<setw(5)<<position<<contact.get_element(position);
                    flag=0;
                }
                else cout<<"\nWrong ...!\nTry again :";
            }
        }
        break;
        case 11:
        {
            contact.reverse_list();

        }
        break;
        case 12:
        {
            ifExit=1;
            cout<<"\n\t\t\t\tExiting... Thank you .\n";
        }
        }
    }
    return 0;
}
