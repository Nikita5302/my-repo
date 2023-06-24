// Generalised Data Structure Library

#include <iostream>
using namespace std;

#pragma pack(1)
template <class T>
struct   SinglyNode 
{
    T data;
    struct  SinglyNode  *next;
};

template <class T>
struct DoublyNode
{
    T data;
    struct DoublyNode *next;
    struct DoublyNode *prev;
};

template <class T>
struct BSTNode
{
    T data;
    struct BSTNode *lchild;
    struct BSTNode *rchild;
};


template <class T>
class SinglyLL
{
    public :

        struct  SinglyNode <T> * First;
        int iCount;

        SinglyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no,int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        int SearchFirstOcc(T no);
        int SearchLastOcc(T no);
        int Frequency(T no);
        int MiddleElement();

        void Display();

};

template <class T>
class SinglyCL
{
    public:
       struct  SinglyNode  <T>* First;
       struct  SinglyNode  <T>* Last;

        SinglyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        int SearchFirstOcc(T no);
        int SearchLastOcc(T no);
        int Frequency(T no);
        int MiddleElement();

        void Display();
        int Count();
};

template <class T>
class DoublyLL
{
    public :
       struct DoublyNode <T>* First;

        DoublyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        int SearchFirstOcc(T no);
        int SearchLastOcc(T no);
        int Frequency(T no);
        int MiddleElement();

        void Display();
        int Count();
};

template <class T>
class DoublyCL
{
    public:
       struct DoublyNode <T>* First;
       struct DoublyNode <T>* Last;

        DoublyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        int SearchFirstOcc(T no);
        int SearchLastOcc(T no);
        int Frequency(T no);
        int MiddleElement();

        void Display();
        int Count();
};

template <class T>
class Stack
{
    public:
        struct  SinglyNode <T> *First;
        int iCount;

        Stack();

        bool IsStackEmpty();
        void Push(T no);      // Insert
        T Pop();              // Delete
        void Display();
};

template <class T>
class Queue
{
    public:
        struct  SinglyNode  <T> *First;
        int iCount;

        Queue();

        bool IsQueueEmpty();
        void EnQueue(T no);      // Insert
        T DeQueue();              // Delete
        void Display();
};

template <class T>
class BST
{
    public :
        struct  BSTNode <T> *Root;
    
        BST();

        void Insert(T No);

        void Inorder(struct BSTNode<T> * temp);
        void Preorder(struct BSTNode<T> * temp);
        void Postorder(struct BSTNode<T> * temp);

        bool Search(struct BSTNode<T> * temp,T No);

        int CountLeafNode(struct BSTNode<T> * temp);
        int CountParentNode(struct BSTNode<T> * temp);
        int CountCompleteParentNode(struct BSTNode<T> * temp);

};

template <class T>
SinglyLL <T>:: SinglyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>      
void SinglyLL <T>:: InsertFirst(T no)
{
   struct  SinglyNode  <T>* newn = new  SinglyNode <T>;

    newn->data = no;
    newn->next = NULL;

    if ( First == NULL)        
    {
        First = newn ;
        iCount ++;
    }
    else   
    {
        newn->data = no;
        newn->next= First;
        First = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL <T>:: InsertLast(T no)
{
   struct  SinglyNode  <T>* newn = new  SinglyNode <T>;
   struct  SinglyNode  <T>* temp = First;

    newn->data = no;
    newn->next = NULL;

    if ( First == NULL)      
    {
        First = newn ;
        iCount ++;
    }
    else
    {
       while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
}

template <class T>
void SinglyLL <T>:: InsertAtPos(T no ,int ipos)
{

    int NodeCnt = 0, iCnt = 0;
    struct  SinglyNode  <T>* newn = NULL;
    struct  SinglyNode  <T>* temp = First;

    NodeCnt = iCount;

    if((ipos < 1) || (ipos > (NodeCnt + 1)))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos ==  NodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new  SinglyNode <T>;

        newn->data = no;
        newn->next = NULL;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next = newn;
        iCount++;

    }

}

template <class T>
void SinglyLL <T>:: DeleteFirst( )
{
   struct  SinglyNode  <T>* temp = First;

    if(First == NULL)  
    {
        return;
    }
    else if((First) -> next == NULL) 
    {
        delete (First);
        iCount--;
        First = NULL;
    }
    else 
    {
        (First) = (First) -> next;
        delete (temp);
        iCount--;
    }
}

template <class T>
void SinglyLL <T>:: DeleteLast( )
{
   struct  SinglyNode  <T>* temp = First;

    if(First == NULL)  
    {
        return;
    }
    else if((First) -> next == NULL) 
    {
        delete (First);
        First = NULL;
    }
    else
    {
        while(temp ->next -> next != NULL)
        {
            temp = temp -> next;
        }
        delete (temp->next);
        iCount--;
        temp->next = NULL;
    }
}

template <class T>
void SinglyLL <T>:: DeleteAtPos(int ipos )
{
    int iCnt = 0,NodeCnt = 0; 
    struct  SinglyNode  <T>* temp1 = NULL;
    struct  SinglyNode  <T>* temp2 = NULL;

    NodeCnt = iCount;

    if((ipos < 1) || (ipos > (NodeCnt)))
    {
        cout<<"Invalid position"<<"\n";
        return;
    } 

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos ==  NodeCnt+1)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;
        for(iCnt = 1; iCnt < ipos-1 ; iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;

        temp1->next = temp2->next;   
        delete (temp2);
        iCount--;
    }
}

template <class T>
void SinglyLL <T>:: Display()
{
    cout<<"Elements of Linked List are : "<<"\n";
   struct  SinglyNode  <T>* temp = First;

    while( temp != NULL)
    {
        cout<<" | "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";

}

template <class T>
int SinglyLL <T>::SearchFirstOcc(T ino)
{
   struct  SinglyNode  <T>* temp = First;
    int iCnt = 1;
    while(temp != NULL)
    {      
        if(temp-> data == ino)
        {
            break;
        }
        temp = temp -> next;
        iCnt++; 
        if(temp == NULL)
        {
            cout<<"Element is not present in Linked List"<<"\n";
            iCnt  = 0;
        } 
    }
    
    return iCnt;
}

template <class  T>
int SinglyLL <T>::SearchLastOcc(T No)
{
    int Count = 1;
    int iPos = -1;
    struct  SinglyNode  <T>* temp = First;

    while(temp != NULL)
    {
        if(temp->data == No)
        {
            iPos = Count;
        }
        
        temp = temp->next;
        Count++;
    }
    return iPos;
}

template <class  T>
int SinglyLL <T>::Frequency(T No)
{
    int Count = 0;
    struct  SinglyNode  <T>* temp = First;

    while(temp != NULL)
    {
        if(temp->data == No)
        {
            Count++;
        }
        temp = temp->next;
    }
    return Count;
}

template <class  T>
int SinglyLL <T>::MiddleElement()
{
    struct  SinglyNode  <T>* Student = First;
    struct  SinglyNode  <T>* Teacher = First;

    while ((Teacher != NULL) && (Teacher->next != NULL) )  
    {
        Student = Student->next;
        Teacher = Teacher->next->next;
    }
    return (Student->data);
    

}

template <class T>
SinglyCL <T>::SinglyCL()
{
    First = NULL;
    Last = NULL;
}

template <class T>
void SinglyCL <T>::InsertFirst(T no)
{
   struct  SinglyNode  <T>* newn = new  SinglyNode <T>;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))    // Empty LL
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else    // LL contains atleast one  SinglyNode 
    {
        newn->next = First;
        First = newn;
        (Last)->next = First;
    }
}

template <class T>
void SinglyCL <T>::InsertLast(T no)
{
   struct  SinglyNode  <T>* newn = new  SinglyNode <T>;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))    // Empty LL
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else    // LL contains atleast one  SinglyNode 
    {
        (Last) -> next = newn;
        Last = newn;
        (Last)->next = First;
    }
}

template <class T>
void SinglyCL <T>::Display()
{
   struct  SinglyNode  <T>* temp = First;

    cout<<"Elements of Linked list are : "<<"\n";

    do
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }while(temp != Last->next);
    cout<<"\n";
}

template <class T>
int SinglyCL <T>::Count()
{
   struct  SinglyNode  <T>* temp = First;

    int iCnt = 0;
    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last->next);
    return iCnt;
}

template <class T>
void SinglyCL <T>::DeleteFirst()
{
   struct  SinglyNode  <T>* temp = First;

    if((First == NULL) && (Last == NULL)) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single  SinglyNode  in LL
    {
        //free(*First);
        delete First;

        First = NULL;
        Last = NULL;
    }
    else    // If LL contains more than 1  SinglyNode 
    {
        First = (First)->next;
        //free(temp);
        delete temp;

        (Last) ->next = First;
    }
}

template <class T>
void SinglyCL <T>::DeleteLast()
{
   struct  SinglyNode  <T>* temp = First;

    if((First == NULL) && (Last == NULL)) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single  SinglyNode  in LL
    { 
        delete First;

        First = NULL;
        Last = NULL;
    }
    else    // If LL contains more than 1  SinglyNode 
    {
        while(temp->next != (Last))
        {
            temp = temp -> next;
        }

        delete temp->next;

        Last = temp; 
        (Last) ->next = First;
    }
}

template <class T>
void SinglyCL <T>::InsertAtPos(T no, int ipos)
{
    int inodeCnt = 0, iCnt = 0;
    inodeCnt = Count();
   struct  SinglyNode  <T>* newn = NULL;
   struct  SinglyNode  <T>* temp = First;

    if((ipos < 1) || (ipos > inodeCnt + 1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == inodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new  SinglyNode <T>;

        newn->data = no;
        newn->next = NULL;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

template <class T>
void SinglyCL <T>::DeleteAtPos(int ipos)
{
    int inodeCnt = 0, iCnt = 0;
    inodeCnt = Count();
   struct  SinglyNode  <T>* temp1 = First;
   struct  SinglyNode  <T>* temp2 = NULL;

    if((ipos < 1) || (ipos > inodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == inodeCnt)
    {
        DeleteLast();
    }
    else
    {
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }   
        temp2 = temp1 ->next;

        temp1->next = temp2->next;
        delete temp2;
    }
}

template <class T>
int SinglyCL <T> ::SearchFirstOcc(T ino)
{
    int iCnt = 1;
   struct  SinglyNode  <T>* temp = First;
   struct  SinglyNode  <T>* Temp = First;

    
    do
    {      
        if(temp-> data == ino)
        {
            break;
        }
        temp = temp -> next;
        iCnt++; 
    } while(temp != Temp);
    
    if(temp == NULL)
    {
        cout<<"Element is not present in Linked List"<<"\n";
        iCnt = 0;
    } 
    
    return iCnt;
}

template <class T>
int SinglyCL<T>::SearchLastOcc(T No)
{
    int Count = 1;
    int iPos = -1;
    struct SinglyNode<T> *temp = First;
    struct SinglyNode<T> *Temp = First;

    do
    {
        if (temp->data == No)
        {
            iPos = Count;
        }

        temp = temp->next;
        Count++;
    } while (temp != Temp);

    return iPos;
}

template <class T>
int SinglyCL<T>::Frequency(T No)
{
    int Count = 0;
    struct SinglyNode<T> *temp = First;
    struct SinglyNode<T> *Temp = First;

        do
    {
        if (temp->data == No)
        {
            Count++;
        }
        temp = temp->next;
    } while (temp != Temp);

    return Count;
}

template <class T>
int SinglyCL<T>::MiddleElement()
{
    struct SinglyNode<T> *Student = First;
    struct SinglyNode<T> *Teacher = First;

    do
    {
        Student = Student->next;
        Teacher = Teacher->next->next;
    } while (Teacher != First && Teacher->next != First);

    return (Student->data);

}

template <class T>
DoublyLL <T>:: DoublyLL()
{
    First = NULL;
}

template <class T>
void DoublyLL <T>::InsertFirst(T no)
{
   struct DoublyNode <T>* newn = new DoublyNode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      // X

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        (First)->prev = newn;  // X

        First = newn;
    }
}

template <class T>
void DoublyLL <T>::InsertLast(T no)
{
   struct DoublyNode <T>* newn = new DoublyNode<T>;
   struct DoublyNode <T>* temp = First;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      // X

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;     
    }
}

template <class T>
void DoublyLL <T>:: Display()
{
   struct DoublyNode <T>* temp = First;

    cout<<"Elements of Linked list are"<<"\n";

    cout<<"NULL<=> ";

    while(First != NULL)
    {
        cout<<"| %d |<=> "<<temp->data;
        temp = temp->next;
    }
    cout<<"NULL"<<"|n";
}

template <class T>
int DoublyLL <T>:: Count()
{
    int iCnt = 0;
   struct DoublyNode <T>* temp = First;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }

    return iCnt;
}

template <class T>
void DoublyLL <T>:: DeleteFirst()
{
    if(First == NULL)  // LL is empty
    {
        return;
    }
    else if((First)->next == NULL) // LL contains 1  SinglyNode 
    {
        free(First);
        First = NULL;
    }
    else    // LL contains more than 1  SinglyNode 
    {
        First = (First) -> next;
        delete ((First)->prev);               // X
        (First)->prev = NULL;              // X
    }
}

template <class T>
void DoublyLL <T>:: DeleteLast()
{
   struct DoublyNode <T>* temp = First;

    if(First == NULL)  // LL is empty
    {
        return;
    }
    else if((First)->next == NULL) // LL contains 1  SinglyNode 
    {
        free(First);
        First = NULL;
    }
    else    // LL contains more than 1  SinglyNode 
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete (temp->next);
        temp->next = NULL;
    }
}

template <class T>
void DoublyLL <T>:: InsertAtPos(T no, int ipos)
{
    int NodeCnt = 0, iCnt = 0;
    struct DoublyNode <T>* newn = NULL;
    struct DoublyNode <T>* temp = NULL;

    NodeCnt = Count();

    if((ipos < 1) || (ipos > (NodeCnt + 1)))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos ==  NodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new DoublyNode<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;  //X


        temp = First;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next->prev = newn;    //X

        temp->next = newn;
        newn->prev = temp;          //X
    }
}

template <class T>
void DoublyLL <T>:: DeleteAtPos(int ipos)
{
    int iCnt = 0,NodeCnt = 0; 
    struct DoublyNode <T>* temp1 = NULL;
    struct DoublyNode <T>* temp2 = NULL;

    NodeCnt = Count();

    if((ipos < 1) || (ipos > (NodeCnt)))
    {
        cout<<"Invalid position"<<"\n";
        return;
    } 

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos ==  NodeCnt+1)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;
        for(iCnt = 1; iCnt < ipos-1 ; iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;

        temp1->next = temp2->next;   
        temp2->next->prev = temp1;  

        delete (temp2);
    }
}

template <class T>
int DoublyLL <T> ::SearchFirstOcc(T ino)
{
    int iCnt = 1;
    struct DoublyNode <T> * temp = First;
    while(temp != NULL)
    {      
        if(temp-> data == ino)
        {
            break;
        }
        temp = temp -> next;
        iCnt++; 
    } 
    if(temp == NULL)
    {
        cout<<"Element is not present in Linked List"<<"\n";
     iCnt = 0;
    } 

    return iCnt;

}

template <class T>
int DoublyLL <T> :: SearchLastOcc(T No)
{
    int Count = 1;
    int iPos = -1;
    struct DoublyNode <T>* temp = First;

    while(temp != NULL)
    {
       if(temp->data == No)
      {
          iPos = Count;
      }
    
     temp = temp->next;
     Count++;
    }
return iPos;
}
template <class T>
int DoublyLL <T> :: Frequency(T No)
{
    int Count = 0;
    struct DoublyNode <T>* temp = First;

    while(temp != NULL)
    {
       if(temp->data == No)
       {
            Count++;
        }

        temp = temp->next;
    }
    return Count;
}

template <class T>
int DoublyLL <T> :: MiddleElement()
{
    struct DoublyNode <T>* Student = First;
    struct DoublyNode <T>* Teacher = First;

    while ((Teacher != NULL) && (Teacher->next != NULL) )  
    {
        Student = Student->next;
        Teacher = Teacher->next->next;
    }
    return (Student->data);
}

template <class T>
DoublyCL <T>:: DoublyCL() 
{
    First = NULL;
    Last = NULL;
}

template <class T>
void DoublyCL <T>:: InsertFirst(T no)
{
   struct DoublyNode <T>* newn = new DoublyNode<T>; 

    newn->data = no;
    newn->next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL)) 
    {
        First = newn;
        Last = newn;
    }
    else    
    {
        newn->next = First;
        (First)->prev = newn;
        First = newn; 
    }

    (First)->prev = Last;
    (Last)->next = First;
}

template <class T>
void DoublyCL <T>:: InsertLast(T no)
{
   struct DoublyNode <T>* newn = new DoublyNode<T>; 

    newn->data = no;
    newn->next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL)) // LL is empty
    {
        First = newn;
        Last = newn;
    }
    else    // If LL contains one or more  SinglyNode s
    {
        (Last) -> next = newn;
        newn->prev = Last;
        Last = newn;
    }

    (First)->prev = Last;
    (Last)->next = First;
}

template <class T>
void DoublyCL <T>:: Display()
{
   struct DoublyNode <T>* temp = First;

    if(First == NULL && Last == NULL)
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }

    cout<<"Elements of Linked list are : "<<"\n";
    do
    {
        cout<<"| " <<temp->data<<"|<=> ";
        temp = temp -> next;
    }while(temp != Last->next);

    cout<<"\n";
}

template <class T>
int DoublyCL <T>:: Count()
{
    int iCnt = 0;
   struct DoublyNode <T>* temp = First;

    if(First == NULL && Last == NULL)
    {
        return iCnt;
    }

    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last->next);

    return iCnt;
}

template <class T>
void DoublyCL <T>:: DeleteFirst()
{
    if(First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single  SinglyNode 
    {
        delete First;
        First = NULL;
        Last= NULL;
    }
    else    // More than one  SinglyNode 
    {
        (First) = (First) ->next;
        delete (Last)->next;        // free((*First)->prev);

        (First)->prev = Last;
        (Last)->next = First;
    }
}

template <class T>
void DoublyCL <T>:: DeleteLast()
{
    if(First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single  SinglyNode 
    {
        delete First;
        First = NULL;
        Last= NULL;
    }
    else    // More than one  SinglyNode 
    {
        Last = (Last) -> prev;
        delete (First)->prev;       // free((*Last)->next);

        (First)->prev = Last;
        (Last)->next = First;
    }
}

template <class T>
void DoublyCL <T>:: InsertAtPos(T no, int ipos)
{
    int inodeCnt = Count();
   struct DoublyNode <T>* newn = NULL;
   struct DoublyNode <T>* temp = NULL;
    int iCnt = 0;

    if((ipos < 1) || (ipos > inodeCnt+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos ==1)
    {
        InsertFirst(no);
    }
    else if(ipos == inodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new DoublyNode<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
    }
}

template <class T>
void DoublyCL <T>:: DeleteAtPos(int ipos)
{
    int inodeCnt = Count();
   struct DoublyNode <T>* temp = NULL;
    int iCnt = 0;

    if((ipos < 1) || (ipos > inodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos ==1)
    {
        DeleteFirst();
    }
    else if(ipos == inodeCnt)
    {
        DeleteLast();
    }
    else
    {
        temp = First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete (temp->next->prev);
        temp->next->prev = temp;
    }
}
template <class T>
int DoublyCL <T> ::SearchFirstOcc(T ino)
{
    int iCnt = 1;
    struct DoublyNode <T> * temp = First;
    struct DoublyNode <T> * Temp = First;

    do
    {
      if(temp-> data == ino)
    {
        break;
    }
    temp = temp -> next;
    iCnt++;
    } while(temp != NULL);

    if(temp == Temp)
{
    cout<<"Element is not present in Linked List"<<"\n";
    iCnt = 0;
} 
}

template <class T>
int DoublyCL <T> :: SearchLastOcc(T No)
{
    int Count = 1;
    int iPos = -1;
    struct DoublyNode <T>* temp = First;
    struct DoublyNode <T>* Temp = First;

    while(temp != Temp)
    {
       if(temp->data == No)
      {
          iPos = Count;
      }
    
     temp = temp->next;
     Count++;
    }
return iPos;
}

template <class T>
int DoublyCL <T> :: Frequency(T No)
{
    int Count = 0;
    struct DoublyNode <T>* temp = First;
    struct DoublyNode <T>* Temp = First;

    while(temp != Temp)
    {
       if(temp->data == No)
       {
            Count++;
        }
        temp = temp->next;
    }
    return Count;
}

template <class T>
int DoublyCL <T> :: MiddleElement()
{
    struct DoublyNode <T>* Student = First;
    struct DoublyNode <T>* Teacher = First;

    do
    {
        Student = Student->next;
        Teacher = Teacher->next->next;
    } while ((Teacher != NULL) && (Teacher->next != NULL) );

    return (Student->data);

}
template <class T>
Stack <T>:: Stack()
{
    First = NULL;
    iCount = 0;
}

template <class T>
bool Stack <T>:: IsStackEmpty()
{
    if(iCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void Stack <T>:: Push(T no)  // InsertFirst
{
    struct  SinglyNode  <T> *newn = new  SinglyNode <T>;

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    
    iCount++;

    cout<<no<<" gets pushed in the stack succesfully"<<"\n";
}

template <class T>
T Stack <T>:: Pop()          // DeleteFirst
{
    if(First == NULL)
    {
        cout<<"Unable to pop the element as Stack is empty."<<"\n";
        return -1;
    }
    else 
    {
        T value = First -> data;
        struct  SinglyNode  <T> *temp = First;

        First = First ->next;
        delete temp;

        iCount--;

        return value;
    }
}

template <class T>
void Stack <T> :: Display()
{
    if(First == NULL)
    {
        cout<<"Stack is empty."<<"\n";
    }
    else 
    {
        cout<<"Elements of stack are : "<<"\n";

        struct  SinglyNode  <T> *temp = First;
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" |-> ";
            temp = temp -> next;
        }
        cout<<" NULL"<<"\n";
    }
}


template <class T>
Queue <T> :: Queue()
{
    First = NULL;
    iCount = 0;
};

template <class T>

bool Queue <T> :: IsQueueEmpty()
{
    if(iCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
};

template <class T>
void Queue <T> :: EnQueue( T no)  // InsertLast
{
    struct  SinglyNode  <T> *newn = new  SinglyNode <T> ;
    struct  SinglyNode  <T> *temp = First;

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;

        }
        temp->next = newn;
    }
    
    iCount++;

    cout<<no<<" gets pushed in the Queue succesfully"<<"\n";
};

template <class T>
T Queue <T> :: DeQueue()          // DeleteFirst
{
    if(First == NULL)
    {
        cout<<"Unable to pop the element as Queue is empty."<<"\n";
        return (T)-1;
    }
    else 
    {
        T value = First -> data;
        struct  SinglyNode  <T> *temp = First;

        First = First ->next;
        delete temp;

        iCount--;

        return value;
    }
}

template <class T>
void Queue <T> :: Display()
{
    if(First == NULL)
    {
        cout<<"Queue is empty."<<"\n";
    }
    else 
    {
        cout<<"Elements of Queue are : "<<"\n";

        struct  SinglyNode  <T>*temp = First;
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" |-> ";
            temp = temp -> next;
        }
        cout<<" NULL"<<"\n";
    }
}
int main()
{
    return 0;
}

template <class T>
BST <T>:: BST()
{
    Root = NULL;
}

template <class T>
void BST <T>::Insert(T No)
{
    struct BSTNode <T>* newn = new BSTNode<T>;

    newn->data = No;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(Root == NULL)
    {
        Root = newn;
    }
    else
    {
        struct BSTNode <T>*temp = Root;
        while(1)
        {
            if(No > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else if(No < temp->data)
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
            else if(No == temp->data)
            {
                delete (newn);
                cout<<"Duplicate element not allowed."<<"\n";
                break;
            } 
        }
    }
}

template <class T>
void BST <T>::Inorder(struct BSTNode<T> * temp)
{
    if(temp != NULL)
    {
        Inorder(temp->lchild);
        printf("%d\t",temp->data);
        Inorder(temp->rchild);
    }
}

template <class T>
void BST <T>::Preorder(struct BSTNode<T> * temp)
{
    if(temp != NULL)
    {
        printf("%d\t",temp->data);
        Preorder(temp->lchild);
        Preorder(temp->rchild);
    }
}

template <class T>
void BST <T>::Postorder(struct BSTNode<T> * temp)
{
    if(temp != NULL)
    {
        Postorder(temp->lchild);
        Postorder(temp->rchild);
        printf("%d\t",temp->data);
    }
}

template <class T>
bool BST <T>::Search(struct BSTNode<T> * temp, T No)
{
    bool flag = false;

    while(temp != NULL)
    {
        if(temp->data == No)
        {
            flag = true;
            break;
        }
        else if(No > temp->data)
        {
            temp = temp -> rchild;
        }
        else if(No < temp -> data)
        {
            temp = temp -> lchild;
        }
    }
    return flag;
}

template <class T>
int BST <T>::CountLeafNode(struct BSTNode<T> * temp)
{
    static int Count = 0;

    if(temp != NULL)
    {
        if((temp->lchild == NULL) && (temp ->rchild == NULL))
        {
            Count++;
        } 
        CountLeafNode(temp->lchild);
        CountLeafNode(temp->rchild);
    }

    return Count;
}

template <class T>
int BST <T>::CountParentNode(struct BSTNode<T> * temp)
{
    static int Count = 0;

    if(temp != NULL)
    {
        if((temp->lchild != NULL) || (temp ->rchild != NULL))
        {
            Count++;
        } 
        CountParentNode(temp->lchild);
        CountParentNode(temp->rchild);
    }

    return Count;
}

template <class T>
int BST <T>::CountCompleteParentNode(struct BSTNode<T> *temp)
{
    static int Count = 0;

    if(temp != NULL)
    {
        if((temp->lchild != NULL) && (temp ->rchild != NULL))
        {
            Count++;
        } 
        CountCompleteParentNode(temp->lchild);
        CountCompleteParentNode(temp->rchild);
    }

    return Count;
}

int main()
{
    return 0;
}