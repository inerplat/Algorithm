#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
int main()
{
	srand(time(NULL));
	vector <int> v;
	vector <int>::iterator vp;
	for (int i = 0; i < 10; i++) v.push_back(rand() % 100);
	for (int i = 0; i < (int)v.size(); i++) cout << v[i] << ' ';
	cout << endl << endl;

	vp = v.begin() + 3;
	v.insert(vp, 1000);


	for (int i = 0; i < (int)v.size(); i++) cout << v[i] << ' ';
	cout << endl << endl;

	vp = v.begin() + 5;
	v.erase(vp);

	for (vp = v.begin(); vp != v.end(); vp++) cout << *vp << ' ';
	cout << endl << endl;

	v.pop_back();

	for (vp = v.begin(); vp != v.end(); vp++) cout << *vp << ' ';

	cout << endl << endl;

	return 0;


}