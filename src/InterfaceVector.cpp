#include "InterfaceVector.hh"


InterfaceVector::InterfaceVector(/* args */)
{
}

InterfaceVector::~InterfaceVector()
{
}

void InterfaceVector::CreateCmd(std::string Cmd)
{
    if (Cmd == "Move")
    {
        std::shared_ptr<LibInterface> LibPlugin = std::make_shared<LibInterface>(LIB_Move, wolny);
        _LibHandlers[Cmd] = LibPlugin;
        _LibHandlers[Cmd]->CreateCmd();
    }
    if (Cmd == "Rotate")
    {
        std::shared_ptr<LibInterface> LibPlugin = std::make_shared<LibInterface>(LIB_Rotate, wolny);
        _LibHandlers[Cmd] = LibPlugin;
        _LibHandlers[Cmd]->CreateCmd();
    }
    if (Cmd == "Pause")
    {
        std::shared_ptr<LibInterface> LibPlugin = std::make_shared<LibInterface>(LIB_Pause, wolny);
        _LibHandlers[Cmd] = LibPlugin;
        _LibHandlers[Cmd]->CreateCmd();
    }
    if (Cmd == "Set")
    {
        std::shared_ptr<LibInterface> LibPlugin = std::make_shared<LibInterface>(LIB_Set, wolny);
        _LibHandlers[Cmd] = LibPlugin;
        _LibHandlers[Cmd]->CreateCmd();
    }

}

// std::string InterfaceVector::GetCmdName(std::string Cmd)
// {
//     return _LibHandlers[Cmd]->getCmdName();
// }

std::shared_ptr<LibInterface> InterfaceVector::operator [] (std::string Cmd)
{
    return _LibHandlers[Cmd];
}