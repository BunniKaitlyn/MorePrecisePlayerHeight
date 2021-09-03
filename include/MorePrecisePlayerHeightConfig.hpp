#pragma once

#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(MorePrecisePlayerHeightConfig,
    CONFIG_VALUE(Enabled, bool, "Enabled", true);
    CONFIG_VALUE(HeightUnit, int, "HeightUnit", 0);

    CONFIG_INIT_FUNCTION(
        CONFIG_INIT_VALUE(Enabled);
        CONFIG_INIT_VALUE(HeightUnit);
    )
)