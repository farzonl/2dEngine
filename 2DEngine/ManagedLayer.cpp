#include "pch.h"
#include "ManagedLayer.h"

static Draw_Callback* s_pDraw_Callback = nullptr;
static Setup_Callback* s_pSetup_Callback = nullptr;

void WINAPI Draw()
{
	if (s_pDraw_Callback != nullptr)
	{
		s_pDraw_Callback();
	}
}

void WINAPI Draw_SetCallback(Draw_Callback* pCallback)
{
	s_pDraw_Callback = pCallback;
}

void WINAPI Setup()
{
	if (s_pSetup_Callback != nullptr)
	{
		s_pSetup_Callback();
	}
}

void WINAPI Setup_SetCallback(Setup_Callback* pCallback)
{
	s_pSetup_Callback = pCallback;
}