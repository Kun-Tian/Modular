#include "SelfModule.h"

int main(int argc, char* argv[])
{
	printf("\n");

	SelfModuleList::GetInstance()->Inits();

	printf("\n");

	// ������ǲ�ָ��ģ��������˳����ô
	// ��ʼ��˳��Ҳ����CDAEFB��Ҳ����������

	// �������һЩ��ʼ��˳����E<F<A=B<D<C��
	// ��ô������������!��Mod_Config��

	SelfModuleList::GetInstance()->Uninits();

	printf("\n");

	return 0;
}

