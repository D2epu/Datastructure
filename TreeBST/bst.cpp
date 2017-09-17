//////////////////////////////////////////////////////////
// Descrp : Implementation of Generic BinarySearchTree
// Author : DipuKumar
// Language : C++
//////////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <string>

template <typename T>
class BinaryTree;

template <typename T>
class BNode
{
    private:
        typename T Data;
        BNode<T> * pLeft;
        BNode<T> * pRight;

        BNode ( const T & d = T () ) : Data ( d ), pLeft ( nullptr ), pRight ( nullptr )
        {
        }
        static int Size ( BNode<T> * pnode )
        {
            if ( pnode == nullptr ) return 0;

            else return 1 + Size ( pnode->pLeft ) + Size ( pnode->pRight );
        }
        static int Height ( BNode<T> * pnode )
        {
            if ( pnode == nullptr ) return -1;

            else return 1 + std::max ( Size ( pnode->pLeft ), Size ( pnode->pRight ) );
        }

        friend class BinaryTree<T>;
};

template <typename T>
class BinaryTree
{
    private:
        BNode<T> * pRoot;

        void Insert ( const T & data, BNode<T> * & pnode )
        {
            if ( pnode == nullptr ) pnode = new BNode<T> ( data );

            else if ( data < pnode->Data ) Insert ( data, pnode->pLeft );

            else Insert ( data, pnode->pRight );
        }
        bool Search ( const T & key, BNode<T> * pnode )
        {
            if ( pnode == nullptr ) return false;

            else if ( pnode->Data == key ) return true;

            else if ( key < pnode->Data ) return Search ( key, pnode->pLeft );

            else return Search ( key, pnode->pRight );
        }
        void PrintInOrder ( BNode<T> * pnode ) const
        {
            if ( pnode == nullptr ) return;

            PrintInOrder ( pnode->pLeft );

            std::cout << pnode->Data << "\t";

            PrintInOrder ( pnode->pRight );
        }
        void PrintPreOrder ( BNode<T> * pnode ) const
        {
            if ( pnode == nullptr ) return;

            std::cout << pnode->Data << "\t";

            PrintPreOrder ( pnode->pLeft );

            PrintPreOrder ( pnode->pRight );
        }
        void PrintPostOrder ( BNode<T> * pnode ) const
        {
            if ( pnode == nullptr ) return;

            PrintPostOrder ( pnode->pLeft );

            PrintPostOrder ( pnode->pRight );

            std::cout << pnode->Data << "\t";
        }
        const T & Min ( BNode<T> * pnode ) const
        {
            if ( pnode != nullptr )
                while ( pnode->pLeft != nullptr )
                    pnode = pnode->pLeft;

            return pnode->Data;
        }
        const T & Max ( BNode<T> * pnode ) const
        {
            if ( pnode != nullptr )
                while ( pnode->pRight != nullptr )
                    pnode = pnode->pRight;

            return pnode->Data;
        }
        void FreeTree ( BNode<T> * & pnode )
        {
            if ( pnode != nullptr )
            {
                FreeTree ( pnode->pLeft );
                FreeTree ( pnode->pLeft );

                delete pnode; pnode = nullptr;
            }
        }
    public:
        BinaryTree () : pRoot ( nullptr )
        {
        }
        BinaryTree ( const T & RootData ) : pRoot ( new BNode<T> ( RootData ) )
        {
        }
        ~BinaryTree ()
        {
            FreeTree ( pRoot );
        }
        void Insert ( const T & data )
        {
            Insert ( data, pRoot );
        }
        bool Search ( const T & key )
        {
            return Search ( key, pRoot );
        }
        const T & Min () const
        {
            return Min ( pRoot );
        }
        const T & Max () const
        {
            return Max ( pRoot );
        }
        void PrintInOrder () const
		{
			PrintInOrder ( pRoot );
		}
		void PrintPreOrder () const
		{
			PrintPreOrder ( pRoot );
		}
		void PrintPostOrder () const
		{
			PrintPostOrder ( pRoot );
		}
        bool Empty () const
        {
            return pRoot == nullptr;
        }
        int Size () const
        {
            return BNode<T>::Size ( pRoot );
        }
        int Height () const
        {
            return BNode<T>::Height ( pRoot );
        }
};

int main ()
{
    BinaryTree<int> bt;

    bt.Insert ( 200 );
    bt.Insert ( 300 );
    bt.Insert ( 100 );
    bt.Insert ( 400 );
    bt.Insert ( 500 );

    bt.PrintInOrder (); std::cout << std::endl;
    bt.PrintPreOrder (); std::cout << std::endl;
    bt.PrintPostOrder (); std::cout << std::endl;

    if ( bt.Search ( 400 ) ) std::cout << "found\n";

    std::cout << "size   : " << bt.Size () << "\n";
    std::cout << "height : " << bt.Height () << "\n";
    std::cout << "min    : " << bt.Min () << "\n";
    std::cout << "max    : " << bt.Max () << "\n";

    return 0;
}





