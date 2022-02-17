//
//  FileListAttr.hpp
//  
//
//  Created by uwe on 17.02.22.
//

#ifndef FileListAttr_h
#define FileListAttr_h

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <vector>
using namespace std;


class FileListAttr {
public: vector<vector<string> > sayFileListAttr(string dirName);
    
};

#endif /* FileListAttr_h */
