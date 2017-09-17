//////////////////////////////////////////////////////
// Descrp : Implementation of Generic Dynamic Array
// Author : DipuKumar
// Language : C++
//////////////////////////////////////////////////////

#include <iostream>
#include <string>

template <typename T>
class Vector
{
    private:
        int   vSize, vCap;
        typename T * Elem;
        
        void Error ( std::string errmsg ) const
        {
            std::cout << errmsg;
            exit ( 1 );
        }
    public:
        explicit Vector ( int siz = 0 ) 
        : vSize ( siz ), vCap ( siz + 16 ), Elem ( new T[vCap] ) 
        { 
        }
        ~Vector ()
        {
            delete [] Elem;
        }
        
        typedef T * Iterator;
        
        Iterator Begin ()
        {
            return & Elem[0];
        }
        Iterator End ()
        {
            return & Elem[ Size () ];
        }
        typename T & operator [] ( int index )
        {
            if ( index < 0 || index >= Size () ) Error ( "error : out of bound" );

            return Elem[index];
        }
        const Vector<T> & operator = ( const Vector<T> & rhs )
        {
            if ( this != &rhs )
            {
                delete [] Elem;
                vSize = rhs.Size ();
                vCap  = rhs.Capacity();

                Elem = new T[ Capacity () ];

                for ( int k = 0; k < Size (); k++ )
                    Elem[k] = rhs.Elem[k];
            }
            return *this;
        }
        void Resize ( int sz )
        {
            if ( vSize > vCap ) Reserve ( vSize * 2 );

            vSize = sz;
        }
        void Reserve ( int newcap )
        {
            typename T * oldarr = Elem;

            int nocopy = newcap < vSize ? newcap : vSize;

            newcap += 16;

            Elem = new T[newcap];

            for ( int i = 0; i < nocopy; i++ )
                Elem[i] = oldarr[i];

            vSize = nocopy;
            vCap  = newcap;

            delete [] oldarr;
        }
        void Pushback ( const T & data )
        {
            if ( vSize == vCap ) Reserve ( 2 * vCap + 1 );

            Elem[vSize++] = data;
        }
        void Popback ()
        {
            if ( Empty () ) Error ( "error : underflow" );

            vSize--;
        }
        const T & Back () const
        {
            if ( Empty () ) Error ( "error : empty vector" );

            return Elem[vSize - 1];
        }
        bool Empty () const
        {
            return vSize == 0;
        }
        int Size () const
        {
            return vSize;
        }
        int Capacity () const
        {
            return vCap;
        }
};

int main ()
{
    Vector<int> dv;

    for ( int i = 0; i < 10; i++ )
        dv.Pushback ( i );

    for ( int i = 0; i < dv.Size (); i++ )
        std::cout << dv[i] << "\t";

    auto itr = dv.Begin ();

    while ( itr != dv.End () )
    {
        std::cout << *itr << "\t";
        itr++;
    }

    return 0;
}


