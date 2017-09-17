//////////////////////////////////////////////////////////
// Descrp : Implementation of Generic Doubly LinkedList
// Author : DipuKumar
// Language : C++
//////////////////////////////////////////////////////////

#include <iostream>
#include <string>

template <typename T> struct Node {
	typename T  Data;
	Node<T> *  pNext;
	Node<T> *  pPrev;

	Node ( const T & d ) : Data ( d ), pNext ( nullptr ), pPrev ( nullptr ) { }
};

template <typename T>
class List
{
    private:
        Node<T> * pHead;
        Node<T> * pTail;

        void Error ( std::string errmsg ) const
        {
            std::cout << "error : " + errmsg;
            exit ( 1 );
        }
    public:
        List () : pHead ( nullptr ), pTail ( nullptr )
        {
        }
        void Insert ( const T & data, int pos )
        {
            if ( pos < 1 || pos > Size () ) Error ( "out of range" );

            if ( pos == 1 )
            {
                Pushfront ( data );
                return;
            }

            auto newnode = new Node<T> ( data ), pnode = pHead;

            for ( int i = 0; i < pos - 2; i++ )
                pnode = pnode->pNext;

            newnode->pNext = pnode->pNext;
            newnode->pPrev = pnode;
            pnode->pNext = newnode;

            if ( newnode->pNext )
                newnode->pNext->pPrev = newnode;
        }
        void Erase ( int pos )
        {
            if ( pHead == nullptr ) Error ( "list underflow" );

            if ( pos < 1 || pos > Size () ) Error ( "out of range" );

            if ( pos == 1 )
            {
                Popfront ();
                return;
            }

            Node<T> * node = pHeader, * temp;

            for ( int i = 0; i < pos - 2; i++ )
                node = node->pNext;

            temp = node->pNext;
            node->pNext = temp->pNext;

            delete temp;
        }
        void Pushfront ( const T & data )
        {
            auto newnode = new Node<T> ( data );

            if ( pHead == nullptr )
                pTail = newnode;
            else
                pHead->pPrev = newnode;

            newnode->pNext = pHead;

            pHead = newnode;
        }
        void Pushback ( const T & data )
        {
            auto newnode = new Node<T> ( data );

            if ( pHead == nullptr )
                pTail = newnode;
            else
            {
                pTail->pNext = newnode;
                newnode->pPrev = pTail;
            }

            pTail = newnode;
        }
        void Popfront ()
        {
            if ( pHead == nullptr ) Error ( "list underflow" );

            auto pnode = pHead;

            if ( pHead->pNext == nullptr )
                pTail = nullptr;
            else
                pHead->pNext->pPrev = nullptr;

            pHead = pHead->pNext;

            delete pnode;
        }
        void Popback ()
        {
            if ( pHead == nullptr ) Error ( "list underflow" );

            auto pnode = pTail;

            if ( pHead->pNext == nullptr )
                pHead = nullptr;
            else
                pTail->pPrev->pNext = nullptr;

            pTail = pTail->pPrev;

            delete pnode;
        }
        const T & Front () const
        {
            if ( pHead == nullptr ) Error ( "list is empty" );

            return pHead->Data;
        }
        const T & Back () const
        {
            if ( pHead == nullptr ) Error ( "list is empty" );

            if ( pHead->pNext == nullptr )
                return pHead->Data;

            return pTail->Data;
        }
        const auto Begin () const
        {
            return pHead;
        }
        const auto End () const
        {
            return pTail;
        }
        bool Empty () const
        {
            return pHead == nullptr;
        }
        int Size ()  const
        {
            int _count = 0;

            for ( auto itr = pHead; itr; itr = itr->pNext )
                _count++;

            return _count;
        }
        void PrintForward () const
        {
            for ( auto itr = pHead; itr; itr = itr->pNext )
                std::cout << itr->Data << "\t";

            std::cout << std::endl;
        }
        void PrintBackward () const
        {
            for ( auto itr = pTail; itr; itr = itr->pPrev )
                std::cout << itr->Data << "\t";

            std::cout << std::endl;
        }
};

int main ()
{
	List<int> il;

	il.Pushback ( 100 );
	il.Pushback ( 200 );
	il.Print ();
	il.Pushfront ( 300 );
	il.Pushfront ( 400 );
	il.Print ();
	il.Insert ( 100, 2 );
	il.Insert ( 200, 3 );
	il.Print ();
	il.Popback ();
	il.Print ();
	il.Popfront ();
	il.Print ();
	il.Erase ( 3 );
	il.Print ();

	List<std::string> sl;

	sl.Pushback ( "DEEPU" );
	sl.Pushback ( "KUMAR" );
	sl.Pushback ( "GUPTA" );
	sl.Print ();

	List<std::string>::Iterator itr = sl.Begin ();

    while ( itr )
    {
        std::cout << itr->Data << "\n";
        itr = itr->pNext;
    }


	return 0;
}
