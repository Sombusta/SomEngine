// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "pch.h"
#include "LinearColor.h"

const float FLinearColor::OneOver255 = 1.f / 255.f;
const FLinearColor FLinearColor::Error(1.f, 0.f, 1.f, 1.f);
const FLinearColor FLinearColor::White(1.f, 1.f, 1.f, 1.f);
const FLinearColor FLinearColor::Black(0.f, 0.f, 0.f, 1.f);
const FLinearColor FLinearColor::Gray(0.5f, 0.5f, 0.5f, 1.f);
const FLinearColor FLinearColor::Red(1.f, 0.f, 0.f, 1.f);
const FLinearColor FLinearColor::Green(0.f, 1.f, 0.f, 1.f);
const FLinearColor FLinearColor::Blue(0.f, 0.f, 1.f, 1.f);
const FLinearColor FLinearColor::Yellow(1.f, 1.f, 0.f, 1.f);
const FLinearColor FLinearColor::Cyan(0.f, 1.f, 1.f, 1.f);
const FLinearColor FLinearColor::Magenta(1.f, 0.f, 1.f, 1.f);