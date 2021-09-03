#include "main.hpp"
#include "MorePrecisePlayerHeight.hpp"
#include "MorePrecisePlayerHeightConfig.hpp"

DEFINE_CONFIG(MorePrecisePlayerHeightConfig);

Logger& getLogger() {
    static Logger* logger = new Logger(modInfo);
    return *logger;
}

extern "C" void setup(ModInfo& info) {
    info.id = ID;
    info.version = VERSION;
    modInfo = info;
	
    getMorePrecisePlayerHeightConfig().Init(modInfo);
    getLogger().info("Completed MorePrecisePlayerHeight setup!");
}

extern "C" void load() {
    il2cpp_functions::Init();

    getLogger().info("Installing MorePrecisePlayerHeight...");
    MorePrecisePlayerHeight::Install();
    getLogger().info("Installed MorePrecisePlayerHeight!");
}