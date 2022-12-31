set -e #exit on error
if [ "$1" == "self" ] ; then
    speedie --self --quiet
fi
cd ~/Speedie/jeebox.scproj
speedie . -x --quiet --nocompile
cmake -BBuild > /dev/null
cd Build
make > /dev/null
./jb -n ../Examples/Users.box 
./example_xml > /dev/null
./example_test > /dev/null
./example_userlist  ../Examples/Users.box > /dev/null
echo "Tests complete! Lets install."
sudo make install > /dev/null
cd ..
git status
