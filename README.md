# FOV Modifier (Beat Saber Quest, 1.40.8)

Source files for the mod. Build scaffolding comes from the official template so the
CMake/QPM setup is correct for the current game version.

## Build from an iPad (GitHub, no PC)
1. Go to https://github.com/QuestPackageManager/Quest-Mod-Template -> "Use this template" -> new repo.
2. In that repo, replace/add these from this zip: `src/main.cpp`, `src/ui/SettingsViewController.cpp`,
   `include/main.hpp`, `include/config.hpp`, `include/ui/SettingsViewController.hpp`, `mod.template.json`.
3. Delete any leftover template example source files that conflict.
4. In `qpm.json` set dependencies: beatsaber-hook, paper2_scotland2, scotland2, custom-types,
   config-utils, bsml, bs-cordl (pick the versions for 1.40.8 that your template/QPM suggests).
   Set `info.id` = FOVModifier and `info.name` = FOV Modifier.
5. Commit. The template's GitHub Actions workflow builds it; download the `.qmod` artifact.
6. Send it to your Quest (Discord) and install via MBF / ModsBeforeFriday.
