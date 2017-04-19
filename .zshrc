[ -f ~/.fzf.zsh ] && source ~/.fzf.zsh
# Lines configured by zsh-newuser-install
HISTFILE=~/.zshhistory
HISTSIZE=1000
SAVEHIST=1000
setopt autocd nomatch
bindkey -v
# End of lines configured by zsh-newuser-install
# The following lines were added by compinstall
zstyle :compinstall filename '/home/fourfour/.zshrc'

autoload -Uz compinit
compinit

autoload -Uz up-line-or-beginning-search down-line-or-beginning-search
zle -N up-line-or-beginning-search
zle -N down-line-or-beginning-search

[[ -n "${key[Up]}"   ]] && bindkey "${key[Up]}"   up-line-or-beginning-search
[[ -n "${key[Down]}" ]] && bindkey "${key[Down]}" down-line-or-beginning-search

zstyle ':completion:*' menu select

source ~/.zsh/zsh-autosuggestions/zsh-autosuggestions.zsh

bindkey '^ ' autosuggest-accept

PS1='| %D{%H}時:%D{%M}分:%D{%S}秒 | %1d | > '
VIMRUNTIME=/usr/bin
EDITOR=/usr/bin/vim

#echo $(( ($(date --date="161205" +%s) - $(date +%s) )/(60*60*24) )) "days until U30A2 due in"
#echo "-----U30A2 now has a 1 week extension-----"
#echo $(( ($(date --date="161205" +%s) - $(date +%s) )/(60*60*24) )) "days until U7A3 due in"
#echo "-----U7A3 now has a 1 week extension-----"
#echo $(( ($(date --date="161209" +%s) - $(date +%s) )/(60*60*24) )) "days until U29A2 due in"

alias py="python"
alias ls="ls --color"
alias v="vim"
alias cl="clear"
alias s='sudo $(fc -ln -1)'
#alias work='cd /home/fourfour/work && cat /home/fourfour/work/todo'
alias cp="rsync -a --no-i-r --info=progress2"
alias vim='nvim'
#sudo loadkeys jp106
export SSH_AUTH_SOCK="$XDG_RUNTIME_DIR/ssh-agent.socket" 

autoload -Uz compinit
compinit
# End of lines added by compinstall
#
fancy-ctrl-z () {
  if [[ $#BUFFER -eq 0 ]]; then
    BUFFER="fg"
    zle accept-line
  else
    zle push-input
    zle clear-screen
  fi
}
zle -N fancy-ctrl-z
bindkey '^Z' fancy-ctrl-z

function preexec() {
  timer=${timer:-$SECONDS}
}

function precmd() {
  if [ $timer ]; then
    timer_show=$(($SECONDS - $timer))
    export RPROMPT="%F{white}${timer_show}s %{$reset_color%}"
    unset timer
  fi
}

ssh-add /home/fourfour/.ssh/github &> /dev/null
cat /home/fourfour/git/scripts/colorscripts/cirno
