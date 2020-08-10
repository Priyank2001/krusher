#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<time.h>
#include<iomanip>
#include<fstream>
#include<vector>

using namespace std;

class login{
    public:
      char id[100];
      char pass[100];
      char*password[100];

        void getid(){
          cout << "Please enter your ID\n";
          cin >> id;
          cout << "Please enter your password\n";
          cin>>pass;
      }

      void display(){
          cout << "ID:"<<"\t"<<id<<"\n";        
          cout << "Password:"<<"\t"<<pass<<"\n";     
      }
}
// Regarding the details of the train, a class is defined
;
class detail{
    public :
      
      string train_name ;
      int train_no ;

      string boarding_point;
      string destination ;
      int clss1,clss1_fare; // number of seats in class 1 and fare
      int clss2 , clss2_fare;  // number of seats in class 2 and fare
      int d , m , y; // date of travel
      void details(){
          cout << "\tEnter the train name:\n";
          cin>>train_name;
          cout << "\tEnter the Train Number:\n";
          cin >> train_no ;
          cout << "\tEnter Boarding point:\n";
          cin>>boarding_point;
          cout << "\tEnter Destination point:\n";
          cin >> destination;
          cout<< "\tNo. of seats in class 1 and Fare of class 1\n";
          cin>>clss1>>clss1_fare;
          cout<< "\tNo. of seats in class 2 and Fare of class 2\n";
          cin>>clss2>>clss2_fare;
          cout << "Enter date, month, year of travel\n";
          cin>>d>>m>>y;
      }
      void displaydetail(){
          cout<<train_no<<"\t"<<train_name<<"\t"<<boarding_point<<"\t"<<destination<<"\t";
          cout << clss1<<"\t"<<clss1_fare<<"\t"<<clss2<<"\t"<<clss2_fare<<"\t";
          cout<<d<<"-"<<m<<"-"<<y<<"\t\n";
      }    
};
// for the reservation thing
class reser{

    public:
    int pnr;
    int train_no;
    char train_name[100];
    char boarding_point[100];
    char destination[100];
    vector<char *> pname;
    int age[20];
    char clas[10];
    int nosr;  //Number of seats required
    int i ;
    int d,m,y;
    int con;

    float amc;
    void getresdet()
    {
        cout<<"Enter the details as follows\n";
        cout<<"Train no:";
        cin>>train_no;
        cout<<"Train name:";
        cin >> train_name;
        cout<<"Boarding point:";
        cin>>boarding_point;
        cout<<"Destination pt:";
        cin>>destination;
        cout<<"No of seats required:";
        cin>>nosr;
        for(i=0; i<nosr ; i++)
        {
            cout<<"Passenger name:";
            char v1[50];
            cin>>v1;
            pname.push_back(v1);
            cout<<"Passenger age:";
            cin>>age[i];
        }
     cout<<"Enter the class f-first class s-second class:";
     cin >> clas ;
        cout<<"Date of travel:";
        cin>>d>>m>>y;
     //   cout<<"Enter the concession category\n";
     //   cout<<"1.Military\n2.Senior citizen\n";
     //   cout<<"3.Children below 5 yrs\n4.None\n";
     //   cin>>con;
     //   cout<<"............END OF GETTING DETAILS............\n";
    }
    int amount = 0;
    void display_data(){
        cout<<train_no<<"\t"<<train_name<<"\t"<<boarding_point<<"\t"<<destination<<"\t";


         cout<< "\n"; 
    }


};

//void admin();
//void user();
void enquiry();
void displaypassdetail();
void reserve();
void cancell();
void res();
void manage();


void admin(){
    char pass[100] = "adminmode";
    char x[100];
    cout<<"Please enter your password\n";
    cin >> x;
    int choice;
     detail a;
     fstream f;
    if(strcmp(pass, x)==0)
      {
          cout << "\tEntered Admin Mode\n";
          cout<<"------------------------------Administrator's Menu--------------------------------------------\n";
          cout<<"1.\tCreate Database\n";
          cout<<"2.\tAdd Details\n";
          cout<<"3.\tDisplay Details\n";
          cout<<"4.\tPassenger Details\n";
          cout <<"5.\tUser Management Menu\n";

          cout<< "Enter your choice\n";
          int ch;
          char c;
          cout<<endl;
          cin>> choice;

          switch(choice)
            {
                case  1 :
                 {   f.open("t.txt",ios::out|ios::binary);
                do
                {
                    a.details();
                    f.write((char *) & a,sizeof(a));
                    cout<<"Do you want to add one more record?\n";
                    cout<<"y-for Yes\nn-for No\n";
                    cin>>c;
                }
                while(c=='y');
                f.close();
                break;}
                case 2 :
                    {
                        f.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
                a.details();
                f.write((char *) & a,sizeof(a));
                f.close();
                admin();
                break;
                

                    }
                case 3 :
                    {
                        f.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
                f.seekg(0);
                while(f.read((char *) & a,sizeof(a)))
                {
                    a.displaydetail();
                }
                f.close();
                break;
                    }
                case 4 :
                    {
                        displaypassdetail();
                    }
                case 5 :{
                    manage();
                }

             }
      }
    else
    {
          cout<< "login attempt failed\n";
     //    admin();
    }
    
    
     

};
void user(){
    cout<<"\t-------------------------Welcome to User Mode---------------------------\n";
    login a;
    char id[100],password[100];
    int choice;

     fstream f;
    f.open("id.txt",ios::in|ios::out|ios::binary);
  //  char id[100];
 //   puts("Enter your id:\n");
  //  gets(id);
  //  cout<<"Enter your password:\n";
    

    cout<<"\tPlease Enter your ID\n";
   cin >>  id;
    cout<<"\tPLease enter your password\n";
    cin >> password;

    while(f.read((char *) & a,sizeof(a)))
 {if(strcmp(a.id,id) != 0 && strcmp(a.pass,password)!=0)
      {
        cout<<"1.Reserve\n2.Cancell\n3.Enquiry\n4.Return to the main menu\n";
                cout<<"Enter your choice:";
                cin>>choice;
                cout<<endl;

                switch(choice)
                  {
                      case 1 :
                        {
                           reserve();
                           break;
                        }
                        case 2:
                        {
                            cancell();
                            break;
                        }
                        case 3:
                        {
                            enquiry();
                            break;
                        }
                        case 4:
                        {
                             goto h;
                        }
                      
                  }
      }
  else
   {
        cout << "Wrong Credentials\n";
         goto h;
    }
   h:
   ;} 
}
    




void reserve(){
  
    int ch;
    
        cout<<"1.Reserve\n2.Return to the main menu\n";
        cout<<"Enter your choice:";
        cin>>ch;
        cout<<endl;
        switch(ch)
        {
        case 1:
            res();
            break;
        }
    
    while(ch==1);
    getch();
}

void res(){
    int choice;
    
    detail x;
    reser y;
    
    fstream f1,f2;
    time_t t;
    f1.open("t.txt",ios::in|ios::binary);
    f2.open("p.txt",ios::in|ios::binary|ios::app);
    
    y.getresdet();
    
    int r_class1 = x.clss1 ;

    int r_class2 = x.clss2 ;
    char a[10] = "f";
    char b[10] = "s" ;

    while(f1.read((char *)& x, sizeof(x) ))
      {
         if(x.train_no == y.train_no)
           {
                if(strcmp(y.clas,a) == 0)
                {
                if(x.clss1 >= y.nosr  && x.clss1 > 0)
                  {
                     x.clss1 -= y.nosr;
                     f1.write((char*) & x.clss1, sizeof(x.clss1));
                     srand((unsigned) time(&t));
                     y.pnr = rand();
                     
                     y.amount += y.nosr*x.clss1_fare;
                     f2.write((char*) & y, sizeof(y));
                     y.display_data();
                     cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

                     cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~Reservation is Completed~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                     cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

                  }
                  else if(strcmp(y.clas,b) == 0)
                  {
                     if(y.nosr <= x.clss2 && x.clss2>0)
                       {
                           x.clss2 -= y.nosr;
                           f1.write((char* ) & x.clss2,sizeof(x.clss2));
                           srand((unsigned) time(&t));
                           y.pnr = rand();
                           y.amount += y.nosr * x.clss2_fare ;
                           f2.write((char *) & y , sizeof(y));
                           y.display_data();
                            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

                     cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~Reservation is Completed~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                     cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

                       }

                       else
                       {
                            cout << "Sorry!!!!!!!!\n No seats Available";
                       }
                       

                }
           }
      }

         else
         {
               cout << "\n \t Wrong Train Number";
         }


    f1.close();
    f2.close()  ;

}
}

void cancell(){;}

void enquiry(){
    
    fstream f;
    f.open("t.txt",ios::in|ios::out|ios::binary);
    detail a;
    while(f.read((char *) & a,sizeof(a)))
    {
        a.displaydetail();
    }
    getch();
}

void displaypassdetail(){
    fstream f;
    reser b;
    f.open("p.txt",ios::in|ios::out|ios::binary);
    f.seekg(0);
    while(f.read((char *) & b,sizeof(b)))
    {
        b.display_data();
    }
    f.close();
    getch();
}

void manage(){
        int ch;
    fstream f;
    char c;
    login a;
    cout<<".........WELCOME TO THE USER MANAGEMENT MENU........\n";
    do
    {
        cout<<"1.Create id data base\n2.Add details\n";
        cout<<"3.Display details\n4.Return to the main menu\n";
        cout<<"Enter your choice:";
        cin>>ch;
        cout<<endl;
        switch(ch)
        {
        case 1:
            f.open("id.txt",ios::out|ios::binary);
            do
            {
                a.getid();
                f.write((char *) & a,sizeof(a));
                cout<<"Do you want to add one more record\n";
                cout<<"y-Yes\nn-No\n";
                cin>>c;
            }
            while(c=='y');
            f.close();
            break;
        case 2:
            f.open("id.txt",ios::in|ios::out|ios::binary|ios::app);
            a.getid();
            f.write((char *) & a,sizeof(a));
            f.close();
            break;
        case 3:
            f.open("id.txt",ios::in|ios::out|ios::binary);

            f.seekg(0);
            while(f.read((char *) & a,sizeof(a)))
            { 
                a.display();
            }
            f.close();
            break;
        }
    }
    while(ch<=3);
    getch();
}

int main(){
    

    int ch;
    cout<<"-------------------------------------------------------------------------------------------------------\n";
    cout<<"-------------------------------Welcome to the Railway Reservation system-------------------------------\n";
    cout<<"-------------------------------------------------------------------------------------------------------\n";
    cout<<"--------------------------------------------Main Menu--------------------------------------------------\n";
    

   
{
    cout<<"\t1.  \tAdmin Mode\n";
    cout<<"\t2.  \tUser Mode\n";
   // cout<<"\t3.  \t"
    cout<<"\t3.  \tExit\n";
     cin >> ch;
    switch(ch)
    {
        case 1 : 
                 {admin();
                 break;}
        case 2 : 
                { user();
                 break;}
        case 3 : exit(0);

    }
}



 return 0;
}



