/*Asala Ehab Mohmed (20201020)(S33)
Abdullah yasser Albunni(20200725)(S34)*/
#include <iostream>
#include<string>
#include<sstream>
using namespace std;
int valid(int length){
    if(length >= 14 && length <= 16){
        return true;
    }
    else{
        return false;
    }
}
int multipled_by_2( int arr[],int length){
    int singlesum = 0, doublesum = 0;
    for(int i=length-1;i>=0;i-=2)
        {


             if(((arr[i]%10)*2)<10)
                 singlesum=singlesum+((arr[i]%10)*2);


             else
             {
                 doublesum=doublesum+((((arr[i]%10)*2)%10)+(((arr[i]%10)*2)/10));

             }

           }
    return singlesum+doublesum;
}
int not_multipled_by_2( int arr[],int length){
    int sum = 0;
    for(int i=length;i>0;i-=2)
           {
               sum=sum+(arr[i]%10);
           }
    return sum;
}

int main()
{
    unsigned long long cardnum;
    cout<<"enter your number\n";
    cin>>cardnum;
   string str=to_string(cardnum);
    int len =str.length();
    cardnum=stoull(str);
    unsigned long long num=cardnum;
    int arr[len];
    for (int i=len;i>0;i--)
    {
        arr[i]=num%10;
        num/=10;
    }
    cout<<valid(len)<<endl;
    if(valid(len) == true)
    {
        if (( multipled_by_2(arr, len) + not_multipled_by_2(arr, len) ) % 10 == 0) {
            cout<<"Valid"<<endl;
        }
        else{
            cout<<"Not Valid"<<endl;
        }
    }
    else{
        cout<<"Please enter length between 14 to 16"<<endl;
    }


    return 0;



}
