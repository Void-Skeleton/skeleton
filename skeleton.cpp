#include<iostream>
#include<fstream>
#include<sstream>
#include<cassert>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<cctype>
using namespace std;
struct Var
{
	int var_type;
	union
	{		
		int int_var;
		double double_var;
		long double ldouble_var;
		long long_var;
		unsigned long ulong_var;
		long long llong_var;
		short short_var;
		bool boolean_var;
		char char_var;
		unsigned char uchar_var;
		unsigned int uint_var;
		unsigned long long ullong_var;
		float float_var;
	};
};
vector<Var> memory_pool;
map<string,int> type_to_int,name_to_id;
void define_var(stringstream &ss)
{
	string var_name;
	ss>>var_name;
	assert(!isdigit(var_name[0]));
	assert(!name_to_id.count(var_name));
	Var tmp;
	string var_type;
	ss>>var_type>>var_type;
	tmp.var_type=type_to_int[var_type];
	switch(tmp.var_type)
	{
		case 0: tmp.int_var=0;break;
		case 1: tmp.double_var=0;break;
		case 2: tmp.ldouble_var=0;break;
		case 3: tmp.long_var=0;break;
		case 4: tmp.ulong_var=0;break;
		case 5: tmp.llong_var=0;break;
		case 6: tmp.short_var=0;break;
		case 7: tmp.boolean_var=0;break;
		case 8: tmp.char_var=0;break;
		case 9: tmp.uchar_var=0;break;
		case 10:tmp.uint_var=0;break;
		case 11:tmp.ullong_var=0;break;
		case 12:tmp.float_var=0;break;
		default:assert(false);
	}
	memory_pool.push_back(tmp);
	name_to_id[var_name]=memory_pool.size()-1;
	char nex;
	ss>>nex;
	if(nex==',') define_var(ss);
	else if(nex==';') return;
	else assert(false);
}
int main(int argc,char *argv[])
{
	assert(argc==2);
	string code_name(argv[1]);
	type_to_int["int"]=0;type_to_int["double"]=1;type_to_int["ldouble"]=2;
	type_to_int["long"]=3;type_to_int["ulong"]=4;type_to_int["llong"]=5;
	type_to_int["short"]=6;type_to_int["boolean"]=7;type_to_int["char"]=8;
	type_to_int["uchar"]=9;type_to_int["uint"]=10;type_to_int["float"]=11;
	type_to_int["ullong"]=12;
	ifstream code(code_name);
	string line;
	while(getline(code,line,';'))
	{
		stringstream ss(line+';');
		string command;
		ss>>command;
		if(command=="var") define_var(ss);
	}
	return 0;
}
