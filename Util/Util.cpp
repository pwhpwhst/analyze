#include <vector>
#include<io.h>
#include<unordered_map>
#include<boost/algorithm/string.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../dao/TCompileFileDao.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include "Util.h"

Util::Util() {
	

}

Util::~Util() {
}

string Util::logFile = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\log\\log.txt";

void Util::listFiles(const string dir, vector<string>& files)
{
	string dirNew;
	dirNew = dir + "\\*.*";    // 在目录后面加上"\\*.*"进行第一次搜索

	intptr_t handle;
	_finddata_t findData;

	handle = _findfirst(dirNew.data(), &findData);
	if (handle == -1)        // 检查是否成功
		return;

	do
	{
		if (findData.attrib & _A_SUBDIR)
		{
			if (strcmp(findData.name, ".") == 0 || strcmp(findData.name, "..") == 0)
				continue;

			//cout << findData.name << "\t<dir>\n";

			// 在目录后面加上"\\"和搜索到的目录名进行下一次搜索
			dirNew = dir + "\\" + findData.name;

			listFiles(dirNew, files);
		}
		else {
			files.push_back(dir + "\\" + findData.name);
		}

	} while (_findnext(handle, &findData) == 0);

	_findclose(handle);    // 关闭搜索句柄
}

bool Util::endsWith(string s, string sub) {
	return s.rfind(sub) == (s.length() - sub.length());
}


void Util::getFileList(string base_path, string project) {
	//获取文件列表 begin
	vector<string> files;
	//	string base_path = "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat-main\\tomcat-main\\java";
		//getFiles(path, files);
	listFiles(base_path.data(), files);

	vector <string> behaves;
	ostringstream os;
	vector <unordered_map<string, string>> file_list;

	for (auto &e : files) {
		behaves.clear();
		boost::split(behaves, e, boost::is_any_of("\\"));
		if (endsWith(behaves.back(), ".java")) {
			file_list.push_back(unordered_map<string, string>());
			os.str("");
			if (behaves.size() > 1) {
				for (int i1 = 0; i1 < (behaves.size() - 1); i1++) {
					os << behaves[i1];
					if (i1 != (behaves.size() - 2)) {
						os << "\\\\";
					}
				}
			}
			file_list.back()["path"] = os.str();
			file_list.back()["fileName"] = behaves.back();
			file_list.back()["status"] = "0";
			file_list.back()["project"] = project;
		}
	}

	P_TCompileFileDao tCompileFileDao = TCompileFileDao::getInstance();
	tCompileFileDao->insertList(file_list);
	//获取文件列表 end
}
	


string Util::replaceAll(string str, string sub, string replacement) {
	int pos;
	pos = str.find(sub);
	while (pos != -1) {
		// str.length()求字符的长度，注意str必须是string类型
		str.replace(pos, string(sub).length(), replacement);
		pos = str.find(sub);
	}

	return str;
}


string Util::genUUID() {
	boost::uuids::uuid newId = boost::uuids::random_generator()();
	return Util::replaceAll(boost::uuids::to_string(newId), "-", "");
}

void Util::log(const string &s) {
	cout<< s << endl;

	if (logSwitch) {
		std::ofstream outfile;
		outfile.open(logFile, std::ios::app);
		outfile << s << std::endl;
		outfile.close();
	}
}

void Util::cleanLog() {
	if (logSwitch) {
		std::ofstream outfile;
		outfile.open(logFile);
		outfile << "" << std::endl;
		outfile.close();
	}
}
