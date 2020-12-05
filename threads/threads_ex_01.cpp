//Multithreading using pthread.h

#include <iostream>
#include <pthread.h>
#include <cstdlib>
using namespace std;

void *test(void *thread_id)
{
	long id;
	id = (long)thread_id;
	cout << "Test coming from ID: " << id <<endl;
	pthread_exit(NULL);
}

int main()
{
	pthread_t threads[3];
	int i;
	int rc;
	for(i=0;i<3;i++)
	{
		cout << "Creating number: " << i << endl;
		rc = pthread_create(&threads[i], NULL, test, (void*)i);
		if(rc)
		{
			cout << "ERROR: cannot create a new thread," << rc << endl;
			exit(-1);
		}
	}
	pthread_exit(NULL);
	return 0;
}