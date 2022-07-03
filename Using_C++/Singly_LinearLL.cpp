///////////////////////////////////////////////////////////////////////////////
// Singly Linear LinkedList using C++
///////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;


///////////////////////////////////////////////////////////////////////////////
//
// Function Name : LikedList
// Description   : Used to Count elements and display Singly Linear Linked list 
// Input         : Integer
// Output        : Integer
// Date          : 30/05/2022
// Author        : Thorat Swapnil Harishchandra
//
////////////////////////////////////////////////////////////////////////////////

#define TRUE 1
#define FALSE 0

typedef int BOOL;

struct node       //structure Defination
{
    int Data;
    node *Next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class Singly_linkedList
{
    private:
      PNODE Head;

    public:
      Singly_linkedList();
      ~Singly_linkedList();
      BOOL InsertFirst(int);
      BOOL InsertLast(int);
      BOOL InsertAtPosition(int,int);
      inline void Display();
      inline int Count();
      BOOL DeleteFirst();
      BOOL DeleteLast();
      BOOL DeleteAtPosition(int);
     
};

Singly_linkedList :: Singly_linkedList()
{
    Head = NULL;
}

Singly_linkedList::~Singly_linkedList()
{
    PNODE Temp,Navigate;

    if(Head != NULL)
    {
        Navigate = Head;
            while(Navigate != NULL)
            {
                Temp = Navigate->Next;
                delete Navigate;
                Navigate = Temp;
            }
    }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  InsertFirst
//  Description   :  Used to insert at first position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  BOOL
//
/////////////////////////////////////////////////////////////////////////////

BOOL Singly_linkedList::InsertFirst(int no)
{
    PNODE newn = NULL;

    newn = new NODE;     //Allocate memory

    if(newn == NULL)
    {
        return FALSE;
    }

    newn->Next = NULL;   //Initialise pointer
    newn->Data = no;     //Initialise data

    if(Head == NULL)    //Linkedlist is empty
    {
        Head = newn;
    }
    else                //LL Contains atleast one node
    {
        newn->Next = Head;
        Head = newn;
    }
    return TRUE;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  InsertLast
//  Description   :  Used to insert at last position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  BOOL
//
/////////////////////////////////////////////////////////////////////////////

BOOL Singly_linkedList::InsertLast(int no)
{
    PNODE newn = NULL, temp = Head;

    newn = new NODE;   //Allocate memory

    if(newn == NULL)
    {
        return FALSE;
    }
    newn->Next = NULL;  //Initialise data 
    newn->Data = no;    //Initialise pointer

    if(Head == NULL)    //Linkedlist is empty
    {
        Head = newn;
    }
    else                //LL contains atleast one node
    {
        while(temp->Next != NULL)
        {
            temp = temp->Next;
        }
        temp->Next = newn;
    }
    return TRUE;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  InsertAtPosition
//  Description   :  Used to Insert At Position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  BOOL
//
/////////////////////////////////////////////////////////////////////////////

BOOL Singly_linkedList::InsertAtPosition(int pos,int no)
{
    if((Head == NULL)  || (pos > Count()+1 ) || (pos <= 0))
    {
        return FALSE;
    }

    if(pos == 1)
    {
        return(InsertFirst(no));
    }
    else if(pos == (Count()) +1)
    {
        return(InsertLast(no));
    }
    else
    {
        PNODE newn = NULL, temp = Head;

        newn = new NODE;
        if(newn == NULL)
        {
            return FALSE;
        }
        newn->Next = NULL;
        newn->Data = no;

        for(int i = 1; i<= (pos-2); i++)
        {
            temp = temp->Next;
        }
        newn->Next = temp->Next;
        temp->Next = newn;
    }
    return TRUE;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  DeleteFirst
//  Description   :  Used to Delete at first position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  BOOL
//
/////////////////////////////////////////////////////////////////////////////

BOOL Singly_linkedList::DeleteFirst()
{
    PNODE temp = Head;

    if(Head == NULL)
    {
        return FALSE;
    }
    else
    {
        Head = Head->Next;
        delete(temp);
    }
    return TRUE;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  DeleteLast
//  Description   :  Used to Delete at Last position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  BOOL
//
/////////////////////////////////////////////////////////////////////////////

BOOL Singly_linkedList::DeleteLast()
{
    if(Head == NULL)
    {
        return FALSE;
    }
    else if(Head->Next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        PNODE temp1 = Head,temp2 = NULL;

        while(temp1-> Next-> Next != NULL)
        {
            temp1 = temp1-> Next;
        }

        temp2 = temp1->Next;
        temp1->Next = NULL;
        delete(temp2);
    }
    return TRUE;
}


////////////////////////////////////////////////////////////////////////////
//
//  Function name :  DeleteAtPosition
//  Description   :  Used to Delete at Position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  BOOL
//
/////////////////////////////////////////////////////////////////////////////

BOOL Singly_linkedList::DeleteAtPosition(int pos)
{
    if((Head == NULL) || (pos > Count()) ||(pos <= 0))
    {
        return FALSE;
    }
    else if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == (Count()))
    {
        DeleteLast();
    }
    else
    {
        PNODE temp1 = Head,temp2 = NULL;

        for(int i = 1;i<= (pos-2); i++)
        {
            temp1 = temp1-> Next;
            ++i;
        }

        temp2 = temp1->Next;
        temp1->Next = temp2->Next;

        delete temp2;
    }
    return TRUE;
    
}


////////////////////////////////////////////////////////////////////////////
//
//  Function name :  Display
//  Description   :  Used to display elements of Linked List
//  Parameters    :  First pointer
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////

void Singly_linkedList::Display()
{
    PNODE Temp = Head;

    while(Temp != NULL)
    {
        cout<<Temp->Data<<"-> ";
        Temp = Temp->Next;
    }
    cout<<"NULL\n";
}


////////////////////////////////////////////////////////////////////////////
//
//  Function name :  Count
//  Description   :  Used to Count elements of Linked List
//  Parameters    :  First pointer
//  Return Value  :  int
//
/////////////////////////////////////////////////////////////////////////////

int Singly_linkedList::Count()
{
    PNODE Temp = Head;
    int iCnt = 0;

    while(Temp != NULL)
    {
        iCnt++;
        Temp = Temp->Next;
    }
    return iCnt;
}

int main()
{
    Singly_linkedList obj1;
    Singly_linkedList *obj2 = new Singly_linkedList(); 

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);

    obj1.Display();

    cout<<"\nNumber of nodes : "<<obj1.Count()<<"\n";

    obj1.InsertFirst(101);
    obj1.InsertFirst(111);

    obj1.Display();

    cout<<"\nNumber of nodes : "<<obj1.Count()<<"\n";

    obj1.InsertAtPosition(75,4);
    obj1.Display();

    obj1.DeleteFirst();
    obj1.Display();

    obj2->InsertFirst(501);
    obj2->InsertFirst(511);
    obj2->InsertFirst(521);

    obj2->Display();

    obj2->InsertLast(551);
    obj2->InsertAtPosition(601,3);

    obj2->Display();

    cout<<"\nNumber of nodes :"<<obj2->Count()<<"\n";

    delete obj2;

    return 0;
}

//////////////////////////////////////////////////////////////////////
//  OUTPUT :
//  11-> 21-> 51-> NULL
//
//  Number of nodes : 3
//  111-> 101-> 11-> 21-> 51-> NULL
//
//  Number of nodes : 5
//  111-> 101-> 11-> 21-> 51-> NULL
//  101-> 11-> 21-> 51-> NULL
//  521-> 511-> 501-> NULL
//  521-> 511-> 501-> 551-> NULL
//
//  Number of nodes :4
//////////////////////////////////////////////////////////////////////