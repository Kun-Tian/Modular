#include "SelfModule.h"
#include "TypeSelect.h"
#include "Modular.h"

/**
 * ���嵱ǰģ��
 */
static DefModule _Module("ModuleB"
#ifdef Mod_Config
	, "ModuleD;"
#else
	,""
#endif
	, []$(Constructor)(){
		printf("ModuleB::Constructor()\n");
	}
	, []$(Initializer)(){
		printf("ModuleB::Initializer()\n");
	}
	, []$(Uninitializer)(){
		printf("ModuleB::Uninitializer()\n");
	}
	, []$(Destructor)(){
		printf("ModuleB::Destructor()\n");
	});