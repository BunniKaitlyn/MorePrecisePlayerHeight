#include "MorePrecisePlayerHeight.hpp"
#include "MorePrecisePlayerHeightConfig.hpp"

#include "GlobalNamespace/PlayerHeightSettingsController.hpp"
#include "System/Math.hpp"

double METERS_TO_FEET_CONVERSION_FACTOR = .3048;
double METERS_TO_BANANA_CONVERSION_FACTOR = 100. / 13;

MAKE_HOOK_MATCH(
    PlayerHeightSettingsController_RefreshUI,
    &GlobalNamespace::PlayerHeightSettingsController::RefreshUI,
    void,
    GlobalNamespace::PlayerHeightSettingsController* self
) {
    using namespace System;

    if (getMorePrecisePlayerHeightConfig().Enabled.GetValue()) {
        int heightUnit = getMorePrecisePlayerHeightConfig().HeightUnit.GetValue();
        if (heightUnit == 0) { // Meters
            self->text->set_text(::Il2CppString::Format(il2cpp_utils::newcsstr("<size=80%>{0:0.00}m</size>"), il2cpp_functions::value_box(classof(float), &self->value)));
        } else if (heightUnit == 1) { // Feet
            double inchFeet = self->value / METERS_TO_FEET_CONVERSION_FACTOR;
            int wholeFeet = static_cast<int>(inchFeet);
            double inches = Math::Round((inchFeet - wholeFeet) / .0833);
            self->text->set_text(::Il2CppString::Format(il2cpp_utils::newcsstr("<size=85%>{0}'\n{1:0.0}\"</size>"), il2cpp_functions::value_box(classof(int), &wholeFeet), il2cpp_functions::value_box(classof(double), &inches)));
        } else if (heightUnit == 2) { // Banana
            double banana = self->value * METERS_TO_BANANA_CONVERSION_FACTOR;
            self->text->set_text(::Il2CppString::Format(il2cpp_utils::newcsstr("<size=75%>{0:0.00}\nbanana</size>"), il2cpp_functions::value_box(classof(double), &banana)));
        }
    } else {
        PlayerHeightSettingsController_RefreshUI(self);
    }
}

void MorePrecisePlayerHeight::Hooks::PlayerHeightSettingsController() {
    INSTALL_HOOK(getLogger(), PlayerHeightSettingsController_RefreshUI);
}