#!/bin/bash


# 						! ! ! REQUIRED PART ! ! !

# Need to modify the main fonction so that the first argument passed to
# the minishell executable is interpreted as the input (like if you entered it
# from the terminal)

 # 1) Executable name : minishell
 # 2) Shell script must be in the same folder as the executable

 # 4) All quotes are escaped so that the minishell interpret them correctly
 # 5) Dont launch the script with bash

 # Colors might not work on Ubuntu, idk why
 # The minishell exit code are check so that it match bash or bash --posix
 # (so it will work on mac or ubuntu, but not both, there is somes differences
 # around exit code that I ignore)

 # Theses tests are not inserted in the current version, you'll see why by
 # by running them ...

	# 1) echo and export in the same line separed by ;
		# outputTest "export A B C ; echo \$A \$B \$C"
		# outputTest "export A= B= C= ; echo \$A \$B \$C"
		# outputTest "export A=XXX B=YYY C=ZZZ ; echo \$A \$B \$C"
		# outputTest "export LS=\"ls -la\" ; \$LS"

	# 2) Strange redirections
		# exitValTest ">>> < ><<"

	# 3) Export with # or Null variable
		# outputTest "export #"
		# outputTest "export \$aze"

	# 4) Others
		# outputTest "echo \$PATH?abc"
		# outputTest "echo \$\"A\""
		# exitValTest "exit -1A"


 RED='\033[0;31m'
 GREEN='\033[0;32m'
 NC='\033[0m' # NO COLOR
 ERRORS=0

 touch bashoutput
 touch minioutput
 touch diffoutput

 # OUTPUT ><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><

 declare -a testOuput=(
 	# Commandes valides et basiques
 	"/bin/ls"
 	"/bin/echo -n \"Hello\""
 	"/bin/echo -n \" \$PATH \""
 	"/bin/ls -a"
 	"/bin/ls -a ../"
 	"awk"

 	"echo"
 	"echo -n"
 	"echo -n -n -n -n"
 	"echo Hello"
 	"echo A B C D E F -n G H I"
 	"/bin/ls filethatdoesntexist"
	"echo /s/a/l/u/t////"
	"echo \$PATH:abc"
	"echo \$PATH.abc"
	"echo \$PATH\ abc"
	"echo \$PATH\\abc"
	"echo \$PATH+abc"
	"echo \$PATH,abc"

 	# Commandes valides et + complexes

 	"ls ; pwd ; echo Hello"
 	"ls ; pwd ;"
 	"pwd;ls"
 	"\"echo\" \"hello\""
 	"\"echo\" \"he;llo\""
 	"echo \"\ls\"ls"

 	# Commandes builtins valide
 	# Export (tout court) non testable car variables d'ENV toujours différentes
 	# Export non testable car le nom du shell qui est en cours d'exécution s'affiche dans l'erreur
 	"unset qd sdfbdqfgqdfgsdg"
 	# env pareil qu'export

 	# Commandes echo + variables d'environnement
 	"echo \$PATH"
 	"echo \"PATH\""
 	"echo PATH"
 	"echo \'PATH\'"
 	"echo \" PATH \""
 	"echo \" \$PATH \""
 	"echo \" \$PATH \$_system_name\""
 	"echo \'\$PATH\'"
 	"echo \' \$PATH \'"
 	"echo \"\$PATH\" \$SHELL Hello \"\$1\""

 	# Test PWD
 	"pwd"
 	"\"pwd\""
 	"pwd ."
 	"pwd .."
 	" pwd .. "
 	"pwd ; echo \$?"

 	# Test Simple Quotes
 	"'/bin/ls'"
 	'l''s'

 	# Test Pipe
 	"cat file | grep bla | more"
 	"ls filethatdoesntexist | grep bla | more"
 	"ls .. | grep Makefile | rev"
 	"/bin/ls \"|\" /usr/bin/grep microshell"
 	# "pwd | cut -c7- | rev | tr e 42 | rev | tr e 42 | tr e 42 | tr e 42 | tr e 42 | tr e 42 | tr e 42 | tr e 42 | tr e 42 | tr e 42 | tr e 42 | tr e 42 | tr e 42 | tr e 42 | tr e 42 | tr e 42 | tr e 42 | tr e 42 | tr e 42 | tr e 42 | tr e 42 | tr e 42 | tr e 42 | tr e 42 | tr e 42 | tr e 42 | tr e 42 | tr e 42 | tr e 42 | tr e 42 | tr e 42 | tr e 42 | tr e 42 | tr e 42  | tr e 42 | tr e 42 | tr e 42  | tr e 42 | tr e 42 | tr e 42  | tr e 42 | tr e 42 | tr e 42  | tr e 42 | tr e 42 | tr e 42  | tr e 42 | tr e 42 | tr e 42  | tr e 42 | tr e 42 | tr e 42  | tr e 42 | tr e 42 | tr e 42  | tr e 42 | tr e 42 | tr e 42  | tr e 42 | tr e 42 | tr e 42  | tr e 42 | tr e 42 | tr e 42  | tr e 42 | tr e 42 | tr e 42  | tr e 42 | tr e 42 | tr e 42  | tr e 42 | tr e 42 | tr e 42  | tr e 42 | tr e 42 | tr e 42  | tr e 42 | tr e 42 | tr e 42  | tr e 42 | tr e 42 | tr e 42 "
 	"pwd | cut -c7- | rev | tail | echo \$PWD"

 	# Impossible de tester en récupérant PWD car on exit aussitôt
 	# Donc on teste via un ls pour check si on est au bon endroit

 	"cd ; ls"
 	"cd . ; ls"
 	"cd .. ; ls"
 	"cd ~ ; ls"
 	"cd ~/ ; ls"
 	"cd .. ; pwd"
 	"cd .. ; pwd ; echo \$?"
 	"cd ; /bin/ls"
 	"cd ; ../../bin/ls"

 )
 function outputTest() {
 	./minishell "$1" > minioutput 2>&1
 	bash -c	"$1" > bashoutput 2>&1
 	cmp -s minioutput bashoutput
 	if [ $? != 0 ]; then
 		echo "OUTPUT TEST : $1" " : ${RED}KO${NC}\n"
 		ERRORS=`expr $ERRORS + 1`
 		diff minioutput bashoutput > diffoutput
 	else
 		echo "OUTPUT TEST : $1" " : ${GREEN}OK${NC}\n"
 	fi
 }

 # BUILTIN EXIT ><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><

 declare -a testBuitinExit=(

 	# Attention aux différences UBUNTU / OSX

 	"exit"
 	"exit 1"
 	"exit A"
 	"exit 1 2"
 	"exit A B C"
 	"exit A1 B2"
 	"exit 1A 2B"
 	"exit -1"
 	"exit -A"
 	"exit 1-A"
 	"exit 1A-"
 	"exit 100000000000000000"
 	"exit -100000000000000000"
 )

 function exitTest() {
 	./minishell "$1" > minioutput 2>&1
 	exitMini=$?
 	bash -c	"$1" > bashoutput 2>&1
 	exitBash=$?
 	# Attention : le then/else est inversé car "-eq" retourne true à priori
 	if [ "$exitMini" -eq "$exitBash" ]; then
 		echo "EXIT TEST : $1" " : ${GREEN}OK${NC}\n"
 	else
 		echo "EXIT TEST : $1" " : ${RED}KO${NC}\n"
 		ERRORS=`expr $ERRORS + 1`
 		echo "DIFFERENCE : mini=$exitMini et bash=$exitBash"
 	fi
 }

 # PARSING EXIT VALUE ><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

 declare -a testExitVal=(
 	";"
 	";;;"
 	"<"
 	">"
 	";;;;;"
 	"\";"\"
 	"\"; ; ;\""
 	"\"; < ;\""
 	"\"; > ;\""
 	"; pwd ; echo Hello"
 	"pwd;;;ls"
 	";;ls;;"
 	";ls;pwd;"
 	"'"
 	"\""
 	"\"\""
 	"''"
 	"'''''"
 	"\"\"\"\"\"\""
 	" \"  \" "
 	"|"
 	" | "
 	"  |;"
 	";|"
 	";|<"
 	"<;"
 	">;"
 	";<"
 	";>"
 	" ;< ls ; "
 	" ;> ls ; "

 	"'';"
 	">>"
 	"  \"|\" ;"
 	"'|'"
 	"  '|' "
 	"|."
 	"< \" \" < ' '<"
 	"\" \" ' ' > < > ''"
 	"<"
 	">"
 	"<<<<<<<<"
 	"<<<"
 	">>>"

 	"cat fddsqffgfhds"
 	"unset HOME ; cd"
 	"cd ; ../../bin/cdfg"
 	"cd ; ../../bin/ls"

 	"ls||pwd" # KO MAIS LE TEST NE DETECTE PAS ! Pourquoi ? Remet en cause les tests ...
 	"ls|;|pwd" # OK mais par exemple ici, il y a une différence d'exit value si on rajoute --posix
 	"ls filethatdoesntexist | grep bla | more"
 )
 function exitValTest() {

 	./minishell "$1" > minioutput 2>&1
 	exitMini=$?
 	bash -c "$1" > bashoutput 2>&1
 	exitBash=$?

 	# Needed because --posix change returned value and I ignore the behavior on Ubuntu so I accept the two behaviors (posix and non-posix)
 	bash -c --posix 	"$1" > bashoutput 2>&1
 	exitBashPosix=$?

 	# Attention : le then/else est inversé car "-eq" retourne true à priori
 	if [ "$exitMini" -eq "$exitBash" ] || [ "$exitMini" -eq "$exitBashPosix" ]
 	then
 		echo "PARSE EXIT TEST : $1" " : ${GREEN}OK${NC}\n"
 	else
 		echo "PARSE EXIT TEST : $1" " : ${RED}KO${NC}\n"
 		ERRORS=`expr $ERRORS + 1`
 		echo "DIFFERENCE : mini=$exitMini et bash=$exitBash et bashposix=$exitBashPosix"
 	fi
 }

 # HERE ARE THE TESTING LOOPS ><><><><><><><><><><><><><><><><><><><><><><><><><>

 for t in "${testOuput[@]}"; do
 	outputTest "$t"
 done

 echo
 for t in "${testBuitinExit[@]}"; do
 	exitTest "$t"
 done

 echo
 for t in "${testExitVal[@]}"; do
 	exitValTest "$t"
 done

 echo
 echo "Nombre d'erreurs : $ERRORS"

 rm minioutput bashoutput diffoutput
