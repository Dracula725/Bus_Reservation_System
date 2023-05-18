#include <iostream>
#include <string.h>
#include<bits/stdc++.h>
using namespace std;

static int p = 0;
class a{
  char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];
public:
  void install();
  void allotment();
  void empty();
  void show();
  void avail();
  void position(int i);
}
bus[10];

void a::install()
{
  cout<<"-----BUS ASSIGNMENT-----"<<endl;
  cout<<"\tEnter bus no: ";
  cin>>bus[p].busn;
  cout<<"\tEnter Driver's name: ";
  cin>>bus[p].driver;
  cout<<"\tArrival time: ";
  cin>>bus[p].arrival;
  cout<<"\tDeparture time: ";
  cin>>bus[p].depart;
  cout<<"\tStart Point: ";
  cin>>bus[p].from;
  cout<<"\tEnd Point: ";
  cin>>bus[p].to;
  bus[p].empty();
  p++;
}

void a::allotment()
{
  int seat;
  char number[5];
  top:
  cout<<"Enter Bus no: ";
  cin>>number;
  int n;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
  while(n<=p)
  {
    cout<<"\nEnter Seat Number: ";
    cin>>seat;
    if(seat>32)
    {
      cout<<"\nThe maximum number of seats available in this bus is 32.\n";
    }
    else
    {
    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
      {
        cout<<"Enter name of Student: ";
        cin>>bus[n].seat[seat/4][(seat%4)-1];
        break;
      }
    else
      cout<<"The seat no. is already reserved.\n";
      }
      }
    if(n>p)
    {
      cout<<"Invalid Bus Number"<<endl;
      goto top;
    }
  }

void a::empty()
{
  for(int i=0; i<8;i++)
  {
    for(int j=0;j<4;j++)
    {
      strcpy(bus[p].seat[i][j], "Empty");
    }
  }
}

void a::show()
{
  int n;
  char number[5];
  cout<<"Enter bus no: ";
  cin>>number;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
while(n<=p)
{
  cout<<"---------------------------------------------"<<endl;
  cout<<"Bus no: \t"<<bus[n].busn<<"\tArrival time: \t"
  <<bus[n].arrival
  <<"\nDriver: \t"<<bus[n].driver<<"\tDeparture time:"<<bus[n].depart
  <<"\nFrom: \t\t"<<bus[n].from<<"\tTo: \t\t"<<
  bus[n].to<<"\n";
  cout<<"---------------------------------------------"<<endl;
  bus[0].position(n);
  int a=1;
  for (int i=0; i<8; i++)
  {
    for(int j=0;j<4;j++)
    {
      a++;
      if(strcmp(bus[n].seat[i][j],"Empty")!=0)
      cout<<"\nSeat no "<<(a-1)<<" is reserved in the name of "<<bus[n].seat[i][j]<<"."<<endl;
    }
  }
  break;
  }
  if(n>p)
    cout<<"Enter correct bus no: ";
}

void a::position(int l)
{
  int s=0;p=0;
  for (int i =0; i<8;i++)
  {
    cout<<"\n";
    for (int j = 0;j<4; j++)
    {
      s++;
      if(strcmp(bus[l].seat[i][j], "Empty")==0)
        {
          cout.width(5);
          cout.fill(' ');
          cout<<s<<".";
          cout.width(10);
          cout.fill(' ');
          cout<<bus[l].seat[i][j];
          p++;
        }
        else
        {
        cout.width(5);
        cout.fill(' ');
        cout<<s<<".";
        cout.width(10);
        cout.fill(' ');
        cout<<bus[l].seat[i][j];
        }
      }
    }
  cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn;
  }

void a::avail()
{
  for(int n=0;n<p;n++)
  {
    cout<<"---------------------------------------------"<<endl;
    cout<<"Bus no: \t"<<bus[n].busn<<endl;
    cout<<"Driver: \t"<<bus[n].driver<<endl;
    cout<<"Arrival time: \t"<<bus[n].arrival<<endl;
    cout<<"Departure Time:  "<<bus[n].depart<<endl;
    cout<<"From: \t"<<bus[n].from<<endl;
    cout<<"To: \t"<<bus[n].to<<endl;
    cout<<"---------------------------------------------"<<endl;

  }
}

int main()
{
int w;
    while(1){
        bus:
        cout<<"-------BUS RESERVATION SYSTEM-------"<<endl;
        cout<<"1 . Student Login"<<endl;
        cout<<"2 . Admin Login"<<endl;
        cout<<"3 . Exit"<<endl;
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        if(choice==1){
            string email;
            string password;
            cout<<"**************Student Login**************"<<endl;
            hi:
            cout<<"Enter Email: ";
            cin>>email;
            cout<<"Enter your password: ";
            cin>>password;
            reverse(email.begin(),email.end());
            email.erase(0,13);
            reverse(email.begin(),email.end());
            if(password==email){
                cout<<"\nLogin Successful"<<endl;
                stu:
                cout<<"-----TRANSPORT REGISTRATION-----"<<endl;
                cout<<"1 . Seat Number Reservation"<<endl;
                cout<<"2 . Show Available Seats"<<endl;
                cout<<"3 . Show Available Buses"<<endl;
                cout<<"4 . Exit"<<endl;
                cout<<"Enter your choice: ";
                cin>>w;
                if(w==1){
                    cout<<"Seat Number Reservation"<<endl;
                    bus[p].allotment();
                    goto stu;
                }
                else if(w==2){
                    cout<<"Show Available Seats"<<endl;
                    bus[0].show();
                    goto stu;
                }
                else if(w==3){
                    cout<<"Show Available Buses"<<endl;
                    bus[0].avail();
                    goto stu;
                }
                else if(w==4){
                    goto bus;
                }
                else{
                    cout<<"Invalid Choice"<<endl;
                }
            }
            else{
                cout<<"\nInvalid Password\n";
                goto hi;
            }

        }
        else if(choice==2){
            cout<<"**************Admin Login**************"<<endl;
            string email;
            string password;
            hii:
            cout<<"Enter Email: ";
            cin>>email;
            cout<<"Enter your password: ";
            cin>>password;
            reverse(email.begin(),email.end());
            email.erase(0,13);
            reverse(email.begin(),email.end());
            if(password==email){
                cout<<"\nLogin Successful\n";
                adm:
                cout<<"-----TRANSPORT ASSIGNING-----"<<endl;
                cout<<"1 . Assign Buses"<<endl;
                cout<<"2 . Show Available Buses"<<endl;
                cout<<"3 . Exit"<<endl;
                cout<<"Enter your choice: ";
                cin>>w;
                if(w==1){
                    cout<<"Assign Buses"<<endl;
                    bus[p].install();
                    goto adm;
                }
                else if(w==2){
                    cout<<"Show Available Buses"<<endl;
                    bus[0].avail();
                    goto adm;
                }
                else if(w==3){
                    goto bus;
                }
                else{
                    cout<<"Invalid Choice"<<endl;
                }
            }
            else{
                cout<<"\nInvalid Password\n";
                goto hii;
            }
        }
        else if(choice==3){
            cout<<"Exit"<<endl;
            exit(0);
        }
        else{
            cout<<"Invalid Choice"<<endl;
        }
    }

}
