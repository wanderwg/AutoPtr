//AutoPtr����ָ��
template<class T>
class AutoPtr
{
public:
	AutoPtr(T* ptr=NULL)
		:_ptr(ptr)
	{}
	~AutoPtr()
	{
		if (_ptr)
			delete _ptr;
	}

	//һ�������������ͽ�ap����Դת�Ƶ���ǰ�����У�Ȼ����ap������������Դ�Ͽ���ϵ
	//�����ͽ����һ��ռ䱻�������ʹ�ö���ɳ����������
	AutoPtr(AutoPtr<T>& ap)
		:_ptr(ap._ptr)
	{
		ap._ptr = NULL;
	}
	
	AutoPtr<T>& operator=(AutoPtr<T>& ap)
	{
		//����Ƿ�Ϊ�Լ����Լ���ֵ
		if (this != &ap)
		{
			//�ͷŵ�ǰ��������Դ
			if (_ptr)
				delete _ptr;
			 //ת��ap����Դ����ǰ������
			_ptr = ap._ptr;
			ap._ptr = NULL;
		}
		return *this;
	}

	T& operator*() { return *_ptr; }
	T* operator->() { return _ptr; }
private:
	T* _ptr;
};
int main()
{
	AutoPtr<Date> ap(new Date);
	//�����ٴ�ʵ��ԭ����������ᷢ�֣����������ap�����ָ�븳���ˣ�����ap��������
	//ͨ��ap���������Դʱ�ͻ��������
	AutoPtr<Date> copy(ap);
	ap->_year = 2000;

	return 0;
}