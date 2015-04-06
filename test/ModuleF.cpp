#include "SelfModule.h"
#include "TypeSelect.h"
#include "Modular.h"

/**
 * ���嵱ǰģ��
 */
static DefModule _Module("ModuleF"
#ifdef Mod_Config
	, "ModuleA;"
#else
	,""
#endif
	, []$(Initializer)(){
		printf("ModuleF::Initializer()\n");
	}
	, []$(Uninitializer)(){
		printf("ModuleF::Uninitializer()\n");
	});