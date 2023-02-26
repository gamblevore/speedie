#!/bin/bash
echo "Prebuild .cpp files"
/usr/local/bin/speedie . --x --nocompile
/usr/local/bin/speedie --self --x --nocompile
