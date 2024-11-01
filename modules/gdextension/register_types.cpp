#include "register_types.h"
#include "core/error/error_macros.h"
#include "core/object/object.h"
#include "core/extension/gdextension_interface.h"

extern "C" GDExtensionBool riscv_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization);

	struct Extension {
		ObjectGDExtension gdextension;
	};
void initialize_gdextension_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_CORE) {
		return;
	}
	GDExtensionInitialization initialization;
	riscv_library_init(nullptr, nullptr, &initialization);
	ERR_PRINT("Loaded item: gdextension");
}

void uninitialize_gdextension_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_CORE) {
		return;
	}
}
