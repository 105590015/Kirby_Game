#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Door.h"
#include <fstream> 


namespace game_framework {
	Door::Door(){
	}

	int Door::GetHeight() {
		return door.Height();
	}

	int Door::GetWidth() {
		return door.Width();
	}

	void Door::Initialize() {

	}
}