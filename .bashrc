#
# ~/.bashrc
#

# If not running interactively, don't do anything
[[ $- != *i* ]] && return
if [ -f /home/lethurion/.bash_aliases ]; then
	. /home/lethurion/.bash_aliases
fi
PATH=~/bin:$PATH 

PS1='[\u@\h \W]\$ '
set -o vi

export GCC_COLORS='error=01;31:warning=01;35:note=01;36:caret=01;32:locus=01:quote=01'
