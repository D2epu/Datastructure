#include <iostream>
#include <string>

template <typename T>
class Array
{
    private:
        T * Elem;
        int Siz, Index;

        void Error ( std::string errmsg ) const
        {
            std::cout << errmsg;
            exit ( 1 );
        }
    public:
        explicit Array ( int siz = 100 ) : Elem ( new T[siz]), Siz ( siz ), Index ( 0 )
        {
        }
        ~Array ()
        {
            delete [] Elem;
        }
        void Add ( const T & data )
        {
            if ( Index >= Size () ) Error ( "error : array is full" );

            Elem[Index++] = data;
        }
        typename T Get ( int index )
        {
            if ( index >= Index ) Error ( "error : invalid index" );

            return Elem[index];
        }
        void Insert ( const T & data, int pos )
        {
            if ( pos < 0 || pos > Index ) Error ( "error : invalid position" );

            for ( int i = Index - 1; i >= pos - 1; i-- )
                Elem[i + 1] = Elem[i];

            Elem[pos - 1] = data;
        }
        void Erase ( int pos )
        {
            if ( pos < 0 || pos > Index ) Error ( "error : deletion impossible" );

            for ( i = pos - 1; i < Index - 1; i++ )
                Elem[i] = Elem[i + 1];
        }
        int Size () const
        {
            return Siz;
        }
};

int main ()
{
    Array<double> darr ( 10 );

    for ( int i = 0; i < darr.Size (); i++ )
        darr.Add ( i * 5.12 );

    for ( int i = 0; i < darr.Size (); i++ )
        std::cout << darr.Get ( i ) << "\t";

    Array<std::string> sarr;

    sarr.Add ( "Deepu" );
    sarr.Add ( "Gupta" );

    std::cout << sarr.Get ( 0 ) << sarr.Get ( 1 );

    sarr.Insert ( "Kumar", 2 );

    std::cout << "\n" << sarr.Get ( 0 ) << sarr.Get ( 1 ) << sarr.Get ( 2 );

    return 0;
}


