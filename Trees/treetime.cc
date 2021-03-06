#include <iostream> 
#include <cstdlib>
#include "RBTree.h"
#include "BinarySearchTree.h"
#include <boost/timer.hpp>
#include <iomanip>
#include <climits>
using namespace boost;
using namespace std;

int main(int argc, char* argv[])
{
   timer clock;
   srand(time(0));
   int numBatches = atoi(argv[2]);
   int batchSize = atoi(argv[1]);
   RBTree<long long, long long> myRBTree;
   BinarySearchTree<long long, long long> myBinTree;
   long long k= 0;
   long long m =0;
   double time1;
   double time2;
   cout<<endl;
   cout<<"Strictly Increasing Inserts"<<endl;
   cout<< setw(20) <<left << "Size" << setw(20)<<left<<"RBTreeTime"<<"BSTreeTime"<<endl;
   for(long long i = 0;i<numBatches;i++)
   {
     cout<<setw(20)<<left<<myRBTree.getSize();
     clock.restart();
     for (long long j = 0; j<batchSize;j++)
       {
	 myRBTree.insert(k,j);
	 k++;
       }
     time1 = clock.elapsed();
     clock.restart();
     for (long long j = 0; j<batchSize;j++)
	{
	  myBinTree.insert(m,j);
	  m++;
	}
     time2 = clock.elapsed();
     cout<<setw(20)<<left <<time1<<  time2 <<endl;      
   }
   cout<<endl;
   RBTree<long long, long long> myRBTree2;
   BinarySearchTree<long long, long long> myBinTree2;
   cout<<"Random Inserts"<<endl;
   cout<< setw(20) <<left << "RBTreeSize" << setw(20)<<left<<"RBTreeTime"<< setw(20)<<left<<"BSTreeSize"<<"BSTreeTime"<<endl;
   for(long long i = 0;i<numBatches;i++)
   {
     cout<<setw(20)<<left<<myRBTree2.getSize();
     clock.restart();
     for (long long j = 0; j<batchSize;j++)
       {
	 long long k = 0;
	 while (k < LONG_MAX)  //random number generation
	   {
	     int num = rand()%256;
	     unsigned char b = (unsigned char)num;
	     k = b|k;
	     k=k<<8;
	   }
	 myRBTree2.insert(k,j);
       }  
     time1 = clock.elapsed();
     cout<<setw(20)<<left <<time1<<setw(20)<<left<<myBinTree2.getSize();
     clock.restart();
     for (long long j = 0; j<batchSize;j++)
       {
	 long long k =0;
	  while (k<LONG_MAX)  
	   {
	     int num = rand()%256;
	     unsigned char b = (unsigned char)num;
	     k = b|k;
	     k=k<<8;
	   }
	 myBinTree2.insert(k,j);
       }  
     time2 = clock.elapsed();
     cout<<time2 <<endl;      
   }
}

   
