#include <iostream>
#include <string>

template <typename T>
class Iter;

template <typename T>
class List;

template <typename T>
class Node
{
    typename T Data;
    Node<T> * pPrev;
    Node<T> * pNext;

    Node ( const T & d = T (), Node<T> * p = nullptr, Node<T> * n = nullptr )
    : Data ( d ), pPrev ( p ), pNext ( n ) { }

    friend class Iter<T>;
    friend class List<T>;
};

template <typename T>
class List
{
    private:
        Node<T> * pHead;
        Node<T> * pTail;
        int       iSize;

        void Free ()
        {
            while ( ! Empty () )
                Popfront ();
        }
        void Error ( std::string errmsg ) const
        {
            std::cout << errmsg;
            exit ( 1 );
        }
    public:
        typedef Iter<T> Iterator;

        List ()
        {
            iSize = 0;
            pHead = new Node<T>;
            pTail = new Node<T>;

            pHead->pNext = pTail;
            pTail->pPrev = pHead;
        }
        ~List ()
        {
            Free ();

            delete pHead;
            delete pTail;
        }
        List ( const List<T> & rhs )
        {
            iSize = 0;
            pHead = new Node<T>;
            pTail = new Node<T>;

            pHead->pNext = pTail;
            pTail->pPrev = pHead;

            *this = rhs;
        }
        const List<T> & operator = ( const List<T> & rhs )
        {
            if ( this == & rhs ) return *this;

            Free ();

            for ( Iterator itr = rhs.Begin (); itr != rhs.End (); ++itr )
                Pushback ( *itr );

            return *this;
        }
        Iterator Insert ( Iterator itr, const T & data )
        {
            itr.CheckIfValid ();

            if ( itr.pHeader != pHead )
                Error ( "insert iterator not in this list" );

            Node<T> * p = itr.pCurrent;

            p->pPrev->pNext = new Node<T> ( data, p->pPrev, p );
            p->pPrev = p->pPrev->pNext;

            iSize++;

            return Iterator ( *this, p->pPrev );
        }
        Iterator Erase ( Iterator itr )
        {
            itr.CheckIfValid ();

            if ( itr == End () )
                Error ( "error : cannot erase at end ()" );

            if( itr.pHeader != pHead )
                Error ( "error : erase iterator not in this list" );

            Node<T> * p = itr.pCurrent;

            Iterator retVal ( *this, p->pNext );

            p->pPrev->pNext = p->pNext;
            p->pNext->pPrev = p->pPrev;

            delete p; iSize--;

            return retVal;
        }
        Iterator Erase ( Iterator from, Iterator to )
        {
            for ( Iterator itr = from; itr != to; )
                itr = Erase ( itr );

            return to;
        }
        void Pushback ( const T & data )
        {
            Insert ( End (), data );
        }
        void Pushfront ( const T & data )
        {
            Insert ( Begin (), data );
        }
        void Popback ()
        {
            Erase ( --End () );
        }
        void Popfront ()
        {
            Erase ( Begin () );
        }
        const T & Front ()
        {
            return *Begin ();
        }
        const T & Back ()
        {
            return *--End ();
        }
        Iterator Begin ()
        {
            Iterator itr ( *this, pHead );

            return ++itr;
        }
        Iterator End ()
        {
            return Iterator ( *this, pTail );
        }
        bool Empty () const
        {
            return iSize == 0;
        }
        int  Size () const
        {
            return iSize;
        }

        friend class Iter<T>;
};

template <typename T>
class Iter
{
    private:
        Node<T> * pHeader;
        Node<T> * pCurrent;

		void CheckIfInit () const
		{
		    if ( pHeader == nullptr || pCurrent == nullptr )
                Error ( "error : iterator uninitialize" );
		}
		void CheckIfValid () const
		{
		    CheckIfInit();

		    if ( pCurrent == pHeader )
                Error ( "error : iterator out of boound" );
		}
		void CheckIfCanAdvance () const
		{
		    CheckIfInit ();

            if ( pCurrent->pNext == nullptr )
                Error ( "error :  cannot perform ++end()" );
		}
		void CheckIfCanRetreat () const
		{
		    CheckIfValid ();

            if ( pCurrent->pPrev == pHeader )
                Error ( "error :  cannot perform --begin()" );
		}
		void Error ( std::string errmsg ) const
		{
		    std::cout << errmsg;
		    exit ( 1 );
		}
		typename T &  Retrieve () const
		{
		    CheckIfValid ();

		    if ( pCurrent->pNext == nullptr )
                Error ( "error : cannot perform *End ()" );

            return pCurrent->Data;
		}
		Iter ( const List<T> & source, Node<T> * p ) : Iter<T> ( source, p ) { }
    public:
        Iter ()
        {

        }
        typename T & operator * ()
        {
            return this->Retrieve ();
        }
        Iter<T> & operator ++ ()
        {
            this->CheckIfCanAdvance();
            this->pCurrent = this->pCurrent->pNext;
            return *this;
        }
        Iter<T> operator ++ ( int )
        {
            Iter<T> old = *this;
            ++ ( *this );
            return old;
        }
        Iter<T> & operator -- ()
        {
            this->CheckIfCanRetreat ();
            this->pCurrent = this->pCurrent->pPrev;
            return *this;
        }
        Iter<T> operator -- ( int )
        {
            Iter<T> old = *this;
            -- ( *this );
            return old;
        }
        bool operator == ( const Iter<T> & rhs )
        {
            return pCurrent == rhs.pCurrent;
        }
        bool operator != ( const Iter<T> & rhs )
        {
            return ! ( *this == rhs );
        }

        friend class List<T>;
};

int main ()
{
	List<int> il;

	il.Pushback ( 100 );
	il.Pushback ( 200 );
	il.Pushback ( 300 );

    std::cout << il.Back (); il.Popback ();
    std::cout << il.Back (); il.Popback ();
    std::cout << il.Back (); il.Popback ();

	return 0;
}









