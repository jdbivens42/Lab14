#if !defined (TABLESORTEDLIST_H)
#define TABLESORTEDLIST_H

#include "SortedListDoublyLinked.h"

template < class T >
class TableSortedList
{

   private:
      SortedListDoublyLinked<T>* sldl;

   public:
      TableSortedList(int (*comp_item) (T* item_1, T* item_2), int (*comp_key) (String* key, T* item));
      ~TableSortedList();

      bool tableIsEmpty();
      int tableSize();
      T* tableRetrieve(String* sk);
      void tableInsert(T* item);  //does not allow duplicate search keys into the table (need to use getKey() to check for duplicates)
      bool tableRemove(String* search_key);  //returns true if delete is successful (need to call tableRetrieve to see if the item is there)

      ListDoublyLinkedIterator<T>* iterator();

};

//DO THIS
//complete the implementation for TableSortedList
template < class T >
TableSortedList<T>::TableSortedList(int (*comp_item) (T* item_1, T* item_2), int (*comp_key) (String* key, T* item))
{
	SortedListDoublyLinked<T>* list=new SortedListDoublyLinked<T>(comp_item,comp_key);
	sldl=list;
}

template < class T >
TableSortedList<T>::~TableSortedList()
{
	delete sldl;
}

template < class T >
bool TableSortedList<T>::tableIsEmpty()
{
	return sldl->isEmpty();
}

template < class T >
int TableSortedList<T>::tableSize()
{
	return sldl->size();
}

template < class T >
T* TableSortedList<T>::tableRetrieve(String* sk)
{
	return sldl->get(sk);
}

template < class T >
void TableSortedList<T>::tableInsert(T* item)  //does not allow duplicate search keys into the table (need to use getKey() to check for duplicates)
{
	if (sldl->get(item->getKey()))
		return;
	else
		sldl->add(item);
}

template < class T >
bool TableSortedList<T>::tableRemove(String* search_key) //returns true if delete is successful (need to call tableRetrieve to see if the item is there)
{
	if (sldl->get(search_key))
	{
		sldl->remove(search_key);
		return true;
	}
	else
	{
		return false;
	}
}

template < class T >
ListDoublyLinkedIterator<T>* TableSortedList<T>::iterator()
{
	return sldl->iterator();
}

#endif
