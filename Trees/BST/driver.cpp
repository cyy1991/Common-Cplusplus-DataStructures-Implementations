#include "BST.cpp"

template class BST<int>;

void main ( )
{
	BST<int> bt;

	bt.insert ( 5 );
	bt.insert ( 3 );
	bt.insert ( 8 );
	bt.insert ( 0 );
	bt.insert ( 4 );
	bt.insert ( 7 );
	bt.insert ( 9 );
	bt.insert ( 1 );
	bt.insert ( 2 );
	bt.insert ( 6 );
	bt.insert ( 6 );


	bt.displaySorted ( );
}