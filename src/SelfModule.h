#ifndef Self_Module_H
#define Self_Module_H

#include <vector>
#include <string>
#include <functional>
using namespace std;

#ifndef _UNICODE
typedef std::string StdString;
#else
typedef std::wstring StdString;
#endif

/**
 * �����ʼ��������ʼ����������
 */
typedef function<void()> SelfFunction;

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
	StdString _depends;

	/**
	 * ��ʼ��֮ǰ�Ĳ���
	 */
	SelfFunction _preinit;

	/**
	 * ��ʼ������
	 */
	SelfFunction _init;

	/**
	 * ����ʼ������
	 */
	SelfFunction _uninit;
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
	 * @Param preinit
	 *        ��ʼ��֮ǰ�Ĳ���
	 * @Param init
	 *        ģ��ĳ�ʼ������
	 * @Param uninit
	 *        ģ��ķ���ʼ������
	 * @Param destructor
	 *        ģ�����������
	 */
	DefModule(StdString id
		, StdString depends
		, SelfFunction preinit
		, SelfFunction init
		, SelfFunction uninit
		, SelfFunction destructor);

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
	 * ��ʼ��֮ǰ�Ĳ���
	 */
	void PreInits()
	{
		for (auto iter = _list.begin(); iter != _list.end(); iter++)
		{
			(*iter)._preinit();
		}
	}

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
	 * @Param mod
	 *        ģ��
	 */
	void AddModule(SelfModule mod)
	{
		_list.push_back(mod);
	}

	/**
	 * ����ģ��
	 * 
	 * @Param id
	 *        �����ҵ�ģ���ID
	 * @Return ���ز��ҵ���ģ��
	 */
	SelfModule& FindModule(StdString id);

	/**
	 * ģ��Ŀ�����
	 */
	static SelfModule _NullModule;

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