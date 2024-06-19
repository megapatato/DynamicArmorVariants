Framework for mods to define variants of armors by swapping armor addons
dynamically at runtime.

## Requirements
* Skyrim Special Edition
    * Skyrim Special Edition Creation Kit
    * Unpack %ProgramFiles%\Steam\steamapps\common\Skyrim Special Edition\Data\Scripts.zip
* [CMake](https://cmake.org/)
	* Add this to your `PATH`
* [Visual Studio Community 2022](https://visualstudio.microsoft.com/)
	* Desktop development with C++

## Register Visual Studio as a Generator
* Open `x64 Native Tools Command Prompt`
* Run `cmake`
* Close the cmd window

## Building on the command line
```
git clone https://github.com/Exit-9B/DynamicArmorVariants
cd DynamicArmorVariants
git submodule init
git submodule update
cmake --preset vs2022-windows
cmake --build build --config Release
```

## Dependencies
The following projects are dependencies of this mod, automatically
fetched and built. They are listed here for reference in case they
need to be updated.

* [SKSE64 SDK](https://skse.silverlock.org/)
* [MCM Helper SDK](https://github.com/Exit-9B/MCM-Helper/releases)
* [UIExtensions SDK](https://www.nexusmods.com/skyrimspecialedition/mods/17561)
	* Extract the BSA using your favorite tool (e.g.
	[Bethesda Archive Extractor](https://www.nexusmods.com/skyrimspecialedition/mods/974))
	* Update files at `External/UIExtensions`