#include "SelfModule.h"
#include "TypeSelect.h"
#include "Modular.h"

/**
 * ���嵱ǰģ��
 */
static DefModule _Module("ModuleC"
	,""
	, []$(Constructor)(){
		printf("ModuleC::Constructor()\n");
	}
	, []$(Initializer)(){
		printf("ModuleC::Initializer()\n");
	}
	, []$(Uninitializer)(){
		printf("ModuleC::Uninitializer()\n");
	}
	, []$(Destructor)(){
		printf("ModuleC::Destructor()\n");
	});