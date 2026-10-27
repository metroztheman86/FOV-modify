#include "ui/SettingsViewController.hpp"
#include "config.hpp"
#include "main.hpp"

#include "bsml/shared/BSML-Lite.hpp"
#include "UnityEngine/Transform.hpp"
#include "UnityEngine/GameObject.hpp"

DEFINE_TYPE(FOVModifier, SettingsViewController);

void FOVModifier::SettingsViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
    if (!firstActivation) return;

    auto container = BSML::Lite::CreateScrollableSettingsContainer(get_transform());
    auto parent = container->get_transform();

    BSML::Lite::CreateToggle(parent, "Enabled", getModConfig().Enabled.GetValue(),
        [](bool value) { getModConfig().Enabled.SetValue(value); });

    BSML::Lite::CreateSliderSetting(parent, "Field of View", 1.0f, getModConfig().FOV.GetValue(), 30.0f, 150.0f,
        [](float value) { getModConfig().FOV.SetValue(value); });
}
