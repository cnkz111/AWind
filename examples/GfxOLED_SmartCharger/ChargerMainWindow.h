/*
This file is part of AWind library

Copyright (c) 2014-2018 Andrei Degtiarev

Licensed under the Apache License, Version 2.0 (the "License"); you
may not use this file except in compliance with the License.  You may
obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
implied.  See the License for the specific language governing
permissions and limitations under the License.
*/
#pragma once

#include "TextBoxString.h"
#include "TextBoxNumber.h"
#include "DecoratorPrimitives.h"
#include "ChartWindow.h"
#include "ChargerController.h"


extern uint8_t SmallOledFont[];
extern uint8_t BigOledFont[];

///Osciloscope main window
class ChargerMainWindow : public MainWindow
{
public:
	ChargerMainWindow(int width,int height):MainWindow(width, height)
	{

	}

	void AddTab(Window *tab)
	{
		tab->Move(0, 0, Width(), Height());
		AddChild(tab);
	}

};