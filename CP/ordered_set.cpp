#include<bits/stdc++.h>

//header files
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;

//namespace for pbds
using namespace __gnu_pbds;

//less<int> implies ascending, greater<int> will do it descending, less_equal<int> will allow us to store duplicate val too
//ds behind it is a red black tree
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

int main() {
	pbds A; // declaration

	// Inserting elements - 1st query
	A.insert(1);
	A.insert(10);
	A.insert(2);
	A.insert(7);
	A.insert(2);  // ordered set only contains unique values

	// A contains
	cout << "A = ";
	for (auto i : A)
		cout << i << " ";
	cout << endl;
	cout << endl;

	// finding kth element - 4th query
	cout << "0th element: " << *A.find_by_order(0) << endl;
	cout << "1st element: " << *A.find_by_order(1) << endl;
	cout << "2nd element: " << *A.find_by_order(2) << endl;
	cout << "3rd element: " << *A.find_by_order(3) << endl;
	cout << endl;

	// finding number of elements smaller than X - 3rd query
	cout << "No. of elems smaller than 6: " << A.order_of_key(6) << endl; // 2
	cout << "No. of elems smaller than 11: " << A.order_of_key(11) << endl; // 4
	cout << "No. of elems smaller than 1: " << A.order_of_key(1) << endl; // 0
	cout << endl;

	// lower bound -> Lower Bound of X = first element >= X in the set
	cout << "Lower Bound of 6: " << *A.lower_bound(6) << endl;
	cout << "Lower Bound of 2: " << *A.lower_bound(2) << endl;
	cout << endl;

	// Upper bound -> Upper Bound of X = first element > X in the set
	cout << "Upper Bound of 6: " << *A.upper_bound(6) << endl;
	cout << "Upper Bound of 1: " << *A.upper_bound(1) << endl;
	cout << endl;

	// // Remove elements - 2nd query
	A.erase(1);
	A.erase(11); // element that is not present is not affected

	// A contains
	cout << "A = ";
	for (auto i : A)
		cout << i << " ";
	cout << endl;

}




//op
A = 1 2 7 10 

0th element: 1
1st element: 2
2nd element: 7
3rd element: 10

No. of elems smaller than 6: 2
No. of elems smaller than 11: 4
No. of elems smaller than 1: 0

Lower Bound of 6: 7
Lower Bound of 2: 2

Upper Bound of 6: 7
Upper Bound of 1: 2

A = 2 7 10
