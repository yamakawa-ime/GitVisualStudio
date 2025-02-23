
#include "Database.h"

PersistanceInterface* instance = nullptr;

PersistanceInterface* get_persistance_interface()
{
	static bool init = []() {
		if (!instance)
		{
			static Database db;
			instance = &db;
		}
		return true;
		}();
	return instance;
}
void set_persistance_interface(PersistanceInterface* persistance)
{
	instance = persistance;
}