//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "FreeflowTestApp.h"
#include "FreeflowApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
FreeflowTestApp::validParams()
{
  InputParameters params = FreeflowApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

FreeflowTestApp::FreeflowTestApp(InputParameters parameters) : MooseApp(parameters)
{
  FreeflowTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

FreeflowTestApp::~FreeflowTestApp() {}

void
FreeflowTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  FreeflowApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"FreeflowTestApp"});
    Registry::registerActionsTo(af, {"FreeflowTestApp"});
  }
}

void
FreeflowTestApp::registerApps()
{
  registerApp(FreeflowApp);
  registerApp(FreeflowTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
FreeflowTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  FreeflowTestApp::registerAll(f, af, s);
}
extern "C" void
FreeflowTestApp__registerApps()
{
  FreeflowTestApp::registerApps();
}
