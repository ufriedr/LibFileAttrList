//
//  FileListAttr.cpp
//  
//
//  Created by uwe on 17.02.22.
//

#include "FileListAttr.h"

#include <fstream>

#include <filesystem>
#include <vector>

#include <sys/stat.h>
#include <time.h>
#include <stdio.h>

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <stdexcept>
#include <iterator>
#include <sstream>

//
using namespace std;
namespace fs = filesystem;

//***
    ostream& formatDateTime(ostream& out, const tm& t, const char* fmt) {
      const time_put<char>& dateWriter = use_facet<time_put<char> >(out.getloc());
      int n = strlen(fmt);
      if (dateWriter.put(out, out, ' ', &t, fmt, fmt + n).failed()) {
        throw runtime_error("failure to format date time");
      }
      return out;
    }

    string dateTimeToString(const tm& t, const char* format) {
      stringstream s;
      formatDateTime(s, t, format);
      return s.str();
    }

    tm now() {
      time_t now = time(0);
      return *localtime(&now);
    }
//***

vector< vector<string> > FileListAttr::sayFileListAttr(string dirName)
{
    vector<vector<string>> listeFilesAttr;
    // Iterate over the `std::filesystem::directory_entry` elements explicitly
       for (const fs::directory_entry& dir_entry :
           std::filesystem::recursive_directory_iterator(dirName))
       {
           vector<string> wrkListe;
           struct stat t_stat;
           
           stat(dir_entry.path().c_str(), &t_stat);
           struct tm * timeinfo = localtime(&t_stat.st_mtime);
           string modDate = dateTimeToString(*timeinfo, "%Y-%m-%d %H:%M:%S");
           string groesse = to_string(t_stat.st_size);
           
           wrkListe.push_back(dir_entry.path());
           wrkListe.push_back(modDate);
           wrkListe.push_back(groesse);
           if(t_stat.st_mode & S_IFREG) {
               //printf("Reguläre Datei\n");
               wrkListe.push_back("Datei");
           }
           else if(t_stat.st_mode & S_IFDIR) {
               //printf("Directory\n");
               wrkListe.push_back("Verzeichnis");
           }
           else {
               //printf("Unbekannte Datei\n");
               wrkListe.push_back("Unbekannt");
           }
           
           listeFilesAttr.push_back(wrkListe);
           //std::cout << dir_entry.path() << '\n';
       }
    
    return listeFilesAttr;

}
