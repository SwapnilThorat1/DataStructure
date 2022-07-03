/////////////////////////////////////////////////////////////////////////////////
//  Doubly Linear LinkedList Using C++
/////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////
//
// Function Name : LinkedList
// Description   : Used to Count elements and display Doubly Linear Linked list 
// Input         : Integer
// Output        : Integer
// Date          : 08/06/2022
// Author        : Thorat Swapnil Harishchandra
//
//////////////////////////////////////////////////////////////////////////////////

#define TRUE 1;
#define FALSE 0;

typedef int BOOL;

struct  node
{
    int Data;
    node *Next;
    node *Prev;
};
typedef struct node NODE;
typedef struct node*PNODE;

class Doubly_linkedList
{
    private:
    PNODE Head;

    public:
    Doubly_linkedList();
    ~Doubly_linkedList();
    BOOL InsertFirst (int);
    BOOL InsertLast(int);
    BOOL InsertAtPosition(int,int);
    inline void Display();
    inline int Count();
    BOOL DeleteFirst();
    BOOL DeleteAtPosition(int);
    BOOL DeleteLast();
};

Doubly_linkedList :: Doubly_linkedList()
{
    Head = NULL;
}

Doubly_linkedList :: ~Doubly_linkedList()
{
    PNODE Temp = Head;

    if(Head != NULL)
    {
        while(Head !=NULL)
        {
            Head = Head->Next;
            delete Temp;
            Temp = Head;
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

BOOL Doubly_linkedList::InsertFirst(int no)
{
    PNODE newn = NULL;

    newn = new NODE;
    if(newn == NULL)
    {
        return FALSE;
    }

    newn->Next = NULL;
    newn->Prev = NULL;
    newn->Data = no;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        Head->Prev = newn;
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

BOOL Doubly_linkedList::InsertLast(int no)
{
    PNODE newn = NULL, temp = Head;
    newn = new NODE;

    if(newn == NULL)
    {
        return FALSE;
    }

    newn->Next = NULL;
    newn->Prev = NULL;
    newn->Data =- no;
    
    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        while(temp->Next != NULL)
        {
            temp = temp->Next;
        }

        temp->Next = newn;
        newn->Prev = temp;
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


BOOL Doubly_linkedList::InsertAtPosition(int no ,int pos)
{
    if((Head == NULL) || (pos > Count()+1) || (pos <= 0))
    {
        return FALSE;
    }

    if(pos == 1)
    {
        return(InsertFirst(no));
    }
    else if(pos == (Count()) + 1)
    {
        return(InsertLast(no));
    }
    else
    {
        PNODE newn = NULL,temp = Head;

        newn = new NODE;
        if(newn == NULL)
        {
            return FALSE;
        }

        newn->Next = NULL;
        newn->Prev = NULL;
        newn->Data = no;

        for(int i = 1; i<=(pos-2); i++)
        {
            temp = temp->Next;
        }
        newn->Next = temp->Next;
        temp->Next->Prev = newn;

        newn->Prev = temp;
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

BOOL Doubly_linkedList::DeleteFirst()
{
    PNODE temp = Head;

    if(Head == NULL)
    {
        return FALSE;
    }
    else
    {
        Head = Head -> Next;
        Head->Prev = NULL;

        delete temp;
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


BOOL Doubly_linkedList:: DeleteLast()
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
        PNODE temp = Head;

        while((temp->Next) != NULL)
        {
            temp = temp->Next;
        }

        temp->Prev->Next = NULL;
        delete temp;
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


BOOL Doubly_linkedList::DeleteAtPosition(int pos)
{
    if((Head == NULL) || (pos > Count()) || (pos <= 0))
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
        PNODE temp = Head;

        for(int i = 1; i<= (pos-2); i++)
        {
            temp = temp ->Next;
        }

        temp->Next = temp->Next->Next;
        delete temp->Next->Prev;
        temp->Next->Prev = temp;

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

void Doubly_linkedList:: Display()
{
    PNODE Temp = Head;

    while(Temp != NULL)
    {
        cout<<Temp->Data<<"-> ";
        Temp = Temp -> Next;
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

int Doubly_linkedList::Count()
{
    PNODE Temp = Head;
    int iCnt = 0;

    while(Temp != NULL)
    {
        iCnt++;
        Temp = Temp -> Next;
    }
    return iCnt;
}

int main()
{
    Doubly_linkedList obj1;
    Doubly_linkedList *obj2 = new Doubly_linkedList();

    obj1.InsertFirst(21);
    obj1.InsertFirst(11);

    obj1.Display();

    cout<<"\nNUmber of nodes : "<<obj1.Count()<<"\n";

    obj1.InsertFirst(101);
    obj1.InsertAtPosition(75,4);

    obj1.Display();
    
    cout<<"\nNUmber of nodes :"<<obj1.Count()<<"\n";

    obj1.DeleteFirst();
    obj1.Display();

    obj1.DeleteLast();
    obj1.Display();

    obj1.DeleteLast();
    obj1.Display();

    obj2->InsertFirst(501);
    obj2->InsertFirst(511);
    obj2->InsertFirst(521);

    cout<<"\nNumber of nodes : "<<obj2->Count()<<"\n";

    delete obj2;

    return 0;
}

//////////////////////////////////////////////////////////////
//  OUTPUT : 
//  11-> 21-> NULL
//
//  NUmber of nodes : 2
//   101-> 11-> 21-> -75-> NULL
//
//  NUmber of nodes :4
//  11-> 21-> -75-> NULL
//  11-> 21-> NULL
//  11-> NULL
//
// Number of nodes : 3
//////////////////////////////////////////////////////////////