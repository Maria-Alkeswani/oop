#include<iostream>
#include<stdlib.h>
#include<math.h>
//using namespace std;

template <typename T> const T pi = T(3.1415926535897932385L);

bool inPiRange_1(int n)
{
    if(abs(n) < pi<int>) 
    return true;
    else 
    return false;
}
//-------------------------------------

template <class T1,class T2>
bool greater_than(T1 x,T2 y)
{
    if(x>y) return true;
    else return false;
}


template <typename T>
void swap_elements(T &x,T &y)
{
    T t;
    t=x;
    x=y;
    y=t;
}

template <typename T>
void bubbleSort(T arr[],int n)
{
    int i,j;

    for(i=0;i<n-1;i++)
    for(j=0;j<n-1;j++)
    if(greater_than(arr[j],arr[j+1]))
    swap_elements(arr[j],arr[j+1]);

}

template <typename T>
void print_arr(T arr[],int n)
{
    int i;

    for(i=0;i<n;i++)
    std::cout<<arr[i]<<" ";

    std::cout<<std::endl;
}
//--------------------------------------
//--------------------------------------

//template <typename T> class container;




 template <typename T>
 class container
 {
private:

class Node //elements
{
    public:
    Node()
    {
    next=NULL;
    prev=NULL;
    }
    
    T data;
    Node* next;
    Node* prev;
};
Node* head_ref;


public:



Node* head()
{
    return head_ref;
}

container()
{
    head_ref=NULL;
}

~container()
{
    delete(head_ref);
}


void insert(Node* pos, T new_data)
{   
    if (head_ref == NULL)                     //  head_ref= [prev][data][next]
    {
        Node* new_node = new Node();
        new_node->data=new_data;
        head_ref=new_node;
       return;
    }
    else if (pos->prev==NULL) // >>> pos=head_ref   >>   [prev][data][next] = [Null][data][Null]

                                 // 1- new node >>  [prev][data][next]

                                 // 2- {new_node , head_ref} = [prev][new data][next] [prev][head data][next]
    {
        Node *t=head_ref;
        Node *new_node=new Node();
        new_node->data=new_data;
        new_node->next=t;
        t->prev=new_node;
        head_ref=new_node;
    }
                               // >>> pos=head_ref->next
                               // >>> {head_ref ,node} = [prev][head data][next] [prev][node data][next] 

                                   // 1- new node >>  [prev][data][next]

              // 2- {head_ref , node ,new_node} =[prev][head data][next] [prev][new_node data][next] [prev][node data][next] 
    
    else
    {
        Node *new_node=new Node();
        new_node->data=new_data;
        new_node->next=pos;
        new_node->prev=pos->prev;

        pos->prev->next=new_node;
        pos->prev=new_node;
    }

}

void printList()
{   
    Node* node=head_ref;
   // Node* last;
    //cout<<"Display: ";
    while (node != NULL)
    {
        std::cout<<" "<<node->data<<" ";
        //last = node;
        node = node->next;
    }
}

void erase(Node* del)     //erase
{
    /* base case */
    if (head_ref == NULL || del == NULL)
        return;
 
    if (head_ref == del)
        head_ref = del->next;
 
    if (del->next != NULL)    // {node1 , node2 ,node3} = 
        del->next->prev = del->prev;
 
    if (del->prev != NULL)
        del->prev->next = del->next;

    delete(del);
    return;
}         


friend void bubbleSort(container<T>::Node *start)  //Exercise 5: Sorting a List
{
    int swapped;
    container<int>::Node *ptr1;
  
    /* Checking for empty list */
    if (start == NULL)
        return;
  
    do
    {
        swapped = 0;
        for(ptr1 = start;ptr1->next != NULL;ptr1=ptr1->next)
        if (ptr1->data > ptr1->next->data)
        {
            swap_elements(ptr1->data, ptr1->next->data);
            swapped = 1;
        }
    }
    while (swapped);
}



}; 
//---------------------------------------------------------------
//void bubbleSort(container<int>::Node *start)


//==========================================================================
template <typename T1 , typename T2>
class Point
{
    public:
    T1 x;
    T2 y;
    Point(T1 x1,T2 y1)
    {
        x=x1;
        y=y1;
    }
    
    Point()
    {}
};


template<> bool greater_than< Point<int, int> , Point<int, int> >(Point<int, int> p1, Point<int, int> p2)
{
    if(p1.x>p2.x) return true;
    else return false;
}


template <> void print_arr< Point<int, int> >(Point<int, int> arr[],int n)
{
    int i;

    for(i=0;i<n;i++)
    std::cout<<"P"<<i+1<<"("<<arr[i].x<<","<<arr[i].y<<")"<<std::endl;

    std::cout<<std::endl;
}


//template<> bool greater_than<Point<int, int>, Point<int, int> >(Point<int, int>, Point<int, int>);








