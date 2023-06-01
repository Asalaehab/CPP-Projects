/*Asala Ehab Mohmed(20201020)(S33)
Abdullah Yasser Albunni(20200725)(S34)*/
#include <iostream>

using namespace std;

float total=0, allow=0, rejeted=0;

void check_daynumber(int daynumber);
void check_starttime(int starttime);
void check_endtime(int endtime);
void check_travelplane(string travelway,float fees);
void check_traveltaxi(string travelway,float cost);
void check_travelcar(string travelway,float pay,float distance,float par);
void check_seminar(string replay,float con_cost);
void check_accommondiation(float acco);
void check_meals(float breakfast,float lunch,float dinner,int starttime,int endtime,int daynumber,int i);
void Total_expenses_rejected();

int main()
{   int daynumber;
    cout<<"how many days did you spent on the trip?\n";
    cin>>daynumber;
    check_daynumber(daynumber);
    int starttime,endtime;
    float ticket = 0,cost = 0 ,pay= 0,distance = 0,par=0,con_cost=0,acco = 0,breakfast =0,lunch = 0,dinner = 0;
    cout<<"enter the start time\n";
    cin>>starttime;
    check_starttime(starttime);
    cout<<"enter the end time\n";
    cin>>endtime;
    check_endtime(endtime);
    string travelway,replay;
    for(int i=1;i<=daynumber;i++)
    {
     cout<<"DAY:"<<i<<"\n";
    cout<<"what is your transportation for this day (plane) or (car) or (taxi) (choose from them in small letter )\n";
    cin>>travelway;
    if(travelway=="plane"){
        cout<<"how much its ticket cost\n";
        cin>>ticket;
        check_travelplane(travelway,ticket);}
    else if (travelway=="taxi")
    {
        cout<<"how much dose it cost\n";
        cin>>cost;
        check_traveltaxi( travelway, cost);
    }
    else{
        cout<<"are you travel by (rentedcar) or (owncar):\n";
        cin>>travelway;
        if (travelway=="rentedcar"){
            cout<<"how much did you pay:\n";
            cin>>pay;
        }else{
            cout<<"how much kilometers did you drive:\n";
            cin>>distance;
            cout<<"how much did you pay for parking:\n";
            cin>>par;
        }
        check_travelcar(travelway, pay, distance, par);
    }cout<<"Are you attend any seminar or  conference:\n";
    cin>>replay;
     if(replay=="yes"){
        cout<<"how much did you pay?\n";
        cin>>con_cost;
         check_seminar(replay,cost);
     }

        cout<<"how much did you pay in the accommodation for that day?\n";
        cin>>acco;
        check_accommondiation(acco);
        cout<<"how much did you pay for breakfast?\n";
        cin>>breakfast;
        cout<<"how much did you pay for lunch?\n";
        cin>>lunch;
        cout<<"how much did you pay for dinner?\n";
        cin>>dinner;
        check_meals(breakfast, lunch, dinner, starttime, endtime, daynumber,i);
    }
    Total_expenses_rejected();
    return 0;
}


void check_daynumber(int daynumber)
{
    if(daynumber>=1)
    {
        cout<<"The number of days = "<<daynumber<<endl;
    }
    else
    {
        cout<<"Please enter Valid number of days"<<endl;
    }
}
void check_starttime(int starttime)
{
    if(starttime>0)
        cout<<"The Depurture time = "<<starttime<<endl;
    else
        cout<<"Please enter Valid number"<<endl;
}
void check_endtime(int endtime)
{
    if (endtime>0)
        cout<<"The Arrival time = "<<endtime<<endl;

        else
            cout<<"Please enter Valid number"<<endl;
}
void check_travelplane(string travelway, float fees)
{
    if (travelway=="plane")
    {
        if(fees>0)

        {   allow=allow+fees;
            total=total+fees;
            cout<<"The fees of the plane = "<<fees<<endl;
        }
        else{
            cout<<"Please enter Valid number"<<endl;
        }
    }

}
void check_traveltaxi(string travelway,float cost)
{
    if(travelway=="taxi")
    {
       if(cost>1)
       {
           if(cost<=100)
           {   allow=allow+cost;
               total=total+cost;
           }
           else{
           rejeted=rejeted+(cost-100);
           total=total+cost;

           }
           cout<<"Taxi cost = "<<cost<<endl;

       }
    }


}
void check_travelcar(string travelway,float pay,float distance,float par)
{
    float carcost = 0;
    if(travelway=="rentedcar"){
       if(pay>1){
         allow=allow+pay;
        total=total+pay;
           cout<<"Rent car cost = "<<pay<<endl;
       }
       else{
           cout<<"Please enter valid number"<<endl;
       }
    }
    else{
            if(carcost>0){
                 carcost=distance*(0.775);
                if(carcost<=25){
                allow=allow+carcost;
                total=total+carcost;
            }else{
                rejeted=rejeted+(carcost-25);
                total+=carcost;
            }
            }if(par>1){
                if(par>=25){
                   allow=allow+par;
                    total=total+par;
                }
                }else{

                rejeted=rejeted+(par-25);
                total+=par;
                    }
        cout<<"The refun for the own car = "<< carcost<<endl;
        cout<<"The parking fees = "<<par<<endl;

    }

}
void check_seminar(string replay,float con_cost)
{
    if (replay=="yes"){
        if(con_cost>1){
            allow=allow+con_cost;
            total=total+con_cost;
            cout<<"The Seminar fees = "<<endl;
        }
        else{
            cout<<"Please enter valid number"<<endl;
        }
    }

}
void check_accommondiation(float acco)
{
    if(acco>1)
    {
        if(acco<=500)
        {
            allow=allow+acco;
            total=total+acco;
        }else{
            rejeted=rejeted+(acco-500);
            total+=acco;
        }
        cout<<"The accomondaition = "<<acco<<endl;
    }else
        cout<<"Please enter valid number"<<endl;

}
void check_meals(float breakfast,float lunch,float dinner,int starttime,int endtime,int daynumber,int i)
{
    if(i==1){
    if(starttime<8){
        if(breakfast>1){
            if(breakfast<=40){
                allow=allow+breakfast;
                total=total+breakfast;
            }
            else{
                rejeted=rejeted+(breakfast-40);
                total=total+breakfast;
            }
            cout<<"The breakfast in 1st day= "<<breakfast<<endl;
        }
        else
            cout<<"Please enter valid number"<<endl;

    }

   else if(starttime<12 && starttime>=8){
        if(lunch>1){
            if(lunch<=60){
                allow=allow+lunch;
                total=total+lunch;
            }else{
                 rejeted=rejeted+(lunch-60);
                total=total+lunch;
            }
            cout<<"The lunch in 1st day= "<<lunch<<endl;
        }
        else{
            cout<<"Please enter valid number"<<endl;
        }
    }
       else if (starttime<18 && starttime >= 12){
        if(dinner>1){
            if(dinner<=80){
                 allow=allow+dinner;
                total=total+dinner;
            }
            else{
               rejeted=rejeted+(dinner-80);
                total=total+dinner;
            }
            cout<<"The dinner in 1st day= "<<dinner<<endl;

        }
        else{
            cout<<"Please enter valid number"<<endl;
        }

    }
    }
    else if((i>1)&&(i<daynumber))
    {
         if(breakfast>1){
            if(breakfast<=40){
                allow=allow+breakfast;
                total=total+breakfast;
            }
            else{
                rejeted=rejeted+(breakfast-40);
                total=total+breakfast;
            }
             cout<<"The breakfast in "<<daynumber<<" day = " <<breakfast<<endl;


         }
         else{
             cout<<"Please enter valid number"<<endl;
         }
            if(lunch>1){
            if(lunch<=60){
                allow=allow+lunch;
                total=total+lunch;
            }else{
                 rejeted=rejeted+(lunch-60);
                total=total+lunch;
            }
                cout<<"The lunch in "<<daynumber<<" day = " <<lunch<<endl;
            }
            else{

                cout<<"Please enter valid number"<<endl;
            }

            if(dinner>1){
            if(dinner<=80){
                 allow=allow+dinner;
                total=total+dinner;
            }else{
               rejeted=rejeted+(dinner-80);
                total=total+dinner;
            }
                cout<<"The dinner in "<<daynumber<<" day = " <<dinner<<endl;

        }else
            cout<<"Please enter valid number"<<endl;
    }
    else{
        if((endtime>9)&&(endtime<13)){
                if(breakfast>1){
            if(breakfast<=40){
                allow=allow+breakfast;
                total=total+breakfast;
            }
            else{
                rejeted=rejeted+(breakfast-40);
                total=total+breakfast;
            }
                    cout<<"The breakfast in last day= "<<breakfast<<endl;

                }
                else{
                    cout<<"Please enter valid number"<<endl;

                }


        }else if ((endtime>13)&&(endtime<19)){
              if(lunch>1){
            if(lunch<=60){
                allow=allow+lunch;
                total=total+lunch;
            }else{
                 rejeted=rejeted+(lunch-60);
                total=total+lunch;
            }
                  cout<<"The lunch in last day= "<<lunch<<endl;

              }
              else{
                  cout<<"Please enter valid number"<<endl;
              }

        }else if(endtime>19){


            if(dinner>1){
            if(dinner<=80){
                 allow=allow+dinner;
                total=total+dinner;
            }else{
               rejeted=rejeted+(dinner-80);
                total=total+dinner;
            }
                cout<<"The lunch in last day= "<<lunch<<endl;

        }else
            cout<<"Please enter valid number"<<endl;

    }
}
}

void Total_expenses_rejected(){
    cout<<"Total expense = "<<total<<endl;
    cout<<"The total refund = "<<total - rejeted<<endl;
    cout<<"The total rjected = "<<rejeted<<endl;
}
