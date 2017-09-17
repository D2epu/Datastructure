//////////////////////////////////////////////////////////
// Descrp : Implementation of Generic Singly LinkedList
// Author : DipuKumar
// Language : C++
//////////////////////////////////////////////////////////

#include <iostream>
#include <string>

template <typename T> struct Node {
	typename T  Data;
	Node<T> *  pNext;

	Node ( const T & d = T () ) : Data ( d ), pNext ( nullptr ) { }
};

template <typename T>
class List
{
    private:
        Node<T> * pHeader;

        void Error ( std::string errmsg ) const
        {
            std::cout << "error : " + errmsg;
            exit ( 1 );
        }
    public:
        List () : pHeader ( nullptr )
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

            auto newnode = new Node<T> ( data ), pnode = pHeader;

            for ( int i = 0; i < pos - 2; i++ )
                pnode = pnode->pNext;

            newnode->pNext = pnode->pNext;
            pnode->pNext = newnode;
        }
        void Erase ( int pos )
        {
            if ( pHeader == nullptr ) Error ( "list underflow" );

            if ( pos < 1 || pos > Size () ) Error ( "out of range" );

            if ( pos == 1 )
            {
                Popfront ();
                return;
            }

            auto pnode = pHeader;

            for ( int i = 0; i < pos - 2; i++ )
                pnode = pnode->pNext;

            auto ptmp = pnode->pNext;

            pnode->pNext = ptmp->pNext;

            delete ptmp;
        }
        void Pushfront ( const T & data )
        {
            auto newnode = new Node<T> ( data );

            if ( pHeader == nullptr )
                pHeader = newnode;
            else
            {
                newnode->pNext = pHeader;
                pHeader = newnode;
            }
        }
        void Pushback ( const T & data )
        {
            auto newnode = new Node<T> ( data );

            if ( pHeader == nullptr )
                pHeader = newnode;
            else
            {
                auto pnode = pHeader;

                while ( pnode->pNext )
                    pnode = pnode->pNext;

                pnode->pNext = newnode;
            }
        }
        void Popfront ()
        {
            if ( pHeader == nullptr ) Error ( "list underflow" );

            auto pnode = pHeader;

            pHeader = pnode->pNext;

            delete pnode;
        }
        void Popback ()
        {
            if ( pHeader == nullptr ) Error ( "list underflow" );

            if ( pHeader->pNext == nullptr )
            {
                Popfront ();
                return;
            }

            Node<T> * pnode = pHeader, * ptmp;

            while ( pnode->pNext )
            {
                ptmp = pnode;
                pnode = pnode->pNext;
            }

            delete ptmp->pNext;

            ptmp->pNext = nullptr;
        }
        const T & Front () const
        {
            if ( pHeader == nullptr ) Error ( "list is empty" );

            return pHeader->Data;
        }
        const T & Back () const
        {
            if ( pHeader == nullptr ) Error ( "list is empty" );

            auto pnode = pHeader;

            while ( pnode->pNext )
                pnode = pnode->pNext;

            return pnode->Data;
        }
        const auto Begin () const
        {
            return pHeader;
        }
        bool Empty () const
        {
            return pHeader == nullptr;
        }
        int Size ()  const
        {
            int _count = 0;

            for ( auto itr = pHeader; itr; itr = itr->pNext )
                _count++;

            return _count;
        }
        void Print () const
        {
            for ( auto itr = pHeader; itr; itr = itr->pNext )
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

	auto itr = sl.Begin ();

    while ( itr )
    {
        std::cout << itr->Data << "\n";
        itr = itr->pNext;
    }


	return 0;
}
