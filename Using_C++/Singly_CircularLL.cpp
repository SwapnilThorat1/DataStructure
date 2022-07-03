//////////////////////////////////////////////////////////////////////////////
//   Singly circular LinkedList using C++
///////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////
//
// Function Name : LinkedList
// Description   : Used to Count elements and display Singly Circular Linked list 
// Input         : Integer
// Output        : Integer
// Date          : 04/06/2022
// Author        : Thorat Swapnil Harishchandra
//
//////////////////////////////////////////////////////////////////////////////////

struct node
{
  int data;
  struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;    
class SinglyCLL
{
   private:              //characteristic

      PNODE Head;       
      PNODE Tail;           

   public:             //Behaviour 

      SinglyCLL();    //Defualt Constructor
      void InsertFirst(int no);
      void InsertLast(int no);
      void InsertAtPos(int no,int ipos);
      void DeleteFirst();
      void DeleteLast();
      void DeleteAtPos(int ipos);
      void Display();
      int Count();         

};

SinglyCLL::SinglyCLL()    //Defualt Constructor
{
  Head = NULL;
  Tail = NULL;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  InsertFirst
//  Description   :  Used to insert at first position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////

void SinglyCLL::InsertFirst(int no)
{
  PNODE newn = NULL;   //initialised

  newn = new NODE;     
  newn->data = no;     
  newn->next = NULL;    

  if((Head == NULL) && (Tail == NULL))    
  {
    Head = newn;
    Tail = newn;          
  }
  else         
  {
    newn->next = Head;
    Head = newn;
  }
  Tail->next = Head;       
}
////////////////////////////////////////////////////////////////////////////
//
//  Function name :  InsertLast
//  Description   :  Used to insert at last position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////

void SinglyCLL::InsertLast(int no)
{
  PNODE newn = NULL;   

  newn = new NODE;     
  newn->data = no;     
  newn->next = NULL;    

  if((Head == NULL) && (Tail == NULL))    //If LL is empty
  {
    Head = newn;
    Tail = newn;          
  }
  else         // If LL contains atleast one node
  {
    Tail->next = newn;
    Tail = newn;
  }
  Tail->next = Head;       
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  InsertAtPosition
//  Description   :  Used to Insert At Position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////

void SinglyCLL::InsertAtPos(int no,int ipos)
{
  int iSize = Count();  

  if((ipos <1) || (ipos>iSize+1))
  {
    cout<<"Invalid position\n";
    return;
  }
  if(ipos ==1)
  {
    InsertFirst(no);
  }
  else if(ipos == iSize +1)
  {
    InsertLast(no);
  }
  else
  {
     PNODE newn = NULL;   

     newn = new NODE;     

     newn->data = no;     
     newn->next = NULL;   //Initialise pointer

     PNODE temp = Head;
     int iCnt = 0;

     for(iCnt =1; iCnt<ipos-1; iCnt++)
     {
       temp = temp->next;
     }

     newn->next = temp->next;
     temp->next  = newn;
  }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  DeleteFirst
//  Description   :  Used to Delete at first position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////

void SinglyCLL::DeleteFirst()
{
  if(Head == NULL && Tail == NULL)     //If  LL is empty
  {
    return;
  }
  else if(Head == Tail)     //if LL contains 1 node
  {
    delete Head;
    Head = NULL;
    Tail = NULL;
  }
  else              //if LL contains more than 1 node
  {
    Head = Head ->next;
    delete Tail->next;

    Tail->next = Head;
  }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  DeleteLast
//  Description   :  Used to Delete at Last position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////

void SinglyCLL::DeleteLast()
{
  if(Head == NULL && Tail == NULL)     //If  LL is empty
  {
    return;
  }
  else if(Head == Tail)     //if LL contains 1 node
  {
    delete Head;
    Head = NULL;
    Tail = NULL;
  }
  else              //if LL contains more than 1 node
  {
    PNODE temp = Head;   

   while(temp->next != Tail)   
   {
     temp = temp->next;
   }

   delete Tail;
   Tail = temp;

   Tail->next = Head;
  }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  DeleteAtPosition
//  Description   :  Used to Delete at Position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////


void SinglyCLL::DeleteAtPos(int ipos)
{
  int iSize = Count();  

  if((ipos < 1) || (ipos > iSize+1))
  {
    cout<<"Invalid position\n";
    return;
  }
  if(ipos ==1)
  {
    DeleteFirst();
  }
  else if(ipos == iSize +1)
  {
    DeleteLast();
  }
  else
  {
    PNODE temp1 = Head;
    int iCnt = 0;

    for(iCnt =1; iCnt<ipos-1; iCnt++)
    {
      temp1 = temp1->next;
    }

    PNODE temp2 = temp1->next;

    temp1->next = temp2->next;
    delete temp2;
  }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  Display
//  Description   :  Used to display elements of Linked List
//  Parameters    :  First pointer
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////

void SinglyCLL::Display()
{
   PNODE temp = Head;          

   if(Head == NULL && Tail == NULL)   //fillter
   {
     return ;
   }
   
   do
   {
     cout<<"|"<<temp->data<<"|->";
     temp = temp->next;
   }while(temp != Head);              //Head =  temp->next

   cout<<endl;
}


////////////////////////////////////////////////////////////////////////////
//
//  Function name :  Count
//  Description   :  Used to Count elements of Linked List
//  Parameters    :  First pointer
//  Return Value  :  int
//
/////////////////////////////////////////////////////////////////////////////

int SinglyCLL::Count()        
{
  int iCnt = 0;
  PNODE temp = Head;

  if(Head == NULL && Tail == NULL)   //fillter
   {
     return 0;
   }

  do
  {
    iCnt++;
    temp = temp->next;
  }while(temp != Head);

  return iCnt;
}         

int main()
{
  int iRet = 0;
  
  SinglyCLL obj;

  obj.InsertFirst(51);
  obj.InsertFirst(21);
  obj.InsertFirst(11);

  obj.InsertLast(101);
  obj.InsertLast(111);    
  obj.InsertLast(121);
  obj.InsertLast(151);
  obj.InsertLast(201);

  obj.Display();
  iRet =obj.Count();

  cout<<"Number of nodes are :"<<iRet<<endl;

  obj.InsertAtPos(75,4);


  obj.Display();
  iRet = obj.Count();
  
  cout<<"Number of nodes are :"<<iRet<<endl;

  obj.DeleteAtPos(4);

  obj.Display();
  iRet = obj.Count();
  
  cout<<"Number of nodes are :"<<iRet<<endl;

  return 0;
}

/////////////////////////////////////////////////////////////////////
//   OUTPUT : 
//     |11|->|21|->|51|->|101|->|111|->|121|->|151|->|201|->
//     Number of nodes are :8
//     |11|->|21|->|51|->|75|->|101|->|111|->|121|->|151|->|201|->
//     Number of nodes are :9
//     |11|->|21|->|51|->|101|->|111|->|121|->|151|->|201|->
//     Number of nodes are :8
/////////////////////////////////////////////////////////////////////
