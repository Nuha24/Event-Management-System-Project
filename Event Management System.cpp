#include<bits/stdc++.h>
#include<string.h>
#include<conio.h>
#define max 100
using namespace std;
class User
{
public:
    char name[1000];
    char address[1000];
    char id[1000];
    char phone[12];
    char date[20];
    float payment_advance;
    int booking_id;
};

class Event
{
public:
    int time;
    char stype;
    string ven;
    int gs;
    int EventNumber;
    int cost;
    int info;
    class User usr;
    class Event addEvent(int);
    void searchEvent(int);
    void deleteEvent(int);
    void displayEvent(Event);
};
class Event Events[max];
int cnt=0;
Event Event::addEvent(int ev)
{
    class Event Event;
    Event.EventNumber=ev;
    cout<<"\n    Total Guest : ";
    cin>>Event.gs;
    cout<<"\n    Total Time (in minutes) : ";
    cin>>Event.time;
    cout<<"\n    Venue Name : ";
    cin>>Event.ven;
    Event.info=0;
    cout<<"\n    Event Added Successfully!";
    getch();
    return Event;
}
void Event::searchEvent(int ev)
{
    int i,found=0;
    for(i=0; i<cnt; i++)
    {
        if(Events[i].EventNumber==ev)
        {
            found=1;
            break;
        }
    }
    if(found==1)
    {
        cout<<"\n\t\t\t\t\t--------Event Details--------\n\n";
        if(Events[i].info==1)
        {
            cout<<"\n   Event is Booked. ";
        }
        else
        {
            cout<<"\n\n   Event is Available. ";
        }
        displayEvent(Events[i]);
        getch();
    }
    else
    {
        cout<<"\n   Event not Found. ";
        getch();
    }
}
void Event::displayEvent(Event tempEvent)
{
    cout<<"\n\n   User Information  \n";
    cout<<"\n   Event Number : "<<tempEvent.EventNumber;
    cout<<"\n   Total Guest : "<<tempEvent.gs;
    cout<<"\n   Total Time : "<<tempEvent.time;
    cout<<"\n   Venue Name : " <<tempEvent.ven; //Your Preferred Venue For Booking
}
class EventMen:protected Event
{
public:
    void checkIn();
    void getAvailEvent();
    void searchUser(char *);
    void checkOut(int);
    void GuestSummary(char *);
};
void EventMen::GuestSummary(char *uname)
{
    system("cls");
    int z;
    cout<<"\n\n   For Guest Info Type 1 & To Know About Us Type 2 : ";
    cin>>z;
    if(z==1)
    {
    if(cnt==0)
    {
        cout<<"\n\n  No Event Booked !!";
    }
    for(int i=0; i<cnt; i++)
    {
        if(Events[i].info==1)
        {
            cout<<"\n\t\t\t\t___________ Guest Summary ___________\n\n";
            cout<<"\n\n   User First Name : "<<Events[i].usr.name;
            cout<<"\n\n   Event Number : "<<Events[i].EventNumber;
            cout<<"\n\n   Address (only city) : "<<Events[i].usr.address;
            cout<<"\n\n   Phone : "<<Events[i].usr.phone;
        }
    }
    }
    else if(z==2)
    {
    cout<<"\n\t\t\t\t          About Event Management          \n\n";
    cout<<"\n Celebrate any occassion with us to make your event more special in reasonale price.\n You can also customize the decors.\n We work on any venue you prefer "<<endl;
    cout<<" Payment Methods : Bkash/Nagad; \n Or Your Nearest XY Bank"<<endl;
    cout<<" Contact NOW Email : eventmanagement24@gmail.com"<<endl;
    cout<<" Phone: 01234567890" <<endl;
    cout<<" Address: Chittagong, Bangladesh";
    cout<<"\n Saturday-Thursday \n Opening & Closing Hour : 9AM To 9PM"<<endl;
    cout<<" Appointments: facebook.com"<<endl;
    cout<<" Thank You :) ! "<<endl<<endl;
    }
    getch();
}
void EventMen::checkIn()
{
    int i,found=0,ev;
    class Event Event;
    cout<<"\n   Enter Event number : ";
    cin>>ev;
    for(i=0; i<cnt; i++)
    {
        if(Events[i].EventNumber==ev)
        {
            found=1;
            break;
        }
    }
    if(found==1)
    {
        if(Events[i].info==1)
        {
            cout<<"\n   Sorry, We Are already Booked.";
            getch();
            return;
        }
        system("cls");
        cout<<"\n\t\t\t\t___________ Book Event ___________\n\n";
        cout<<"\n\n   Enter booking id: ";
        cin>>Events[i].usr.booking_id;
        cout<<"\n\n   Enter User Name(First Name): ";
        cin>>Events[i].usr.name;
        cout<<"\n\n   Enter Address (only city): ";
        cin>>Events[i].usr.address;
        cout<<"\n\n   Enter Phone: ";
        cin>>Events[i].usr.phone;
        cout<<"\n\n   Enter Date: ";
        cin>>Events[i].usr.date;
        cout<<"\n\n   Enter Advance Payment: ";
        cin>>Events[i].usr.payment_advance;
        Events[i].info=1;
        cout<<"\n\n   User Logged-in Successfully..";
        getch();
    }
}
void EventMen::getAvailEvent()
{
    int i,found=0;
    for(i=0; i<cnt; i++)
    {
        if(Events[i].info==0)
        {
            displayEvent(Events[i]);
            cout<<"\n\n   Press Enter for Next Event\n";
            found=1;
            getch();
        }
    }
    if(found==0)
    {
        cout<<"\n   All Events Date Are Booked";
        getch();
    }
}
void EventMen::searchUser(char *uname)
{
    int i,found=0;
    for(i=0; i<cnt; i++)
    {
        if(Events[i].info==1 && stricmp(Events[i].usr.name,uname)==0)
        {
            system("cls");
            cout<<"\n\n\t\t\t\t        _________ User Information  _________ ";
            cout<<"\n\n   User Name: "<<Events[i].usr.name;
            cout<<"\n\n   Event Number: "<<Events[i].EventNumber;
            cout<<"\n\n   Press Enter For Next Record. ";
            found=1;
            getch();
        }
    }
    if(found==0)
    {
        cout<<"\n\n   No Event Found. ";
        getch();
    }
}
class Account
{
    int acc_no;
    int amount;
public:
    Account()
    {
        cout<<"\n\n Enter Account No : ";
        cin>>acc_no;
        amount = 0;
    }
    void deposit(int num)
    {
        if(num == acc_no)
        {
            string date;
            cout<<"\n   Enter Amount : ";
            cin>>amount;
            cout<<"\n   Transferred To Account No 211224. "<< endl;
            cout<<"\n   Branch Name : XY Bank"<< endl;
            cout<<"\n   Transaction Date : ";
            cin>>date;
            cout<<endl;
            cout<<"   Event Confirmed, Thank You :)! "<< endl;
        }
        else
            cout<<"\n   Incorrect account number. Try Again. "<<endl;
    }
};
void EventMen::checkOut(int EventNum)
{
    int i,found=0,TotalGuests,TotalTime,j;
    double billAmount=0;
    string p;
    for(i=0; i<cnt; i++)
    {
        if(Events[i].info==1 && Events[i].EventNumber==EventNum)
        {
            found=1;
            break;
        }
    }
    if(found==1)
    {
        system("cls");
        cout<<"\n\n\t\t\t\t        _________ Event Details  _________ ";
        cout<<"\n\n\n   Enter Number Of Guest:  ";
        cin>>TotalGuests;
        cout<<"\n\n   Total Time(In Minutes) :  ";
        cin>>TotalTime;
        cout <<"\n\n   Total Table Booked : "; //one table = minimum 6 person
        j = ceil(TotalGuests/6);
        cout << j <<endl;
        double cp;
        double TotalStaff, CostH, CostM, OneStaffCost,X, TotalFoodCost, AverageCost, DepositAmount,TotalCost;
        double PerHourCost = 30.00;
        double PerMinCost  = 0.50;
        double CostOfMeal  = 100.00;
        double CarParking  = 1000.00;
        double Lighting    = 1500.00;
// Total Staff Number
        X = TotalGuests / 10;
        TotalStaff = ceil(X);
// One Staffs Cost
        CostM = (TotalTime % 60) * PerMinCost;
        CostH = (TotalTime / 60) * PerHourCost;
        OneStaffCost = CostM+CostH;
// Cost of Food
        TotalFoodCost = (TotalGuests * CostOfMeal) ;

// Average Cost Per Person
        AverageCost = (TotalFoodCost / TotalGuests);

// Total Cost
        TotalCost = TotalFoodCost + (OneStaffCost * TotalStaff)+ Lighting + CarParking;
// Advance (30%) Amount
        DepositAmount = TotalCost * (.30);
        cout<<"\n\n\t\t\t\t __________Event Costing Details__________\n\n";
        cout<<"\n\n  User Name : "<<Events[i].usr.name;
        cout<<"\n\n  Event Number : "<<Events[i].EventNumber;
        cout<<"\n\n  Address : "<<Events[i].usr.address;
        cout<<"\n\n  Phone : "<<Events[i].usr.phone;
        cout<<"\n\n  Number Of Staffs : " << TotalStaff << fixed << setprecision(3) << endl<< endl;
        cout<<"  Average Cost (Per Staff) : "  << OneStaffCost <<endl<< endl;
        cout<<"  Total  Food Cost : "<< TotalFoodCost << endl <<endl;
        cout<<"  Average Cost (Per Person) : "  << AverageCost<<endl<<endl;
        cout<<"  Total Amount : "  << TotalCost << endl<< endl;
        cout<<"  To reserve the event , Please Deposit 30% of Total Amount including VAT" << endl<< endl;
        cout<<"  Deposit Needed : "  << DepositAmount << endl<< endl;
        cout<<"  Advance Paid: "<<Events[i].usr.payment_advance<<" /-"<<endl;
        cout<<"\n  Total Payable: "<<TotalCost - Events[i].usr.payment_advance<<"/- only";
        Events[i].info=0;
        Account acc;
        int num;
        cout<<"\n Re-enter Account No : ";
        cin>>num;
        acc.deposit(num);
        cout<< endl<<endl;
    }
    getch();
}
void manageEvents()
{
    class Event Event;
    int opt,ev,i,flag=0;
    char ch;
    do
    {
        system("cls");
        cout<<"\n\t\t\t\t        _________ Manage Events _________";
        cout<<"\n\n 1. Add Event";
        cout<<"\n\n 2. Search Event";
        cout<<"\n\n 3. Back to Main Menu";
        cout<<"\n\n    Select Option: ";
        cin>>opt;
        switch(opt)
        {
        case 1:
            cout<<"\n    Enter Event Number : ";
            cin>>ev;
            i=0;
            for(i=0; i<cnt; i++)
            {
                if(Events[i].EventNumber==ev)
                {
                    flag=1;
                }
            }
            if(flag==1)
            {
                cout<<"\n  Event Number is Present. \n\n Please Enter An Unique Number : ";
                flag=0;
                getch();
            }
            else
            {
                Events[cnt]=Event.addEvent(ev);
                cnt++;
            }
            break;
        case 2:
            cout<<"\n   Enter Event number: ";
            cin>>ev;
            Event.searchEvent(ev);
            break;
        case 3:
            break;
        default:
            cout<<"\n\n   Error, Please Enter Correct Option ";
            break;
        }
    }
    while(opt!=3);
}
int main()
{
    class EventMen hm;
    int i,j,opt,ev,f;
    char ch;
    char uname[1000];
    system("cls");
    do
    {
        system("cls");
        cout<<"\t\t\t\t    -------------------------------"<<endl;
        cout<<"\t\t\t\t     |   EVENT MANAGEMENT SYSTEM   |"<<endl;
        cout<<"\t\t\t\t    -------------------------------"<<endl;
        cout<<"\n------------------------------------------------------------------------------------------------------------------------\n";
        cout<<"\n-------------------------------------------- Event Details -------------------------------------------------------------"<<endl;
        cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"\n\t\t\t\t         1. Manage Events ";
        cout<<"\n\t\t\t\t         2. Book Event ";
        cout<<"\n\t\t\t\t         3. Available & Booked Event Info";
        cout<<"\n\t\t\t\t         4. Search User ";
        cout<<"\n\t\t\t\t         5. Costings of Event ";
        cout<<"\n\t\t\t\t         6. About Us & Guest Summary ";
        cout<<"\n\n   Enter Option:  " ;
        cin>>opt;
        switch(opt)
        {
        case 1:
            manageEvents();
            break;
        case 2:
            if(cnt==0)
            {
                cout<<"\n   Events data is not available.\n\n   Please add the Events first.";
                getch();
            }
            else
                hm.checkIn();
            break;
        case 3:
            if(cnt==0)
            {
                cout<<"\n   Events data is not available.\n\n   Please add the Events first.";
                getch();
            }
            else
                hm.getAvailEvent();
            break;
        case 4:
            if(cnt==0)
            {
                cout<<"\n   Events are not available.\n\n   Please add the Events first.";
                getch();
            }
            else
            {
                cout<<"\n\n   User Name : ";
                cin>>uname;
                hm.searchUser(uname);
            }
            break;
        case 5:
            if(cnt==0)
            {
                cout<<"\n   Events are not available.\n\n   Please add the Events first.";
                getch();
            }
            else
            {
                cout<<"\n\n   Enter Event Number : ";
                cin>>ev;
                hm.checkOut(ev);
            }
            break;
        case 6:
            hm.GuestSummary(uname);
            break;
        case 7:
            cout<<"\n   THANK YOU! ";
            break;
        default:
            cout<<"\n\n   Please Enter correct option ";
            break;
        }
    }
    while(opt!=7);
    getch();
}
