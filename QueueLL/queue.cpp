/////////////////////////////////////////////////////////
// Descrp : LinkedList Implementation of Generic Queue
// Author : DipuKumar
// Language : C++
/////////////////////////////////////////////////////////

#include <iostream>
#include <string>

template <typename T>
class List
{
    private:
        template <typename T> struct Node {
            typename T  Data;
            Node<T>  * pNext;
            
            Node ( const T & data ) : Data ( data ), pNext ( nullptr ) { }
        };
        Node<T> * pHeader;
    public:
        List () : pHeader ( nullptr ) 
        { 
        }
        void Pushback ( const T & data )
        {
            auto newnode = new Node<T> ( data ), pnode = pHeader;

            if ( ! pHeader ) 
            { 
                 pHeader = newnode; 
                 return; 
            }

            while ( pnode->pNext ) 
                  pnode = pnode->pNext;

            pnode->pNext = newnode;
        }
        void Popfront ()
        {
            if ( pHeader == nullptr ) return;

            auto pnode = pHeader;

            pHeader = pnode->pNext;

            delete pnode;
        }
        const T & Front () const
        {
            return pHeader->Data;
        }
        bool IsEmpty () const
        {
            return pHeader == nullptr;
        }
};

template <typename T>
class Queue : private List<T>
{
    private:
        void Error ( std::string errmsg ) const
        {
            std::cout << "error : " + errmsg;
            exit ( 1 );
        }  
    public:
        Queue () 
        { 
        }
        void Enqueue ( const T & data )
        {
            Pushback ( data );
        }
        void Dequeue ()
        {
            if ( IsEmpty () ) Error ( "queue underflow" );

            Popfront ();
        }
        const T & Peek () const
        {
            if ( IsEmpty () ) Error ( "queue is empty" );

            return Front ();
        }
        bool Empty () const
        {
            return IsEmpty ();
        }
};

int main ()
{
    Queue<std::string> dq;

    dq.Enqueue ( "DEEPU" );
    dq.Enqueue ( "KUMAR" );

    while ( ! dq.Empty () )
    {
        std::cout << dq.Peek () << "\t";
        dq.Dequeue ();
    }

    return 0;
}









