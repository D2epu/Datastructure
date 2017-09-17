/////////////////////////////////////////////////////
// Descrp : Array Implementation of Generic Stack
// Author : DipuKumar
// Language : C++
/////////////////////////////////////////////////////

#include <iostream>
#include <string>

template <typename T>
class Stack
{
	private:
		int Siz, TopStack;
		typename T * Elem;
		
		void Error ( const std::string & errmsg ) const
		{
		    std::cout << "error : " + errmsg;
		    exit ( 1 );
        }
	public:
		Stack ( int siz = 100 ) 
        : Siz ( siz ), TopStack ( -1 ), Elem ( new T[siz] ) 
        { 
        }
		~Stack ()
		{
		    delete [] Elem;
        };
		void Push ( const T & data )
		{
			if ( TopStack == Size () - 1 ) Error ( "stack overflow" );

			Elem[++TopStack] = data;
		}
		void Pop ()
		{
			if ( Empty () ) Error ( "stack underflow" );

			TopStack--;
		}
		const T & Top () const
		{
			if ( Empty () ) Error ( "stack is empty" );

			return ( Elem[TopStack] );
		}
		bool Empty () const
		{
		    return TopStack == -1;
        }
		int  Size () const
		{
		    return Siz;
		}
};

int main ()
{
	Stack<int> is;

	for ( int i = 0; i < 10; i++ )
		is.Push ( i );

	for ( int i = 0; i < 10; i++ )
	{
		std::cout << is.Top () << "\t";
		is.Pop ();
	}

	Stack<std::string> ss;

	ss.Push ( "GUPTA" );
	ss.Push ( "KUMAR" );
	ss.Push ( "DEEPU" );

    while ( ! ss.Empty () )
    {
        std::cout << ss.Top () << "\t";
        ss.Pop ();
    }

	return 0;
}
