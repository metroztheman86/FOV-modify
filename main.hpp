#pragma once

#include "paper2_scotland2/shared/logger.hpp"

#ifndef MOD_ID
#define MOD_ID "FOVModifier"
#endif
#ifndef VERSION
#define VERSION "0.1.0"
#endif

constexpr auto PaperLogger = Paper::ConstLoggerContext("FOVModifier");
