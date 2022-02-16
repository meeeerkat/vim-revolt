
## Vim base framework
to build simple terminal apps with vim bindings

### Why include-prefixes
This directory only contains links to the include/ of statically linked libraries because adding the include/ directory directly doesn't allow to add a prefix and this would cause naming conflicts with files in the current project that would have the same include path (path & name).
Using links allows to choose the prefix (for libvim the prefix choosen is vim).
See https://stackoverflow.com/questions/58766163/how-do-i-use-gcc-options-iprefix-and-iwithprefix

