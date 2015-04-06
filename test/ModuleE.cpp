#include "SelfModule.h"
#include "TypeSelect.h"
#include "Modular.h"

/**
 * ���嵱ǰģ��
 */
static DefModule _Module("ModuleE"
#ifdef Mod_Config
	, "ModuleF;"
#else
	,""
#endif
	, []$(Initializer)(){
		printf("ModuleE::Initializer()\n");
	}
	, []$(Uninitializer)(){
		printf("ModuleE::Uninitializer()\n");
	});