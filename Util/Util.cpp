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

string Util::logFile = "C:\\Users\\Administrator\\Desktop\\����������-��\\��Ͳд����\\kaleidoscope-writing-wheel-eye\\log\\log.txt";

void Util::listFiles(const string dir, vector<string>& files)
{
	string dirNew;
	dirNew = dir + "\\*.*";    // ��Ŀ¼�������"\\*.*"���е�һ������

	intptr_t handle;
	_finddata_t findData;

	handle = _findfirst(dirNew.data(), &findData);
	if (handle == -1)        // ����Ƿ�ɹ�
		return;

	do
	{
		if (findData.attrib & _A_SUBDIR)
		{
			if (strcmp(findData.name, ".") == 0 || strcmp(findData.name, "..") == 0)
				continue;

			//cout << findData.name << "\t<dir>\n";

			// ��Ŀ¼�������"\\"����������Ŀ¼��������һ������
			dirNew = dir + "\\" + findData.name;

			listFiles(dirNew, files);
		}
		else {
			files.push_back(dir + "\\" + findData.name);
		}

	} while (_findnext(handle, &findData) == 0);

	_findclose(handle);    // �ر��������
}

bool Util::endsWith(string s, string sub) {
	return s.rfind(sub) == (s.length() - sub.length());
}


void Util::getFileList(string base_path, string project) {
	//��ȡ�ļ��б� begin
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
	//��ȡ�ļ��б� end
}
	


string Util::replaceAll(string str, string sub, string replacement) {
	int pos;
	pos = str.find(sub);
	while (pos != -1) {
		// str.length()���ַ��ĳ��ȣ�ע��str������string����
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
