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
