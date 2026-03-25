#include <iostream>
#include <string.h>

class Mystring{
    char* string_content;   //문자열 데이터를 가리키는 포인터
    int string_length;      //문자열 길이
    int memory_capacity;    //현재 할당된 용량

    public:

    Mystring(char c);               //문자 하나 생성
    Mystring(const char* str);      //문자열 생성
    Mystring(const Mystring& str);  //복사 생성자

    ~Mystring();                    //소멸자

    int length() const;             //문자열의 길이를 리턴하는 함수
    int capacity() const;           //현재 할당된 크기를 알아오는 함수
    void reserve(int size);         //문자열 메모리 할당 함수
    void print() const;             //문자열 출력 함수
    void println() const;           

    Mystring& assign(const Mystring& str);
    Mystring assign(const char* str);

    char at(int i) const;                           //특정 위치 문자열 반환

    Mystring& insert(int loc, Mystring& str);       //문자열 삽입
    Mystring& insert(int loc, const char* str);
    Mystring& insert(int loc, char c);
};


//문자 1개를 입력하였을 때의 생성자
Mystring::Mystring(char c){
    string_content = new char[1];
    string_content[0] = c;
    memory_capacity = 1;
    string_length = 1;

}

//문자열을 입력하였을 때의 생성자
Mystring::Mystring(const char* str){
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];

    for(int i =0 ; i!=string_length ; i++){
        string_content[i] = str[i];
    }
}

Mystring::Mystring(const Mystring& str){
    string_length = str.string_length;
    memory_capacity = str.string_length;
    string_content = new char[string_length];

    for(int i =0 ; i!=string_length ; i++){
        string_content[i] = str.string_content[i];
    }
}

Mystring::~Mystring(){delete string_content;}
int Mystring :: length()const {return string_length;}

void Mystring::print() const{
    for(int i=0 ; i<string_length ; i++){
        std :: cout << string_content;  
    }
}

void Mystring::println() const{
    for(int i=0 ; i!=string_length ; i++){
        std::cout<<string_content[i];
    }
    std::cout<<std::endl;
}

Mystring& Mystring::assign(const Mystring& str){
    if (str.string_length>memory_capacity){
        delete[] string_content;

        string_content = new char[str.string_length];;
        memory_capacity = str.string_length;
    }
    for(int i=0 ; i<str.string_length ; i++){
        string_content[i] = str.string_content[i]; 
    }
    string_length = str.string_length;
    return *this;
}

Mystring Mystring::assign(const char *str)
{
    int str_length = strlen(str);
    if(str_length > memory_capacity){
        delete[] string_content;

        string_content = new char[str_length];
        memory_capacity = str_length;
    }
    for(int i=0 ; i != str_length; i++){
        string_content[i] = str[i];
    }
    string_length = str_length;

    return *this;
}

int Mystring::capacity() const {return memory_capacity;}

void Mystring::reserve(int size){
    if(size>memory_capacity){
        char * prev_string_content = string_content;

        string_content =new char[size];
        memory_capacity = size;

        for(int i=0 ; i !=string_length ; i++)
            string_content[i] = prev_string_content[i];
        delete[] prev_string_content;
    }
}

char Mystring:: at(int i) const{
    if (i>=string_length || i<0)
        return 0;
    else
        return string_content[i];
}

Mystring &Mystring::insert(int loc, Mystring &str)
{
    //이는 i의 위치 바로 앞에 문자를 삽입하게 된다.
    //abc라는 문자열에 insert(1,"d")를 입력하게 된다면 adbc가 된다.

    //범위를 벗어나는 입력에 대해서 삽입을 수행하지 않는다.
    if(loc<0 || loc>string_length){
        return *this;
    }

    // 새롭게 동적 할당
    if(string_length + str.string_length > memory_capacity){
        memory_capacity = string_length + str.string_length;
        char* prev_string_content = string_content;
        string_content = new char[memory_capacity];
    

    //insert 되는 부분 전까지의 내용을 복사한다.
    int i;
    for(i=0 ; i<loc ; i++){
        string_content[i] = prev_string_content[i];
    }

    //그리고 새롭게 insert 되는 문자열을 넣는다.
    for(int j =0 ; j != str.string_length ; j++){
        string_content[i+j] = str.string_content[j];
    }

    //다시 원 문자열의 나머지 뒷 부분을 복사한다.
    for(;i<string_length;i++){
        string_content[str.string_length+i] = prev_string_content[i];
    }
    delete[] prev_string_content;

    string_length = string_length + str. string_length;
    return *this;
    }
    
    //뒤로 밀기 이때 원래의 문자열 데이터가 사라지지 않게 함.
    for(int i = string_length - 1 ; i >=loc ; i--){
        string_content[i + str.string_length] = string_content[i];
    }

    for(int i =0 ; i<str.string_length; i++){
        string_content[i+loc] = str.string_content[i];
    }
    string_length = string_length + str.string_length;
    return *this;
}

Mystring &Mystring::insert(int loc, const char *str)
{
    Mystring temp(str);
    return insert(loc, temp);
}

Mystring& Mystring::insert(int loc, char c){
    Mystring temp(c);
    return insert(loc, temp);
}

int main(){
    Mystring str1("very long string");
    Mystring str2("<some string inserted between>");

    std::cout <<"Capacity : "<<str1.capacity()<<std::endl;
    std::cout<<"String length : "<<str1.length() <<std::endl;
    str1.println();

    str1.insert(5, str2);
    str1.println();
}

