#include "MyForm.h"
#include "Card.h"
#include "Cell.h"
#include "System.h"
#include <fstream>
#include <map>
#include <string>
#include <vector> 
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

void main() {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	BoardGame::MyForm form;
	Application::Run(% form);
}

