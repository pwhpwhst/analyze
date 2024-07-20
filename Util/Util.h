#pragma once
#include<string>
#include<vector>
#include<fstream>
using namespace std;



class Util {

public: Util();
public: virtual ~Util();
public: static void getFileList(string base_path, string project);
private: static bool endsWith(string s, string sub);
private: static void listFiles(const string dir, std::vector<string>& files);
public: static string replaceAll(string str, string sub, string replacement);
public: static string genUUID();
public: static string getMD5(string fileName);
public: static void cleanLog();
public: static void log(const string &s);
public: static bool const logSwitch = true;
public: static string logFile;
};




