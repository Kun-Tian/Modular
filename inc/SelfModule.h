#ifndef Self_Module_H
#define Self_Module_H

#include <vector>
#include <string>
#include <functional>
using namespace std;

/**
 * �����׼�ַ�����
 */
#ifndef STD_STRING_TYPE
#define STD_STRING_TYPE
typedef std::string StdString;
#endif

/**
 * �����ʼ��������ʼ����������
 */
#ifndef SELF_FUCTION_TYPE
#define SELF_FUCTION_TYPE
typedef function<void()> SelfFunction;
#endif

/**
 * ����ģ������
 */
struct SelfModule
{
	/**
	 * ģ���ID
	 */
	StdString _id;

	/**
	 * ģ�����������ͬ��������֮����';'�ָ�
	 */
	StdString _dep;

	/**
	 * ��ʼ������
	 */
	SelfFunction _init;

	/**
	 * ����ʼ������
	 */
	SelfFunction _uninit;

	/**
	 * ���캯��
	 */
	SelfModule(StdString id)
		: _id(id)
	{}
};

/**
 * ����ģ��Ķ���
 */
class DefModule
{
public:

	/*
	 * ���캯��
	 * 
	 * @Param id
	 *        ģ���ID
	 * @Param depends
	 *        ģ�������
	 * @Param constructor
	 *        ģ��Ĺ��캯��
	 * @Param initializer
	 *        ģ��ĳ�ʼ������
	 * @Param uninitializer
	 *        ģ��ķ���ʼ������
	 * @Param destructor
	 *        ģ�����������
	 */
	DefModule(StdString id
		, StdString depends
		, SelfFunction constructor
		, SelfFunction initializer
		, SelfFunction uninitializer
		, SelfFunction destructor);

	/*
	 * ���캯��
	 * 
	 * @Param id
	 *        ģ���ID
	 * @Param depends
	 *        ģ�������
	 * @Param initializer
	 *        ģ��ĳ�ʼ������
	 * @Param uninitializer
	 *        ģ��ķ���ʼ������
	 */
	DefModule(StdString id
		, StdString depends
		, SelfFunction initializer
		, SelfFunction uninitializer);

	/**
	 * ��������
	 */
	~DefModule();

protected:
	/**
	 * ��������
	 */
	SelfFunction _destructor;
};

/**
 * �б���������
 */
typedef vector<SelfModule>::iterator ModuleWhere;

/**
 * ģ���б�
 */
class SelfModuleList
{
public:

	/**
	 * ��ȡΨһʵ��
	 * 
	 * @Return ����ȫ��Ψһ��ʵ��
	 */
	static SelfModuleList* GetInstance()
	{
		if (_instance != NULL)
		{
			return _instance;
		}

		if (_instance == NULL)
		{
			_instance = new SelfModuleList();
		}

		return _instance;
	}

	/**
	 * ɾ��Ψһʵ��
	 */
	static void DelInstance()
	{
		if (_instance != NULL)
		{
			delete _instance;
			_instance = NULL;
		}
	}

public:

	/**
	 * ��ʼ������
	 */
	void Inits()
	{
		for (auto iter = _list.begin(); iter != _list.end(); iter++)
		{
			(*iter)._init();
		}
	}

	/**
	 * ����ʼ������
	 */
	void Uninits()
	{
		for (auto iter = _list.rbegin(); iter != _list.rend(); iter++)
		{
			(*iter)._uninit();
		}
	}

	/**
	 * ����ģ��
	 * 
	 * @Param id
	 *        �����ҵ�ģ���ID
	 * @Return ���ز��ҵ���ģ��λ��
	 */
	ModuleWhere Find(StdString id)
	{
		ModuleWhere iter = _list.begin();

		for (; iter != _list.end(); iter++)
		{
			if ((*iter)._id.compare(id) == 0)
			{
				break;
			}
		}

		return iter;
	}

	/**
	 * ����ģ�鵽ָ��λ��
	 * 
	 * @Param where
	 *        ����λ��
	 * @Param module
	 *        ģ�����
	 * @return ���ز���λ��
	 */
	ModuleWhere Insert(ModuleWhere where, SelfModule module)
	{
		return _list.insert(where, module);
	}

	/*
	 * ��ȡģ���б�ʼλ��
	 * 
	 * @return �����б�ʼλ��
	 */
	ModuleWhere Begin()
	{
		return _list.begin();
	}

	/**
	 * ģ��λ���Ƿ�Ϊ�б�β��
	 * 
	 * @Param where
	 *        ����λ��
	 * @return ������б�β�˷���true�����򷵻�false��
	 */
	bool End(ModuleWhere where)
	{
		return where == _list.end();
	}

protected:
	/**
	 * ģ���б�
	 */
	vector<SelfModule> _list;

protected:
	SelfModuleList(void) {}
	~SelfModuleList(void) {}

private:
	/**
	 * ȫ��Ψһ��ʵ��
	 */
	static SelfModuleList* _instance;
};

#endif /* Self_Module_H */