#include "register_types.h"
#include "core/error/error_macros.h"
#include "core/object/object.h"
#include "core/extension/gdextension_interface.h"
#include "core/extension/gdextension_manager.h"
#include "./gdextension_static_library_loader.h"
#include "core/object/ref_counted.h"

extern "C" GDExtensionBool gdext_rust_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization);

void initialize_gdextension_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_CORE) {
		return;
	}
	ERR_PRINT("Loaded item: gdextension");

	Ref<GDExtensionStaticLibraryLoader> loader;
	loader.instantiate();
	loader->set_entry_funcptr((void*)(&gdext_rust_init));
	GDExtensionManager::get_singleton()->load_extension_with_loader("rapier", loader);
}

void uninitialize_gdextension_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_CORE) {
		return;
	}
}
