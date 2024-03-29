# Clean out the previous ones
rm compile_commands.json
rm -rf Debug

# CMake compilation to get into compile_commands.json
cmake -H. -BDebug -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=YES;
ln -s Debug/compile_commands.json .;

# CTags
ctags -R .;
