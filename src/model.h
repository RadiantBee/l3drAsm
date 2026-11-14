#ifndef MODEL
#define MODEL

#include <string>
#include <iostream>

enum implementMode {glfw, cpure, assembly};
enum testMode {fps, speed};

class Model
{
private:
  std::string filename;
  implementMode rotationMode;
  testMode measurementType;
  void showHelpAndExit(const std::string& msg = "");
  void showMsgAndExit(const std::string& msg);
  
public:
  Model(int argc, char** argv);
  int test();
  void showInitHelp();
  void showFields();
};


#endif
