#include "FreeflowApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
FreeflowApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

FreeflowApp::FreeflowApp(InputParameters parameters) : MooseApp(parameters)
{
  FreeflowApp::registerAll(_factory, _action_factory, _syntax);
}

FreeflowApp::~FreeflowApp() {}

void 
FreeflowApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<FreeflowApp>(f, af, s);
  Registry::registerObjectsTo(f, {"FreeflowApp"});
  Registry::registerActionsTo(af, {"FreeflowApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
FreeflowApp::registerApps()
{
  registerApp(FreeflowApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
FreeflowApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  FreeflowApp::registerAll(f, af, s);
}
extern "C" void
FreeflowApp__registerApps()
{
  FreeflowApp::registerApps();
}
