# The Octo Desktop Environment
![Screenshot](.screenshot.png)

## Purpose
The Octo Desktop Environment aims to be a GTK-based and Windows 8-like interface for X11.
**CAUTION: THIS PROJECT IS IN VERY EARLY DEVELOPMENT. IT IS NOT EVEN A DESKTOP ENVIRONMENT YET, IT IS JUST A VERY PRIMITIVE APP LAUNCHER.**

### Why copy a failed operating system?
Windows 8 had a lot of potential. It is reminiscent of a window manager like i3 or dwm, where the windows can switch between tiled and floating. It also had many other programs beside the start menu, like the search panel and charms bar, which hopefully will be implemented eventually into this project. However, one of my biggest fears is that it will come too close to GNOME.

## To-do list
- [X] Launch applications
- [X] Look for applications
- [X] Fullscreen and scrollable window
- [ ] Make Octo independent from `octo.xml`
- [ ] Add draggable app tiles
- [ ] Add resizeable app tiles
- [ ] Add search function
- [ ] Add icons in app tiles
- [ ] Tiling functionality
- [ ] Make search panel that can search files, apps, and settings
- [ ] Sort app order alphabetically

## Build
After `git clone`-ing this repo and `cd`-ing into it, simply run `sudo make clean install` to compile and install octo. To compile octo without installing it, run `make clean` instead.

## Contributing
Want to contribute? If you don't know how to code, please add an issue. If you do, please add a pull request.

## Directory Structure
- **src**: contains C source files (`*.c`)
- **include**: contains C header files (`*.h`)
- **ui**: contains GtkBuilder file (`octo.xml`)

## About
Ancient Straits (email: ancientstraits@protonmail.com)
