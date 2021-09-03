#include "MorePrecisePlayerHeight.hpp"
#include "views/MainViewController.hpp"

void MorePrecisePlayerHeight::Install() {
    custom_types::Register::AutoRegister();
    
    QuestUI::Init();
    QuestUI::Register::RegisterModSettingsViewController<MorePrecisePlayerHeight::Views::MainViewController*>(modInfo);
    
    MorePrecisePlayerHeight::Hooks::PlayerHeightSettingsController();
}