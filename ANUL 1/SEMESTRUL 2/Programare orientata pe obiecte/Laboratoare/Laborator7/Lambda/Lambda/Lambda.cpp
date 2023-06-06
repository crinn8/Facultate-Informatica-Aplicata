#include <iostream>
#include"vector"
#include"algorithm"
using namespace std;

struct test
{
	int x, y;
};

struct test2
{
	int x, y;
};

bool operator<(test t1, test t2)
{
	return t1.x * t1.x + t1.y * t1.y < t2.x* t2.x + t2.y * t2.y;
}

bool comp(test t1, test t2)
{
	return t1.x * t1.x + t1.y * t1.y < t2.x* t2.x + t2.y * t2.y;
}

using namespace std;

int main()
{
	float x = 1;
	//......
	auto y = x;
	cout << y << " " << sizeof(y) << endl;
	int u = 1;
	int w(2);
	//int a[4] = { 1, 7, 10, 4 };	// clasic
	//int a[] = { 1, 7, 10, 4 };
	int a[]{ 1, 7, 10, 4 };			// 2011

	vector<int> v;
	v.push_back(10);
	v.reserve(100);
	v.resize(5);
	for (int i = 1; i < 5; i++)
		v[i] = i;

	//vector<int> v2 = { 1, 7, 10, 4 };
	vector<int> v2{ 1, 7, 10, 4 };

	sort(a, a + 4);	// introsort (qsort + heap sort)
	for (int i = 0; i < 4; i++)
		cout << a[i] << " ";
	cout << endl;

	test t[]{ {1,2}, {3,0}, {-1,-1} };
	//sort(t, t + 3);
	sort(t, t + 3, comp);

	vector<test> t2{ { 1,2 },{ 3,0 },{ -1,-1 } };
	sort(t2.begin(), t2.end());
	for (test t : t2)
		cout << t.x << "," << t.y << " ";
	cout << endl;

	sort(v2.begin(), v2.end());
	if (binary_search(v2.begin(), v2.end(), 4))
		cout << "gasit" << endl;
	else
		cout << "nu este" << endl;

	vector<int>::iterator it = lower_bound(v2.begin(), v2.end(), 4);	// upper_bound
	if (it != v2.end())
	{
		if (*it == 4)
			cout << "gasit" << endl;
		else
			cout << "margine superioara: " << *it << endl;
	}
	else
		cout << "nu exista valoare superioara" << endl;

	for (test& t : t2)
	{
		t.x++;
		t.y--;
	}
	for (test t : t2)
		cout << t.x << "," << t.y << " ";
	cout << endl;

	//auto lambda = [=]() { cout << "lambda " << w << endl; };
	//auto lambda = [&]() { cout << "lambda " << w++ << endl; };
	//auto lambda = [=, &w]() { cout << "lambda " << u << " " << w++ << endl;  };
	//auto lambda = [=u, &]() { cout << "lambda " << u << " " << w++ << endl;  };	// gresit
	auto lambda = [=, &w, &t2]() { cout << "lambda " << u << " " << w++ << " " << t2[0].x++ << endl;  };
	lambda();
	lambda();

	vector<test2> t3{ { 1,2 },{ 3,0 },{ -1,-1 } };
	//sort(t3.begin(), t3.end(), [](test2 t1, test2 t2)->bool { return t1.x*t1.x + t1.y*t1.y < t2.x*t2.x + t2.y*t2.y; });	// explicit tip returnat bool
	sort(t3.begin(), t3.end(), [](test2 t1, test2 t2) { return t1.x * t1.x + t1.y * t1.y < t2.x* t2.x + t2.y * t2.y; });	// implicit bool
	for (test2& t : t3)
		cout << t.x << "," << t.y << " ";
	cout << endl;

	return 0;
}