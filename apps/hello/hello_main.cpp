#include <hello.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
    if(argc == 1){
	cout<<"Only one argument ... error !! Please input a string as argument of the program"<<endl;
	return 1;
    }
    print_Hello(argv[1]);
    return 0;
}
