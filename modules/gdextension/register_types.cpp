#include "register_types.h"
#include "core/error/error_macros.h"
#include "core/object/object.h"
#include "core/extension/gdextension_interface.h"
#include "core/extension/gdextension_manager.h"
#include "./gdextension_static_library_loader.h"
#include "core/object/ref_counted.h"

extern "C" {
    GDExtensionBool riscv_library_init(
        GDExtensionInterfaceGetProcAddress p_get_proc_address,
        GDExtensionClassLibraryPtr p_library,
        GDExtensionInitialization *r_initialization
    );
    void riscv_test();
    //GDExtensionBool gdext_rust_init(
    //    GDExtensionInterfaceGetProcAddress p_get_proc_address,
    //    GDExtensionClassLibraryPtr p_library,
    //    GDExtensionInitialization *r_initialization
    //);
}


void initialize_gdextension_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_EDITOR) {
		return;
	}

	Ref<GDExtensionStaticLibraryLoader> loader;
	loader.instantiate();
	ERR_PRINT("1");
	//riscv_test();
	ERR_PRINT("2");
	loader->set_entry_funcptr((void*)&riscv_library_init);
	GDExtensionManager::get_singleton()->load_extension_with_loader("sandbox", loader);
}

void uninitialize_gdextension_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_CORE) {
		return;
	}
}
