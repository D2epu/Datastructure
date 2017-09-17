#include <iostream>
#include <string>

template <typename T>
class Array
{
    private:
        int Siz;
        typename T * Elem;
    public:
        explicit Array ( int siz = 100 ) : Siz ( siz ), Elem ( new T[siz])
        {
        }
        ~Array ()
        {
            delete [] Elem;
        }
        typename T & operator [] ( int i )
        {
            if ( i < 0 || i > Size () - 1 )
            {
                std::cout << "error : out of bound";
                exit ( 1 );
            }
            return Elem[i];
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
        darr[i] = i / 2.7;

    for ( int i = 0; i < darr.Size (); i++ )
        std::cout << darr[i] << "\n";

    darr[10] = 10;

    return 0;
}


