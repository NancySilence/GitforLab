#include<iostream>
#include<fstream>
#include<ostream>
#include<sstream>
#include<cassert>
using namespace std;

/*

////////////////////////////////////////16.1///////////////////////////////////////////////////////////
template <typename T>
inline T abs(const T &v)
{
	return (v>0)?v:-v;
}



int main()
{
	cout<<"int numb:"<<abs(-8)<<endl;
	cout<<"double numb:"<<abs(-8.1)<<endl;
	cout<<"bool numb:"<<abs(false)<<endl;
	int temp;
	cin>>temp;
}



////////////////////////////////////////16.2///////////////////////////////////////////////////////////
template <typename T>
inline void testStream(ostream & v, T value)
{
	v<<value;
}

int main()
{
	testStream(cout,6);
	testStream(cout,true);
	testStream(cout,"Happy");

	ofstream outfile;
	outfile.open("testofstream.txt");
	assert(outfile);
	if(!outfile)
		return NULL;


	testStream(outfile,6);
	testStream(outfile,false);
	testStream(outfile,"test");
	outfile.close();


	stringstream ss;
	testStream(ss,8);
	testStream(ss,false);
	testStream(ss,"ss");

	cout<<ss.str()<<endl;

	system("pause");
	return 0;
}


////////////////////////////////////////16.1.2///////////////////////////////////////////////////////////


// class template
template<class T>
class Queue
{
public:
	Queue();
	T &front ();
	const T &front() const;
	void push(const T&);
	void pop();
	bool empty() const;

};

////////////////////////////////////////16.5///////////////////////////////////////////////////////////

template <typename T>
inline T Larger(T v1,T v2)
{
	return ((v1-v2)>0)?v1:v2;
}

int main(void)
{
	cout<<Larger(1,2)<<endl;
	cout<<Larger(3.8,3.5)<<endl;
	cout<<Larger(true,false)<<endl;
	cout<<Larger("true","test")<<endl;
	system("pause");
	return 0;
}
*/
////////////////////////////////////////16.5///////////////////////////////////////////////////////////
                                                                          