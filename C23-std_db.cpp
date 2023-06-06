#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class student
{
    int rollno,divno;
    string name,address;

    public:
    student()
    {
        rollno=0;
        divno=0;
        name=' ';
        address=' ';
    }
    void putdata();
    void getdata();
    int getRollno();
};
void student::getdata()
{
    cout<<"\nEnter the name of student-->";
    cin>>name;
    cout<<"\nEnter the roll no of student-->";
    cin>>rollno;
    cout<<"\nEnter the div no -->";
    cin>>divno;
    cout<<"\nEnter the home address-->";
    cin>>address;
}
void student::putdata()
{
    cout<<"\nThe name--> "<<name;
    cout<<"\nThe Division no--> "<<divno;
    cout<<"\nThe Roll No --> "<<rollno;
    cout<<"\nThe address --> "<<address<<endl;
}
int student::getRollno()
{
    return rollno;
}
class file
{
    ifstream fin;
    ofstream fout;
    fstream fs;

    public:
    void insert();
    void display();
    void search(int);
    int Delete(int);
    int edit(int);
};
void file::insert()
{
    student s;
    s.getdata();
    fout.open("stuDB",ios::ate | ios::app);
    fout.write((char*)&s,sizeof(s));
    fout.close();
}
void file::display()
{
    student s;
    fin.open("stuDB");
    fin.seekg(0,ios::beg);
    while(fin.read((char*)&s,sizeof(s)))
    {
        s.putdata();
    }
    fin.close();
}
void file::search(int roll)
{
    student s;
    int flag=0;
    fin.open("stuDB");
    fin.seekg(0,ios::beg);
    while(fin.read((char*)&s,sizeof(s)))
    {
        if(s.getRollno()==roll)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        cout<<"\nRecord Not Found\n";
    }
    else if(flag==1)
    {
        cout<<"\nRecord Found\n";
        s.putdata();
    }
    fin.close();
}
int file::Delete(int roll)
{
    student s;
    fin.open("stuDB");
    fout.open("temp",ios::ate |  ios::app);
    fin.seekg(0,ios::beg);
    int flag=0;
    while(fin.read((char*)&s,sizeof(s)))
    {
        if(s.getRollno()==roll)
        {
            flag=1;
        }
        else
        {
            fout.write((char*)&s,sizeof(s));
        }
    }
    fout.close();
    fin.close();
    remove("stuDB");
    rename("temp","stuDB");
    return flag;
}
int file::edit(int roll)
{
    student s;
    fs.open("stuDB");
    fs.seekg(0,ios::beg);
    int flag=0;
    while(fs.read((char*)&s,sizeof(s)))
    {
        if(s.getRollno()==roll)
        {
            flag=1;
            cout<<"\nEnter new Details-->\n";
            s.getdata();
            fs.seekp((int)fs.tellg()-sizeof(s),ios::beg);
            fs.write((char*)&s,sizeof(s));
        }
    }
    fs.close();
    return flag;
}
int main()
{
    file f;
    int ch,roll;
    int flag=0;
    do
    {
        cout<<"\n****************MENU***************\n";
        cout<<"\t***************\n";
        cout<<"1.List Table\n2.Display\n3.Insert\n4.Search\n5.Delete\n6.Edit\nEnter your choice-->";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                int n;
                cout<<"\nEnter the number of records you want to insert-->";
                cin>>n;
                if(flag==0)
                {
                    for(int i=0;i<n;i++)
                    {
                        f.insert();
                    }
                    flag=1;
                }
                else if(flag==1)
                {
                    cout<<"\nDatabase  is already listed if you want to add record then plz choose option 3.\n";
                }
                break;
            }
            case 2:
            {
                f.display();
                break;
            }
            case 3:
            {
                f.insert();
                break;
            }
            case 4:
            {
                cout<<"\nEnter the roll no of student you wants to searched-->";
                cin>>roll;
                f.search(roll);
                break;
            }
            case 5:
            {
                cout<<"\nEnter the roll no of student you wants to delete-->";
                cin>>roll;
                int res=f.Delete(roll);
                if(res==1)
                {
                    cout<<"\nRecord Deleted Successfully\n";
                } 
                else if(res==0)
                {
                    cout<<"\nRecord Not Found\n";
                }  
                break;
            }
            case 6:
            {
                cout<<"\nEnter the roll no of student you wants to edit-->";
                cin>>roll;
                int res=f.edit(roll);
                if(res==1)
                {
                    cout<<"\nRecord Edited Successfully\n";
                } 
                else if(res==0)
                {
                    cout<<"\nRecord Not Found\n";
                }  
                break;
            }
            default:
            {
                cout<<"\nInvalid Choice\n";
                exit(0);
            }
        }
    }while(ch!=7);
    return 0;
}