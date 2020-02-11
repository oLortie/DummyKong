#include "XController.h"
#include <Xinput.h>

XController::XController()
{

	/* Initialize value for buttons and joystick*/
	player =
	{
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
}
XController:: ~XController()
{

} 

void XController::readController()
{
	A_ButtonPressed();
	B_ButtonPressed();
	X_ButtonPressed();
	Y_ButtonPressed();
	leftTrigger();
	rightTrigger();
	rJoyStick();
	lJoyStick();
}
/* this method will be called in the timer callback*/
void XController::updateController()
{
	readController();
}

Controller XController::getPlayer()
{
	return player;
}

void XController::getUserInput()
{
//	int controllerID = -1;
//	
//	for (DWORD i = 0; i < XUSER_MAX_COUNT && controllerID == -1; i++)
//	{
//		XINPUT_STATE state;
//		ZeroMemory(&state, sizeof(XINPUT_STATE));
//		DWORD  result = XInputGetState(i, &state);
//		if (result == 0)
//		{
//			std::cout << "Controller is connected in port: " << i << std::endl;
//		}
//	}
}

void XController::A_ButtonPressed()
{
	player.BTN_A = ((state.Gamepad.wButtons & XINPUT_GAMEPAD_A) != 0);
}

void XController::B_ButtonPressed()
{
		player.BTN_B = ((state.Gamepad.wButtons & XINPUT_GAMEPAD_B) != 0);
}
void XController::X_ButtonPressed()
{
	player.BTN_X = ((state.Gamepad.wButtons & XINPUT_GAMEPAD_X) != 0);
}
void XController::Y_ButtonPressed()
{
	player.BTN_Y = ((state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) != 0);
}

void XController::leftTrigger()
{
	player.left_Trigger = (int)state.Gamepad.bLeftTrigger / 255;
}

void XController::rightTrigger()
{
	player.right_Trigger = (int)state.Gamepad.bRightTrigger / 255;
}

void XController::rJoyStick()
{
	player.RThumbStickX = (int)fmaxf(-1, (float)state.Gamepad.sThumbRX / 32767);
	player.RThumbStickY = (int)fmaxf(-1, (float)state.Gamepad.sThumbRY / 32767);
}

void XController::lJoyStick()
{
	player.LThumbStickX = (int)fmaxf(-1, (float)state.Gamepad.sThumbLX / 32767);
	player.LThumbStickY = (int)fmaxf(-1, (float)state.Gamepad.sThumbLY / 32767);
}

