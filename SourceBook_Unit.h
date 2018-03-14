//---------------------------------------------------------------------------

#ifndef SourceBook_UnitH
#define SourceBook_UnitH
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
class SourceBook{
//	protected:
public:
		char *DB_NAME ;
		const char *TABLE_NAME ;
		short id ;
		char *name ;
		int rating ;
//	public:
		SourceBook() ;
		SourceBook(const char *Table) ;
		SourceBook(const char *Table, const char *Name) ;
		char BASE_REQUEST ;
		void addNew(const char *Name) ;
		void addNew(SourceBook *sb) ;
		void updateRating(int id) ;
		const char findUnitById(int id) ;
		int findUnitByName(const char *Name) ;

} ;
#endif
