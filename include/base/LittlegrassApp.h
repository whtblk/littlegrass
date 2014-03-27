#ifndef LITTLEGRASSAPP_H
#define LITTLEGRASSAPP_H

#include "MooseApp.h"

class LittlegrassApp;

template<>
InputParameters validParams<LittlegrassApp>();

class LittlegrassApp : public MooseApp
{
public:
  LittlegrassApp(const std::string & name, InputParameters parameters);
  virtual ~LittlegrassApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* LITTLEGRASSAPP_H */
