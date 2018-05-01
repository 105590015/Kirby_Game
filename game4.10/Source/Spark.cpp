#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include"Spark.h"

namespace game_framework {
	Spark::Spark():Enemy() {

	}

	int Spark::GetX2() {
		return x + index->Width();
	}

	int Spark::GetY2() {
		return y + index->Height();
	}

}