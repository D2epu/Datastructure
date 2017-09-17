/////////////////////////////////////////////////////
// Descrp : Vector Implementation of Generic Queue
// Author : DipuKumar
// Language : C++
/////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>

using std::vector;

template <typename T>
class Queue
{
    private:
        vector<T> Elem;
        
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
            Elem.push_back ( data );
        }
        void Dequeue ()
        {
            if ( Elem.empty () ) Error ( "queue underflow" );

            Elem.erase ( Elem.begin () );
        }
        const T & Peek () const
        {
            if ( Elem.empty () ) Error ( "queue is empty" );

            return Elem.front ();
        }
        bool Empty () const
        {
            return Elem.empty ();
        }
        int Size () const
        {
            return Elem.size ();
        }
};

int main ()
{
    Queue<int> iq;

    for ( int i = 100; i < 1000; i += 100 )
        iq.Enqueue ( i );

    while ( ! iq.Empty () )
    {
        std::cout << iq.Peek () << "\t";
        iq.Dequeue ();
    }

    return 0;
}









