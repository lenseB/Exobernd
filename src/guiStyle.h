//////////////////////////////////////////////////////////////////////////////////
//                                                                              //
// StyleAsCode exporter v2.0 - Style data exported as a values array            //
//                                                                              //
// USAGE: On init call: GuiLoadStyleLight();                                   //
//                                                                              //
// more info and bugs-report:  github.com/raysan5/raygui                        //
// feedback and support:       ray[at]raylibtech.com                            //
//                                                                              //
// Copyright (c) 2020-2023 raylib technologies (@raylibtech)                    //
//                                                                              //
//////////////////////////////////////////////////////////////////////////////////
#pragma once
#include "raylib.h"
#define LIGHT_STYLE_PROPS_COUNT 9

// Custom style name: Light
static const GuiStyleProp lightStyleProps[LIGHT_STYLE_PROPS_COUNT] = {
    {2, 0, 0x010101ff}, // BUTTON_BORDER_COLOR_NORMAL
    {2, 1, 0x620606ff}, // BUTTON_BASE_COLOR_NORMAL
    {2, 2, 0x010101ff}, // BUTTON_TEXT_COLOR_NORMAL
    {2, 3, 0x4b4b4bff}, // BUTTON_BORDER_COLOR_FOCUSED
    {2, 4, 0x720707ff}, // BUTTON_BASE_COLOR_FOCUSED
    {2, 5, 0x4b4b4bff}, // BUTTON_TEXT_COLOR_FOCUSED
    {2, 6, 0x31060eff}, // BUTTON_BORDER_COLOR_PRESSED
    {2, 7, 0x32030eff}, // BUTTON_BASE_COLOR_PRESSED
    {2, 8, 0x780e52ff}, // BUTTON_TEXT_COLOR_PRESSED
};

// Style loading function: Light
static void GuiLoadStyleLight(void)
{
    // Load style properties provided
    for (int i = 0; i < LIGHT_STYLE_PROPS_COUNT; i++)
    {
        GuiSetStyle(lightStyleProps[i].controlId, lightStyleProps[i].propertyId, lightStyleProps[i].propertyValue);
    }
    GuiSetStyle(DEFAULT, BORDER_WIDTH, 5);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 30); // DEFAULT, shared by all controls
}
