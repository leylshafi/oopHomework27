#include <iostream>

using namespace std;

#include "Shared_Ptr.h"

int main()
{
	cout << boolalpha;

	Shared_Ptr<int> ptr1 = new int(1);
	Shared_Ptr<int> ptr2 = ptr1;
	Shared_Ptr<int> ptr3;
	ptr3 = ptr1;

	

	cout << ptr1.use_count() << endl;

	cout<<ptr1.get();

}
