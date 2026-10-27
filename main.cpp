#include "main.hpp"
#include "config.hpp"
#include "ui/SettingsViewController.hpp"

#include "scotland2/shared/modloader.h"
#include "beatsaber-hook/shared/utils/hooking.hpp"
#include "custom-types/shared/register.hpp"
#include "bsml/shared/BSML.hpp"

#include "UnityEngine/Camera.hpp"

static modloader::ModInfo modInfo{MOD_ID, VERSION, 0};

// Hook for camera FOV
MAKE_HOOK_MATCH(Camera_set_fieldOfView, &UnityEngine::Camera::set_fieldOfView, void,
                UnityEngine::Camera* self, float value) {
    if (getModConfig().Enabled.GetValue()) {
        value = getModConfig().FOV.GetValue();
    }
    Camera_set_fieldOfView(self, value);
}

MOD_EXTERN_FUNC void setup(CModInfo* info) noexcept {
    *info = modInfo.to_c();
    getModConfig().Init(modInfo);
    Paper::Logger::RegisterFileContextId(PaperLogger.tag);
    PaperLogger.info("Completed setup!");
}

MOD_EXTERN_FUNC void late_load() noexcept {
    il2cpp_functions::Init();
    custom_types::Register::AutoRegister();
    BSML::Init();
    BSML::Register::RegisterSettingsMenu<FOVModifier::SettingsViewController*>("FOV Modifier");

    INSTALL_HOOK(PaperLogger, Camera_set_fieldOfView);
    PaperLogger.info("Installed all hooks!");
}
