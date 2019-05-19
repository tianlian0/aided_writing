#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

map<string, map<string, int> > tf;
map<string, string> result_map;
string str;

string readFileIntoString(const char* filename)
{
	ifstream ifile(filename);
	ostringstream buf;
	char ch;
	while (buf && ifile.get(ch))
		buf.put(ch);
	return buf.str();
}

int cmp(const pair<string, int>& x, const pair<string, int>& y)
{
	return x.second > y.second;
}

void sortMapByValue(map<string, int>& tMap, vector<pair<string, int> >& tVector)
{
	for (map<string, int>::iterator curr = tMap.begin(); curr != tMap.end(); curr++)
		tVector.push_back(make_pair(curr->first, curr->second));

	sort(tVector.begin(), tVector.end(), cmp);
}

void init_map(string path) {
	str = readFileIntoString(path.c_str());
	int len = str.size();
	for (int i = 0; i <= len - 22; i+=2)
	{
		string cutstr_8(str.substr(i + 8, 14));
		string cutstr_4(str.substr(i, 8));
		tf[cutstr_4][cutstr_8]++;
	}
}

void convert_map() {
	map<string, map<string, int> >::iterator it1;
	for (it1 = tf.begin(); it1 != tf.end(); it1++)
	{
		vector<pair<string,int> > temp_v;
		sortMapByValue((it1->second), temp_v);
		string temp = "";
		for (size_t i = 0; i < min((int)temp_v.size(),8); i++)
		{
			if (i == 0)
			{
				temp.append(temp_v[i].first);
			}
			else
			{
				temp.append("#" + temp_v[i].first);
			}
		}
		result_map[it1->first] = temp;
	}
}

int main()
{
	//输入和输出文件的路径
	string src_data_path = "src_data.txt";
	string res_map_path = "res_map.txt";

	cout << "开始初始化" << endl;
	init_map(src_data_path);
	cout << "初始化完毕，进行map转换" << endl;
	convert_map();
	str = "";
	tf.clear();
	cout << "map转换完毕，进行文件写入" << endl;
	ofstream in;
	in.open(res_map_path, ios::trunc);
	int ii = 0;
	map<string, string>::iterator it3;
	for (it3 = result_map.begin(); it3 != result_map.end(); it3++)
	{
		if ((it3->first).length() > 0 && !(it3->first).empty() && (it3->second).length() > 0 && !(it3->second).empty())
		{
			in << it3->first << endl << it3->second << endl;
		}
	}
	in.close();
	cout << "文件写入完毕" << endl << "下面可以再控制台中进行测试：" << endl;
	string s;
	while (getline(cin, s)) {
		cout << result_map[s] << endl;
	}
	return 0;
}
