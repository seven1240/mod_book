/* Book Example: Dialplan/App/API  Author: Seven Du */

#include <switch.h>

SWITCH_MODULE_LOAD_FUNCTION(mod_book_load);
SWITCH_MODULE_DEFINITION(mod_book, mod_book_load, NULL, NULL);


SWITCH_MODULE_LOAD_FUNCTION(mod_book_load)
{
	*module_interface = switch_loadable_module_create_module_interface(pool, modname);
	return SWITCH_STATUS_SUCCESS;
}
