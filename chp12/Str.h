#ifndef GUARD_Str
#define GUARD_Str

#include <algorithm>
#include <cctype>
#include <iterator>
class Str {
	//�Է¿�����
	friend std::istream& operator>>(std::istream&, Str&);
	friend std::istream& getline(std::istream&, Str&);
	//getline(); //����
public:

	typedef size_t size_type;
	//���ִ� str ��ü�� ����� �⺻ ������
	Str():value(0), length(0) { }
	//c�� ���纻 n���� �ִ� str ��ü�� ����
	Str(size_type n, char c){
	//�޸� �Ҵ�
		length = n;
		value = new char[length];
		//�迭�� c char�� ä���
		for (size_type i = 0; i != length; ++i) {
			value[i] = c;
		}
	}

	//null�� ������ char Ÿ�Կ� �迭���� str ��ü�� ����
	Str(const char* cp) {
		//�޸� �Ҵ�
		length = std::strlen(cp);
		value = new char[length];

		std::copy(cp, cp + length, value);
			
    }

	//�ٸ� str���� �纻 �����
	Str(const Str& s) {
		//�޸� �Ҵ�
		length = s.length;
		value = new char[length];

		std::copy(s.value, s.value + s.length, value);
	}
	~Str() {
		if (value != 0)
			delete[] value;
	}



	//�ݺ��� b�� e�� ����Ű�� �������� str ��ü�� ����
	template<class input> Str(input b, input e) {
		//�޸� �Ҵ�
		length = e - b;
		value = new char[length];

		std::copy(b, e, value);
	}
	//���տ�����
	Str& operator+=(const Str& s) {
		//�޸� �Ҵ�
		size_type new_length = length + s.length;
		char* new_value = new char[new_length];
		std::copy(value, value + length, new_length);
		//�޸� ��ü�ϱ� ���� ���� value�Ҹ�
		if (value != 0)
			delete[] value;
		//���ο� value�� length ���� ����
		std::copy(s.value, s.value + s.length, new_value + new_length);
		value = new_value;
		length = new_length;
			
		return *this;
	}
	Str& operator +=(const char c) {
		//�޸� �״�
		size_type new_length = length + 1;
		char* new_value = new char[new_length];
		std::copy(value, value + length, new_length);
			
		if (value != 0)
				delete[] value;
		//���ο� value�� length ���� ����
		//char�߰� 
		new_value[length] = c;
		value = new_value;
		length = new_length;

		return *this;
	
	}
	Str& operator +=(const char *c) {
		//�޸� �״�
		size_type new_length = length + strlen(c);
		char* new_value = new char[new_length];
		std::copy(value, value + length, new_length);

		if (value != 0)
			delete[] value;
		//���ο� value�� length ���� ����
		//char�߰� 
		std::copy(c, c + strlen(c), new_value + length);
		value = new_value;
		length = new_length;

		return *this;

	}
	//q11 (�Ҵ� ������)
	Str& operator=(const Str& rhs) {
		//�ڱ��ڽ� �Ҵ�
		if (&rhs != this) {
			if (value != 0)
				delete[] value;

			
			length = rhs.length;
			value = new char[length];
			std::copy(rhs.begin(), rhs.end(), value);
		}

	}
	//�ε��� ������
	char& operator[](size_type i) {
		return value[i];
	}
	const char& operator[](size_type i) const{ 
		return value[i];
	}
	
	typedef char* iterator;
	typedef const char* const_iterator;
	//begin()
	iterator begin() { return value; }
	const_iterator begin()const { return value; }

	//end()
	iterator end() { return value +length; }
	const_iterator end()const { return value + length;}

	size_type size() const { return length; }


	//q2
	const char* c_str() const { return value + '\0'; }
	const char* data() const { return value; }
	void copy(char* p, size_type n) {
		std::copy(value, value + n, p);
	}
private:
	char* value;
	size_type length;
};
std::ostream& operator<<(std::ostream&, const Str&); //�߰�
std::istream& getline(std::istream&, const Str&); //q8
Str operator+(const Str&, const Str&);
Str operator+(const Str&, const char*);  //Q5
Str operator+(const char*, const Str&); //Q11

//<,>,==,<=,!=�� ������ �ʿ�
bool operator<(const Str&, const Str&);  //q3
bool operator>(const Str&, const Str&);  //q3
bool operator<=(const Str&, const Str&);  //q3
bool operator>=(const Str&, const Str&);   //q3
bool operator==(const Str&, const Str&);   //q4
bool operator!=(const Str&, const Str&);   //q4


#endif