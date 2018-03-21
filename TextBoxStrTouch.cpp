/*
GUI library for Arduino TFT and OLED displays

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
#include "UTFT.h"
#include "TextBoxStrTouch.h"
#include "MobileKBWindow.h"

bool TextBoxStrTouch::OnTouch(int x,int y)
{
	bool retCode=TextBox::OnTouch(x,y);
	MobileKBWindow * mobKBWnd=(MobileKBWindow *)FindDialog(F("MobileKeyboard"));
	if(mobKBWnd == NULL)
	{
		mobKBWnd=new MobileKBWindow(2,100);
		RegisterDialog(F("MobileKeyboard"),mobKBWnd); 
	}
	if(mobKBWnd!=NULL)
	{
		mobKBWnd->Initialize(GetText());
		if(DoDialog(mobKBWnd) == IDialogClosedEventReceiver::OK)
			SetText(mobKBWnd->GetText());
		mobKBWnd->Finalization();
	}
	return true;
}
