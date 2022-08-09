#!/bin/bash

export OPENGL_DISABLE_ENV=yes
eval "optbin -s /opt/opengl/bin"
eval "optlib -s /opt/opengl/lib/x86_64-linux-gnu"
eval "optlib -s /opt/opengl/lib/x86_64-linux-gnu/dri"
eval "optpkg -s /opt/opengl/lib/x86_64-linux-gnu/pkgconfig"

