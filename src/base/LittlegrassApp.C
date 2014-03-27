#include "LittlegrassApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<LittlegrassApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

LittlegrassApp::LittlegrassApp(const std::string & name, InputParameters parameters) :
    MooseApp(name, parameters)
{
  srand(libMesh::processor_id());
  
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  LittlegrassApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  LittlegrassApp::associateSyntax(_syntax, _action_factory);
}

LittlegrassApp::~LittlegrassApp()
{
}

void
LittlegrassApp::registerApps()
{
  registerApp(LittlegrassApp);
}

void
LittlegrassApp::registerObjects(Factory & factory)
{
}

void
LittlegrassApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
