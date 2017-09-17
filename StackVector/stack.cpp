/////////////////////////////////////////////////////
// Descrp : Vector Implementation of Generic Stack
// Author : DipuKumar
// Language : C++
/////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>

using std::vector;

template <typename T>
class Stack
{
    private:
        vector<T> Elem;
    public:
        Stack () { }

        void Push ( const T & data )
        {
            Elem.push_back ( data );
        }

        void Pop ()
        {
            if ( Elem.empty () ) Error ( "stack underflow" );

            Elem.pop_back ();
        }

        typename T TopAndPop ()
        {
            if ( Elem.empty () ) Error ( "stack underflow" );

            T data = Elem.back ();

            Elem.pop_back ();

            return data;
        }

        const T & Top () const
        {
            if ( Elem.empty () ) Error ( "stack underflow" );

            return Elem.back ();
        }

        bool Empty () const
        {
            return Elem.empty ();
        }

        int Size () const
        {
            return Elem.size ();
        }

        void Error ( std::string errmsg ) const
        {
            std::cout << "error : " + errmsg;
            exit ( 1 );
        }
};

int main ()
{
    Stack<std::string> ss;

    ss.Push ( "DEEPU" );
    ss.Push ( "KUMAR" );
    ss.Push ( "GUPTA" );

    while ( ! ss.Empty () )
        std::cout << ss.TopAndPop () << "\t";

    Stack<int> is;

    is.Push ( 100 );
    is.Push ( 200 );
    is.Push ( 300 );

    while ( ! is.Empty () )
    {
        std::cout << is.Top () << "\t";
        is.Pop ();
    }

    return 0;
}




















