#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

#define FILE_PATH "/home/debian"

int main(int argc, char * argv[])
{
	fstream fs;
	if(argc!=3){
		cout << endl;
		cout << "Usage is: ./copying-file destination1 destination2" << endl;
		return 3;
	}

	string cmd1(argv[1]);
	string cmd2(argv[2]);
	cout << endl;
	cout << "Staring the copying process" << endl;

	fstream fs1;
	fstream fs2;

	string path(FILE_PATH);
	fs1.open((path + "/" + cmd1).c_str(), std::fstream::in);

	string path2(FILE_PATH);
	fs2.open((path2 + "/" + cmd2).c_str(), std::fstream::out);

	string hold;
	while(getline(fs1, hold)){
		fs2 << hold;
	}

	fs1.close();
	fs2.close();
}

