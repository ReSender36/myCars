// #include <SourceBook>
#include "DM2_Unit.h"

class SourceBook{
	public:
		String DB_NAME ;
		String TABLE_NAME ;
		short id ;
		String name ;
		int rating ;

		void addNew(String Name) ;
		int calcRating(int id){
			id = id + 53 ;
			return id ;
		}
		String findUnitById(String Name) ;
		int findUnitByName(int id) ;

} ;

void SourceBook::addNew(String Name){
//	DB2.adoQ_FirstReq->
}
