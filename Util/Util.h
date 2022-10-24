#pragma once
#include<string>
#include<vector>
using namespace std;



class Util {

public: Util();
public: virtual ~Util();
public: static void getFileList(string base_path, string project);
private: static bool endsWith(string s, string sub);
private: static void listFiles(const string dir, std::vector<string>& files);
public: static string replaceAll(string str, string sub, string replacement);
public: static string genUUID();
};




