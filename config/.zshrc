# Path to your oh-my-zsh installation.
export ZSH=/Users/HimuraXp/.oh-my-zsh

# Set name of the theme to load.
# Look in ~/.oh-my-zsh/themes/
# Optionally, if you set this to "random", it'll load a random theme each
# time that oh-my-zsh is loaded.
ZSH_THEME="muse"

# Uncomment the following line to use case-sensitive completion.
# CASE_SENSITIVE="true"

# Uncomment the following line to use hyphen-insensitive completion. Case
# sensitive completion must be off. _ and - will be interchangeable.
# HYPHEN_INSENSITIVE="true"

# Uncomment the following line to disable bi-weekly auto-update checks.
# DISABLE_AUTO_UPDATE="true"

# Uncomment the following line to change how often to auto-update (in days).
# export UPDATE_ZSH_DAYS=13

# Uncomment the following line to disable colors in ls.
# DISABLE_LS_COLORS="true"

# Uncomment the following line to disable auto-setting terminal title.
# DISABLE_AUTO_TITLE="true"

# Uncomment the following line to enable command auto-correction.
# ENABLE_CORRECTION="true"

# Uncomment the following line to display red dots whilst waiting for completion.
# COMPLETION_WAITING_DOTS="true"

# Uncomment the following line if you want to disable marking untracked files
# under VCS as dirty. This makes repository status check for large repositories
# much, much faster.
# DISABLE_UNTRACKED_FILES_DIRTY="true"

# Uncomment the following line if you want to change the command execution time
# stamp shown in the history command output.
# The optional three formats: "mm/dd/yyyy"|"dd.mm.yyyy"|"yyyy-mm-dd"
# HIST_STAMPS="mm/dd/yyyy"

# Would you like to use another custom folder than $ZSH/custom?
# ZSH_CUSTOM=/path/to/new-custom-folder

# Which plugins would you like to load? (plugins can be found in ~/.oh-my-zsh/plugins/*)
# Custom plugins may be added to ~/.oh-my-zsh/custom/plugins/
# Example format: plugins=(rails git textmate ruby lighthouse)
# Add wisely, as too many plugins slow down shell startup.
plugins=(git)

# User configuration

export PATH="/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/git/bin"
# export MANPATH="/usr/local/man:$MANPATH"

source $ZSH/oh-my-zsh.sh

# You may need to manually set your language environment
# export LANG=en_US.UTF-8

# Preferred editor for local and remote sessions
# if [[ -n $SSH_CONNECTION ]]; then
#   export EDITOR='vim'
# else
#   export EDITOR='mvim'
# fi

# Compilation flags
# export ARCHFLAGS="-arch x86_64"

# ssh
# export SSH_KEY_PATH="~/.ssh/dsa_id"

# Set personal aliases, overriding those provided by oh-my-zsh libs,
# plugins, and themes. Aliases can be placed here, though oh-my-zsh
# users are encouraged to define aliases within the ZSH_CUSTOM folder.
# For a full list of active aliases, run `alias`.
#
# Example aliases
# alias zshconfig="mate ~/.zshrc"
# alias ohmyzsh="mate ~/.oh-my-zsh"


# Header 42
USER42=ylarbi
export USER42

MAIL42="$USER42@student.42.fr"
export MAIL42

# Keypad
# 0 . Enter
bindkey -s "^[Op" "0"
bindkey -s "^[On" "."
bindkey -s "^[OM" "^M"
# 1 2 3
bindkey -s "^[Oq" "1"
bindkey -s "^[Or" "2"
bindkey -s "^[Os" "3"
# 4 5 6
bindkey -s "^[Ot" "4"
bindkey -s "^[Ou" "5"
bindkey -s "^[Ov" "6"
# 7 8 9
bindkey -s "^[Ow" "7"
bindkey -s "^[Ox" "8"
bindkey -s "^[Oy" "9"
# + -  * / =
bindkey -s "^[Ok" "+"
bindkey -s "^[Om" "-"
bindkey -s "^[Oj" "*"
bindkey -s "^[Oo" "/"
bindkey -s "^[OX" "="
# G1 G2 G3
#bindkey -s "^[OP" ":set paste"
#bindkey -s "^[OP" ":set nopaste"

###	--> Alias
##	Ecole 42
#	Dossier de projet
alias libft='cd ~/Documents/my42/project/libft/'
alias fillit='cd ~/Documents/my42/project/fillit/'
alias ft_ls='cd ~/Documents/my42/project/ft_ls/'
alias gnl='cd ~/Documents/my42/project/gnl/'
alias fdf='cd ~/Documents/my42/project/fdf/'
alias ft_sh1='cd ~/Documents/my42/project/ft_sh1/'
alias fractol='cd ~/Documents/my42/project/fractol/'
alias ft_select='cd ~/Documents/my42/project/ft_select/'
alias piscine_php='cd ~/Documents/my42/piscine_php/'
#	Dossier diverses
alias working='cd ~/Documents/my42/working/'
alias my42='cd ~/Documents/my42/'
alias check='cd ~/Documents/check/'
alias tools='cd ~/Documents/tools/'
alias config='cd ~/Documents/my42/config/'
#	Tools
alias norme='~/Documents/tools/Norme-C/./norme'
alias compil='gcc -Wall -Werror -Wextra'
alias cpconfig='cp ~/.zshrc ~/.vimrc ~/Documents/my42/config/ && source .zshrc'
#	Fonction 42 dev
alias ml='myls -al'
alias mlr='myls -Rl'

##	LuxePc
alias luxepc='ssh himuraxp@51.254.121.162 -p5050'


export PATH="$PATH:$HOME/.rvm/bin" # Add RVM to PATH for scripting
