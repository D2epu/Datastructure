////////////////////////////////////////////////////
// Descrp : Array Implementation of Generic Queue
// Author : DipuKumar
// Language : C++
////////////////////////////////////////////////////

#include <iostream>
#include <string>

template <typename T>
class Queue
{
	private:
		int qSize, Front, Rear;
		typename T * Elem;
		
		void Error ( std::string errmsg ) const
		{
		    std::cout << "error : " + errmsg;
		    exit ( 1 );
        }
	public:
		explicit Queue ( int siz = 100 ) 
        : qSize ( siz ), Front ( 0 ), Rear ( -1 ), Elem ( new T[siz] ) 
        { 
        }
		~Queue ()
		{
		    delete [] Elem;
        };
		void Enqueue ( const T & data )
		{
			if ( Rear == qSize - 1 ) Error ( "queue overflow" );

			Elem[++Rear] = data;
		}
		void Dequeue ()
		{
			if ( Rear < Front ) Error ( "queue underflow" );

			Front++;
		}
		const T & Peek () const
		{
            return Elem[Front];
        }
		bool Empty () const
        {
            return bool ( Rear < Front );
        }
		int  Size () const
		{
		    return Siz;
		}
};

int main ()
{
	Queue<int> iq;

	for ( int i = 0; i < 10; i++ )
		iq.Enqueue ( i );

	while ( ! iq.Empty () ) {
		std::cout << iq.Peek () << std::endl;
		iq.Dequeue ();
    }


	return 0;
}

