call plug#begin()
Plug 'tpope/vim-sensible'
Plug 'junegunn/fzf', { 'dir': '~/.fzf', 'do': './install --all' }
Plug 'junegunn/fzf.vim'
Plug 'itchyny/lightline.vim'
Plug 'scrooloose/syntastic'
Plug 'tpope/vim-surround'
Plug 'valloric/youcompleteme'
Plug 'bling/vim-bufferline'
Plug 'severin-lemaignan/vim-minimap' 
Plug 'altercation/vim-colors-solarized'
Plug 'https://github.com/suan/vim-instant-markdown.git'
Plug 'https://github.com/scrooloose/nerdtree.git'

call plug#end()

set t_Co=256

map <C-K> :bnext<CR>
map <C-J> :bprev<CR>
map <C-L> :bnext<CR>
map <C-H> :bprev<CR>
map <space> a

let @s = "[sz=1``"

set exrc
set nu
set showmatch
set ruler
set noshowmode
set wrap lbr
set clipboard=unnamed
set noexpandtab
set tabstop=2

autocmd VimEnter * syntax on

let g:lightline = {
\ 'colorscheme': 'landscape',
\ 'component': {
\ 'readonly': '%{&readonly?"Ξ":""}',
\ },
\ 'separator': { 'left': '▶', 'right': '◀' },
\ 'subseparator': { 'left': '»', 'right': '«' }
\ }
