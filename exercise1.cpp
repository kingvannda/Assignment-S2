/*Q1 - Write a function that determines whether a number if in a specified range 

bool isInside(int number, int min, int max) 

This function returns true if the number is within the range [min, max], and false otherwise 

Q2 – Write the main() function to  input the data and output the result 

Make sure your code work for all the above test cases 

 

Q3 – (BONUS) If the user accidentally enters a minimum value that is larger 
than the maximum value, ask them to enter the values again. */

#include<iostream>
using namespace std;
void result(int min,int max,int num){
    if (min<num && num<max){
        cout<<"Inside bro";
    }else{
        cout<<"Outside bro";
    }
}
int main(){
    int min,max,num;
    cout<<"Enter the number of min: ";cin>>min;
    cout<<"Enter the number of max: ";cin>>max;
    

    while (min>max){
        cout<<"Bro min canot bigger than max dude!"<<endl;
        cout<<"Enter the number again real quick bro?"<<endl;
        cout<<"Enter the number of min: ";cin>>min;
        cout<<"Enter the number of max: ";cin>>max;
    }
    cout<<"Yoh bro enter the number to check dude:";cin>>num;

    result(min,max,num);



}