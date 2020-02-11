#pragma once

#include <Windows.h>
#include <Xinput.h>
#include <math.h>
#include <wdmguid.h>
#include <iostream>


struct Controller
{
	int LThumbStickY;
	int LThumbStickX;
	int RThumbStickY;
	int RThumbStickX;
	bool BTN_A;
	bool BTN_B;
	bool BTN_X;
	bool BTN_Y;
	int left_Trigger;
	int right_Trigger;
};


class XController
{
private:
	Controller player;
	XINPUT_STATE state;

public:
	XController();
	virtual ~XController();
	void readController();
	void updateController();
	Controller getPlayer();
	void getUserInput();
	void A_ButtonPressed();
	void X_ButtonPressed();
	void B_ButtonPressed();
	void Y_ButtonPressed();
	void leftTrigger();
	void rightTrigger();
	void rJoyStick();
	void lJoyStick();
};

