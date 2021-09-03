#include "views/MainViewController.hpp"
#include "MorePrecisePlayerHeightConfig.hpp"

DEFINE_TYPE(MorePrecisePlayerHeight::Views, MainViewController);

void MorePrecisePlayerHeight::Views::MainViewController::DidActivate(
    bool firstActivation,
    bool addedToHierarchy,
    bool screenSystemEnabling
) {
    using namespace UnityEngine;

    if (firstActivation) {
        GameObject* container = QuestUI::BeatSaberUI::CreateScrollableSettingsContainer(get_transform());

        AddConfigValueToggle(container->get_transform(), getMorePrecisePlayerHeightConfig().Enabled);
        
        // I fucking hate this shit.
        std::vector<std::u16string> heightUnitValues = { u"Meters", u"Feet", u"Banana" };
        std::u16string heightUnitValue = heightUnitValues[getMorePrecisePlayerHeightConfig().HeightUnit.GetValue()];
        QuestUI::BeatSaberUI::CreateDropdown(container->get_transform(), "Height Unit", heightUnitValue, heightUnitValues,
            [heightUnitValues](std::u16string_view value) {
                if (value == heightUnitValues[0]) {
                    getMorePrecisePlayerHeightConfig().HeightUnit.SetValue(0);
                } else if (value == heightUnitValues[1]) {
                    getMorePrecisePlayerHeightConfig().HeightUnit.SetValue(1);
                } else if (value == heightUnitValues[2]) {
                    getMorePrecisePlayerHeightConfig().HeightUnit.SetValue(2);
                }
            }
        );
    }
}