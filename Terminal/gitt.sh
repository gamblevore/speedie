set -e #exit on error
cd ~/Speedie/jeebox.scproj
jb Examples/Users.box -n > /dev/null
Build/example_xml > /dev/null
Build/example_test > /dev/null
if [ -z "$1" ] ; then
    echo "to upload: gitt.sh 'changes made'"
    git status
    exit 0
fi
git add .
git commit -m "$1"
git push