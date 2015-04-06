#include "SelfModule.h"
#include "TypeSelect.h"
#include "Modular.h"

/**
 * ���嵱ǰģ��
 */
static DefModule _Module("ModuleD"
#ifdef Mod_Config
	, "ModuleC;"
#else
	,""
#endif
	, []$(Constructor)(){
		printf("ModuleD::Constructor()\n");
	}
	, []$(Initializer)(){
		printf("ModuleD::Initializer()\n");
	}
	, []$(Uninitializer)(){
		printf("ModuleD::Uninitializer()\n");
	}
	, []$(Destructor)(){
		printf("ModuleD::Destructor()\n");
	});