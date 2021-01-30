#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cassert>
#include <Windows.h>
#include <tchar.h>

#define SAFE_FREE(TARGET)			if((TARGET) != nullptr) { free((TARGET)); (TARGET) = nullptr; }
#define SAFE_FCLOSE(TARGET)			if((TARGET) != nullptr) { fclose((TARGET)); (TARGET) = nullptr; }

#define SAFE_DELETE_OBJ(TARGET)			if((TARGET) != nullptr) { DeleteObject((TARGET)); (TARGET) = nullptr; }
