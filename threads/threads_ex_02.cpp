#include <iostream>
#include <cstdlib>
#include <thread>
using namespace std;

void test(int thread_id)
{
	cout << "Test coming from ID: " << thread_id <<endl;
}

int main()
{
	thread th1(test,1), th2(test,2),th3(test,3);
	th1.join();
	th2.join();
	th3.join();
	return 0;
}