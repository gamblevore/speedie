#!/bin/bash
echo "Prebuild .cpp files"
sudo -u $(logname) /usr/local/bin/speedie . --x --nocompile
sudo -u $(logname) /usr/local/bin/speedie --self --x --nocompile
