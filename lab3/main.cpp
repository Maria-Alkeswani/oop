#include<iostream>
#include"a.hpp"

using namespace std;


int main()
{
// Exercise 1: Variable Template
cout<<"Exercise 1: Variable Template"<<endl<<endl;

int n;
n=2;
cout<<"inPiRange: ";
if(inPiRange_1(n)) cout<<"True"<<endl; else cout<<"False"<<endl;

//----------------------------------------

//Exercise 2.1. Greater Than Template Function
cout<<endl<<"Exercise 2.1. Greater Than Template Function"<<endl<<endl;

cout<<"2 > 3 ? ";
if(greater_than(2,3)) cout<<"True"<<endl; else cout<<"False"<<endl;
cout<<"2.2 > 3.7 ? ";
if(greater_than(2.2,3.7)) cout<<"True"<<endl; else cout<<"False"<<endl;
cout<<"2.2 > 2 ? ";
if(greater_than(2.2,2)) cout<<"True"<<endl; else cout<<"False"<<endl;
cout<<"2 > 2.2 ? ";
if(greater_than(2,2.2)) cout<<"True"<<endl; else cout<<"False"<<endl;

//Exercise 2.2. Swap Elements Template Function
cout<<endl<<"Exercise 2.2. Swap Elements Template Function"<<endl<<endl;
/*
int k1,k2;
k1=5;
k2=7;
cout<<k1<<" >> "<<k2<<endl;
swap_elements(k1,k2);
cout<<k1<<" >> "<<k2<<endl;
*/

//Exercise 2.3. Bubble Sort Template Function

cout<<endl<<"Exercise 2.3. Bubble Sort Template Function"<<endl<<endl;

int arr[7]={5,9,1,2,4,8,7};
cout<<"Before sorting:   "; print_arr(arr,7);
bubbleSort(arr,7);
cout<<"After sorting:   "; print_arr(arr,7);

//Exercise 3: Class Template
cout<<endl<<"Exercise 3: Class Template"<<endl;

    container <int>x1;

    x1.insert(x1.head(), 8);                      // 8
    x1.insert(x1.head(), 4);                      // 4 8
    x1.insert(x1.head()->next, 2);                // 4 2 8
    x1.insert(x1.head()->next, 7);                // 4 7 2 8
    x1.insert(x1.head()->next->next->next, 9);    // 4 7 2 9 8
    x1.printList(); cout<<endl;
    x1.erase(x1.head()->next);    // 4 2 9 8
    x1.printList(); cout<<endl;

    

//Exercise 4: Sorting an Array of Points
cout<<endl<<endl<<"Exercise 4: Sorting an Array of Points"<<endl<<endl;

Point<int,int> pt[5];
pt[0].x=1; pt[0].y=3;
pt[1].x=3; pt[1].y=2;
pt[2].x=2; pt[2].y=7;
pt[3].x=-2; pt[3].y=0;
pt[4].x=0; pt[4].y=4;

cout<<"Before sorting:"<<endl;   print_arr(pt,5);

bubbleSort(pt,5);

cout<<"After sorting:"<<endl;   print_arr(pt,5);


//Exercise 5: Sorting a List

cout<<endl<<"Exercise 5: Sorting a List"<<endl<<endl;

cout<<"Before sorting:";   x1.printList();

bubbleSort(x1.head());

cout<<endl<<"After sorting:";    x1.printList();

cout<<endl;







    return 0;
}
