#pragma once

#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig) {
    CONFIG_VALUE(Enabled, bool, "Enabled", true);
    CONFIG_VALUE(FOV, float, "FOV", 90.0f);
};
