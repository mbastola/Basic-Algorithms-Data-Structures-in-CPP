#include "listTiming.h" 
#include <iostream>
#include <fstream>
#include <boost/timer.hpp> 
#include <cstdlib>
#include <stdio.h>
#include <ctime>
using namespace std;
using namespace boost;

void timeAppends(List<int>* list, int numBatches, int numPerBatch, ofstream& fout)
{
   timer clock;
   srand(time(0));
   for(int i = 0;i<numBatches;i++)
   {
      fout<< list->getSize();
      clock.restart();
      for (int j=0; j<numPerBatch;j++)
      {
	 list->pushBack(j);
      }
      fout<< ' ' << clock.elapsed()<<endl;
   }
}
   
void timePrepends(List<int>* list, int numBatches, int numPerBatch, ofstream& fout)
{
   timer clock;
   srand(time(0));
   for(int i = 0;i<numBatches;i++)
   {
      fout<< list->getSize();
      clock.restart();
      for (int j = 0; j<numPerBatch;j++)
      {
	 list->pushFront(j);
      }
      fout<< ' ' << clock.elapsed()<<endl;
   }
}

void timeInserts(List<int>* list, int numBatches, int numPerBatch, ofstream& fout)
{
   timer clock;
   srand(time(0));
   for(int i = 0;i<numBatches;i++)
   {
      fout<< list->getSize();
      clock.restart();
      for (int j = 0; j<numPerBatch;j++)
      {
	 list->insert(list->getSize()/2,j);
      }
      fout<< ' ' << clock.elapsed()<<endl;
   }
}

void timeAccesses(List<int>* list, int numBatches, int numPerBatch, ofstream& fout)
{
   timer clock;
   srand(time(0));
   for(int i = 0;i<numBatches;i++)
   {
      fout<< list->getSize();
      for ( int j = 0;j<numPerBatch;j++)
      {
	 list->insert(list->getSize()/2,j);
      }
      int size =list->getSize();
      clock.restart();
      for ( int j = 0;j<numPerBatch;j++)
      {
	 list->getItem(rand()%size);
      }
      fout<< ' ' << clock.elapsed()<<endl;;
   }
}
