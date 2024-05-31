#ifndef GUARD_Str
#define GUARD_Str

#include <algorithm>
#include <cctype>
#include <iterator>
class Str {
	//입력연산자
	friend std::istream& operator>>(std::istream&, Str&);
	friend std::istream& getline(std::istream&, Str&);
	//getline(); //과제
public:

	typedef size_t size_type;
	//비여있는 str 객체를 만드는 기본 생성자
	Str():value(0), length(0) { }
	//c에 복사본 n개가 있는 str 객체를 생성
	Str(size_type n, char c){
	//메모리 할당
		length = n;
		value = new char[length];
		//배열이 c char로 채우기
		for (size_type i = 0; i != length; ++i) {
			value[i] = c;
		}
	}

	//null로 끝나는 char 타입에 배열에서 str 객체를 생성
	Str(const char* cp) {
		//메모리 할당
		length = std::strlen(cp);
		value = new char[length];

		std::copy(cp, cp + length, value);
			
    }

	//다른 str에서 사본 만들기
	Str(const Str& s) {
		//메모리 할당
		length = s.length;
		value = new char[length];

		std::copy(s.value, s.value + s.length, value);
	}
	~Str() {
		if (value != 0)
			delete[] value;
	}



	//반복자 b와 e가 가리키는 범위에서 str 객체를 생성
	template<class input> Str(input b, input e) {
		//메모리 할당
		length = e - b;
		value = new char[length];

		std::copy(b, e, value);
	}
	//결합연산자
	Str& operator+=(const Str& s) {
		//메모리 할당
		size_type new_length = length + s.length;
		char* new_value = new char[new_length];
		std::copy(value, value + length, new_length);
		//메모리 헤체하기 위해 원래 value소멸
		if (value != 0)
			delete[] value;
		//새로운 value와 length 값을 저장
		std::copy(s.value, s.value + s.length, new_value + new_length);
		value = new_value;
		length = new_length;
			
		return *this;
	}
	Str& operator +=(const char c) {
		//메모리 항당
		size_type new_length = length + 1;
		char* new_value = new char[new_length];
		std::copy(value, value + length, new_length);
			
		if (value != 0)
				delete[] value;
		//새로운 value와 length 값을 저장
		//char추가 
		new_value[length] = c;
		value = new_value;
		length = new_length;

		return *this;
	
	}
	Str& operator +=(const char *c) {
		//메모리 항당
		size_type new_length = length + strlen(c);
		char* new_value = new char[new_length];
		std::copy(value, value + length, new_length);

		if (value != 0)
			delete[] value;
		//새로운 value와 length 값을 저장
		//char추가 
		std::copy(c, c + strlen(c), new_value + length);
		value = new_value;
		length = new_length;

		return *this;

	}
	//q11 (할당 연산자)
	Str& operator=(const Str& rhs) {
		//자기자신 할당
		if (&rhs != this) {
			if (value != 0)
				delete[] value;

			
			length = rhs.length;
			value = new char[length];
			std::copy(rhs.begin(), rhs.end(), value);
		}

	}
	//인덱스 연산자
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
std::ostream& operator<<(std::ostream&, const Str&); //추가
std::istream& getline(std::istream&, const Str&); //q8
Str operator+(const Str&, const Str&);
Str operator+(const Str&, const char*);  //Q5
Str operator+(const char*, const Str&); //Q11

//<,>,==,<=,!=비교 연산자 필요
bool operator<(const Str&, const Str&);  //q3
bool operator>(const Str&, const Str&);  //q3
bool operator<=(const Str&, const Str&);  //q3
bool operator>=(const Str&, const Str&);   //q3
bool operator==(const Str&, const Str&);   //q4
bool operator!=(const Str&, const Str&);   //q4


#endif