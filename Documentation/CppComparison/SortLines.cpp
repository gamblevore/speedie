//
//  main.cpp
//  SortLines comparison vs Speedie. 
//
//  Created by theodore on 07/12/2025.
//
#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <vector>
#include <chrono>
#include <cstdio>
#include <cerrno>
#include <sstream>

#define byte unsigned char
using std::string; using std::string_view; using std::ifstream; using std::ofstream; using std::vector;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;


std::string get_file_contents (const char* filename) {
	std::ifstream in(filename, std::ios::in | std::ios::binary);
	if (in) {
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

#if !USE_STRING_VIEW
string* NextField (string* Self, byte Sep, int& Begin) {
	int B = Begin;
	int N = (int)Self->length();
	if (B >= N)
		return NULL;
	int After = (int)Self->find(Sep, B);
	if (After < 0)
		After = N;
	string* Result = new string(Self->substr(B, After-B)); // not wonderful. But C++ limits us.
	Begin = After + 1;
	return Result;
}

vector<string*> Split (string* Self, byte sep = '\n') {
	vector<string*> Result;
	int Last = 0;
	while (true) {
		auto Word = NextField(Self, sep, Last);
		if (Word == NULL)
			break;
		Result.push_back(Word);
	}
	return Result;	
}

bool StringSorter (string* a, string* b) {
	return *a < *b;
}

void Sort (vector<string*> &R) {
    std::sort(R.begin(), R.end(), StringSorter);
}

void PrintLines (vector<string*> &R) {
	for (auto S : R) {
		int N = (int)S->length();
		const char* A = S->data();
		printf( "%.*s\n", N, A );
	}
}

#else
string_view* NextField (string* Self, byte Sep, int& Begin) {
	int B = Begin;
	int N = (int)Self->length();
	if (B >= N)
		return NULL;
	int After = (int)Self->find(Sep, B);
	if (After < 0)
		After = N;
	string_view* Result = new string_view(Self->data()+B, After-B); // better, but still unpleasant.
	Begin = After + 1;
	return Result;
}

vector<string_view*> Split (string* Self, byte sep = '\n') {
	vector<string_view*> Result;
	int Last = 0;
	while (true) {
		auto Word = NextField(Self, sep, Last);
		if (Word == NULL)
			break;
		Result.push_back(Word);
	}
	return Result;	
}

bool StringSorter (string_view* a, string_view* b) {
	return *a < *b;
}

void Sort (vector<string_view*> &R) {
    std::sort(R.begin(), R.end(), StringSorter);
}

void PrintLines (vector<string_view*> &R) {
	for (auto S : R) {
		int N = (int)S->length();
		const char* A = S->data();
		printf( "%.*s\n", N, A );
	}
}

#endif


void ReportTime (const char* Op, std::chrono::steady_clock::time_point Start, std::chrono::steady_clock::time_point Curr=high_resolution_clock::now()) {
    duration<double, std::milli> ms_double = Curr - Start;
    puts("\n**************\n");
    printf("%s took %fms\n", Op, ms_double.count());
}


int main (int argc, const char * argv[]) {
	std::cout << "Lets do some time-tests on sorting a file of lines, in C++\n";
	const char* Path = argv[1];
	if (!Path) {
		puts("Pass a file-path to sort the file");
		return 0;
	}
    high_resolution_clock::now(); // warmup
    
    auto T = high_resolution_clock::now();
	string Data = get_file_contents(Path);
	ReportTime("Read File", T);

    T = high_resolution_clock::now();
    {
		auto Lines = Split(&Data);
		ReportTime("Split Lines", T);

		T = high_resolution_clock::now();
		Sort(Lines);
		ReportTime("Sort Lines", T);

		T = high_resolution_clock::now();
		Sort(Lines);
		ReportTime("Second Sort", T); // sorting already-sorted data is actually very common.
		
		const char* Print = argv[2];
		if (Print and strcmp(Print, "-p")==0)
			PrintLines(Lines);	
		
		T = high_resolution_clock::now();
		for (auto S: Lines)
			delete S;
	}
	ReportTime("Cleanup", T);
	
	return 0;
}
