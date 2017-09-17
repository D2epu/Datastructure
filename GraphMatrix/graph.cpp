////////////////////////////////////////////////////////
// Descrp : Adjacency Matrix Implementation of Graph
// Author : DipuKumar
// Language : C++
////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <list>

template <typename T>
class Graph
{
    private:
        int gSize;
        typename T Vertices[100];
        bool AdjMatrix[100][100];

        int GetAdjUnVisited ( int vindex, bool * visited )
        {
            for ( int i = 0; i < gSize; i++ )
                if ( AdjMatrix[vindex][i] && visited[i] == false )
                    return i;

            return -1;
        }
    public:
        Graph () : gSize ( 0 )
        {
            for ( int i = 0; i < 100; i++ )
                for ( int j = 0; j < 100; j++ )
                    AdjMatrix[i][j] = false;
        }
        void AddVertex ( const T & data )
        {
            Vertices[gSize++] = data;
        }
        void AddEdge ( int src, int dest )
        {
            AdjMatrix[src][dest] = true;
            AdjMatrix[dest][src] = true;
        }
        void RemoveEdge ( int src, int dest )
        {
            AdjMatrix[src][dest] = false;
            AdjMatrix[dest][src] = false;
        }
        void DepthFirstSearch ()
        {
            bool visited[100]; int unvisited;

            for ( int i = 0; i < gSize; i++ )
                visited[i] = false;

            visited[0] = true;

            std::cout << Vertices[0] << "\t";

            std::stack<int> stk;

            stk.push ( 0 );

            while ( ! stk.empty () )
            {
                int unvisited = GetAdjUnVisited ( stk.top (), visited );

                if ( unvisited == -1 ) stk.pop ();

                else
                {
                    visited[unvisited] = true;
                    std::cout << Vertices[unvisited] << "\t";
                    stk.push ( unvisited );
                }
            }
        }
        void BreadthFirstSearch ()
        {
            bool visited[100]; int unvisited;

            for ( int i = 0; i < gSize; i++ )
                visited[i] = false;

            visited[0] = true;

            std::cout << Vertices[0] << "\t";

            std::queue<int> que;

            stk.push ( 0 );

            while ( ! stk.empty () )
            {
                int unvisited = GetAdjUnVisited ( stk.top (), visited );

                if ( unvisited == -1 ) stk.pop ();

                else
                {
                    visited[unvisited] = true;
                    std::cout << Vertices[unvisited] << "\t";
                    stk.push ( unvisited );
                }
            }
        }
        bool Empty () const
        {
             return gSize == 0;
        }
        int Size () const
        {
             return gSize;
        }
};

int main ()
{
    Graph<std::string> gr;

    gr.AddVertex ( "DEEPU" );
    gr.AddVertex ( "ARYAN" );
    gr.AddVertex ( "RINKI" );
    gr.AddVertex ( "NIRAJ" );
    gr.AddVertex ( "AJEET" );

    gr.AddEdge ( 0, 1 );
    gr.AddEdge ( 0, 2 );
    gr.AddEdge ( 0, 3 );
    gr.AddEdge ( 1, 4 );
    gr.AddEdge ( 2, 4 );
    gr.AddEdge ( 3, 4 );

    gr.DepthFirstSearch ();

    return 0;
}








