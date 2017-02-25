#pragma once
#include <string>
#ifndef MAX_PATH
#define MAX_PATH 512
#endif

typedef unsigned char  byte;


std::string readTextFile(const char* filename);

size_t GetFileSize(const char* fileName);

void FileCopy(const char* src, const char* dest, int bufSize);

bool CreateDir(const char* path);

bool DeleteDir(const char* path);

std::string  GetCurrentDir();

bool DirIsExist(const char*);

bool DirIsExist(const char* path);

const char* getCurrentProcPath();


