#include "TableSortedList.h"
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;
#include "CD.h"
using CSC2110::CD;
#include "Text.h"
using CSC2110::String;

#include <iostream>
using namespace std;

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      delete cd;
   }
   delete iter;
}
void displayTable(TableSortedList<CD>* TSL)
{
	ListDoublyLinkedIterator<CD>* iter= TSL->iterator();
	while (iter->hasNext())
	{
		CD* cd=iter->next();
		cd->getKey()->displayString();
		cout<<endl;
	}
	delete iter;
}
int main()
{
   ListArray<CD>* cds = CD::readCDs("cds.txt");
   int num_items = cds->size();
   cout << num_items << endl;

   TableSortedList<CD>* slt = new TableSortedList<CD>(&CD::compare_items, &CD::compare_keys);

   //DO THIS
   //thoroughly test your table
   ListArrayIterator<CD>* cd_iter= cds->iterator();
   String* my_string;
   while(cd_iter->hasNext())
   {
	   CD* cd=cd_iter->next();
	   slt->tableInsert(cd);
   }
   delete cd_iter;
   displayTable(slt);
   
   cout<<slt->tableSize()<<endl;
   cin.get();
   
   cd_iter= cds->iterator();
   while(!slt->tableIsEmpty()&&cd_iter->hasNext())
   {
	   CD* cd=cd_iter->next();
	   slt->tableRemove(cd->getKey());
   }
   delete cd_iter;
   displayTable(slt);
   cin.get();
   for(int i=0;i<5;i++)
   {
		cd_iter= cds->iterator();
		while(cd_iter->hasNext())
		{
			CD* cd=cd_iter->next();
			slt->tableInsert(cd);
			my_string=cd->getKey();
		}
		delete cd_iter;
		displayTable(slt);
		cout<<slt->tableSize()<<endl;
		cin.get();
   }
   cout<<slt->tableRemove(my_string)<<endl;
   cout<<slt->tableRemove(my_string);
   cout<<slt->tableRemove(my_string);
   cout<<slt->tableRemove(my_string);
   cout<<slt->tableRemove(my_string);
   slt->tableRemove(my_string);

	

	






   deleteCDs(cds);
   delete cds;
   delete slt;
   return 0;
}
