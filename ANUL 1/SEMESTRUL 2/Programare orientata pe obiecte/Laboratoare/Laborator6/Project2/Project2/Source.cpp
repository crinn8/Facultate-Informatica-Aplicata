#include <iostream>
#include "Stiva.h"

int main()
{
	Stiva<int>::Nod n;
	Stiva<int> st;
	st.AddNod(4);
	st.AddNod(1);
	st.AddNod(3);
	st.AddNod(5);
	st.PrintStiva();
	cout<<"Am sters nodul cu info = "<<st.RemoveNod()<<endl;
	st.PrintStiva();
	st.GolireStiva();
	return 0;
}