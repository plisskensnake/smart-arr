#include <stdarg.h>

class Set{
	unsigned size;
	unsigned* set;
public:
	unsigned operator[](const int i) const{
		return set[i];
	}
	int getSize()const{
		return size;
	}
	Set(unsigned c, ...){
		if(c==0)
			throw "Size Error";
		size=c;
		set=new unsigned[size];
		try{
			va_list args;
			va_start(args,c);
				for(unsigned a=0;a<size;++a){
					set[a]=va_arg(args,unsigned);
				}
			va_end(args);
				
		} catch(...) {
			delete[] set;
			throw "Param Error";
		}
	}

	~Set(){
		delete[] set;
	}
	
	int cmp(const Set& obj)const {
		if(this->getSize()!=obj.getSize())
			return this->getSize()-obj.getSize();
		else
		{
			for(int i=0;i<(this->getSize());i++) {
				int tmp0=this->operator[](i);
				int tmp1=obj[i];
				if(tmp0!=tmp1)
					return tmp0-tmp1;
			}
		}
		return 0;
	}
	int cmpEx(const Set& obj)const {
		if(this->getSize()!=obj.getSize())
			return -1;
		else
		{
			for(int i=0;i<(this->getSize());i++) {
				int tmp0=this->operator[](i);
				int tmp1=obj[i];
				if(tmp0!=tmp1)
					return tmp0-tmp1;
			}
		}
		return 0;
	}
};


template <typename T> 
class smartArray{
	unsigned lsize;
	Set* size;
	T* arr;
	public:
		smartArray(Set& s){
			lsize=1;
			size=&s;
			for(int i = 0; i < s.getSize(); i++)
				lsize *= s[i];
			arr =(T*)calloc(sizeof(T),lsize);
		}
		
		T& operator[] (const Set& obj) const{
			if ((size->cmpEx(obj))<0)
				throw "Param Error";
			int ind=0;
			for(int i=0;i<obj.getSize();i++) {
				int tmp=1;
				for(int j=0;j<i;j++) {
					tmp*=(*size)[j];
				}
				
				int tmp0=obj[i];
				ind+=tmp*tmp0;
			}
			return arr[ind];
		}
		
		~smartArray(){
			free(arr);
		}
};
