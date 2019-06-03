env
env FOO=BAR
echo $FOO
env FOO=BAR echo $FOO $HOME
setenv
setenv FOO
echo $FOO
setenv FOO BAR
echo $FOO
unsetenv
unsetenv BAR
unsetenv FOO
echo $FOO
unsetenv FOO
echo $FOO
setenv FOO BAR NASH
# exit