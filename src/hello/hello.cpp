#include <hello.h>
#include <iostream>
#ifdef DO_NOT_PRINT_HELLO
static std::string output_string = "Not Hello ";
#else
static std::string output_string = "Hello ";
#endif

using namespace std;

void print_Hello(const std::string& user_input){
	cout<<output_string<<user_input<<endl;
}
