# Ray's STM8 CLion Dev Container Template

This project provides a template for STM8 microcontroller development using CLion and a pre-configured Docker development container. The container includes the necessary toolchain (SDCC, stm8-gdb, OpenOCD, stm8flash) and configuration for a streamlined setup, pulling the image directly from Docker Hub.

## Notes to Keep in Mind
This setup uses CLion's Dev Container feature to automatically set up and run the development environment.

**Prerequisites:**

*   **Docker:** Docker must be installed and running on your host machine (Linux or Windows). Ensure the Docker daemon is accessible.
    *   For WSL2 on Windows, ensure Docker Desktop is configured to work with your WSL2 distribution.
*   **Git:** Git must be installed.
*   **CLion:** JetBrains CLion IDE (version supporting Dev Containers).

**Important Note on Privileged Mode:**

The Dev Container is configured to run in **privileged mode**. This is necessary to allow the container direct access to USB devices connected to your host machine, which is required for flashing the STM8 microcontroller using `stm8flash` and for debugging with OpenOCD and an ST-Link debugger.

## Quick Start ##
1.  **Run the Dev Container:**
From CLion, choose Remote Development -> Dev Containers, and create a new Dev Container from git@github.com:raywilfong/Stm8Template.git  
2. **Add the Build Configuration**
When the container first starts up, it needs to have the build and external tools configurations, added to clion. That can be done automatically by opening the CLion terminal and hitting the up arrow to select the "previous" command. Then hit Enter to run that command. Once done, exit CLion and restart the dev container. When you get back into the dev container, your build configurations and external tools will be configured correctly OpenOCD debugging.
3. **Build One Of the OpenOCD Builds** I have two sample projects. You should be able to connect your ST-Link and Debug one of the samples to validate your configuration.

## How to configure a new project ##
1. Copy the MyProject folder to a new name like **MyNewProjectName**
2. At the bottom of the root **CMakeLists.txt** file, add this: `add_subdirectory(Projects/MyNewProjectName)`
3. In your new directory, edit that **CMakeLists.txt**
>* change your project name: `project(MyNewProjectName C)`
>* commment and uncomment your desired list of included SPL ".c" files (i.e. "stm8s_gpio.c")
4. Build your new project so an initial ".elf" file will exist: "cmake-build-debug-stm8s103/MyNewProjectName/MyNewProjectName.elf"
5. Edit build configurations and copy the "MyProject OpenOCD" to "MyNewProjectName OpenOCD"
>* "Executable binary" points to the elf file you just built
6. Code your new STM8 robot army!!!


## Todo: WSL Specific help ##
* (Windows with WSL2 only) USBIPD-WIN allows WSL environments to use USB Devices
>* See the instructions [here](https://learn.microsoft.com/en-us/windows/wsl/connect-usb)
>* Admin Powershell Commands used:
>>* usbipd.exe list
>>* usbipd.exe bind --busid 14-2
>>* usbipd attach --wsl --busid 14-2
* (Windows with WSL2 only) UDEV service must be running. Change /etc/wsl.conf as follows:
> [boot] <br>
> command="service udev start"
