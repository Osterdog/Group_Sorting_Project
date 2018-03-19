#ifndef __GENERALARRAYWITHREF_H_
#define __GENERALARRAYWITHREF_H_


#include "generalArray.h"


/////////// FV TEST ////////////////
class general_array_with_ref : public general_array{
protected:
	basic_item * reference_item;
	
	// when true it means the array holds items that have been allocated somewhere else
	bool container_only;
	

	// allocate item on heap for the specific type (calling the porper constructor)
	virtual basic_item* allocateSpecificItem()
	{
		if( (reference_item!=NULL) && (container_only==false) )
		{
			return reference_item->allocateNewItem();
		}
		else
			return NULL;
	}

	// remove item from heap for the specific type  (calling the porper distructor)
	virtual void deallocateSpecificItem(basic_item* item)
	{
		if( (reference_item!=NULL) && (container_only==false) )
		{
			reference_item->deleteOtherItem(item);
		}
	}

	//bool insertElementPtr(int index, basic_item* item_ptr)

	void set_defaults(){reference_item=NULL; container_only=false;}
public:
	general_array_with_ref(){set_defaults();}	
	general_array_with_ref(basic_item * ref_item, bool inp_container_only=false){set_defaults(); set_ref(ref_item); set_container_only(inp_container_only);}
	void set_container_only(bool inp_container_only)
	{
		// only allowed to set when the size of the array is (still) zero
		if(max_arraysize==0)
			container_only=inp_container_only;
	}
	
	void set_ref(basic_item * ref_item)
	{
		// only allowed to set once
		if(ref_item!=NULL && reference_item==NULL)
			reference_item=ref_item;
	}
	
	//basic_item * getRefItemCopy();

	// overload to avoid 
	virtual bool allocateArray(int in_arraysize)
	{
		if( (!memIsAllocated()) && (in_arraysize>0) )
		{
			// in case items do not have to be alloced 
			// i.e. existugng items will be added to the array
			if(container_only)
			{
				// calloc guarantees the pointer are set to NULL
				thearray=(basic_item **)calloc(in_arraysize, sizeof(basic_item *) );
				if(thearray!=NULL)
				{
					max_arraysize=in_arraysize;
					memallocated=true;
					return true;
				}
				else 
					return false;
			}
			else
				return (general_array::allocateArray(in_arraysize) );
		}
		else
			return false;
	}
};
////////////////////////////////////





#endif