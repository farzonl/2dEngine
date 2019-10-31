#ifndef _MANAGED_LAYER_H_
#define _MANAGED_LAYER_H_

typedef void(WINAPI void_Callback)();
typedef void_Callback Draw_Callback;
void WINAPI Draw_SetCallback(Draw_Callback* pCallback);
Draw_Callback Draw;

typedef void_Callback Setup_Callback;
void WINAPI Setup_SetCallback(Setup_Callback* pCallback);
Setup_Callback Setup;

typedef void(WINAPI MousePressed_Callback)(int mouseX, int mouseY);
void WINAPI MousePressed_SetCallback(MousePressed_Callback* pCallback);
MousePressed_Callback MousePressed;

#endif// _MANAGED_LAYER_H_
