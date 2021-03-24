#!/bin/bash

octo_build () {
	ninja -C build
	cp build/src/octo ./octo
	cp build/compile_commands.json ./compile_commands.json
}
octo_setup () {
	mkdir build
	meson setup build
	octo_build
}


[ -d build ] && octo_build || octo_setup
