#include "SelfModule.h"
#include "TypeSelect.h"
#include "Modular.h"

/**
 * ���嵱ǰģ��
 */
static DefModule _Module("ModuleA"
	,""
	, []$(Initializer)(){
		printf("ModuleA::Initializer()\n");
	}
	, []$(Uninitializer)(){
		printf("ModuleA::Uninitializer()\n");
	});