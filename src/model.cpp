#include "model.h"

/*
 * Command call must contain filename of the .obj model
 *
 * Command line flags:
 *  Mode selection:
 *   -g (default) - GLFW function.
 *   -c - pure c++ rotation implementation.
 *   -a - assembly rotation implementation.
 *  Test selection:
 *   -f (default) - normal operation mode with fps measurments.
 *   -s - will measure time of one full roration.
*/

Model::Model(int argc, char** argv)
{
    if(!(argc-1))
        showHelpAndExit();

    filename = "";
    bool wasModeSet = false;
    bool wasTestSet = false;
    rotationMode = glfw;
    measurementType = fps;
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        if(arg[0] == '-')
        {
            for(char c : arg)
            {
                if(!wasModeSet)
                {
                    if(c == 'g')
                    {
                        wasModeSet = true;
                        rotationMode = glfw;
                    }
                    else if(c == 'c') 
                    {
                        wasModeSet = true;
                        rotationMode = cpure;
                    }
                    else if(c == 'a')
                    {
                        wasModeSet = true;
                        rotationMode = assembly;
                    }
                }
                if(!wasTestSet)
                {
                    if(c == 'f')
                    {
                        wasTestSet = true;
                        measurementType = fps;
                    }
                    else if(c == 's')
                    {
                        wasTestSet = true;
                        measurementType = speed;
                    }
                }
            }
        }
        else if(filename.empty())
            filename = arg;
        if(wasModeSet && wasTestSet && !filename.empty())
            break;
    }
    if(filename.empty())
        showMsgAndExit("No filename was specified!\n");

}

void Model::showInitHelp()
{
    std::cout << "l3rdAsm is a lighweight 3d renderer for .obj files.\n";
    std::cout << "Command call must contain filename of the .obj model.\n";
    std::cout << "Command line flags:\n";
    std::cout << "\tMode selection:\n";
    std::cout << "\t\t-g (default) - GLFW function.\n";
    std::cout << "\t\t-c - pure c++ rotation implementation.\n";
    std::cout << "\t\t-a - assembly rotation implementation.\n";
    std::cout << "\tTest selection:\n";
    std::cout << "\t\t-f (default) - normal operation mode with fps measurments.\n";
    std::cout << "\t\t-s - will measure time of one full roration.\n";
    std::cout << "Examples of usage:\n";
    std::cout << "./l3drAsm\t\t\t - show help.\n";
    std::cout << "./l3drAsm model.obj\t\t - render model.obj with default settings.\n";
    std::cout << "./l3drAsm -c model.obj\t\t - render model.obj with c implementation.\n";
    std::cout << "./l3drAsm -as model.obj\t\t - render model.obj with assembly measuring speed.\n";
    std::cout << "./l3drAsm -a -s model.obj\t - same as above.\n";
    std::cout << "./l3drAsm -s -a model.obj\t - same as above.\n";
}

void Model::showHelpAndExit(const std::string& msg)
{
    if(!msg.empty())
        std::cout << msg <<"\n";
    showInitHelp();
    exit(EXIT_SUCCESS);
}

void Model::showMsgAndExit(const std::string& msg)
{
    std::cout << msg <<"\n";
    exit(EXIT_SUCCESS);
}

void Model::showFields()
{
    std::cout << "filename: " << filename << "\n";
    std::cout << "rotationMode: " << rotationMode << "\n";
    std::cout << "measurmentType: " << measurementType << "\n";
}

int Model::test()
{
    return 1;
}
