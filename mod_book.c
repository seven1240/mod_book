/* Book Example: Dialplan/App/API  Author: Seven Du */

#include <switch.h>

SWITCH_MODULE_LOAD_FUNCTION(mod_book_load);
SWITCH_MODULE_DEFINITION(mod_book, mod_book_load, NULL, NULL);

SWITCH_STANDARD_DIALPLAN(book_dialplan_hunt)
{
	switch_caller_extension_t *extension = NULL;
	switch_channel_t *channel = switch_core_session_get_channel(session);

	if (!caller_profile) {
		caller_profile = switch_channel_get_caller_profile(channel);
	}

	switch_log_printf(SWITCH_CHANNEL_SESSION_LOG(session), SWITCH_LOG_INFO,
		"Processing %s <%s>->%s in context %s\n",
		caller_profile->caller_id_name, caller_profile->caller_id_number,
		caller_profile->destination_number, caller_profile->context);

	if ((extension = switch_caller_extension_new(session, "book", "book")) == 0) {
		abort();
	}

	switch_caller_extension_add_application(session, extension, "log",
		"INFO Hey, I'm in the book");

	return extension;
}

SWITCH_MODULE_LOAD_FUNCTION(mod_book_load)
{
	switch_dialplan_interface_t *dp_interface;

	*module_interface = switch_loadable_module_create_module_interface(pool, modname);

	SWITCH_ADD_DIALPLAN(dp_interface, "book", book_dialplan_hunt);

	return SWITCH_STATUS_SUCCESS;
}
