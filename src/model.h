#ifndef MODEL
#define MODEL

#include <string>

enum translation {cpure, assembly, glfw};

class Model
{
private:
  std::string filename;
  translation mode;
  
public:
  Model(int argc, char** argv);
  int test();
};


#endif
