/////////////////////////////////////////////////////////
// Descrp : LinkedList Implementation of Generic Stack
// Author : DipuKumar
// Language : C++
/////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>

template <typename T>
class List
{
    private:
        template <typename T> struct Node {
            typename T  Data;
            Node<T> *  pNext;
            
            Node ( const T & data ) : Data ( data ), pNext ( nullptr ) { }
        };
        Node<T> * pHeader;
    public:
        List () : pHeader ( nullptr ) 
        { 
        }
        void Pushfront ( const T & data )
        {
            auto newnode = new Node<T> ( data );

            if ( pHeader ) newnode->pNext = pHeader;

            pHeader = newnode;
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
class Stack : private List<T>
{
    public:
        Stack () 
        { 
        }
        void Push ( const T & data )
        {
            Pushfront ( data );
        }
        void Pop ()
        {
            if ( IsEmpty () )
            {
                std::cout << "stack underflow";
                exit ( 1 );
            }

            Popfront ();
        }
        const T & Top () const
        {
            return Front ();
        }
        bool Empty () const
        {
            return IsEmpty ();
        }
};

int main ()
{
    Stack<std::string> ss;

    ss.Push ( "GUPTA" );
    ss.Push ( "KUMAR" );
    ss.Push ( "DEEPU" );

    while ( ! ss.Empty () )
    {
        std::cout << ss.Top () << "\t";
        ss.Pop ();
    }

    Stack<double> ds;

    ds.Push ( 100.10 );
    ds.Push ( 200.20 );
    ds.Push ( 300.30 );

    while ( ! ds.Empty () )
    {
        std::cout << ds.Top () << "\t";
        ds.Pop ();
    }

    return 0;
}











