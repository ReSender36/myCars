//---------------------------------------------------------------------------

#ifndef AutomobileH
#define AutomobileH
//---------------------------------------------------------------------------
//#include <Classes.hpp>
#include "SourceBook_Unit.h"
//---------------------------------------------------------------------------
class Automobile : public SourceBook
{
	const char *DB_NAME ;

	public:
		int currOdometer ;
		Automobile() ;//:SourceBook(const char *Table){}
		Automobile(const char *Table);

};
//		void calcOdometer() ;
//} ;
#endif
